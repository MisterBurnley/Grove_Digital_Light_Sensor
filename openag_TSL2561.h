#ifndef OPENAG_TSL2561
#define OPENAG_TSL2561

#include "Arduino.h"
#include "Wire.h"
#include "TSL2561.h"
#include <openag_module.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Int16.h>

class TSL2561 : public Module {
  public:
  TSL2561(int i2c_address);
  void begin();
  void update();
  bool get_light_illuminence(std_msgs::Int32 &msg);
  bool get_light_illuminence(std_msgs::Int16 &msg);
  
  private:
  TSL2561_I2C _sensor;
  uint32_t _init_time;
  bool _initializing;
  uint32_t _time_of_last_reading;
  
  bool _is_on;
  
  
  void readData();
}


#endif
