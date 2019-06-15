/*
 * Code developed by @PastorEdu
 */

#include <SoftwareSerial.h>
#include <TinyGPS++.h>       //用来解析GPS返回数据的程序包
int i = 0;
SoftwareSerial Serial1(2,3); //TX 接 D2；RX 接D3

TinyGPSPlus gps;  //新建一个TinyGPS的类，名字叫gps

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  Serial.begin(9600);
  Serial.println("Initializing GSM");
  initGSM();
  Serial.println("Initializing GPRS");
  initGPRS();
  Serial.println("Initializing GPS");
  initGPS();
  Serial.println("System Ready");
  delay(2000);
  Serial.println("AT+GPSRD=5");
  Serial1.println("AT+GPSRD=5");
  delay(5000);
}

void loop() {

    while(Serial1.available()>0)
    {
      byte gpsData = Serial1.read();
      //Serial.println("reading data");
      //Serial.write(gpsData);
      gps.encode(gpsData);   //调用gps类中的encode函数
      if (gps.location.isUpdated())
      {
        Serial.print("Latitude= ");   //输出纬度值
        Serial.print(gps.location.lat(), 6);
        Serial.print("Longitude= ");  //输出经度值
        Serial.println(gps.location.lng(), 6);
      }
    }


}

void initGSM()
{
  connectGSM("AT","OK");
  connectGSM("ATE1","OK");
  connectGSM("AT+CPIN?","READY");
}

void initGPRS()
{
  //connectGSM("AT+CIPSHUT","OK");
  connectGSM("AT+CGATT=1","OK");
  delay(1500);
  //connectGSM("AT+CGDCONT,'IP','CMNET'","OK");
  connectGSM("AT+CGACT=1,1","OK");
  //connectGSM("AT+CSTT="airtelgprs.com","",""","OK");
  //connectGSM("AT+CIICR","OK");
  delay(1000);
  //Serial1.println("AT+CIFSR");
  //delay(1000);
}

void initGPS()
{
  connectGSM("AT+GPS=1","OK");
  connectGSM("AT+GPSMD=2","OK");
  connectGSM("AT+GPSRD=5","GNGGA");
  delay(10000);
  connectGSM("AT+GPSMD=1","OK");
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
