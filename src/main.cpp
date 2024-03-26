#include <TFT_eSPI.h>
#include <Arduino.h>
#include <TimeLib.h>
#include <SPI.h>

#define Display_28       //according to the board you using ,if you using the ESP32 Display 3.5inch board, please define 'Display_35'.if using 2.4inch board,please define 'Display_24'.

#include <lvgl.h>
#include "ui.h"

#if defined Display_35      //ESP32 Display 3.5inch Board
/*screen resolution*/
static const uint16_t screenWidth  = 480;
static const uint16_t screenHeight = 320;
uint16_t calData[5] = { 353, 3568, 269, 3491, 7  };     /*touch caldata*/

#elif defined Display_24    //ESP32 Display 2.4inch Board
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 240;
uint16_t calData[5] = { 557, 3263, 369, 3493, 3  };

#elif defined Display_28    //ESP32 Display 2.8inch Board
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 240;
uint16_t calData[5] = { 189, 3416, 359, 3439, 1 };
#endif

TFT_eSPI lcd = TFT_eSPI(); /* TFT entity */

// Install the "XPT2046_Touchscreen" library by Paul Stoffregen to use the Touchscreen - https://github.com/PaulStoffregen/XPT2046_Touchscreen
// Note: this library doesn't require further configuration
#include <XPT2046_Touchscreen.h>

// ----------------------------
// Touch Screen pins
// ----------------------------

// The CYD touch uses some non default
// SPI pins

#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33
SPIClass mySpi = SPIClass(VSPI);
XPT2046_Touchscreen ts(XPT2046_CS, XPT2046_IRQ);
uint16_t touchScreenMinimumX = 200, touchScreenMaximumX = 3700, touchScreenMinimumY = 240,touchScreenMaximumY = 3800;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf1[ screenWidth * screenHeight / 13 ];

// Wifi & HTTP & MQTT
#include <WiFi.h>
#include <HTTPClient.h>
#include <PubSubClient.h>

// Get user config
#include "config.h"

const char* ssid = SSID;
const char* password = PASSWORD;

// Add your MQTT Broker IP address, example:
//const char* mqtt_server = "192.168.1.144";
const char* mqtt_server = EVCC_SERVER_IP;

WiFiClient espClient;
HTTPClient http_client;
PubSubClient wifi_client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

// Some internal temporary variables
int Plan = 0;
int PlanSoc = 0;
String PlanTime = "00:00";

//_______________________
/* display flash */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
  uint32_t w = ( area->x2 - area->x1 + 1 );
  uint32_t h = ( area->y2 - area->y1 + 1 );

  lcd.startWrite();
  lcd.setAddrWindow( area->x1, area->y1, w, h );
  lcd.pushColors( ( uint16_t * )&color_p->full, w * h, true );
  lcd.endWrite();

  lv_disp_flush_ready( disp );
}

