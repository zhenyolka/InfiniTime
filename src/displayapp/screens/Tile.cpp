#include "displayapp/screens/Tile.h"
#include "displayapp/DisplayApp.h"
#include "displayapp/screens/BatteryIcon.h"

using namespace Pinetime::Applications::Screens;

namespace {
  void lv_update_task(struct _lv_task_t* task) {
    auto* user_data = static_cast<Tile*>(task->user_data);
    user_data->UpdateScreen();
  }

  void event_handler(lv_obj_t* obj, lv_event_t event) {
    if (event != LV_EVENT_RELEASED) {
      return;
    }

    Tile* screen = static_cast<Tile *>(obj->user_data);
    screen->OnObjectEvent(obj);
  }
}

static std::array<std::array<lv_coord_t, 2>, 4> iconPos = {{{-55, -50}, {55, -50}, {-55, 60}, {55, 60}}};

Tile::Tile(uint8_t screenID,
           uint8_t numScreens,
           DisplayApp* app,
           Controllers::Settings& settingsController,
           Pinetime::Controllers::Battery& batteryController,
           Controllers::DateTime& dateTimeController,
           std::array<Applications, 4>& applications)
  : Screen(app), batteryController {batteryController}, dateTimeController {dateTimeController}, pageIndicator(screenID, numScreens) {

  settingsController.SetAppMenu(screenID);

  // Time
  label_time = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_align(label_time, LV_LABEL_ALIGN_CENTER);
  lv_obj_align(label_time, nullptr, LV_ALIGN_IN_TOP_LEFT, 0, 0);

  // Battery
  batteryIcon.Create(lv_scr_act());
  lv_obj_align(batteryIcon.GetObject(), nullptr, LV_ALIGN_IN_TOP_RIGHT, -8, 0);

  pageIndicator.Create();

  for(int i = 0; i < 4; i++) {
    apps[i] = applications[i].application;
    if ( applications[i].application != Apps::None) {
      iconsApps[i] = lv_imgbtn_create(lv_scr_act(), NULL);
      lv_imgbtn_set_src(iconsApps[i], LV_BTN_STATE_RELEASED, applications[i].icon);
      lv_imgbtn_set_src(iconsApps[i], LV_BTN_STATE_PRESSED, applications[i].icon);
      lv_obj_align(iconsApps[i], NULL, LV_ALIGN_CENTER, iconPos[i][0], iconPos[i][1]);
      iconsApps[i]->user_data = this;
      lv_obj_set_event_cb(iconsApps[i], event_handler);

      iconsAppsLabel[i] = lv_label_create(lv_scr_act(), NULL);
      //lv_label_set_long_mode(iconsAppsLabel[i], LV_LABEL_LONG_SROLL);
      lv_label_set_long_mode(iconsAppsLabel[i], LV_LABEL_LONG_CROP);
      lv_obj_set_width(iconsAppsLabel[i], 115);
      lv_label_set_text(iconsAppsLabel[i], applications[i].name);
      lv_label_set_align(iconsAppsLabel[i], LV_LABEL_ALIGN_CENTER );
      lv_obj_align(iconsAppsLabel[i], iconsApps[i], LV_ALIGN_IN_BOTTOM_MID, 0, 25);
    }
  }

  taskUpdate = lv_task_create(lv_update_task, 5000, LV_TASK_PRIO_MID, this);

  UpdateScreen();
}

Tile::~Tile() {
  lv_task_del(taskUpdate);
  lv_obj_clean(lv_scr_act());
}

void Tile::UpdateScreen() {
  lv_label_set_text(label_time, dateTimeController.FormattedTime().c_str());
  batteryIcon.SetBatteryPercentage(batteryController.PercentRemaining());
}

void Tile::OnObjectEvent(lv_obj_t *obj) {
  for(int i = 0; i < 4; i++) {
    if ( apps[i] != Apps::None && obj == iconsApps[i] ) {
      app->StartApp(apps[i], DisplayApp::FullRefreshDirections::Up);
      running = false;
      return;
    }
  }
}
