int sensor1 = A0;  
int sensor2 = A1;
int ledPin = 13;     
int sensor1Value = 0;
int sensor2Value = 0; 

int lastValue = 0;
const int changeLim = 50;

int pinA = 2;
int pinB = 4;
int pinC = 3;
int pinD = 5;

void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(pinA,OUTPUT);
  pinMode(pinB,OUTPUT);
  pinMode(pinC,OUTPUT);
  pinMode(pinD,OUTPUT);
  halt();
}

int t1 = 50;
int t2 = 100;

int up = 2;

void loop() {
  sensor1Value = analogRead(sensor1);
  sensor2Value = analogRead(sensor2);
  
  Serial.print("Sensor 1 Value : ");
  Serial.print(sensor1Value);
  Serial.print("  ");
  Serial.print("Sensor 2 Value : ");
  Serial.println(sensor2Value);
  
   if(sensor1Value<t1&sensor2Value<t2) {
    Serial.println("halt!");
    halt();
  }
  else if(sensor1Value>t1&&sensor2Value>t2) {
    Serial.println("reverse!");
    reverse();
  }
  else if(sensor1Value>t1&&sensor2Value<t2) {
    Serial.println("forward!");
    forward();
  }
  else {
    Serial.println("nothing!");
    halt();
  }
  
  //........................................
  /*
  sensor1Value = analogRead(sensor1);
  Serial.print("Sensor 1 Value : ");
  Serial.println(sensor1Value);

  int dif = sensor1Value - lastValue;
  if(dif < 0) {
    dif *= -1;
    up -= 2;
    if(up < 0) up = 0;
  } else {
    if(++up > 4) up = 4;
  }
  
  if(dif > changeLim) {
    if(up == 4) {
      Serial.println("up");
      forward();  
    } else if(up == 0) {
      reverse();
      Serial.println("down");
    }
    lastValue=sensor1Value;
    //halt();
  }
  if(digitalRead(8)==HIGH) {
    halt();
    Serial.println("halt");
  }
  */
  //..............................
  /*
  if(digitalRead(8)==HIGH) {
    Serial.println("forward");
    forward();
  }
  else if(digitalRead(9)==HIGH) {
    Serial.println("reverse!");
    reverse();
  }
  else{
    halt();
    Serial.println("halt");
  }
  */
  delay(300);
}
void forward() {
  digitalWrite(pinA, 1);
  digitalWrite(pinB, 0);  
  digitalWrite(pinC, 0);
  digitalWrite(pinD, 1);  
}

void reverse() {
  digitalWrite(pinA, 0);
  digitalWrite(pinB, 1);  
  digitalWrite(pinC, 1);
  digitalWrite(pinD, 0);  
}

void halt() {
  digitalWrite(pinA, 1);
  digitalWrite(pinB, 1);
  digitalWrite(pinC, 1);
  digitalWrite(pinD, 1);
}
