#include "openag_TSL2561.h"

//set the i2c address
#define TSL2561_Address 0*29

//turn sensor on 
void TSL2561::begin() {
  _sensor.init();  
}

// read from the sensor and output lux reading
void TSL2561::update() {

bool TSL2561::get_light_illuminance(std_msgs::Int64 &msg) {
  msg.data = _sensor.readVisibleLux();
  bool res = _send_light_illuminance;
  _send_light_illuminance = false;
  return res;
}

