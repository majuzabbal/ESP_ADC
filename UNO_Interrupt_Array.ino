const byte interruptPin = 3;
int analogValue = 0;
bool flag = 0;
#define analogPin A3

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(interruptPin, INPUT);
  
  //analogReference(EXTERNAL);
  attachInterrupt(digitalPinToInterrupt(interruptPin), interruptFunction, RISING);
}

void loop() {
  delay(500);
  if(flag == 1){
    analogValue = analogRead(analogPin);
    Serial.println(analogValue);
    flag = 0;
  }
}

void interruptFunction() {
  flag = 1;
}
