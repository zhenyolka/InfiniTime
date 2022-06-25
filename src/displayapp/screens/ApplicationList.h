#pragma once

#include <array>
#include <memory>

#include "displayapp/screens/Screen.h"
#include "displayapp/screens/ScreenList.h"
#include "components/datetime/DateTimeController.h"
#include "components/settings/Settings.h"
#include "components/battery/BatteryController.h"
#include "displayapp/screens/Symbols.h"
#include "displayapp/screens/Tile.h"

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class ApplicationList : public Screen {
      public:
        explicit ApplicationList(DisplayApp* app,
                                 Pinetime::Controllers::Settings& settingsController,
                                 Pinetime::Controllers::Battery& batteryController,
                                 Controllers::DateTime& dateTimeController);
        ~ApplicationList() override;
        bool OnTouchEvent(TouchEvents event) override;

      private:
        auto CreateScreenList() const;
        std::unique_ptr<Screen> CreateScreen(unsigned int screenNum) const;

        Controllers::Settings& settingsController;
        Pinetime::Controllers::Battery& batteryController;
        Controllers::DateTime& dateTimeController;

        static constexpr int appsPerScreen = 4;

        // Increment this when more space is needed
        static constexpr int nScreens = 3;

        static constexpr std::array<Tile::Applications, appsPerScreen * nScreens> applications {{
          {"F:/res/icon_apps/time-management.bin",    Apps::StopWatch,  "Stop Watch"},
          {"F:/res/icon_apps/music.bin",      Apps::Music,      "Music"},
          {"F:/res/icon_apps/sand-clock.bin",     Apps::Timer,      "Timer"},
          {"F:/res/icon_apps/footprint.bin",  Apps::Steps,      "Steps"},

          {"F:/res/icon_apps/heart.bin",          Apps::HeartRate,  "Heart Rate"},
          {"F:/res/icon_apps/map.bin",        Apps::Navigation, "Navigation"},
          {"F:/res/icon_apps/paint-palette.bin",  Apps::Paint,      "Paint"},
          {"F:/res/icon_apps/ping-pong.bin",      Apps::Paddle,     "Paddle"},

          {"F:/res/icon_apps/pastime.bin",          Apps::Twos,       "2048"},
          {"F:/res/icon_apps/line-chart.bin",       Apps::Motion,     "Motion"},
          {"F:/res/icon_apps/metronome.bin",        Apps::Metronome,  "Metronome"},
          {"F:/res/icon_apps/alarm-clock.bin",      Apps::Alarm,      "Alarm"},
        }};
        ScreenList<nScreens> screens;
      };
    }
  }
}
