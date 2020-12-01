#include "DisplayAppFactory.h"
#include "DisplayAppFactory.h"
#include <FreeRTOS.h>
#include <task.h>
#include <libraries/log/nrf_log.h>

using namespace Pinetime::Applications;

DisplayApp::DisplayApp(Drivers::St7789 &lcd, Components::LittleVgl &lvgl, Drivers::Cst816S &,
                       Controllers::Battery &batteryController, Controllers::Ble &bleController,
                       Controllers::DateTime &dateTimeController, Drivers::WatchdogView &watchdog,
                       System::SystemTask &systemTask,
                       Pinetime::Controllers::NotificationManager& notificationManager) :
        lcd{lcd} {
  msgQueue = xQueueCreate(queueSize, itemSize);

}

void DisplayApp::Start() {
  if (pdPASS != xTaskCreate(DisplayApp::Process, "displayapp", 512, this, 0, &taskHandle))
    APP_ERROR_HANDLER(NRF_ERROR_NO_MEM);
}

void DisplayApp::Process(void *instance) {
  auto *app = static_cast<DisplayApp *>(instance);
  NRF_LOG_INFO("displayapp task started!");
  app->InitHw();

  // Send a dummy notification to unlock the lvgl display driver for the first iteration
  xTaskNotifyGive(xTaskGetCurrentTaskHandle());

  while (1) {
    app->Refresh();
  }
}

void DisplayApp::InitHw() {

}

void DisplayApp::Refresh() {
  static bool hello = false;


  if(hello) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        lcd.DrawPixel(j, i, 0xF000);
      }
    }
  }
  else {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        lcd.DrawPixel(j, i, 0x0);
      }
    }
  }

  hello = !hello;
  vTaskDelay(200);
}

void DisplayApp::PushMessage(Display::Messages msg) {
  BaseType_t xHigherPriorityTaskWoken;
  xHigherPriorityTaskWoken = pdFALSE;
  xQueueSendFromISR(msgQueue, &msg, &xHigherPriorityTaskWoken);
  if (xHigherPriorityTaskWoken) {
    /* Actual macro used here is port specific. */
    // TODO : should I do something here?
  }
}