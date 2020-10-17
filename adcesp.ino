const byte interruptPin = 19;
int analog_value = 0;
#define ANALOG_PIN_0 36
 
void setup(){
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(interruptPin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(interruptPin), interruptFunction, RISING);
}
 
void loop(){
  delay(500);
  Serial.println(map(analog_value, 0, 4095, 0, 1023));
}

void interruptFunction(){
//delayMicroseconds(3);
analog_value = analogRead(ANALOG_PIN_0);
}
