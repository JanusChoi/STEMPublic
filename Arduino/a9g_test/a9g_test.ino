/*
 * Code developed by @PastorEdu
 */
 
/* usb to ttl converter code
void setup() {
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
}
 
void loop() {
  
}
*/

#include <SoftwareSerial.h>
int i = 0;
SoftwareSerial Serial1(2,3); //TX 接 D2；RX 接D3

void setup()
{
  Serial1.begin(115200); //设置A9G波特率为115200
  Serial.begin(9600);    //设置Arduino串口波特率为9600
  Serial.println("Initializing GSM");
  initGSM();             //调用GSM初始化函数
  Serial.println("System Ready");
  delay(2000);
}

void loop()
{
  if(i == 0){

    connectGSM("AT+CMGF=1","OK");  
    Serial1.println("AT+CMGS=13570486126"); //这里要改成你能收到短信的电话号码
    delay(1000);
    
    while(Serial1.available())
    {
      char c=Serial1.read();
      Serial.write(c);
      if(c=='>'){
        Serial1.println("Welcome to AT command's World");
        delay(2000);
        //Serial1.write(0x1A);  //结束码，使用该行或下一行代码均可，感兴趣的同学可以多了解 16进制 与 10进制 之间的转换
        Serial1.write(26);
        while(Serial1.available()){
          char c=Serial1.read();
          Serial.write(c);
        }
      }
    }

/*  //发送中文短信示例，需要用到网页转码：http://www.multisilicon.com/blog/a22201774~/pdu.htm
    //使用前要先注释掉上面相应的代码
    connectGSM("AT+CMGF=0","OK");  
    Serial1.println("AT+CMGS=29"); //这里要改成你能收到短信的电话号码
    delay(1000);
    
    while(Serial1.available())
    {
      char c=Serial1.read();
      Serial.write(c);
      if(c=='>'){
        Serial1.print("放上网页转换后的PUD编码");
        delay(2000);
        //Serial1.write(0x1A);  //结束码，使用该行或下一行代码均可，感兴趣的同学可以多了解 16进制 与 10进制 之间的转换
        Serial1.write(26);
        while(Serial1.available()){
          char c=Serial1.read();
          Serial.write(c);
        }
      }
    }
*/


    
    i++;
    if(i==1){
      Serial.println("Program End");
      i++;
    }
  }
}
void initGSM()  //函数功能：确认GSM模块工作正常
{
  connectGSM("AT","OK");
  connectGSM("ATE1","OK");
  connectGSM("AT+CPIN?","READY");
}

void connectGSM (String cmd, char *res)  //发送命令函数，若AT指令返回值与第二个参数相等，则退出函数
{
  while(1)
  {
    Serial.println(cmd);
    Serial1.println(cmd);
    delay(500);
    while(Serial1.available()>0)
    {
      if(Serial1.find(res))
      {
        delay(1000);
        return;
      }
    }
    delay(1000);
   }
}
