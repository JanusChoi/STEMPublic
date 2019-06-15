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

#define speed 255 //定义统一速度

#define pinSwitchLeft A4 //左前开关信号
#define pinSwitchRight A5 //右前开关信号

void setup() {
  // put your setup code here, to run once:
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

void loop() {

  //蓝牙信号处理，通过BlueSPP控制车子行进
    String c = readTtl();
    if (c == "FL" )   move_forward_left();
    if (c == "FF" )   move_forward();
    if (c == "FR" )   move_forward_right();
    if (c == "LL" )   move_left();
    if (c == "STOP" ) move_stop();
    if (c == "RR" )   move_right();
    if (c == "BL" )   move_backward_left();
    if (c == "BB" )   move_backward();
    if (c == "BR" )   move_backward_right();

    int switch_left  = digitalRead(pinSwitchLeft);
    int switch_right = digitalRead(pinSwitchRight);

  //根据两个按钮接收的信号来行进，此处需要考虑蓝牙控制和按钮控制之间可能存在的冲突
    if ( switch_left == 1 && switch_right == 1 ) move_forward();
    if ( switch_left == 1 && switch_right == 0 ) move_forward_right();
    if ( switch_left == 0 && switch_right == 1 ) move_forward_left();
}

String readTtl()
{
  String comdata = "";
  while (Serial.available())
  {
    comdata += char(Serial.read());
    delay(2);
  }
  return comdata;
}

//小车行进指令封装函数
void move_forward_left(){
  Serial.println("moving forward left");
  digitalWrite(pinAIN1, 1);
  digitalWrite(pinAIN2, 0);
  digitalWrite(pinAIN3, 0);
  digitalWrite(pinAIN4, 0);
  digitalWrite(pinAIN5, 0);
  digitalWrite(pinAIN6, 0);
  digitalWrite(pinAIN7, 0);
  digitalWrite(pinAIN8, 1);
  analogWrite(pinPWMB, speed);
  analogWrite(pinPWMC, speed);
}

void move_forward(){
  Serial.println("moving forward");
  digitalWrite(pinAIN1, 1);
  digitalWrite(pinAIN2, 0);
  digitalWrite(pinAIN3, 0);
  digitalWrite(pinAIN4, 1);
  digitalWrite(pinAIN5, 1);
  digitalWrite(pinAIN6, 0);
  digitalWrite(pinAIN7, 0);
  digitalWrite(pinAIN8, 1);
  analogWrite(pinPWMA, speed);
  analogWrite(pinPWMB, speed);
  analogWrite(pinPWMC, speed);
  analogWrite(pinPWMD, speed);
}

void move_forward_right(){
  Serial.println("moving forward right");
  digitalWrite(pinAIN1, 0);
  digitalWrite(pinAIN2, 0);
  digitalWrite(pinAIN3, 0);
  digitalWrite(pinAIN4, 1);
  digitalWrite(pinAIN5, 1);
  digitalWrite(pinAIN6, 0);
  digitalWrite(pinAIN7, 0);
  digitalWrite(pinAIN8, 0);
  analogWrite(pinPWMB, speed);
  analogWrite(pinPWMC, speed);
}

void move_left(){
  //todo 补充向左移动的代码
  Serial.println("moving left");
}

void move_right(){
  //todo 补充向右移动的代码
  Serial.println("moving right");
}

void move_backward_left(){
  //todo 补充向右后移动的代码
  Serial.println("moving backward left");
}

void move_backward(){
  //todo 补充向后移动的代码
  Serial.println("moving backward");
}

void move_backward_right(){
  //todo 补充向右后移动的代码
  Serial.println("moving backward");
}

void move_clockwise(){
  //todo 补充顺时针转动的代码
}

void move_ct_clockwise(){
  //todo 补充逆时针转动的代码
}

void move_stop(){
  //让车子停止
  Serial.println("stopping");
  analogWrite(pinPWMA, 0);
  analogWrite(pinPWMB, 0);
  analogWrite(pinPWMC, 0);
  analogWrite(pinPWMD, 0);
  digitalWrite(pinAIN1, 0);
  digitalWrite(pinAIN2, 0);
  digitalWrite(pinAIN3, 0);
  digitalWrite(pinAIN4, 0);
  digitalWrite(pinAIN5, 0);
  digitalWrite(pinAIN6, 0);
  digitalWrite(pinAIN7, 0);
  digitalWrite(pinAIN8, 0);
}
