/*
 * Code developped by @PastorEdu
 */
 
//单个马达测试代码 For Nano
//Define the Pins
#define pinIN1 7
#define pinIN2 6
#define pinPWM 5

#define pinA A0
#define pinB A1

const int d_time=100;
int speed = 255;
int i = 0;
int valA = 0;
int valB = 0;
unsigned long duration = 0;
unsigned long times;
unsigned long newtime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Set the PIN Modes
  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinPWM, OUTPUT);
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println("前");
  
  digitalWrite(pinIN1, 1);
  digitalWrite(pinIN2, 0);
  analogWrite(pinPWM, speed);
  //SpeedCheck();
  delay(2000);

  Serial.println("结束");
  analogWrite(pinPWM, 0);
  delay(1000);
  
  
  Serial.println("后");
  digitalWrite(pinIN1, 0);
  digitalWrite(pinIN2, 1);
  analogWrite(pinPWM, speed);
  delay(2000);

  Serial.println("结束");
  analogWrite(pinPWM, 0);
  delay(1000);

}

// 霍尔编码器测速代码
void SpeedCheck()
{
  newtime = times = millis();
  while((newtime - times) < d_time){
    if(digitalRead(pinA)==HIGH){
      valA++;
    };
    if(digitalRead(pinB)==HIGH){
      valB++;
    };
    newtime = millis();
  }
  duration = (valA + valB)/(1.496 * d_time);
  
  Serial.print("v is");
  Serial.print(duration);
  Serial.println("rad/s");
 
}
