#pragma once
#include <FreeRTOS.h>
#include <task.h>
#include <drivers/St7789.h>
#include <drivers/SpiMaster.h>
#include <bits/unique_ptr.h>
#include <queue.h>
#include "components/gfx/Gfx.h"
#include "components/battery/BatteryController.h"
#include "components/brightness/BrightnessController.h"
#include "components/ble/BleController.h"
#include "components/datetime/DateTimeController.h"
#include "components/ble/NotificationManager.h"
#include "components/firmwarevalidator/FirmwareValidator.h"
#include "drivers/Cst816s.h"
#include <date/date.h>
#include "displayapp/screens/Clock.h"
#include "displayapp/screens/Modal.h"
#include <drivers/Watchdog.h>
#include "TouchEvents.h"
#include "Apps.h"
#include "Messages.h"
#include "DummyLittleVgl.h"

namespace Pinetime {
  namespace System {
    class SystemTask;
  };
  namespace Applications {
    class DisplayApp {
      public:
        DisplayApp(Drivers::St7789 &lcd, Components::LittleVgl &lvgl, Drivers::Cst816S &,
                   Controllers::Battery &batteryController, Controllers::Ble &bleController,
                   Controllers::DateTime &dateTimeController, Drivers::WatchdogView &watchdog,
                   System::SystemTask &systemTask,
                   Pinetime::Controllers::NotificationManager& notificationManager);
        void Start();
        void PushMessage(Pinetime::Applications::Display::Messages msg);

      private:
        TaskHandle_t taskHandle;
        static void Process(void* instance);
        void InitHw();
        void Refresh();
        Pinetime::Drivers::St7789& lcd;
        static constexpr uint8_t queueSize = 10;
        static constexpr uint8_t itemSize = 1;
        QueueHandle_t msgQueue;


    };
  }
}


