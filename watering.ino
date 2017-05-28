#include "Arduino.h"
#include <EEPROM.h>
#include "SensorController.h"

#ifndef int8_t
  #define int8_t unsigned char;
#endif

#define SENSORS_CONFIG_ADDR 0x0001

SensorController sensorController;

void setup()
{
  Serial.begin(57600);
  sensorController.loadConfig(SENSORS_CONFIG_ADDR);
  awaitNthSeconds(10);
}


void loop()
{
  byte sensorId;
  
  for (byte sensorId=1; sensorId<=MAX_HUMIDITY_SENSORS; sensorId++) {
    if (sensorController.isSensorEnabled(sensorId)) {
      // Enable & read sensor 'sensorId'
    }
  }
  Serial.println("Tick");
  delay(1000);
}



void awaitNthSeconds(unsigned int seconds)
{
  unsigned long reachTime;

  char message[30];
  
  reachTime = millis() + 1000;
  seconds = 10;

  do {
    if (millis() > reachTime) {
      seconds--;
      reachTime += 1000;
      sprintf(message, "Esperando %d segundos", seconds);
      Serial.println(message);
    }
    delay(100);
  } while (seconds);

  Serial.println("Inicializacion completada");
}
