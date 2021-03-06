#include <pebble.h>

#define DEBUG_ENABLED

#include "settings.h"
#include "window.h"
#include "weather.h"
#include "battery.h"
#include "bluetooth.h"
#include "clock.h"
//#include "accelerometer.h"
#include "communication.h"

#ifdef PBL_HEALTH
#include "health.h"
#endif

static void init() {  
  settings_init();
  
  communication_init();
  
  show_mainwindow();
  
  clock_init();

  battery_init();
  
  bluetooth_init();
  
  weather_init();
  
  #ifdef PBL_HEALTH
  Health_init();
  #endif
  
  //accelerometer_init();
 
}

static void deinit() {
  settings_deinit();
  
  weather_deinit();
  
  bluetooth_deinit();
  
  battery_deinit();
  
  clock_deinit();
  
  communication_deinit();
  
  hide_mainwindow();
  
  #ifdef PBL_HEALTH
  Health_deinit();
  #endif
  
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
