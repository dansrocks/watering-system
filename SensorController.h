
#ifndef __SENSOR_CONTROLLER_H_LIBRARY__
#define __SENSOR_CONTROLLER_H_LIBRARY__

#include "Arduino.h"
#include <EEPROM.h>


#define HUMIDITY_PROBE_A 0x01
#define HUMIDITY_PROBE_B 0x02
#define HUMIDITY_PROBE_C 0x04
#define HUMIDITY_PROBE_D 0x08
#define HUMIDITY_PROBE_E 0x0A
#define HUMIDITY_PROBE_F 0x20


class SensorController
{
  public:
  void readConfig(int address);
  void saveConfig(int address);
  
  void enableSensor(byte sensorId);
  void disableSensor(byte sensorId);
  boolean isSensorEnabled(byte sensorId);
  
  private:
  byte sensors;
};


#endif

