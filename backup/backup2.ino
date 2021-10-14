#include <Servo.h> 

int escPin = 5;   // esc 일반 모터 핀 번호
int servoPin = 9; // 서보 모터 핀 번호
int maxSpeed = 98;
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

  delay(2000);

}

void loop() {
  Serial.println((String)"속도" + speed1);
//  servo.write(speed1);
  esc.write(speed1);
  delay(2000);
}
