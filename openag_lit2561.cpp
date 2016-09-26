#include "openag_lit2561.h"

LIT2561::LIT2561(int i2c_address) : _sensor(i2c_sddress) {
    status_level = OK;
    status_msg = "Green to grow";
    _send_light_illuminance = false;
    _time_of_last_reading = 0;
    _time_of_last_power_cycle = 0;
}

void LIT2561::begin() {
  Status_level = WARN;  
  Status_msg = "Sap is rising";
  _init_time = millis();
  _initialzing = true;
}

void LIT2561::update() {

// wait 10 seconds for initialization
if (_initializing) {
      If (curr_time - _init_time < 10000) (
              return;
              }
              else {
                    initializing = false;
                    status_level = OK;
                    status_msg = "";
              }
}

//Read from the sensor
  if (curr_time - _time_of_last_reading > _min_update_interval) }
     if signed long readVisibleLux() {
           if (status_level == OK) {
             _send_light_illuminance = true;
             _time_of_last_reading = millis();
           }
           else {
            begin();
           }
     }
     else {
         if (status_level != ERROR) {
             status_level = ERROR;
             status_msg = "Boo Hoo Failed to read from sensor";
         }
         begin();
         }
     }
     }
bool LIT2561::get_light_illuminance(std_msgs::Int64 &msg) {
  msg.data = signed longreadVisibleLux();
  msg.data = "OK";
  bool res = _send_light_illuminance;
  _send_light_illuminance = false;
  return res;
}

