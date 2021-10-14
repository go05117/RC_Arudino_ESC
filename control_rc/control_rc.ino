#include <Servo.h> 

int escPin = 5;   // esc 일반 모터 핀 번호
int servoPin = 9; // 서보 모터 핀 번호

// 스피드 지정 96~177 속도 점점 증가 및 풀스로틀
// 정지 8~22
int stop1 = 8;
int stop2 = 9;
int speed1 = 96;
int speed2 = 97;
int speed3 = 98;
int speed4 = 99;
int count = 8;
int backcount = 1000;

Servo esc;
Servo servo;

// 정지 :: 속도 8
void stop11() {
  esc.write(stop1);
  delay(1);
}

// 정지 :: 속도 9
void stop22() {
  esc.write(stop1);
  delay(1);
}

// 전진 :: 속도 96
void speed11() {
  esc.write(speed1);
  delay(1);
}

// 전진 :: 속도 97
void speed22() {
  esc.write(speed2);
  delay(1);
}

// 전진 :: 속도 98
void speed33() {
  esc.write(speed3);
  delay(1);
}

// 전진 :: 속도 99
void speed44() {
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
//  Serial.println((String)"속도 " + speed1);
////  servo.write(speed1);
//  speed11();
//  delay(4000);
//  Serial.println((String)"속도 " + speed2);
//  speed22();
//  delay(4000);
//  Serial.println((String)"속도 " + speed3);
//  speed33();
//  delay(4000);
//  Serial.println((String)"정지 " + stop1);
//  stop11();
//  delay(4000);
//
//  Serial.println((String)"속도 " + speed1);
//  speed11();
//  delay(4000);
//  Serial.println((String)"속도 " + speed2);
//  speed22();
//  delay(4000);
//  Serial.println((String)"속도 " + speed3);
//  speed33();
//  delay(4000);
//  Serial.println((String)"정지 " + stop2);
//  stop22();
//  delay(4000);

  // 브레이크 테스트 8-22
  Serial.println((String)"속도 " + speed1);
  speed11();
  delay(1000);
  Serial.println((String)"속도 " + speed2);
  speed22();
  delay(1000);
  Serial.println((String)"속도 " + speed3);
  speed33();
  delay(1000);
  // 브레이크
  Serial.println((String)"브레이크 번호 8");
  esc.write(8);
  delay(2000);

  Serial.println((String)"속도 " + speed1);
  speed11();
  delay(1000);
  Serial.println((String)"속도 " + speed2);
  speed22();
  delay(1000);
  Serial.println((String)"속도 " + speed3);
  speed33();
  delay(1000);
  // 브레이크
  Serial.println((String)"브레이크 번호 77");
  esc.write(77);
  delay(2000);
}
