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

bool LIT2561::get_light_illuminance(std_msgs::Int64 &msg) {
  msg.data = _sensor.readVisibleLux();
  bool res = _send_light_illuminance;
  _send_light_illuminance = false;
  return res;
}

