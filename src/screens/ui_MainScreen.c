// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"

void ui_MainScreen_screen_init(void)
{
    ui_MainScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_MainScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_MainScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MainScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pnlSolar1 = lv_obj_create(ui_MainScreen);
    lv_obj_set_width(ui_pnlSolar1, 320);
    lv_obj_set_height(ui_pnlSolar1, 124);
    lv_obj_set_align(ui_pnlSolar1, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_pnlSolar1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_pnlSolar1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_pnlSolar1, lv_color_hex(0x262626), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_pnlSolar1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_pnlSolar1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_pnlSolar1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_pnlSolar1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_pnlSolar1, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImgEvcc = lv_img_create(ui_MainScreen);
    lv_img_set_src(ui_ImgEvcc, &ui_img_evcc_logo_png);
    lv_obj_set_width(ui_ImgEvcc, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImgEvcc, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ImgEvcc, -117);
    lv_obj_set_y(ui_ImgEvcc, -105);
    lv_obj_set_align(ui_ImgEvcc, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImgEvcc, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgEvcc, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_ImgEvcc, 180);

    ui_barHomeBattery = lv_bar_create(ui_MainScreen);
    lv_obj_set_width(ui_barHomeBattery, 9);
    lv_obj_set_height(ui_barHomeBattery, 19);
    lv_obj_set_x(ui_barHomeBattery, 103);
    lv_obj_set_y(ui_barHomeBattery, 6);
    lv_obj_set_style_radius(ui_barHomeBattery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_barHomeBattery, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_barHomeBattery, lv_color_hex(0x00FF17), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_barHomeBattery, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_barHomeBattery, lv_color_hex(0xC0C0C0), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_barHomeBattery, 128, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_barHomeBattery, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_barHomeBattery, LV_GRAD_DIR_VER, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_ImgBattery = lv_img_create(ui_MainScreen);
    lv_img_set_src(ui_ImgBattery, &ui_img_1529214255);
    lv_obj_set_width(ui_ImgBattery, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImgBattery, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ImgBattery, -53);
    lv_obj_set_y(ui_ImgBattery, -106);
    lv_obj_set_align(ui_ImgBattery, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImgBattery, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgBattery, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_ImgBattery, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_ImgBattery, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_barBatteryPower = lv_bar_create(ui_MainScreen);
    lv_bar_set_range(ui_barBatteryPower, 0, 5000);
    lv_obj_set_width(ui_barBatteryPower, 8);
    lv_obj_set_height(ui_barBatteryPower, 25);
    lv_obj_set_x(ui_barBatteryPower, -38);
    lv_obj_set_y(ui_barBatteryPower, -106);
    lv_obj_set_align(ui_barBatteryPower, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_barBatteryPower, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_barBatteryPower, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_barBatteryPower, lv_color_hex(0xFFA600), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_barBatteryPower, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_barBatteryPower, lv_color_hex(0x01FF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_barBatteryPower, 20, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_barBatteryPower, 55, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_barBatteryPower, LV_GRAD_DIR_VER, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_spinLadung = lv_spinner_create(ui_MainScreen, 1000, 90);
    lv_obj_set_width(ui_spinLadung, 25);
    lv_obj_set_height(ui_spinLadung, 25);
    lv_obj_set_x(ui_spinLadung, -13);
    lv_obj_set_y(ui_spinLadung, -105);
    lv_obj_set_align(ui_spinLadung, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_spinLadung, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_spinLadung, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_arc_color(ui_spinLadung, lv_color_hex(0x474747), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_spinLadung, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_spinLadung, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_spinLadung, lv_color_hex(0x1BDA43), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_spinLadung, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_spinLadung, 6, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_ImgPlug = lv_img_create(ui_MainScreen);
    lv_img_set_src(ui_ImgPlug, &ui_img_955610505);
    lv_obj_set_width(ui_ImgPlug, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImgPlug, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ImgPlug, 10);
    lv_obj_set_y(ui_ImgPlug, -104);
    lv_obj_set_align(ui_ImgPlug, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImgPlug, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgPlug, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_lblLadepunkt = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_lblLadepunkt, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblLadepunkt, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblLadepunkt, -10);
    lv_obj_set_y(ui_lblLadepunkt, -1);
    lv_obj_set_align(ui_lblLadepunkt, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_lblLadepunkt, "");
    lv_obj_set_style_text_color(ui_lblLadepunkt, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblLadepunkt, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_lblLadepunkt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblLadepunkt, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblLadeleistung = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_lblLadeleistung, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblLadeleistung, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblLadeleistung, -10);
    lv_obj_set_y(ui_lblLadeleistung, -100);
    lv_obj_set_align(ui_lblLadeleistung, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_lblLadeleistung, "W");
    lv_obj_set_style_text_color(ui_lblLadeleistung, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblLadeleistung, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblLadeleistung, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_txtLadeleistung = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_txtLadeleistung, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_txtLadeleistung, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_txtLadeleistung, -40);
    lv_obj_set_y(ui_txtLadeleistung, -100);
    lv_obj_set_align(ui_txtLadeleistung, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_txtLadeleistung, "0");
    lv_obj_set_style_text_color(ui_txtLadeleistung, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_txtLadeleistung, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_txtLadeleistung, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pnlCarSoc = lv_obj_create(ui_MainScreen);
    lv_obj_set_width(ui_pnlCarSoc, 75);
    lv_obj_set_height(ui_pnlCarSoc, 35);
    lv_obj_set_x(ui_pnlCarSoc, 5);
    lv_obj_set_y(ui_pnlCarSoc, -75);
    lv_obj_set_align(ui_pnlCarSoc, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_pnlCarSoc, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_pnlCarSoc, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_pnlCarSoc, lv_color_hex(0x901010), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_pnlCarSoc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_pnlCarSoc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_txtLadestand = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_txtLadestand, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_txtLadestand, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_txtLadestand, -249);
    lv_obj_set_y(ui_txtLadestand, -70);
    lv_obj_set_align(ui_txtLadestand, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_txtLadestand, "--%");
    lv_obj_set_style_text_color(ui_txtLadestand, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_txtLadestand, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_txtLadestand, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_txtLadestand, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblAuto = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_lblAuto, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblAuto, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblAuto, -118);
    lv_obj_set_y(ui_lblAuto, -86);
    lv_obj_set_align(ui_lblAuto, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblAuto, "");
    lv_obj_set_style_text_color(ui_lblAuto, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblAuto, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_lblAuto, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblAuto, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_barCarSoc = lv_bar_create(ui_MainScreen);
    lv_obj_set_width(ui_barCarSoc, 230);
    lv_obj_set_height(ui_barCarSoc, 24);
    lv_obj_set_x(ui_barCarSoc, 86);
    lv_obj_set_y(ui_barCarSoc, -73);
    lv_obj_set_align(ui_barCarSoc, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_barCarSoc, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE);     /// Flags
    lv_obj_set_style_radius(ui_barCarSoc, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_barCarSoc, lv_color_hex(0x00FF96), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_barCarSoc, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_anim_time(ui_barCarSoc, 500, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_barCarSoc, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_barCarSoc, lv_color_hex(0x00FF0B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_barCarSoc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_barCarSoc, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_barCarSoc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_barCarSoc, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_barCarSoc, LV_BORDER_SIDE_RIGHT, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_barCarSoc, 190, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_sliderSocLimit = lv_slider_create(ui_MainScreen);
    lv_slider_set_value(ui_sliderSocLimit, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_sliderSocLimit) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_sliderSocLimit, 0,
                                                                                                   LV_ANIM_OFF);
    lv_obj_set_width(ui_sliderSocLimit, 220);
    lv_obj_set_height(ui_sliderSocLimit, 30);
    lv_obj_set_x(ui_sliderSocLimit, 91);
    lv_obj_set_y(ui_sliderSocLimit, -73);
    lv_obj_set_align(ui_sliderSocLimit, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_sliderSocLimit, LV_OBJ_FLAG_SNAPPABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_sliderSocLimit, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_sliderSocLimit, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_sliderSocLimit, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_sliderSocLimit, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_sliderSocLimit, 4, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_sliderSocLimit, lv_color_hex(0x364AB2), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_sliderSocLimit, 200, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_sliderSocLimit, -8, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_sliderSocLimit, -8, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_sliderSocLimit, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_sliderSocLimit, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_lblReichweite = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_lblReichweite, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblReichweite, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblReichweite, 10);
    lv_obj_set_y(ui_lblReichweite, -45);
    lv_obj_set_align(ui_lblReichweite, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_lblReichweite, "Reichweite                 km");
    lv_obj_set_style_text_color(ui_lblReichweite, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblReichweite, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_txtReichweite = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_txtReichweite, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_txtReichweite, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_txtReichweite, -168);
    lv_obj_set_y(ui_txtReichweite, -45);
    lv_obj_set_align(ui_txtReichweite, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_txtReichweite, "-");
    lv_obj_set_style_text_color(ui_txtReichweite, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_txtReichweite, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblRestzeit = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_lblRestzeit, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblRestzeit, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblRestzeit, 10);
    lv_obj_set_y(ui_lblRestzeit, -28);
    lv_obj_set_align(ui_lblRestzeit, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_lblRestzeit, "Restladezeit               h");
    lv_obj_set_style_text_color(ui_lblRestzeit, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblRestzeit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_txtRestzeit = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_txtRestzeit, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_txtRestzeit, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_txtRestzeit, -168);
    lv_obj_set_y(ui_txtRestzeit, -28);
    lv_obj_set_align(ui_txtRestzeit, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_txtRestzeit, "--:--");
    lv_obj_set_style_text_color(ui_txtRestzeit, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_txtRestzeit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblLadeenergie = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_lblLadeenergie, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblLadeenergie, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblLadeenergie, 10);
    lv_obj_set_y(ui_lblLadeenergie, -11);
    lv_obj_set_align(ui_lblLadeenergie, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_lblLadeenergie, "Geladen                      kWh");
    lv_obj_set_style_text_color(ui_lblLadeenergie, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblLadeenergie, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_txtLadeenergie = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_txtLadeenergie, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_txtLadeenergie, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_txtLadeenergie, -168);
    lv_obj_set_y(ui_txtLadeenergie, -11);
    lv_obj_set_align(ui_txtLadeenergie, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_txtLadeenergie, "--.-");
    lv_obj_set_style_text_color(ui_txtLadeenergie, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_txtLadeenergie, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblLadelimit = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_lblLadelimit, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblLadelimit, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblLadelimit, 100);
    lv_obj_set_y(ui_lblLadelimit, -45);
    lv_obj_set_align(ui_lblLadelimit, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblLadelimit, "Ladelimit");
    lv_obj_set_style_text_color(ui_lblLadelimit, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblLadelimit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_txtLadelimit = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_txtLadelimit, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_txtLadelimit, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_txtLadelimit, 100);
    lv_obj_set_y(ui_txtLadelimit, -20);
    lv_obj_set_align(ui_txtLadelimit, LV_ALIGN_CENTER);
    lv_label_set_text(ui_txtLadelimit, "--%");
    lv_obj_set_style_text_color(ui_txtLadelimit, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_txtLadelimit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_txtLadelimit, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_txtLadelimit, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_txtLadelimit, lv_color_hex(0x364AB2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_txtLadelimit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_txtLadelimit, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_txtLadelimit, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_txtLadelimit, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_txtLadelimit, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BtnModusPv = lv_btn_create(ui_MainScreen);
    lv_obj_set_width(ui_BtnModusPv, 75);
    lv_obj_set_height(ui_BtnModusPv, 50);
    lv_obj_set_x(ui_BtnModusPv, -100);
    lv_obj_set_y(ui_BtnModusPv, 40);
    lv_obj_set_align(ui_BtnModusPv, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BtnModusPv, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnModusPv, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BtnModusPv, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BtnModusPv, lv_color_hex(0x4C4C4C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BtnModusPv, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BtnModusPv, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BtnModusPv, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_txtBtnModusPv = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_txtBtnModusPv, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_txtBtnModusPv, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_txtBtnModusPv, -100);
    lv_obj_set_y(ui_txtBtnModusPv, 40);
    lv_obj_set_align(ui_txtBtnModusPv, LV_ALIGN_CENTER);
    lv_label_set_text(ui_txtBtnModusPv, "PV");
    lv_obj_set_style_text_color(ui_txtBtnModusPv, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_txtBtnModusPv, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_txtBtnModusPv, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_txtBtnModusPv, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BtnModusPlan = lv_btn_create(ui_MainScreen);
    lv_obj_set_width(ui_BtnModusPlan, 75);
    lv_obj_set_height(ui_BtnModusPlan, 50);
    lv_obj_set_x(ui_BtnModusPlan, 0);
    lv_obj_set_y(ui_BtnModusPlan, 40);
    lv_obj_set_align(ui_BtnModusPlan, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BtnModusPlan, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnModusPlan, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BtnModusPlan, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BtnModusPlan, lv_color_hex(0x4C4C4C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BtnModusPlan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BtnModusPlan, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BtnModusPlan, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_txtBtnModusPlan = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_txtBtnModusPlan, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_txtBtnModusPlan, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_txtBtnModusPlan, 0);
    lv_obj_set_y(ui_txtBtnModusPlan, 40);
    lv_obj_set_align(ui_txtBtnModusPlan, LV_ALIGN_CENTER);
    lv_label_set_text(ui_txtBtnModusPlan, "Plan\n<keiner>");
    lv_obj_set_style_text_color(ui_txtBtnModusPlan, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_txtBtnModusPlan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_txtBtnModusPlan, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BtnModusNow = lv_btn_create(ui_MainScreen);
    lv_obj_set_width(ui_BtnModusNow, 75);
    lv_obj_set_height(ui_BtnModusNow, 50);
    lv_obj_set_x(ui_BtnModusNow, 100);
    lv_obj_set_y(ui_BtnModusNow, 40);
    lv_obj_set_align(ui_BtnModusNow, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BtnModusNow, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnModusNow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BtnModusNow, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BtnModusNow, lv_color_hex(0x4C4C4C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BtnModusNow, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BtnModusNow, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BtnModusNow, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_txtBtnModusNow = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_txtBtnModusNow, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_txtBtnModusNow, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_txtBtnModusNow, 100);
    lv_obj_set_y(ui_txtBtnModusNow, 40);
    lv_obj_set_align(ui_txtBtnModusNow, LV_ALIGN_CENTER);
    lv_label_set_text(ui_txtBtnModusNow, "Schnell");
    lv_obj_set_style_text_color(ui_txtBtnModusNow, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_txtBtnModusNow, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_txtBtnModusNow, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pnlSolar = lv_obj_create(ui_MainScreen);
    lv_obj_set_width(ui_pnlSolar, 320);
    lv_obj_set_height(ui_pnlSolar, 42);
    lv_obj_set_align(ui_pnlSolar, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_pnlSolar, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_pnlSolar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_pnlSolar, lv_color_hex(0x262626), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_pnlSolar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_pnlSolar, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_pnlSolar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_pnlSolar, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_pnlSolar, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_barSolarGrid = lv_bar_create(ui_MainScreen);
    lv_bar_set_range(ui_barSolarGrid, -2, 102);
    lv_bar_set_value(ui_barSolarGrid, 50, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_barSolarGrid, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_barSolarGrid, 230);
    lv_obj_set_height(ui_barSolarGrid, 12);
    lv_obj_set_x(ui_barSolarGrid, 0);
    lv_obj_set_y(ui_barSolarGrid, 99);
    lv_obj_set_align(ui_barSolarGrid, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_barSolarGrid, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE);     /// Flags
    lv_obj_set_style_radius(ui_barSolarGrid, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_barSolarGrid, lv_color_hex(0xDA1B1B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_barSolarGrid, 180, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_barSolarGrid, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_barSolarGrid, lv_color_hex(0x00FF0B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_barSolarGrid, 150, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_barSolarGrid, lv_color_hex(0xC0C0C0), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_barSolarGrid, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_barSolarGrid, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_barSolarGrid, LV_BORDER_SIDE_RIGHT, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_barSolarPower = lv_bar_create(ui_MainScreen);
    lv_bar_set_range(ui_barSolarPower, 0, 6000);
    lv_obj_set_width(ui_barSolarPower, 8);
    lv_obj_set_height(ui_barSolarPower, 25);
    lv_obj_set_x(ui_barSolarPower, -123);
    lv_obj_set_y(ui_barSolarPower, 99);
    lv_obj_set_align(ui_barSolarPower, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_barSolarPower, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_barSolarPower, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_barSolarPower, lv_color_hex(0x00FF17), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_barSolarPower, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_barSolarPower, lv_color_hex(0xFF9600), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_barSolarPower, 100, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_barSolarPower, 230, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_barSolarPower, LV_GRAD_DIR_VER, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_ImgSolar = lv_img_create(ui_MainScreen);
    lv_img_set_src(ui_ImgSolar, &ui_img_9025960_sun_icon_png);
    lv_obj_set_width(ui_ImgSolar, 30);
    lv_obj_set_height(ui_ImgSolar, 30);
    lv_obj_set_x(ui_ImgSolar, -143);
    lv_obj_set_y(ui_ImgSolar, 99);
    lv_obj_set_align(ui_ImgSolar, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImgSolar, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgSolar, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_ImgSolar, lv_color_hex(0xFFD000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_ImgSolar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImgGrid = lv_img_create(ui_MainScreen);
    lv_img_set_src(ui_ImgGrid, &ui_img_1680447448);
    lv_obj_set_width(ui_ImgGrid, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImgGrid, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ImgGrid, 144);
    lv_obj_set_y(ui_ImgGrid, 100);
    lv_obj_set_align(ui_ImgGrid, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImgGrid, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgGrid, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_ImgGrid, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_ImgGrid, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_barGridPower = lv_bar_create(ui_MainScreen);
    lv_bar_set_range(ui_barGridPower, 0, 6000);
    lv_obj_set_width(ui_barGridPower, 8);
    lv_obj_set_height(ui_barGridPower, 25);
    lv_obj_set_x(ui_barGridPower, 123);
    lv_obj_set_y(ui_barGridPower, 99);
    lv_obj_set_align(ui_barGridPower, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_barGridPower, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_barGridPower, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_barGridPower, lv_color_hex(0xFF0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_barGridPower, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_barGridPower, lv_color_hex(0xFF8E00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_barGridPower, 100, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_barGridPower, 230, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_barGridPower, LV_GRAD_DIR_VER, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_pnlDark = lv_obj_create(ui_MainScreen);
    lv_obj_set_width(ui_pnlDark, 320);
    lv_obj_set_height(ui_pnlDark, 240);
    lv_obj_set_align(ui_pnlDark, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_pnlDark, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_pnlDark, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_pnlDark, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_pnlDark, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_pnlDark, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblWifiWait = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_lblWifiWait, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblWifiWait, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_lblWifiWait, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblWifiWait, "Waiting for \nWifi Connection");
    lv_obj_add_flag(ui_lblWifiWait, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_color(ui_lblWifiWait, lv_color_hex(0xFE0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblWifiWait, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_lblWifiWait, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblWifiWait, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_lblWifiWait, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_lblWifiWait, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_lblWifiWait, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_lblWifiWait, lv_color_hex(0xDB1111), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_lblWifiWait, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_lblWifiWait, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_lblWifiWait, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_lblWifiWait, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_lblWifiWait, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_lblWifiWait, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblMqttWait = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_lblMqttWait, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblMqttWait, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_lblMqttWait, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblMqttWait, "Waiting for \nMQTT Connection");
    lv_obj_add_flag(ui_lblMqttWait, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_color(ui_lblMqttWait, lv_color_hex(0xFE0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblMqttWait, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_lblMqttWait, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblMqttWait, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_lblMqttWait, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_lblMqttWait, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_lblMqttWait, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_lblMqttWait, lv_color_hex(0xDB1111), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_lblMqttWait, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_lblMqttWait, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_lblMqttWait, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_lblMqttWait, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_lblMqttWait, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_lblMqttWait, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_sliderSocLimit, ui_event_sliderSocLimit, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BtnModusPv, ui_event_BtnModusPv, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BtnModusPlan, ui_event_BtnModusPlan, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BtnModusNow, ui_event_BtnModusNow, LV_EVENT_ALL, NULL);

}
