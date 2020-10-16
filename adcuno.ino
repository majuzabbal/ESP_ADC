const byte interruptPin = 3;
int analog_value = 0;
#define ANALOG_PIN_0 A3

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(interruptPin, INPUT);
  
  //analogReference(EXTERNAL);
  attachInterrupt(digitalPinToInterrupt(interruptPin), interruptFunction, RISING);
}

void loop() {
  delay(500);
  Serial.println(analog_value);
}

void interruptFunction() {
analog_value = analogRead(ANALOG_PIN_0);
}
