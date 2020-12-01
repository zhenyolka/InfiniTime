#include <legacy/nrf_drv_clock.h>
#include <softdevice/common/nrf_sdh.h>
#include <drivers/SpiMaster.h>
#include <drivers/Spi.h>
#include <drivers/SpiNorFlash.h>
#include <libraries/log/nrf_log.h>
#include <FreeRTOS.h>
#include <task.h>
#include <legacy/nrf_drv_gpiote.h>
#include <libraries/gpiote/app_gpiote.h>
#include <hal/nrf_wdt.h>
#include <cstring>
#include <components/gfx/Gfx.h>
#include <drivers/St7789.h>
#include <components/brightness/BrightnessController.h>
#include "factoryImage.h"


#if NRF_LOG_ENABLED
#include "logging/NrfLogger.h"
Pinetime::Logging::NrfLogger logger;
#else
#include "logging/DummyLogger.h"
Pinetime::Logging::DummyLogger logger;
#endif

static constexpr uint8_t pinSpiSck = 2;
static constexpr uint8_t pinSpiMosi = 3;
static constexpr uint8_t pinSpiMiso = 4;
static constexpr uint8_t pinSpiFlashCsn = 5;
static constexpr uint8_t pinLcdCsn = 25;
static constexpr uint8_t pinLcdDataCommand = 18;

Pinetime::Drivers::SpiMaster spi{Pinetime::Drivers::SpiMaster::SpiModule::SPI0, {
        Pinetime::Drivers::SpiMaster::BitOrder::Msb_Lsb,
        Pinetime::Drivers::SpiMaster::Modes::Mode3,
        Pinetime::Drivers::SpiMaster::Frequencies::Freq8Mhz,
        pinSpiSck,
        pinSpiMosi,
        pinSpiMiso
  }
};
Pinetime::Drivers::Spi flashSpi{spi, pinSpiFlashCsn};
Pinetime::Drivers::SpiNorFlash spiNorFlash{flashSpi};

Pinetime::Drivers::Spi lcdSpi {spi, pinLcdCsn};
Pinetime::Drivers::St7789 lcd {lcdSpi, pinLcdDataCommand};

Pinetime::Components::Gfx gfx{lcd};
Pinetime::Controllers::BrightnessController brightnessController;

extern "C" {
void vApplicationIdleHook(void) {

}

void SPIM0_SPIS0_TWIM0_TWIS0_SPI0_TWI0_IRQHandler(void) {
  if(((NRF_SPIM0->INTENSET & (1<<6)) != 0) && NRF_SPIM0->EVENTS_END == 1) {
    NRF_SPIM0->EVENTS_END = 0;
    spi.OnEndEvent();
  }

  if(((NRF_SPIM0->INTENSET & (1<<19)) != 0) && NRF_SPIM0->EVENTS_STARTED == 1) {
    NRF_SPIM0->EVENTS_STARTED = 0;
    spi.OnStartedEvent();
  }

  if(((NRF_SPIM0->INTENSET & (1<<1)) != 0) && NRF_SPIM0->EVENTS_STOPPED == 1) {
    NRF_SPIM0->EVENTS_STOPPED = 0;
  }
}
}

void Process(void* instance) {
  // Wait before erasing the memory to let the time to the SWD debugger to flash a new firmware before running this one.
  vTaskDelay(5000);

  APP_GPIOTE_INIT(2);

  NRF_LOG_INFO("Init...");
  spi.Init();
  spiNorFlash.Init();
  spiNorFlash.Wakeup();
  brightnessController.Init();
  lcd.Init();
  gfx.Init();
  NRF_LOG_INFO("Init Done!")

  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      gfx.pixel_draw(70+i, 70+j, 0x00AA);
    }
  }

  NRF_LOG_INFO("Erasing...");
  for (uint32_t erased = 0; erased < sizeof(factoryImage); erased += 0x1000) {
    spiNorFlash.SectorErase(erased);
  }
  NRF_LOG_INFO("Erase done!");

  NRF_LOG_INFO("Writing graphic...");
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      gfx.pixel_draw(70+i, 70+j, 0xaa00);
    }
  }

  static constexpr uint32_t memoryChunkSize = 200;
  uint8_t writeBuffer[memoryChunkSize];
  for(size_t offset = 0; offset < sizeof(factoryImage); offset+=memoryChunkSize) {
    std::memcpy(writeBuffer, &factoryImage[offset], memoryChunkSize);
    spiNorFlash.Write(offset, writeBuffer, memoryChunkSize);
  }
  NRF_LOG_INFO("Writing graphic done!");

  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      gfx.pixel_draw(70+i, 70+j, 0xffff);
    }
  }


  NRF_LOG_INFO("Done!");

  while(1) {
    asm("nop" );
  }
}

int main(void) {
  TaskHandle_t taskHandle;

  logger.Init();
  nrf_drv_clock_init();

  if (pdPASS != xTaskCreate(Process, "MAIN", 512, nullptr, 0, &taskHandle))
    APP_ERROR_HANDLER(NRF_ERROR_NO_MEM);

  vTaskStartScheduler();

  for (;;) {
    APP_ERROR_HANDLER(NRF_ERROR_FORBIDDEN);
  }
}
