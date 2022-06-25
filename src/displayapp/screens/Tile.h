#pragma once

#include <lvgl/lvgl.h>
#include <cstdint>
#include <memory>
#include "displayapp/screens/Screen.h"
#include "displayapp/Apps.h"
#include "components/datetime/DateTimeController.h"
#include "components/settings/Settings.h"
#include "components/datetime/DateTimeController.h"
#include "components/battery/BatteryController.h"
#include "displayapp/screens/BatteryIcon.h"
#include "displayapp/widgets/PageIndicator.h"

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class Tile : public Screen {
      public:
        struct Applications {
          const char* icon;
          Pinetime::Applications::Apps application;
          const char* name;
        };

        explicit Tile(uint8_t screenID,
                      uint8_t numScreens,
                      DisplayApp* app,
                      Controllers::Settings& settingsController,
                      Pinetime::Controllers::Battery& batteryController,
                      Controllers::DateTime& dateTimeController,
                      std::array<Applications, 4>& applications);

        ~Tile() override;

        void UpdateScreen();
        void OnObjectEvent(lv_obj_t* obj);

      private:
        Pinetime::Controllers::Battery& batteryController;
        Controllers::DateTime& dateTimeController;

        lv_task_t* taskUpdate;

        lv_obj_t* label_time;
        lv_obj_t* btnm1;

        Widgets::PageIndicator pageIndicator;

        BatteryIcon batteryIcon;

        Pinetime::Applications::Apps apps[4];

        lv_obj_t * iconsApps[4];
        lv_obj_t * iconsAppsLabel[4];
      };
    }
  }
}
