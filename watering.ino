#include "Arduino.h"
#include <EEPROM.h>
#include "SensorController.h"

#ifndef int8_t
  #define int8_t unsigned char;
#endif

#define SETUP_PIN 8
#define SETUP_PIN_LED 2

#define SENSORS_CONFIG_ADDR 0x0001

#define STARTING     0x01
#define CONFIGURING  0x02
#define WORKING      0x04


byte globalStatus;
SensorController sensorController;

void setup()
{
  globalStatus = STARTING;
  
  pinMode(SETUP_PIN, INPUT);
  pinMode(SETUP_PIN_LED, OUTPUT);
  digitalWrite(SETUP_PIN_LED, HIGH);  // turn off led
  
  Serial.begin(57600);
  sensorController.loadConfig(SENSORS_CONFIG_ADDR);
  awaitNthSeconds(10);
  globalStatus = WORKING;
}


void loop()
{
  byte sensorId;
  char message[30];

  // Check for setup  
  if (isAwaitingSetup()) {
    digitalWrite(SETUP_PIN_LED, LOW);  // turn on led
    enterSetup();
    digitalWrite(SETUP_PIN_LED, HIGH);  // turn off led
  }
  
  for (byte sensorId=1; sensorId<=MAX_HUMIDITY_SENSORS; sensorId++) {
    if (sensorController.isSensorEnabled(sensorId)) {
      // Enable & read sensor 'sensorId'
      sprintf(message, "Leyendo sensor con id: %d", sensorId);
      Serial.println(message);
    } else {
      sprintf(message, "Sensor id: %d desactivado", sensorId);
      Serial.println(message);
    }
    delay(1000);
  }
  
  Serial.println("Tick");
  delay(5000);
}


boolean isAwaitingSetup()
{
  return (digitalRead(SETUP_PIN) == HIGH);
}

void enterSetup()
{
  // do something
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
