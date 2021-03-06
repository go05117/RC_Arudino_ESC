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
int current_speed = 1;
int current_direction = 6;

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
  Serial.setTimeout(100);
  pinMode(servoPin, OUTPUT);
  pinMode(escPin, OUTPUT);
  
  servo.attach(servoPin);
  esc.attach(escPin);

  // bldc 모터, 서보 모터 초기화
  servo.write(89);
  esc.write(95);

//  delay(1500);
}

void loop() {

  while(Serial.available() > 0) {
    // 시리얼 통신 
    // 스레드 지원 X : 스레드를 읽고 값이 있으면 반영, 없으면 예외처리
    input_data = Serial.readString();
  
    String text = "";
  
    Serial.println((String)"input Data " + input_data);
  
    if(input_data[0] == '1')
    {
      // Enter값이 들어가는 여부 확인 후 length-1 조절 필요
      // 나중에 코드 최적화할 거임
      for (int i = 1; i < input_data.length()-1; i++) {
        text += input_data[i];
        Serial.println((String)"input Speed Data : " + input_data[i]);
      }    
      current_speed = text.toInt();
      speedController(current_speed);
    }
    else if(input_data[0] == '2')
    {
      for (int i = 1; i < input_data.length()-1; i++) {
        text += input_data[i];
        Serial.println((String)"input Direction Data : " + input_data[i]);
      }    
      current_direction = text.toInt();
      directionController(current_direction);
    }
    else
    {
      Serial.println((String)"아무 값도 없으니 현행값 유지" + input_data);
    }
  
    Serial.println((String)"text : " + text);
    text = "";
    
    // 15초 테스트를 위한 코드
//    unsigned long now = millis(); // 현재 시간을 저장
//    if(now >= 15000){ 
//      Serial.println((String)"15초란다 친구야");
//      delay(500);
//      exit(0);
//    }
  
    // 코너 돌기 코드
//    speedController(1);
//    directionController(5);
//    delay(190);
//    directionController(6);
//    delay(1000);
  }
}