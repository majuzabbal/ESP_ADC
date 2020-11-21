#include <Wire.h>
#include <Adafruit_MCP4725.h>
int voltage[] = {0, 683, 1365, 2047, 3413, 4095};
int interruptPin = 34;  
volatile bool flag = false;
int counter = 0;

Adafruit_MCP4725 dac;

void setup(void) {
  Serial.begin(9600);
  Serial.println("Hello!");

  dac.begin(0x62);

  attachInterrupt(digitalPinToInterrupt(interruptPin), interruptFunction, RISING);
}

void loop(void) {
    while(counter < 7){
      if(flag){
        dac.setVoltage(voltage[counter], false);
        counter++;
        flag = false;
      }
    }
}

void interruptFunction() {
  flag = true;
}
