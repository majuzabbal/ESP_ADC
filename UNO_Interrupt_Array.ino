const byte interruptPin = 3;
int analogValue[7];
volatile bool flag = false;
int count = 0;
int value = 0;

#define analogPin A3

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(interruptPin, INPUT);
  
  //analogReference(EXTERNAL);
  attachInterrupt(digitalPinToInterrupt(interruptPin), interruptFunction, RISING);
}

void loop() {
  while (count < 7) {
    if(flag){
      analogValue[count] = analogRead(analogPin);
      count++;
      flag = true;
      Serial.println(count);
    }
  }
}

  for (value = 0; value < 7; value++){
    Serial.println(analogValue[value]);
  }
}

void interruptFunction() {
  flag = true;
}
