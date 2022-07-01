#pragma once

#include "displayapp/screens/Screen.h"
#include "displayapp/screens/BatteryIcon.h"
#include "displayapp/screens/Symbols.h"
#include "components/datetime/DateTimeController.h"
#include "components/battery/BatteryController.h"
#include <lvgl/lvgl.h>

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class Calendar : public Screen {
      public:
        Calendar(DisplayApp* app,
            Pinetime::Controllers::Battery& batteryController,
            Controllers::DateTime& dateTimeController);
        ~Calendar() override;

        bool OnTouchEvent(TouchEvents event) override;
        void Refresh() override;

      private:
        Pinetime::Controllers::Battery& batteryController;

        Controllers::DateTime& dateTimeController;

        DirtyValue<uint8_t> batteryPercentRemaining {};
        DirtyValue<std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds>> currentDateTime {};
        DirtyValue<bool> powerPresent {};

        BatteryIcon batteryIcon;

        lv_obj_t* label_time = nullptr;
        lv_obj_t* calendar = nullptr;
        lv_obj_t* batteryPlug = nullptr;
        lv_calendar_date_t today;
        lv_calendar_date_t current;

        lv_task_t* taskRefresh;
      };
    }
  }
}