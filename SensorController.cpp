#ifndef __SENSOR_CONTROLLER_CPP_LIBRARY__
#define __SENSOR_CONTROLLER_CPP_LIBRARY__

#include "Arduino.h"
#include <EEPROM.h>

#include "SensorController.h"

/**
 *
 */
void SensorController::readConfig(int address)
{
  this->sensors = EEPROM.read(address);
}

/**
 *
 */
void SensorController::saveConfig(int address)
{
  EEPROM.write(address, this->sensors);
}

/**
 *
 */
void SensorController::enableSensor(byte sensorId)
{
  this->sensors = this->sensors & ( 0xFF ^ sensorId);
}

/**
 *
 */
void SensorController::disableSensor(byte sensorId)
{
  this->sensors = this->sensors | sensorId;
}

/**
 *
 */
boolean SensorController::isSensorEnabled(byte sensorId)
{
  return (this->sensors & sensorId) ? true : false;
}


#endif



