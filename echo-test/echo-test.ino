// 내 예상 : 60cm 이하면 브레이크 신호를 보내는 것이 옳을듯 하다.

//#define TRIG 13 // TRIG 핀 설정 (초음파 보내는 핀)
//#define ECHO 12 // ECHO 핀 설정 (초음파 받는 핀)
int trig1 = 13;
int echo1 = 12;
int trig2 = 11;
int echo2 = 10;
int trig3 = 7;
int echo3 = 6;

// 변수 설정
long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);
}

void loop()
{
  // 초음파 센서1
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  duration = pulseIn(echo1, HIGH); //물체에 반사되어돌아온 초음파의 시간을 변수에 저장합니다.

  distance = duration * 17 / 1000; 

  Serial.print("\n정면 : ");
  Serial.print(distance); //측정된 물체로부터 거리값(cm값)
  Serial.println(" Cm");


  // 초음파 센서2
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);

  duration = pulseIn(echo2, HIGH);
  distance = duration * 17 / 1000;

  Serial.print("\n우측 : ");
  Serial.print(distance);
  Serial.println(" Cm");


  // 초음파 센서3
  digitalWrite(trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);

  duration = pulseIn(echo3, HIGH);
  distance = duration * 17 / 1000;

  Serial.print("\n좌측 : ");
  Serial.print(distance);
  Serial.println(" Cm");
  Serial.println("--------------------------------------");
  delay(1000);
}
