#include "openag_lit2561.h"

LIT2561::LIT2561(int i2c_address) {

}

void LIT2561::begin() {

  TSL2561.init();
//  delay(100);
  Serial.begin(9600);
  TSL2561.readVisibleLux();
//  delay(100);

}

void LIT2561::update() {


//Read from the sensor

     if (TSL2561.readVisibleLux()) {
         _send_light_illuminance = true;
           }
           else {
            begin();
           }
     }


bool LIT2561::get_light_illuminance(std_msgs::Int32 &msg) {
  msg.data = (TSL2561.readVisibleLux());
  bool res = _send_light_illuminance;
  _send_light_illuminance = false;
  return res;
}

