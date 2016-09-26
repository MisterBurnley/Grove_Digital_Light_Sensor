#ifndef OPENAG_LIT2561
#define OPENAG_LIT2561

#include "Arduino.h"
#include <Wire.h>
#include "TSL2561.h"
#include <openag_module.h>
#include <std_msgs/Int64.h>

class LIT2561 : public Module {
  public:
  LIT2561(int i2c_address);
  void begin();
  void update();
  bool get_light_illuminance(std_msgs::Int64 &msg);
  
  private:
  
  bool _send_light_illuminance;
  uint32_t _init_time;
  bool _initializing;
  uint32_t _time_of_last_reading;
  bool _is_on;
  const static uint32_t _leave_off_for = 2000;
  uint32_t _time_of_last_power_cycle;
  const static uint32_t _power_cyce_interval = 43200000;
  
  void readData();
};

#endif