/*touch read*/
void my_touchpad_read( lv_indev_drv_t * indev_drv, lv_indev_data_t * data )
{
   if(ts.touched())
  {
    TS_Point p = ts.getPoint();
    //Some very basic auto calibration so it doesn't go out of range
    if(p.x < touchScreenMinimumX) touchScreenMinimumX = p.x;
    if(p.x > touchScreenMaximumX) touchScreenMaximumX = p.x;
    if(p.y < touchScreenMinimumY) touchScreenMinimumY = p.y;
    if(p.y > touchScreenMaximumY) touchScreenMaximumY = p.y;
    //Map this to the pixel position
    data->point.x = map(p.x,touchScreenMinimumX,touchScreenMaximumX,1,screenWidth); /* Touchscreen X calibration */
    data->point.y = map(p.y,touchScreenMinimumY,touchScreenMaximumY,1,screenHeight); /* Touchscreen Y calibration */
    data->state = LV_INDEV_STATE_PRESSED;
    
    // Serial.print("Touch x ");
    // Serial.print(data->point.x);
    // Serial.print(" y ");
    // Serial.println(data->point.y);
    
  }
  else
  {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

lv_indev_t * indev; //Touchscreen input device

/* Setup WIfi */
void setup_wifi() {
  delay(10);
  lv_obj_clear_flag(ui_pnlDark, LV_OBJ_FLAG_HIDDEN);     /// Flags
  lv_obj_clear_flag(ui_lblWifiWait, LV_OBJ_FLAG_HIDDEN);     /// Flags
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    lv_timer_handler();
    Serial.print(".");
  }

  lv_obj_add_flag(ui_pnlDark, LV_OBJ_FLAG_HIDDEN);     /// Flags
  lv_obj_add_flag(ui_lblWifiWait, LV_OBJ_FLAG_HIDDEN);     /// Flags
  lv_timer_handler();

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void callback(char* topic, byte* message, unsigned int length) {
  String messageTemp;
  
  /* Convert char to NUL terminated string */
  for (int i = 0; i < length; i++) {
    messageTemp += (char)message[i];
  }
  messageTemp += '\0';

  // If a message is received on the topic esp32/output, you check the text of the message. 
  if (String(topic) == "evcc/loadpoints/" + (String)LOADPOINT + "/charging") {
   if(messageTemp == "false"){
      lv_obj_add_flag(ui_spinLadung, LV_OBJ_FLAG_HIDDEN);
    }
    else if(messageTemp == "true"){
     lv_obj_clear_flag(ui_spinLadung, LV_OBJ_FLAG_HIDDEN);
    }
  }

  else if (String(topic) == "evcc/loadpoints/" + (String)LOADPOINT + "/connected") {
   if(messageTemp == "false"){
      lv_obj_add_flag(ui_ImgPlug, LV_OBJ_FLAG_HIDDEN);
    }
    else if(messageTemp == "true"){
     lv_obj_clear_flag(ui_ImgPlug, LV_OBJ_FLAG_HIDDEN);
    }
  }

  else if (String(topic) == "evcc/loadpoints/" + (String)LOADPOINT + "/chargePower") {
    lv_label_set_text(ui_txtLadeleistung, messageTemp.c_str());
  }

  else if (String(topic) == "evcc/site/batterySoc") {
    int messageTempInt = messageTemp.toInt(); // remove decimals
    lv_bar_set_value(ui_barHomeBattery, messageTempInt, LV_ANIM_OFF);
  }

  else if (String(topic) == "evcc/site/bufferSoc") {
    int messageTempInt = messageTemp.toInt(); // remove decimals
    lv_obj_set_style_bg_main_stop(ui_barHomeBattery, (255*(100-messageTempInt))/100, LV_PART_INDICATOR | LV_STATE_DEFAULT);
  }

  else if (String(topic) == "evcc/site/batteryPower") {
   int messageTempInt = messageTemp.toInt(); // remove decimals
   lv_bar_set_value(ui_barBatteryPower, abs(messageTempInt), LV_ANIM_OFF);
   if (messageTempInt > 0) {
      lv_obj_set_style_img_recolor(ui_ImgBattery, lv_color_hex(COL_RED), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_grad_color(ui_barBatteryPower, lv_color_hex(COL_RED), LV_PART_INDICATOR | LV_STATE_DEFAULT);
   }
   else if (messageTempInt < 0) {
      lv_obj_set_style_img_recolor(ui_ImgBattery, lv_color_hex(COL_GREEN), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_grad_color(ui_barBatteryPower, lv_color_hex(COL_INTENSE_GREEN), LV_PART_INDICATOR | LV_STATE_DEFAULT);
   }
   else {
      lv_obj_set_style_img_recolor(ui_ImgBattery, lv_color_hex(COL_WHITE), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_grad_color(ui_barBatteryPower, lv_color_hex(COL_WHITE), LV_PART_INDICATOR | LV_STATE_DEFAULT);
   }
  }

  else if (String(topic) == "evcc/site/gridPower") {
    int messageTempInt = messageTemp.toInt(); // remove decimals
   if (messageTempInt >= 100) {
      lv_bar_set_value(ui_barGridPower, abs(messageTempInt), LV_ANIM_OFF);
      lv_obj_set_style_img_recolor(ui_ImgGrid, lv_color_hex(COL_RED), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(ui_barGridPower, lv_color_hex(COL_RED), LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_grad_color(ui_barGridPower, lv_color_hex(COL_ORANGE), LV_PART_INDICATOR | LV_STATE_DEFAULT);
   }
   else if (messageTempInt <= -100) {
      lv_bar_set_value(ui_barGridPower, abs(messageTempInt), LV_ANIM_OFF);
      if (messageTempInt <= -MIN_WALLBOX_POWER) {
        animGridJump_Animation(ui_ImgGrid, 0);
      }
      lv_obj_set_style_img_recolor(ui_ImgGrid, lv_color_hex(COL_GREEN), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(ui_barGridPower, lv_color_hex(COL_INTENSE_GREEN), LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_grad_color(ui_barGridPower, lv_color_hex(COL_INTENSE_GREEN), LV_PART_INDICATOR | LV_STATE_DEFAULT);
   }
   else {
      lv_bar_set_value(ui_barGridPower, abs(messageTempInt), LV_ANIM_OFF);
      lv_obj_set_style_img_recolor(ui_ImgGrid, lv_color_hex(COL_WHITE), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(ui_barGridPower, lv_color_hex(COL_WHITE), LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_grad_color(ui_barGridPower, lv_color_hex(COL_WHITE), LV_PART_INDICATOR | LV_STATE_DEFAULT);
   }
  }

  else if (String(topic) == "evcc/site/pvPower") {
   int messageTempInt = messageTemp.toInt(); // remove decimals
   lv_bar_set_value(ui_barSolarPower, messageTempInt, LV_ANIM_OFF);
   if (messageTempInt >= 100) {
      lv_obj_set_style_img_recolor(ui_ImgSolar, lv_color_hex(COL_YELLOW), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(ui_barSolarPower, lv_color_hex(COL_INTENSE_GREEN), LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_grad_color(ui_barSolarPower, lv_color_hex(COL_YELLOW), LV_PART_INDICATOR | LV_STATE_DEFAULT);
   }
   else {
      lv_obj_set_style_img_recolor(ui_ImgSolar, lv_color_hex(COL_WHITE), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(ui_barSolarPower, lv_color_hex(COL_WHITE), LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_grad_color(ui_barSolarPower, lv_color_hex(COL_WHITE), LV_PART_INDICATOR | LV_STATE_DEFAULT);
   }
  }

  else if (String(topic) == "evcc/loadpoints/" + (String)LOADPOINT + "/vehicleSoc") {
    int messageTempInt = messageTemp.toInt(); // remove decimals
    lv_label_set_text(ui_txtLadestand, (String(messageTempInt) + "%").c_str());
    lv_bar_set_value(ui_barCarSoc, messageTempInt, LV_ANIM_OFF);
  }

  else if (String(topic) == "evcc/loadpoints/" + (String)LOADPOINT + "/vehicleRange") {
    lv_label_set_text(ui_txtReichweite, messageTemp.c_str());
  }

  else if (String(topic) == "evcc/loadpoints/" + (String)LOADPOINT + "/chargeRemainingDuration") {
    // Convert Unix Time to hour:min
    // format with sprintf
    int messageTempInt = messageTemp.toInt(); 
    char timestamp[5];
    sprintf(timestamp,"%02d:%02d", hour(messageTempInt), minute(messageTempInt));
    lv_label_set_text(ui_txtRestzeit, timestamp);
  }

  else if (String(topic) == "evcc/loadpoints/" + (String)LOADPOINT + "/chargedEnergy") {
    float messageTempInt = messageTemp.toFloat()/1000; // remove decimals and convert to kWh
    lv_label_set_text(ui_txtLadeenergie, String(messageTempInt).c_str());
  }

  else if (String(topic) == "evcc/loadpoints/" + (String)LOADPOINT + "/effectiveLimitSoc") {
    int messageTempInt = messageTemp.toInt(); // remove decimals
    lv_label_set_text(ui_txtLadelimit, (String(messageTempInt) + "%").c_str());
    lv_slider_set_value(ui_sliderSocLimit, messageTempInt, LV_ANIM_OFF);
  }

  else if (String(topic) == "evcc/loadpoints/" + (String)LOADPOINT + "/title") {
    lv_label_set_text(ui_lblLadepunkt, String(LOADPOINT + ": " + messageTemp).c_str());
  }

  else if (String(topic) == "evcc/vehicles/ev1/title") {
    lv_label_set_text(ui_lblAuto, messageTemp.c_str());
  }


  else if (String(topic) == "evcc/vehicles/ev1/plans") {
    Plan = messageTemp.toInt(); // remove decimals
    if (Plan == true) {
      lv_obj_set_style_bg_color(ui_BtnModusPlan, lv_color_hex(COL_BUTTON_PLAN_ACTIVE), LV_PART_MAIN | LV_STATE_DEFAULT);
    } else {
      lv_obj_set_style_bg_color(ui_BtnModusPlan, lv_color_hex(COL_BUTTON_INACTIVE), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(ui_txtBtnModusPlan, "Plan\n<keiner>");
    }
  }

  else if (String(topic) == "evcc/vehicles/ev1/plans/1/soc") {
    PlanSoc = messageTemp.toInt(); // remove decimals
    lv_label_set_text(ui_txtBtnModusPlan, ("Plan\n" + String(PlanSoc) + "%\n" + PlanTime +" h").c_str());
    if (Plan == true) {
      lv_obj_set_style_bg_color(ui_BtnModusPlan, lv_color_hex(COL_BUTTON_PLAN_ACTIVE), LV_PART_MAIN | LV_STATE_DEFAULT);
    } else {
      lv_obj_set_style_bg_color(ui_BtnModusPlan, lv_color_hex(COL_BUTTON_INACTIVE), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
  }

  else if (String(topic) == "evcc/vehicles/ev1/plans/1/time") {
    char timestamp[5];
    sprintf(timestamp,"%02d:%02d", hour(messageTemp.toInt()), minute(messageTemp.toInt()));
    PlanTime = timestamp;
    lv_label_set_text(ui_txtBtnModusPlan, ("Plan\n" + String(PlanSoc) + "%\n" + PlanTime +" h").c_str());
    if (Plan == true) {
      lv_obj_set_style_bg_color(ui_BtnModusPlan, lv_color_hex(COL_BUTTON_PLAN_ACTIVE), LV_PART_MAIN | LV_STATE_DEFAULT);
    } else {
      lv_obj_set_style_bg_color(ui_BtnModusPlan, lv_color_hex(COL_BUTTON_INACTIVE), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
  }

  else if (String(topic) == "evcc/loadpoints/" + (String)LOADPOINT + "/mode") {
    if(messageTemp == "pv"){
      lv_obj_set_style_bg_color(ui_BtnModusPv, lv_color_hex(COL_BUTTON_PV_ACTIVE), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(ui_BtnModusNow, lv_color_hex(COL_BUTTON_INACTIVE), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else if(messageTemp == "now"){
      lv_obj_set_style_bg_color(ui_BtnModusNow, lv_color_hex(COL_BUTTON_NOW_ACTIVE), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(ui_BtnModusPv, lv_color_hex(COL_BUTTON_INACTIVE), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else if(messageTemp == "off" || messageTemp == "minpv"){
      lv_obj_set_style_bg_color(ui_BtnModusNow, lv_color_hex(COL_BUTTON_INACTIVE), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(ui_BtnModusPv, lv_color_hex(COL_BUTTON_INACTIVE), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
  }

  else if (String(topic) == "evcc/loadpoints/" + (String)LOADPOINT + "/sessionSolarPercentage") {
    int messageTempInt = (int)(messageTemp.toFloat() + 0.5); // round and remove decimals
    lv_bar_set_value(ui_barSolarGrid, messageTempInt, LV_ANIM_OFF);
  }

}

void reconnect() {
  // Loop until we're reconnected
  while (!wifi_client.connected()) {
    lv_obj_clear_flag(ui_pnlDark, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_lblMqttWait, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_timer_handler();
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (wifi_client.connect("evcc-display")) {
      Serial.println("connected");
      lv_obj_add_flag(ui_pnlDark, LV_OBJ_FLAG_HIDDEN);     /// Flags
      lv_obj_add_flag(ui_lblMqttWait, LV_OBJ_FLAG_HIDDEN);     /// Flags
      lv_timer_handler();

      // subscribe to loadpoint topics
      String loadpoint_topics[] = {
        "connected", 
        "charging", 
        "chargePower", 
        "effectiveLimitSoc", 
        "effectiveMinSoc", 
        "mode", 
        "chargedEnergy", 
        "sessionSolarPercentage", 
        "vehicleSoc", 
        "vehicleRange",
        "chargeRemainingDuration",
        "planProjectedStart",
        "effectivePlanSoc",
        "title",
        "vehicleName"
        };

      for (int i = 0; i < (sizeof(loadpoint_topics) / sizeof(loadpoint_topics[0]));i++){
        // build MQTT topics
        String evcc_topic_loadpoint = EVCC_MQTT_PREFIX;
        evcc_topic_loadpoint += "/loadpoints/";
        evcc_topic_loadpoint += LOADPOINT;
        evcc_topic_loadpoint += "/";
        evcc_topic_loadpoint += loadpoint_topics[i];
        Serial.println("Subscribe to " + evcc_topic_loadpoint);
        wifi_client.subscribe(evcc_topic_loadpoint.c_str());
      }

      // subscribe to site topics
      String site_topics[] = {
        "batterySoc", 
        "bufferSoc", 
        "batteryPower", 
        "gridPower", 
        "pvPower"
        };

      for (int i = 0; i < (sizeof(site_topics) / sizeof(site_topics[0]));i++){
        // build MQTT topics
        String evcc_topic_site = EVCC_MQTT_PREFIX;
        evcc_topic_site += "/site/";
        evcc_topic_site += site_topics[i];
        Serial.println("Subscribe to " + evcc_topic_site);
        wifi_client.subscribe(evcc_topic_site.c_str());
      }
     
      // subscribe to vehicle topics
      String vehicle_topics[] = {
        "title",
        "plans",
        "plans/" + (String)VEHICLE_PLAN + "/soc", 
        "plans/" + (String)VEHICLE_PLAN + "/time"
        };

      for (int i = 0; i < (sizeof(vehicle_topics) / sizeof(vehicle_topics[0]));i++){
        // build MQTT topics
        String evcc_topic_vehicle = EVCC_MQTT_PREFIX;
        evcc_topic_vehicle += "/vehicles/";
        evcc_topic_vehicle += VEHICLE;
        evcc_topic_vehicle += "/";
        evcc_topic_vehicle += vehicle_topics[i];
        Serial.println("Subscribe to " + evcc_topic_vehicle);
        wifi_client.subscribe(evcc_topic_vehicle.c_str());
      }

    } else {
      Serial.print("failed, rc=");
      Serial.print(wifi_client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

// Round to 5
int round5(int n) {
  return (n/5 + (n%5>2)) * 5;
}

void setup()
{
  Serial.begin( 9600 ); /*serial init */

  //LCD init
  lcd.begin();          
  lcd.setRotation(1); 
  lcd.fillScreen(TFT_BLACK);

 // Start the SPI for the touchscreen and init the touchscreen
  //Initialise the touchscreen
  mySpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS); /* Start second SPI bus for touchscreen */
  ts.begin(mySpi); /* Touchscreen init */
  ts.setRotation(1); /* Landscape orientation */

  delay(100);

  //background light pin
  // pinMode(27, OUTPUT);
  // digitalWrite(27, LOW);
  // IS THIS NECESSARY? NOOOO!!!!

  //lvgl init
  lv_init();
  
  lv_disp_draw_buf_init( &draw_buf, buf1, NULL, screenWidth * screenHeight / 13 );

  /*Display init*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init( &disp_drv );
  /*Display driver port of LVGL*/
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register( &disp_drv );

  /*Initialize the (dummy) input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init( &indev_drv );
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_t * my_indev = lv_indev_drv_register( &indev_drv );

  ui_init();        //LVGL UI init

  /* Wifi & Mqtt Setup */
  setup_wifi();
  wifi_client.setServer(mqtt_server, 1883);
  wifi_client.setCallback(callback);

  /*Set User defined values from config.h to GUI elements*/
  lv_obj_set_style_bg_color(ui_txtLadestand, lv_color_hex(COL_CAR_SOC), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_sliderSocLimit, lv_color_hex(COL_LIMIT), LV_PART_KNOB | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_txtLadelimit, lv_color_hex(COL_LIMIT), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_barHomeBattery, lv_color_hex(COL_BAR_BATTERY_SOC), LV_PART_INDICATOR | LV_STATE_DEFAULT);

  lv_obj_set_style_bg_color(ui_barSolarGrid, lv_color_hex(COL_BAR_GRID), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_barSolarGrid, lv_color_hex(COL_BAR_SOLAR), LV_PART_INDICATOR | LV_STATE_DEFAULT);

  lv_bar_set_range(ui_barSolarPower, 0, MAX_SOLAR_POWER);
  lv_bar_set_range(ui_barGridPower, 0, MAX_GRID_POWER);
  lv_bar_set_range(ui_barBatteryPower, 0, MAX_HOMEBAT_POWER);
  
  Serial.println( "Setup done" );
}


/* ------------------------------------------ */
/* events for LVGL GUI elements */

void sendEvccModePV(lv_event_t * e)
{
  String serverPath = "http://";
  serverPath += EVCC_SERVER_IP ; 
  serverPath += ":";
  serverPath += (String)EVCC_SERVER_PORT;
  serverPath += "/api/loadpoints/";
  serverPath += LOADPOINT;
  serverPath += "/mode/pv";
  http_client.begin(serverPath.c_str());
    http_client.addHeader("Content-Type", "text/plain");
    int httpResponseCode = http_client.POST("");
    // if (httpResponseCode>0) {
    //       Serial.print("HTTP Response code: ");
    //       Serial.println(httpResponseCode);
    //       String payload = http_client.getString();
    //       Serial.println(payload);
    //   }
    //   else {
    //     Serial.print("Error code: ");
    //     Serial.println(httpResponseCode);
    //   }
  // Free resources
  http_client.end();
}

void sendEvccModeNow(lv_event_t * e)
{
  String serverPath = "http://";
  serverPath += EVCC_SERVER_IP ; 
  serverPath += ":";
  serverPath += (String)EVCC_SERVER_PORT;
  serverPath += "/api/loadpoints/";
  serverPath += LOADPOINT;
  serverPath += "/mode/now";
  http_client.begin(serverPath.c_str());
    http_client.addHeader("Content-Type", "text/plain");
    int httpResponseCode = http_client.POST("");
  http_client.end();
}

void sendEvccPlan(lv_event_t * e)
{
  Serial.println("Button Plan gedrückt!");
  /// Set:   /api/vehicles/<name>/plan/soc/<soc>/<time>
  // Delete: /api/vehicles/<name>/plan/soc
  String serverPath = "http://";
  serverPath += EVCC_SERVER_IP ; 
  serverPath += ":";
  serverPath += (String)EVCC_SERVER_PORT;
  serverPath += "/api/vehicles/";
  serverPath += VEHICLE;
  serverPath += "/plan/soc";
  // serverPath += PLAN_SOC;
  // serverPath += "/";
  // serverPath += PLAN_TIME;
  http_client.begin(serverPath.c_str());
    http_client.addHeader("Content-Type", "text/plain");
    int httpResponseCode = http_client.sendRequest("DELETE", "");
      // if (httpResponseCode>0) {
      //     Serial.print("HTTP Response code: ");
      //     Serial.println(httpResponseCode);
      //     String payload = http_client.getString();
      //     Serial.println(payload);
      // }
      // else {
      //   Serial.print("Error code: ");
      //   Serial.println(httpResponseCode);
      // }
http_client.end();

}

void sendEvccLimitSoc(lv_event_t * e)
{
  lv_obj_t * slider = lv_event_get_target(e);
  // char buf[8];
  // lv_snprintf(buf, sizeof(buf), "%d%", (int)round5(lv_slider_get_value(slider)));

  // Serial.println("LimitSoc auf " + (String)buf + "% gesetzt!");

  String serverPath = "http://";
  serverPath += EVCC_SERVER_IP ; 
  serverPath += ":";
  serverPath += (String)EVCC_SERVER_PORT;
  serverPath += "/api/loadpoints/";
  serverPath += LOADPOINT;
  serverPath += "/limitsoc/";
  serverPath += (String)round5(lv_slider_get_value(slider));

  http_client.begin(serverPath.c_str());
    http_client.addHeader("Content-Type", "text/plain");
    int httpResponseCode = http_client.POST("");
  http_client.end();

}

void loop()
{
  lv_timer_handler();
  delay(5);

  if (!wifi_client.connected()) {
    reconnect();
  }
  wifi_client.loop();
}