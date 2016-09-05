#ifndef OPENAG_TSL2561
#define OPENAG_TSL2561

#include "Arduino.h"
#include "Wire.h"
#include "TSL2561.h"
#include <openag_module.h>
#include <std_msgs/Int32.h>

class TSL2561 : public Module {
  public:
  TS2561(int i2c_address);
  void begin();
  void update();
  bool get_lux(std_msgs::Int32 &msg);
  
  private:
  TSL2561_I2C_sensor;
  uint32_t_init_time;
  bool _initializing;
  uint32_t _time_of_last_reading;
  const static uint32_t _min_update_interval = 2000;
  bool _is_on;
  
  
  void readData();
}


#endif
