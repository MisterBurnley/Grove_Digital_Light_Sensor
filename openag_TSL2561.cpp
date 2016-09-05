#include "openag_TSL2561.h"

//set the i2c address

//turn sensor on then output working message and init time
void TSL2561::begin() {
  TSL2561.init();  
}

// read from the sensor and output lux reading
void TSL2561::update() {
  uint32_t curr_time = millis();
  Wire.begin();
  TSL2561.readVisibleLux();
  
}
