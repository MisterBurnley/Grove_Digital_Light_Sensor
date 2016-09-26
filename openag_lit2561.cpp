#include "openag_lit2561.h"


void LIT2561::begin() {
  status_level = OK;  
  status_msg = "Sap is rising";
  _init_time = millis();
  _initialzing = true;
}

void LIT2561::update() {

//Read from the sensor
  if (curr_time - _time_of_last_reading > _min_update_interval) }
     if (signed long readVisibleLux()) {
           if (status_level == OK) {
             _send_light_illuminance = true;
             _time_of_last_reading = millis();
           }
           else {
            begin();
           }
     }

bool LIT2561::get_light_illuminance(std_msgs::Int64 &msg) {
  msg.data = signed long readVisibleLux();
  msg.data = "OK";
  bool res = _send_light_illuminance;
  _send_light_illuminance = false;
  return res;
}

