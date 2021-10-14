#include <Servo.h> 

int escPin = 5;   // esc 일반 모터 핀 번호
int servoPin = 9; // 서보 모터 핀 번호

// 스피드 지정
int stop1 = 95;
int speed1 = 96;
int speed2 = 97;
int speed3 = 98;
int speed4 = 99;

Servo esc;
Servo servo;

// 정지 :: 속도 95
void stop95() {
  esc.write(stop1);
  delay(1);
}

// 전진 :: 속도 96
void speed96() {
  esc.write(speed1);
  delay(1);
}

// 전진 :: 속도 97
void speed97() {
  esc.write(speed2);
  delay(1);
}

// 전진 :: 속도 98
void speed98() {
  esc.write(speed3);
  delay(1);
}

// 전진 :: 속도 99
void speed99() {
  esc.write(speed4);
  delay(1);
}

void setup() {
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT);
  pinMode(escPin, OUTPUT);

//  digitalWrite(escPin, LOW);
  
  servo.attach(servoPin);
  esc.attach(escPin);

  delay(2000);

}

void loop() {
  Serial.println((String)"속도 " + speed1);
//  servo.write(speed1);
  speed96();
  delay(4000);
  Serial.println((String)"속도 " + speed2);
  speed97();
  delay(4000);
  Serial.println((String)"속도 " + speed3);
  speed98();
  delay(4000);
  Serial.println((String)"정지 95");
  stop95();
  delay(4000);
}
