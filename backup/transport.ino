#include <Servo.h>

//***************************** 핀 번호 *****************************//
int escPin = 5;   // esc 일반 모터 핀 번호
int servoPin = 9; // 서보 모터 핀 번호

//***************************** 변속 & 조향 조정 *****************************//
// 스피드 지정 96~177 속도 점점 증가 및 중간부터 풀스로틀
// 정지 8~22
//int speeds[] = {8, 101, 96, 102, 103, 104};    // 실전 속도 코드
int speeds[] = {8, 101, 102, 103, 104, 105};    // 실전 속도 코드
//int speeds[] = {8, 100, 101, 102, 103, 104};    // 실전 속도 코드 - 1단 속도 부족
//int speeds[] = {8, 97, 98, 99, 100, 101};       // 교실 내 테스트 시 속도 조절 코드

// 각도 0, 14, 29, 44, 59, 74, 89(중립), 104, 119, 134, 149, 164, 179
// directions[6]이 중앙 전진 => 좌6단, 전진(6), 우6단
int directions[] = {0, 14, 29, 44, 59, 74, 89, 104, 119, 134, 149, 164, 179};     // 15도씩
//int directions[] = {71, 74, 77, 80, 83, 86, 89, 92, 95, 98, 101, 104, 107, 110};  // 3도씩
//int directions[] = {59, 64, 69, 74, 79, 84, 89, 94, 99, 104, 109, 114, 119};      // 5도씩
//int directions[] = {29, 39, 49, 59, 69, 79, 89, 99, 109, 119, 129, 139, 149};     // 10도씩
//int directions[] = {0, 0, 9, 29, 49, 69, 89, 109, 129, 149, 169, 179, 179};     // 20도씩
//int directions[] = {0, 0, 0, 0, 29, 59, 89, 109, 129, 149, 169, 179, 179};     // 30도씩

// 현재 속도 또는 조향 값
String input_datas;             // 시리얼 통신으로 받아온 데이터
int save_input = 0;             // input_datas에서 데이터를 저장할지 말지 boolean
int is_play = 0;                // 실행 여부
String charge_once;             // input_data에 저장할 값 한 단위
String charge_data;             // input_data에 저장할 값 임시 저장소
String input_data;              // input_datas에서 필요한 값만 추출한 데이터
String text = "";               // 시리얼 통신으로 받아온 데이터에서 속도 또는 조향값 따로 받는 변수
int current_speed = 0;          // 현재 속도 값
int current_direction = 6;      // 현재 조향 값


Servo esc;
Servo servo;

// 전진 :: 파라미터에 따른 속도 조절
void speedController(int speedStatus) {
  esc.write(speeds[speedStatus]);
//  delay(1);
}

// 조향 :: x < 6(좌측) / 6(전방) / x > 6(우측)
void directionController(int directionStatus) {
//  speedController(3);
  servo.write(directions[directionStatus]);
  if (1 < directionStatus && directionStatus < 11) {
    delay(100);
    servo.write(directions[6]);
  }
  else {
    delay(100);
    servo.write(directions[6]);
  }
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
  
  speedController(current_speed);
//  delay(1500);
}


void loop() {
  while(true) {
    while(Serial.available() > 0) {      
      // 시리얼 통신 
      // 스레드 지원 X : 스레드를 읽고 값이 있으면 반영, 없으면 예외처리
      input_datas = Serial.readString();

//      if(input_datas.length() > 5) {
//        
//      }

      for(int i = 0; i < input_datas.length(); i++) {
        if(save_input == 0 && input_datas[i] == '/') {
          save_input = 1;
        }
        
        if(save_input == 1) {
          charge_once = charge_once + input_datas[i];
          charge_data = charge_data + input_datas[i];
        }

        if(save_input == 1 && input_datas[i] == '*') {
          Serial.println();
          is_play = 1;
          save_input = 0;
          charge_once = "";
          input_data = charge_data;
        }
      }

//      Serial.println("1차 처리한 input_data : " + input_data);

      for(int a = 0; a < input_data.length(); a++) {
        if(is_play == 1 && input_data[a] == '/' && input_data[a+1] == '1')
        {
  
          // Enter값이 들어가는 여부 확인 후 length-1 조절 필요
          for (int i = a; input_data[i+1] != '*'; i++) {
            text += input_data[i+2];
//            Serial.println((String)"input Speed Data : " + input_data[i+2]);
          }
          current_speed = text.toInt();
          Serial.println((String)"/1" + current_speed + "*");
          speedController(current_speed);
          charge_data = charge_once;
        }
        else if(is_play == 1 && input_data[a] == '/' && input_data[a+1] == '2')
        {
//          Serial.println((String)input_data);
          for (int i = a; input_data[i+1] != '*'; i++) {
            text += input_data[i+2];
//          Serial.println((String)"input Direction Data : " + input_data[i+2]);
          }    
          current_direction = text.toInt();
          Serial.println((String)"/2" + current_direction + "*");
          directionController(current_direction);
          charge_data = charge_once;
//          Serial.println("Charge_data : " + charge_data);
//          Serial.println("Charge_once : " + charge_once);
        }
        text = "";
      }
      is_play = 0;
      Serial.println("--------------------------------------");
    }
  }
}