#include <Wire.h>
#include <Adafruit_MCP4725.h>
int voltage[] = {0, 683, 1365, 2047, 2730, 3413, 4095};

Adafruit_MCP4725 dac;

void setup(void) {
  Serial.begin(9600);
  Serial.println("Hello!");

  dac.begin(0x62);
    
}

void loop(void) {
    int counter;

    for (counter = 0; counter < 7; counter++)
    {
      dac.setVoltage(voltage[counter], false);
      delay(500);
    }
}
