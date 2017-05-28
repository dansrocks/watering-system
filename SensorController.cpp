#ifndef __SENSOR_CONTROLLER_CPP_LIBRARY__
#define __SENSOR_CONTROLLER_CPP_LIBRARY__

#include "Arduino.h"
#include <EEPROM.h>

#include "SensorController.h"


/**
 *
 */
void SensorController::loadConfig(int configAddress)
{
  this->sensors = EEPROM.read(configAddress);
}

/**
 *
 */
void SensorController::updateConfig(int configAddress)
{
  byte sensors;
  sensors = EEPROM.read(configAddress);
  if (sensors != this->sensors) {
    this->saveConfig(configAddress);
  }
}


/**
 *
 */
int8_t SensorController::readHumidityFromSensorId(byte sensorId)
{
  if (sensorId > MAX_HUMIDITY_SENSORS) {
    return -1;
  }
 
  byte port;
  port = this->getSensorPortById(sensorId);
  port++;
  
  // dummy value
  return -1;
}


/**
 *
 */
void SensorController::enableSensor(byte sensorId)
{
  byte sensorRegister;
  
  sensorRegister = this->getSensorRegister(sensorId);
  this->sensors = this->sensors & ( 0xFF ^ sensorRegister);
}

/**
 *
 */
void SensorController::disableSensor(byte sensorId)
{
  byte sensorRegister;
  
  sensorRegister = this->getSensorRegister(sensorId);
  this->sensors = this->sensors | sensorRegister;
}

/**
 *
 */
boolean SensorController::isSensorEnabled(byte sensorId)
{
  byte sensorRegister;
  
  sensorRegister = this->getSensorRegister(sensorId);
  return (this->sensors & sensorRegister) ? true : false;
}


/**
 *
 */
void SensorController::readConfig(int configAddress)
{
  this->sensors = EEPROM.read(configAddress);
}

/**
 *
 */
void SensorController::saveConfig(int configAddress)
{
  EEPROM.write(configAddress, this->sensors);
}


byte SensorController::getSensorPortById(byte sensorId)
{
  if (sensorId == 1) {
    return A0;
  } else if(sensorId == 2) {
    return A1;
  } else if(sensorId == 3) {
    return  A2;
  } else if(sensorId == 4) {
    return A3;
  } else if(sensorId == 5) {
    return A4;
  } else if(sensorId == 6) {
    return A5;
  }
  
  return 0;
}

byte SensorController::getSensorRegister(byte sensorId)
{
  if (sensorId == 1) {
    return HUMIDITY_PROBE_A;
  } else if(sensorId == 2) {
    return HUMIDITY_PROBE_B;
  } else if(sensorId == 3) {
    return HUMIDITY_PROBE_C;
  } else if(sensorId == 4) {
    return HUMIDITY_PROBE_D;
  } else if(sensorId == 5) {
    return HUMIDITY_PROBE_E;
  } else if(sensorId == 6) {
    return HUMIDITY_PROBE_F;
  }
  
  return 0x00;
}


#endif



