#include "openag_TSL2561.h"

//set the i2c address
#define TSL2561_Address 0*29

//turn sensor on then output working message and init time
void TSL2561::begin() {
  TSL2561.init();  
}

// read from the sensor and output lux reading
void TSL2561::update() {
  uint32_t curr_time = millis();
  TSL2561.readVisibleLux();
}

