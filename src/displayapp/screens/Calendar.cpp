#include "displayapp/screens/Calendar.h"

#include "displayapp/DisplayApp.h"
#include "displayapp/screens/Screen.h"
#include "displayapp/screens/BatteryIcon.h"
#include "components/datetime/DateTimeController.h"
#include "components/battery/BatteryController.h"

using namespace Pinetime::Applications::Screens;

Calendar::Calendar(DisplayApp* app, Pinetime::Controllers::Battery& batteryController, Controllers::DateTime& dateTimeController) : Screen(app), batteryController {batteryController}, dateTimeController {dateTimeController} {

    // Status bar clock
    label_time = lv_label_create(lv_scr_act(), nullptr);
    lv_label_set_align(label_time, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 0, 0);

    // Battery
    batteryIcon.Create(lv_scr_act());
    lv_obj_align(batteryIcon.GetObject(), lv_scr_act(), LV_ALIGN_IN_TOP_RIGHT, 0, 0);

    batteryPlug = lv_label_create(lv_scr_act(), nullptr);
    lv_obj_set_style_local_text_color(batteryPlug, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0xFF0000));
    lv_label_set_text_static(batteryPlug, Symbols::plug);
    lv_obj_align(batteryPlug, batteryIcon.GetObject(), LV_ALIGN_OUT_LEFT_MID, -5, 0);

    // Create calendar object
    calendar = lv_calendar_create(lv_scr_act(), NULL);
    // Set size
    lv_obj_set_size(calendar, 230, 200);
    // Set alignment
    lv_obj_align(calendar, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -5);
    // Disable clicks
    lv_obj_set_click(calendar, false);

    // Set background of today's date
    lv_obj_set_style_local_bg_opa(calendar, LV_CALENDAR_PART_DATE, LV_STATE_FOCUSED, LV_OPA_COVER);
    lv_obj_set_style_local_bg_color(calendar, LV_CALENDAR_PART_DATE, LV_STATE_FOCUSED, LV_COLOR_WHITE);
    lv_obj_set_style_local_radius(calendar, LV_CALENDAR_PART_DATE, LV_STATE_FOCUSED, 3);

    // Set style of today's date
    lv_obj_set_style_local_text_color(calendar, LV_CALENDAR_PART_DATE, LV_STATE_FOCUSED, LV_COLOR_BLACK);

    // Set style of inactive month's days
    lv_obj_set_style_local_text_color(calendar, LV_CALENDAR_PART_DATE, LV_STATE_DISABLED, lv_color_hex(0x505050));

    // Get today's date
    today.year = static_cast<int>(dateTimeController.Year());
    today.month = static_cast<int>(dateTimeController.Month());
    today.day = static_cast<int>(dateTimeController.Day());

    // Set today's date
    lv_calendar_set_today_date(calendar, &today);
    lv_calendar_set_showed_date(calendar, &today);

    // Use today's date as a reference for which month to show if moved
    current = today;

    taskRefresh = lv_task_create(RefreshTaskCallback, LV_DISP_DEF_REFR_PERIOD, LV_TASK_PRIO_MID, this);
    Refresh();
}

Calendar::~Calendar() {
    lv_obj_clean(lv_scr_act());
}

bool Calendar::OnTouchEvent(Pinetime::Applications::TouchEvents event) {
    switch (event) {
        case TouchEvents::SwipeLeft: {
            if (current.month == 12) {
                current.month = 1;
                current.year++;
            }
            else{
                current.month++;
            }
            lv_calendar_set_showed_date(calendar, &current);
            return true;
        }
        case TouchEvents::SwipeRight: {
            if (current.month == 1) {
                current.month = 12;
                current.year--;
            }
            else{
                current.month--;
            }
            lv_calendar_set_showed_date(calendar, &current);
            return true;
        }
        default: {
            return false;
        }
    }
    return false;
}

void Calendar::Refresh() {
    powerPresent = batteryController.IsPowerPresent();
    if (powerPresent.IsUpdated()) {
        lv_label_set_text_static(batteryPlug, BatteryIcon::GetPlugIcon(powerPresent.Get()));
    }

    batteryPercentRemaining = batteryController.PercentRemaining();
    if (batteryPercentRemaining.IsUpdated()) {
        auto batteryPercent = batteryPercentRemaining.Get();
        batteryIcon.SetBatteryPercentage(batteryPercent);
    }

    currentDateTime = dateTimeController.CurrentDateTime();

    if (currentDateTime.IsUpdated()) {
        lv_label_set_text(label_time, dateTimeController.FormattedTime().c_str());
    }

    lv_obj_realign(batteryPlug);
    lv_obj_realign(label_time);
}