
#ifndef __SENSOR_CONTROLLER_H_LIBRARY__
#define __SENSOR_CONTROLLER_H_LIBRARY__

#include "Arduino.h"
#include <EEPROM.h>

#define MAX_HUMIDITY_SENSORS 6

#define HUMIDITY_PROBE_A 0x01
#define HUMIDITY_PROBE_B 0x02
#define HUMIDITY_PROBE_C 0x04
#define HUMIDITY_PROBE_D 0x08
#define HUMIDITY_PROBE_E 0x0A
#define HUMIDITY_PROBE_F 0x20


/**
 * Class SensorController
 */
class SensorController
{
  public:
  SensorController();
  void loadConfig(int configAddress);
  void updateConfig(int configAddress);
  
  void enableSensor(byte sensorId);
  void disableSensor(byte sensorId);
  boolean isSensorEnabled(byte sensorId);
  
  int8_t readHumidityFromSensorId(byte sensorId);
  
  private:
  byte sensors;
  void readConfig(int address);
  void saveConfig(int address);
  
  byte getSensorPortById(byte sensorId);
  byte getSensorRegister(byte asensorId);

};


#endif

