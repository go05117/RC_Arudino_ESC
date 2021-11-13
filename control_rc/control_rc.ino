#include <Servo.h>

//***************************** 핀 번호 *****************************//
int escPin = 5;   // esc 일반 모터 핀 번호
int servoPin = 9; // 서보 모터 핀 번호

//***************************** 변속 & 조향 조정 *****************************//
// 스피드 지정 96~177 속도 점점 증가 및 중간부터 풀스로틀
// 정지 8~22
int speeds[] = {8, 100, 101, 102, 103, 104};    // 실전 속도 코드
//int speeds[] = {8, 97, 98, 99, 100, 101};       // 교실 내 테스트 시 속도 조절 코드

// 각도 0, 14, 29, 44, 59, 74, 89(중립), 104, 119, 134, 149, 164, 179
// directions[6]이 중앙 전진 => 좌6단, 전진(6), 우6단
//int directions[] = {0, 14, 29, 44, 59, 74, 89, 104, 119, 134, 149, 164, 179};     // 15도씩
//int directions[] = {71, 74, 77, 80, 83, 86, 89, 92, 95, 98, 101, 104, 107, 110};  // 3도씩
int directions[] = {59, 64, 69, 74, 79, 84, 89, 94, 99, 104, 109, 114, 119};      // 5도씩

// 현재 속도 또는 조향 값
String input_data;              // 시리얼 통신으로 받아온 데이터
String text = "";               // 시리얼 통신으로 받아온 데이터에서 속도 또는 조향값 따로 받는 변수
int current_speed = 1;          // 현재 속도 값
int current_direction = 6;      // 현재 조향 값
int current_break = 0;          // 현재 브레이크 유무

//***************************** 초음파 센서 *****************************//
// 전방
int trig1 = 13;
int echo1 = 12;
// 우측
int trig2 = 11;
int echo2 = 10;
// 좌측
int trig3 = 7;
int echo3 = 6;

// 초음파 변수 설정(초음파 부딪혔다 오는 속도, 정면 거리, 우측 거리, 좌측 거리)
long duration, distanceC, distanceR, distanceL;

// 초음파 센서 정지 거리(cm)
//int distance = 60;
int distance = 30;

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
  delay(190);
  servo.write(directions[6]);
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

  // 초음파 센서 초기화
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);
  
//  speedController(1);
//  delay(1500); 
}

void loop() {
  while(true) {
    if (current_break == 0) {
      Serial.println((String)"current_break : " + current_break);   // 현재 브레이크 유무
      
      // 초음파 센서 정면
      digitalWrite(trig1, LOW);
      delayMicroseconds(2);
      digitalWrite(trig1, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig1, LOW);
    
      duration = pulseIn(echo1, HIGH); //물체에 반사되어돌아온 초음파의 시간을 변수에 저장합니다.
      distanceC = duration * 17 / 1000; 
    
      Serial.print("\n정면 : ");
      Serial.print(distanceC); //측정된 물체로부터 거리값(cm값)
      Serial.println(" Cm");
    
    
      // 초음파 센서 우측
      digitalWrite(trig2, LOW);
      delayMicroseconds(2);
      digitalWrite(trig2, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig2, LOW);
    
      duration = pulseIn(echo2, HIGH);
      distanceR = duration * 17 / 1000;
    
      Serial.print("\n우측 : ");
      Serial.print(distanceR);
      Serial.println(" Cm");
    
    
      // 초음파 센서 좌측
      digitalWrite(trig3, LOW);
      delayMicroseconds(2);
      digitalWrite(trig3, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig3, LOW);
    
      duration = pulseIn(echo3, HIGH);
      distanceL = duration * 17 / 1000;
    
      Serial.print("\n좌측 : ");
      Serial.print(distanceL);
      Serial.println(" Cm");
      Serial.println("--------------------------------------");
      delay(10);
      
      if(distanceC < distance || distanceR < distance || distanceL < distance) {
          speedController(0);
          Serial.println("Stop it!!");
          break;
        } else {
          // 마지막으로 들어갔던 속도 기억 및 출발
          speedController(current_speed);
        }
    }
    
    while(Serial.available() > 0) {
      if(distanceC < distance || distanceR < distance || distanceL < distance) {
        String garbage = Serial.readString();   // 필요없는 Serial 데이터 버리기
        break;
      }
      
      // 시리얼 통신 
      // 스레드 지원 X : 스레드를 읽고 값이 있으면 반영, 없으면 예외처리
      input_data = Serial.readString();
    
      Serial.println((String)"input Data " + input_data);
    
      if(input_data[0] == '1')
      {
        // Enter값이 들어가는 여부 확인 후 length-1 조절 필요
        for (int i = 1; i < input_data.length()-1; i++) {
          text += input_data[i];
          Serial.println((String)"input Speed Data : " + input_data[i]);
          Serial.println((String)"current_break : " + current_break);
        }    
        current_speed = text.toInt();
        speedController(current_speed);
        if(current_speed == 0) {
            current_break = 1;
          } else if(1 || 2 || 3 || 4 || 5) {
            current_break = 0;
          }
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
        Serial.println((String)"There's no value, so keep the current : " + input_data);
      }
    
      Serial.println((String)"text : " + text);
      text = "";
    }
  }
}
