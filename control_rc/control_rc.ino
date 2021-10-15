#include <Servo.h> 

int escPin = 5;   // esc 일반 모터 핀 번호
int servoPin = 9; // 서보 모터 핀 번호

// 카운팅용 변수
int count = 0;

// 스피드 지정 96~177 속도 점점 증가 및 풀스로틀
// 정지 8~22
int stop1 = 8;
int speed1 = 96;
int speed2 = 97;
int speed3 = 98;
int speed4 = 99;
int speed5 = 100;
int speeds[] = {8, 96, 97, 98, 99, 100};

// 각도 0, 14, 29, 44, 59, 74, 89(중립), 104, 119, 134, 149, 164, 179
int pos = 0;
int directions[] = {0, 14, 29, 44, 59, 74, 89, 104, 119, 134, 149, 164, 179};

Servo esc;
Servo servo;

// 정지 :: 속도 8
void stop11() {
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

  // bldc 모터, 서보 모터 초기화
  servo.write(89);
  esc.write(89);

  delay(4500);

}

void loop() {
//  Serial.println((String)"조향 " + count);
//  servo.write(count);
//  count += 1;
//  delay(1000);
//  speed22();
//  delay(2000);
//  stop11();
//  delay(2000);
//  for(pos=0; pos < 180; pos +=1) {
//    Serial.println((String)"조향 각도" + pos);
//    servo.write(pos);
//    delay(50);
//  }

//  Serial.println("기본");
//  servo.write(0);
//  delay(2000);
//  servo.write(30);
//  delay(2000);
//  servo.write(60);
//  delay(2000);
//  servo.write(90);
//  delay(2000);
//  servo.write(120);
//  delay(2000);
//  servo.write(150);
//  delay(2000);
//  servo.write(179);
//  delay(2000);
  Serial.println("추가분");
  servo.write(0);
  delay(1000);
  servo.write(85);
  delay(1000);
  servo.write(179);
  delay(1000);
}
