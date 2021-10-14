#include <Servo.h> 

int escPin = 5;   // esc 일반 모터 핀 번호
int servoPin = 9; // 서보 모터 핀 번호

// 스피드 지정 96~177 속도 점점 증가 및 풀스로틀
int stop1 = 95;
int stop1 = 178;
int speed1 = 96;
int speed2 = 97;
int speed3 = 98;
int speed4 = 99;
int count = 1;
int backcount = 1000;

Servo esc;
Servo servo;

// 정지 :: 속도 95
void stop1() {
  esc.write(stop1);
  delay(1);
}

// 정지 :: 속도 178
void stop2() {
  esc.write(stop1);
  delay(1);
}

// 전진 :: 속도 96
void speed1() {
  esc.write(speed1);
  delay(1);
}

// 전진 :: 속도 97
void speed2() {
  esc.write(speed2);
  delay(1);
}

// 전진 :: 속도 98
void speed3() {
  esc.write(speed3);
  delay(1);
}

// 전진 :: 속도 99
void speed4() {
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
//  speed1();
//  delay(4000);
//  Serial.println((String)"속도 " + speed2);
//  speed2();
//  delay(4000);
//  Serial.println((String)"속도 " + speed3);
//  speed3();
//  delay(4000);
//  Serial.println((String)"정지 95");
//  stop4();
//  delay(4000);

  // 브레이크 테스트
//  esc.write(96);
//  delay(4000);
//  Serial.println((String)"브레이크 번호" + count);
//  esc.write(count);
//  delay(2000);
//  count += 1;

  // 후진 테스트
  Serial.println((String)"후진 번호" + backcount);
  esc.write(178);
  delay(3000);
  backcount -= 1;
}
