#include <Servo.h> 

int escPin = 5;   // esc 일반 모터 핀 번호
int servoPin = 9; // 서보 모터 핀 번호

// 카운팅용 변수
int count = 0;

// 스피드 지정 96~177 속도 점점 증가 및 중간부터 풀스로틀
// 정지 8~22
int speeds[] = {8, 96, 97, 98, 99, 100};

// 각도 0, 14, 29, 44, 59, 74, 89(중립), 104, 119, 134, 149, 164, 179
// directions[6]이 중앙 전진
int pos = 0;
int directions[] = {0, 14, 29, 44, 59, 74, 89, 104, 119, 134, 149, 164, 179};

Servo esc;
Servo servo;

// 정지 :: 8
void stop1() {
  esc.write(speeds[0]);
  delay(1);
}

// 전진 :: 속도 96
void speed1() {
  esc.write(speeds[1]);
  delay(1);
}

// 전진 :: 속도 97
void speed2() {
  esc.write(speeds[2]);
  delay(1);
}

// 전진 :: 속도 98
void speed3() {
  esc.write(speeds[3]);
  delay(1);
}

// 전진 :: 속도 99
void speed4() {
  esc.write(speeds[4]);
  delay(1);
}

// 전진 :: 속도 100
void speed5() {
  esc.write(speeds[5]);
  delay(1);
}

void setup() {
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT);
  pinMode(escPin, OUTPUT);
  
  servo.attach(servoPin);
  esc.attach(escPin);

  // bldc 모터, 서보 모터 초기화
  servo.write(89);
  esc.write(95);

  delay(2500);

}

void loop() {
  Serial.println((String)"전방 조향");
  servo.write(89);
  delay(3000);
  
//  for(int i=0; i < directions.length; i +=1) {
//    Serial.println((String)"조향 각도" + directions[i]);
//    servo.write(directions[i]);
//    delay(50);
//  }

//  Serial.println((String)"전방 조향");
//  servo.write(89);
//  delay(3000);
}