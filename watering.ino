#include "Arduino.h"
#include <EEPROM.h>
#include "SensorController.h"

void setup()
{
  Serial.begin(57600);
  awaitNthSeconds(10);
}


void loop()
{
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
