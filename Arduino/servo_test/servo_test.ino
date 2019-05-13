/*
 * Servo Arduino Tutorial
 * by Dicson Pan @PastorEdu
 * 棕 - GND
 * 红 - 5V
 * 橙 - 10
 */
 #include <Servo.h>

 #define SMOOTHMOVE
 #define PIN_SERVO 10
 Servo myservo;

 void setup()
 {
  myservo.attach(PIN_SERVO);
 }

void loop()
{
  #ifdef SMOOTHMOVE
  int pos = 0;
  while(true) {
    for(pos = 0; pos < 180; pos += 1){   //舵机从0°转到180°，每次增加1°
      myservo.write(pos);            //给舵机写入角度
      delay(15);                     //延时15ms让舵机转到指定位置
    }
    for(pos = 180; pos >= 1; pos -=1){   //舵机从180°转回到0°，每次减少1°
      myservo.write(pos);
      delay(15);
    }
  }
  #endif
  myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(0);
  delay(1000);
}
