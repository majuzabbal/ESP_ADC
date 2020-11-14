int analogPin = 36;
int interruptPin = 34;  
int val[6];
int count = 0;
int value = 0;
volatile bool flag = LOW;

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(interruptPin), interruptFunction, RISING);
}

void loop() {
  while (count < 7) {
      if(flag){
      val[count] = analogRead(analogPin);
      count++;
      flag = LOW;
    }
  }

  for (value = 0; value < 7; value++){
    Serial.println(map(val[value], 0, 1023, 0, 4095));
  }
}

void interruptFunction() {
  flag = HIGH;
}
