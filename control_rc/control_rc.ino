#include <Servo.h> 

int escPin = 5;   // esc 일반 모터 핀 번호
int servoPin = 9; // 서보 모터 핀 번호

// 카운팅용 변수
int count = 0;
unsigned long past = 0; // 과거 시간 저장 변수

// 스피드 지정 96~177 속도 점점 증가 및 중간부터 풀스로틀
// 정지 8~22
int speeds[] = {8, 100, 101, 102, 103, 104};

// 각도 0, 14, 29, 44, 59, 74, 89(중립), 104, 119, 134, 149, 164, 179
// directions[6]이 중앙 전진
int pos = 0;
// 좌6단, 전진(6), 우6단
int directions[] = {0, 14, 29, 44, 59, 74, 89, 104, 119, 134, 149, 164, 179};

String input_data;

Servo esc;
Servo servo;

// 전진 :: 파라미터에 따른 속도 조절
void speedController(int speedStatus) {
  esc.write(speeds[speedStatus]);
  delay(1);
}

// 조향 :: x < 6(좌측) / 6(전방) / x > 6(우측)
void directionController(int directionStatus) {
//  speedController(3);
  servo.write(directions[directionStatus]);
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

  delay(1500);
}

void loop() {
  // 시리얼 통신 
  // 스레드 지원 X : 스레드를 읽고 값이 있으면 반영, 없으면 예외처리
//  input_data = Serial.readString();
//
//  String text = "";
//
//  if(input_data[0] == '0')
//  {
//    for (int i = 0; i < input_data.length()-1; i++) {
//      text += input_data[i];
//      Serial.println((String)"input Data1 : " + input_data[i]);
//    }
//    Serial.println((String)"input Data1 length : " + input_data.length());
//    delay(1000);
//  }
//  else
//  {
//    Serial.println((String)"input Data2 : " + input_data);
//    delay(1000);
//  }
//
//  Serial.println((String)"text : " + text);
//  text = "";
  
  // 15초 테스트를 위한 코드
//  unsigned long now = millis(); // 현재 시간을 저장
//  if(now >= 15000){ 
//    Serial.println((String)"15초란다 친구야");
//    delay(500);
//    exit(0);
//  }

//  Serial.println((String)"전방 조향");
//  servo.write(89);
//  for(int i=0; i < directions.length; i +=1) {
//    Serial.println((String)"조향 각도" + directions[i]);
//    servo.write(directions[i]);
//    delay(50);
//  }

  // 외부 전방 전진 각도 수정을 위한 코드
//  Serial.println((String)"전진 1단");
//  speedController(1);
//  directionController(6);
//  delay(3000);
//  Serial.println((String)"조향 좌1단");
//  speedController(8);   // 조향할 때 속도 조절 시 +2단 +3단 어떤 속도가 나은가
//  directionController(3);
//  delay(2000);

  // 코너 돌기 코드
  speedController(1);
  directionController(5);
  delay(190);
  directionController(6);
  delay(1000);
}
