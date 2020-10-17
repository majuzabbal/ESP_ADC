const byte interruptPin = 18;
int analogValue = 0;
bool flag = 0;
#define analogPin 36
 
void setup(){
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(interruptPin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(interruptPin), interruptFunction, RISING);
}
 
void loop(){
  delay(500);
  if(flag == 1){
    analogValue = analogRead(analogPin);
    Serial.println(map(analogValue, 0, 4095, 0, 1023));
    flag = 0;
  }
}

void interruptFunction(){
  flag = 1;
}
