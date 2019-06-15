/*
 * Sample Code for testing car running
 * Developed by @PastorEdu
 */

//Define the Pins
#define  pinAIN1 4  //右前马达
#define  pinAIN2 2  //右前马达
#define  pinPWMA 3  //右前马达PWM
#define  pinAIN3 7  //左前马达
#define  pinAIN4 6  //左前马达
#define  pinPWMB 5  //左前马达PWM
#define  pinAIN5 10 //右后马达
#define  pinAIN6 8  //右后马达
#define  pinPWMC 9  //右后马达PWM
#define  pinAIN7 12 //左后马达
#define  pinAIN8 13 //左后马达
#define  pinPWMD 11 //左后马达PWM

 void setup()
{
  Serial.begin(9600);
  //Set the PIN Modes
  pinMode(pinAIN1, OUTPUT);
  pinMode(pinAIN2, OUTPUT);
  pinMode(pinPWMA, OUTPUT);
  pinMode(pinAIN3, OUTPUT);
  pinMode(pinAIN4, OUTPUT);
  pinMode(pinPWMB, OUTPUT);
  pinMode(pinAIN5, OUTPUT);
  pinMode(pinAIN6, OUTPUT);
  pinMode(pinPWMC, OUTPUT);
  pinMode(pinAIN7, OUTPUT);
  pinMode(pinAIN8, OUTPUT);
  pinMode(pinPWMD, OUTPUT);
}

void loop()
{
  int speed = 255;
  
  //12A
  Serial.println("前");
  
  digitalWrite(pinAIN1, 1);
  digitalWrite(pinAIN2, 0);
  analogWrite(pinPWMA, speed);
  delay(2000);

  Serial.println("结束");
  analogWrite(pinPWMA, 0);
  delay(1000);
  
  
  Serial.println("后");
  digitalWrite(pinAIN1, 0);
  digitalWrite(pinAIN2, 1);
  analogWrite(pinPWMA, speed);
  delay(2000);

  Serial.println("结束");
  analogWrite(pinPWMA, 0);
  delay(1000);
  
  
  //34B
  Serial.println("后");
  
  digitalWrite(pinAIN3, 1);
  digitalWrite(pinAIN4, 0);
  analogWrite(pinPWMB, speed);
  delay(2000);

  Serial.println("结束");
  analogWrite(pinPWMB, 0);
  delay(1000);
  
  
  Serial.println("前");
  digitalWrite(pinAIN3, 0);
  digitalWrite(pinAIN4, 1);
  analogWrite(pinPWMB, speed);
  delay(2000);

  Serial.println("结束");
  analogWrite(pinPWMB, 0);
  delay(1000);
  
  //56C
  Serial.println("前");
  
  digitalWrite(pinAIN5, 1);
  digitalWrite(pinAIN6, 0);
  analogWrite(pinPWMC, speed);
  delay(2000);

  Serial.println("结束");
  analogWrite(pinPWMC, 0);
  delay(1000);
  
  
  Serial.println("后");
  digitalWrite(pinAIN5, 0);
  digitalWrite(pinAIN6, 1);
  analogWrite(pinPWMC, speed);
  delay(2000);

  Serial.println("结束");
  analogWrite(pinPWMC, 0);
  delay(1000);
  
  //78D
  Serial.println("后");
  
  digitalWrite(pinAIN7, 1);
  digitalWrite(pinAIN8, 0);
  analogWrite(pinPWMD, speed);
  delay(2000);

  Serial.println("结束");
  analogWrite(pinPWMD, 0);
  delay(1000);
  
  
  Serial.println("前");
  digitalWrite(pinAIN7, 0);
  digitalWrite(pinAIN8, 1);
  analogWrite(pinPWMD, speed);
  delay(2000);

  Serial.println("结束");
  analogWrite(pinPWMD, 0);
  delay(1000);
  
  
}
