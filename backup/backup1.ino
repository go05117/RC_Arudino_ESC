//#include <Servo.h>
//
//void setup() {
//  Serial.begin(9600);
//  Serial.println("Program begin...");
//  pinMode(13, OUTPUT);
//}
//
//void loop() {
//  Serial.println("Program loop...");
//  digitalWrite(13,HIGH);
//  delay(1000);
//  digitalWrite(13,LOW);
//  delay(1000);
//}

//#include <Servo.h>
// 
//Servo motor;
// 
//void setup() {
//  Serial.begin(9600);
//  Serial.println("Program begin...");
//  Serial.println("This program will calibrate the ESC.");
//  motor.attach(9);                              
//  motor.write(70); //ESC 대기 신호  
//  delay(4500); //ESC의 준비 시간
//}
// 
//void loop() {
//  Serial.println("Program loop...");
//  motor.write(150); //A
//}


//#include<Servo.h>
//
//Servo esc;                                // esc로 Servo 클래스 생성
//
//void setup() {
//  esc.attach(8);                          // esc 신호 핀 지정 -> D8
//  esc.writeMicroseconds(1000);            // esc 신호 1000으로 초기화
//  Serial.begin(9600);0
//}
//
//void loop() {
//  int val;                                // 변수 val 선언
//  val = analogRead(A0);                   // Read input from analog pin a0 and store in val
//  val = map(val,0, 1023, 1000, 2000);     // mapping the val to minimum and maximum input
//  esc.writeMicroseconds(val);             // using val as the signal to esc
//}


//#include <Servo.h> 
// 
//int servoPin = 9;
//
//Servo servo;
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(servoPin,OUTPUT);
//  pinMode(4, OUTPUT);
//
//  digitalWrite(4, LOW);
//  
//  servo.attach(servoPin);
//  servo.attach(4);
//
//  //모터 시작시 최대 값을 줍니다. 이 값을 2초정도 유지하면 변속기는 최대 값이라고 인지합니다.
//  servo.write(180);
//  delay(2500);
//
//  // 최대 값 입력 후 최소 값 입력을 합니다. 해당 값으로 2초정도 유지하면 최소 값으로 입력됩니다.
//  servo.write(0);
//  delay(2500);
//
//  //위까지 끝나고 나면 모터에서 낮은 소리로 짧게 한번 높은 소리로 길게 소리가 나면서 설정이 완료됩니다.
//
//}
//
//void loop() {
//  variReg();
//  delay(100);
//}
//
//void variReg() {
//  int analogInput = analogRead(A0);
//  int brightness = map(analogInput, 0, 1023, 0, 180);
//  if(brightness >= 59) digitalWrite(4, HIGH);
//  else digitalWrite(4, LOW);
//  
//  servo.write(brightness);
//}

//void setup() {
//  Serial.begin(9600);
//  Serial.println("자, 이제 시작이야");
////  pinMode(9, OUTPUT);
//}
//
//void loop() {
//  Serial.println("반복");
//  digitalWrite(9,HIGH);
//  delay(100);
//}

//#include <Servo.h>
//Servo ESC;     // create servo object to control the ESC
//int potValue;  // value from the analog pin
//void setup() {
//  ESC.attach(9,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
//}
//void loop() {
//  potValue = 100;
//  ESC.write(potValue);    // Send the signal to the ESC
//}

#include <Servo.h> 

int escPin = 5;   // esc 일반 모터 핀 번호
int servoPin = 9; // 서보 모터 핀 번호
int maxSpeed = 120;
int speed1 = 96;
int speed2 = 97;
int speed3 = 98;
int count = 96;

Servo esc;
Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT);
  pinMode(escPin, OUTPUT);

//  digitalWrite(escPin, LOW);
  
  servo.attach(servoPin);
  esc.attach(escPin);

  //모터 시작시 최대 값을 줍니다. 이 값을 2초정도 유지하면 변속기는 최대 값이라고 인지합니다.
  Serial.println((String)"속도 " + maxSpeed + " 최댓값 입력");
  servo.write(maxSpeed);
  esc.write(maxSpeed);
  delay(1000);

  // 최대 값 입력 후 최소 값 입력을 합니다. 해당 값으로 2초정도 유지하면 최소 값으로 입력됩니다.
  Serial.println("속도 0 최솟값 입력");
  servo.write(0);
  esc.write(0);
  delay(1000);

}

void loop() {
  Serial.println((String)"속도" + speed1);
  servo.write(speed1);
  esc.write(speed1);
  delay(2000);
  Serial.println((String)"속도" + speed2);
  servo.write(speed2);
  esc.write(speed2);
  delay(2000);
  Serial.println((String)"속도" + speed3);
  servo.write(speed3);
  esc.write(speed3);
  delay(2000);
  
//  servo.write(97);
//  esc.write(97);
//  delay(2000);
//  servo.write(98);
//  esc.write(98);
//  delay(2000);
  
  
//  Serial.println((String)"속도" + speed2);
//  servo.write(speed2);
//  esc.write(20);
//  delay(3000);
}
