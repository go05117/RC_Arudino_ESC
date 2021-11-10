// 내 예상 : 80cm 이하면 브레이크 신호를 보내는 것이 옳을듯 하다.

//#define TRIG 13 // TRIG 핀 설정 (초음파 보내는 핀)
//#define ECHO 12 // ECHO 핀 설정 (초음파 받는 핀)
int trig1 = 2;
int echo1 = 1;
int trig2 = 13;
int echo2 = 12;
int trig3 = 11;
int echo3 = 10;

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

  duration = pulseIn (echo1, HIGH); //물체에 반사되어돌아온 초음파의 시간을 변수에 저장합니다.

  distance = duration * 17 / 1000; 

  Serial.println(duration ); //초음파가 반사되어 돌아오는 시간
  Serial.print("\nDIstance1 : ");
  Serial.print(distance); //측정된 물체로부터 거리값(cm값)
  Serial.println(" Cm");


  // 초음파 센서2
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);

  duration = pulseIn (echo2, HIGH);
  distance = duration * 17 / 1000;

  Serial.println(duration );
  Serial.print("\nDIstance2 : ");
  Serial.print(distance);
  Serial.println(" Cm");


  // 초음파 센서3
  digitalWrite(trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);

  duration = pulseIn (echo3, HIGH);
  distance = duration * 17 / 1000;

  Serial.println(duration );
  Serial.print("\nDIstance2 : ");
  Serial.print(distance);
  Serial.println(" Cm");
  Serial.println("--------------------------------------");
  delay(1000);
}
