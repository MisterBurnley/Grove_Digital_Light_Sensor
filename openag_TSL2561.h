#ifndef OPENAG_TSL2561
#define OPENAG_TSL2561

#include "Arduino.h"
#include "Wire.h"
#include "TSL2561.h"
#include <openag_module.h>
#include <std_msgs/Int32.h>

class TSL2561 : public Module {
  public:
  void begin();
  void update();
  
  private:
  TSL2561_I2C _sensor;
  uint32_t _init_time;
  bool _initializing;
  uint32_t _time_of_last_reading;
  const static uint32_t _min_update_interval = 2000;
  bool _is_on;
  
  
  void readData();
}


#endif
