/*
 * Code developed by @PastorEdu
 * 代码仍然不规范和不合理的地方，有待改进
 */

#include <SoftwareSerial.h>
#include <TinyGPS++.h>       //用来解析GPS返回数据的程序包
#define _MSG_MAX_FIELD_SIZE 300
//int i = 0;
double latd = 0;
double lngd = 0;
String lats="";
String lngs="";
String newlats="";
String newlngs="";

//返回信息处理参数定义
char term[_MSG_MAX_FIELD_SIZE];
int keyGet = 0;
bool valueGet = 0;

String curKey = "";  //读取到的Key
String curValue = "";  //读取到的Value
String xKey = "";  //x Key
String yKey = "";  //y Key
String sKey = "";  //地址 Key
String xValue = "";  //x 值
String yValue = "";  //y 值
String sValue = "";  //地址值
String cmdAdsTrans = "";

bool isGetValue = false;  //标记是否需要拿Value
bool isJson = false;
bool isRunGPS = false;
bool isRunAdsTrans = false;
bool isRunAdsGet = false;

//循环读数标记参数
uint8_t curKeyStart;
uint8_t curKeyFirstset;
uint8_t curKeyOffset;
uint8_t curValueStart;
uint8_t curValueFirstset;
uint8_t curValueOffset;

SoftwareSerial Serial1(2,3); //TX 接 D2；RX 接D3

TinyGPSPlus gps;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  Serial.begin(9600);
  //Serial.println(latd);
  //Serial.println(lngd);
  Serial.println(F("Initializing GSM"));
  initGSM();
  Serial.println(F("Initializing GPRS"));
  initGPRS();
  Serial.println(F("Initializing GPS"));
  initGPS();
  Serial.println(F("System Ready"));
  delay(2000);
}

void loop() {
  
    //if 3 different condition
    // 1: if running GPSRD then get lat and lng
    // 2: if running AdsTrans then return x,y
    // 3. if running getAdress then return formatted_address
    if(latd == 0 || lngd == 0) {
      //Serial.println("Enter 1: running GPSRD");
      
      if(isRunGPS == 0){
        isRunGPS = 1;
        //Serial.println("AT+GPSRD=5");
        Serial1.println("AT+GPSRD=5");
        delay(5000);
      }
      
      
      while(Serial1.available()>0)
      {
        byte gpsData = Serial1.read();
        //Serial.println("reading data");
        //Serial.write(gpsData);
        gps.encode(gpsData);
        if (gps.location.isUpdated())
        {
          //Serial.print("Latitude= ");
          //Serial.print(gps.location.lat(), 6);
          latd = gps.location.lat();
          lats = String(latd, 6);
          //Serial.print("Longitude= ");
          //Serial.println(gps.location.lng(), 6);
          lngd = gps.location.lng();
          lngs = String(lngd, 6);
          Serial1.println("AT+GPSRD=0");
          isRunGPS = 0;
          delay(500);
        }
      }
      
    }
    
    else if (newlats =="" && newlngs =="") {
      //Serial.println("Enter 2: running AdsTrans");
      if(isRunAdsTrans == 0){
        isRunAdsTrans = 1;
        Serial.println(F("AdsTrans going"));
        //Serial.println(lats);
        //Serial.println(lngs);
        cmdAdsTrans = "AT+HTTPGET=\"http://api.map.baidu.com/geoconv/v1/?coords=" + lngs + "," + lats + "&from=1&to=5&ak=vMgqudzPKNCckkTSzudB0yn6kREsFtvm\"";
        //Serial.println(cmdAdsTrans);
        Serial1.println(cmdAdsTrans);
        //delay(5);
      }
      
      while(Serial1.available())
      {
        byte c=Serial1.read();
        //Serial.write(c);
        msgEncode(c);
        if (xValue !="" && yValue !="")
        {
//          Serial.print(xKey);
//          Serial.print(",");
//          Serial.println(xValue);
//          Serial.print(yKey);
//          Serial.print(",");
//          Serial.println(yValue);
          newlats = yValue.substring(0,9);
          newlngs = xValue.substring(0,9);
          Serial.print("newlats, newlngs:");
          Serial.println(newlats);
          Serial.println(newlngs);
          isRunAdsTrans = 0;
          cmdAdsTrans = "";
          lats = "";
          lngs = "";
          if(newlats !="" && newlngs !=""){break;}
        }
      }
    }

    else if (sValue == ""){
      //Serial.println("Enter 3: running AdsGet");
      if (isRunAdsGet == 0){
        isRunAdsGet = 1;
        Serial.println(F("AdsGet going"));
        //Serial.println(cmdAdsTrans);
        
        //cmdAdsTrans = "AT+HTTPGET=\"http://api.map.baidu.com/geocoder/v2/?callback=renderReverse&location=" + newlats + "," + newlngs + "&output=json&pois=0&latest_admin=1&ak=vMgqudzPKNCckkTSzudB0yn6kREsFtvm";
        cmdAdsTrans = "AT+HTTPGET=\"http://api.map.baidu.com/geocoder/v2/?callback=renderReverse&location=" + newlats + "," + newlngs;
        //Serial.print(cmdAdsTrans);
        Serial1.print(cmdAdsTrans);
        cmdAdsTrans = "&output=json&pois=0&latest_admin=1&ak=vMgqudzPKNCckkTSzudB0yn6kREsFtvm\"";
        //Serial.println(cmdAdsTrans);
        Serial1.println(cmdAdsTrans);
      }
      
      while(Serial1.available())
      {
        byte c=Serial1.read();
        //Serial.write(c);
        msgEncode(c);
//        if (sValue !="")
//        {
//          Serial.println(sValue);  // 输出地址
//        }
      }
    }
    if (sValue !=""){
      Serial.println(sValue);  // 输出地址
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
  connectGSM("AT+CGATT=1","OK");
  delay(1500);
  connectGSM("AT+CGACT=1,1","OK");
  delay(1000);
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

bool msgEncode(char c)
{
  int i = 0;

  switch(c)
  {
    case '{':
    {
      //Serial.println(F("Enter { flow"));
      isJson = true;
      if(isGetValue == 1)  //若遇到嵌套，则需重置控制参数
      {
        curValue = "";
        keyGet = 0;
        isGetValue = 0;
        } 
      break;
    }
    case '\"': // 双引号进入这里
    {
      //Serial.println(F("Enter\"flow"));

      if (curKeyStart == 0 && isGetValue != 1 && isJson == true) //未开始读Key，并且未有读取Value时执行
      {
        curKeyStart = 1;
        curKeyFirstset = curKeyOffset;
        //Serial.println(F("key start"));
        return false;
      }

      if (curKeyStart == 1)  //Key读取完毕
      {
        curKeyStart = 0;
        //Serial.println(F("key end"));

        for(i = curKeyFirstset; i < curKeyOffset; i++){  //把读取到的Key写入到curKey中
          curKey += term[i];
          //Serial.print(F("the value of curKey now is: "));
          //Serial.println(curKey);
        }

        isGetValue = endofKeyHandler(); //调取Key处理函数
        Serial.println(F("Key First to Off"));
        Serial.println(curKeyFirstset);
        Serial.println(curKeyOffset);

      }
      break;
    }

    case ':': //冒号进入这里
    {
      //Serial.println("Enter':'flow");

      if (curValueStart == 0 && isGetValue == true && isJson == true) //未开始读Value，并且确定需要读Value时执行
      {
        curValueStart = 1;
        curValueFirstset = curValueOffset;
        return false;
      }
      break;
    }

    case ',':   //Value读取完毕
    case '}':
    {
      //Serial.println("Enter',}'flow");
      if (curValueStart == 1)
      {
        curValueStart = 0;
        //Serial.println("Value end");

        for(i = curValueFirstset; i < curValueOffset; i++){  //把Value值写进curValue
          curValue += term[i];
          //Serial.print(F("the value of curValue now is: "));
          //Serial.println(curValue);
        }

        valueGet = endofValueHandler();  //调取Value处理函数
        Serial.println(F("Value First to Off"));
        Serial.println(curValueFirstset);
        Serial.println(curValueOffset);

      }
      break;
    }



    default: //其它字符读取处理
    {

      if (curKeyStart == 1)
      {
        //Serial.println(F("default: curKey Writing"));
        term[curKeyOffset++] = c;
      }

      if (curValueStart == 1)
      {
          term[curValueOffset++] = c;
        return false;
      }
    }
  }
}

bool endofKeyHandler(){

  int i = 0;
  if (curKey == "formatted_address" || curKey == "x" || curKey == "y"){  //hardcode了三个需要读取的key，todo: 后续优化以适应更多用途

    if(curKey == "x"){xKey = curKey; keyGet =1;}
    if(curKey == "y"){yKey = curKey; keyGet =2;}
    if(curKey == "formatted_address"){sKey = curKey; keyGet =3;}
    curKey = "";   //重置curKey
    return true;
    }
  else if(keyGet == 0){  //未拿到需要的Key时，清空
//    for(i = 0; i <= curKeyOffset; i++){
//    //Serial.print(F("the value of term now is: "));
//    //Serial.println(term);
//    term[i] = "";
//   }
  curKey = "";
  return false;
  }

}

bool endofValueHandler(){
  if (keyGet > 0){  //hardcode了三个需要读取的key，todo: 后续优化以适应更多用途
    switch(keyGet){
      case 1:
        xValue = curValue;
        //Serial.println(F("xValue get"));
        break;
      case 2:
        yValue = curValue;
        //Serial.println(F("yValue get"));
        break;
      case 3:
        sValue = curValue;
        break;
    }
    curValue = "";  //重置控制处参数
    keyGet = 0;
    isGetValue = 0;
  }
}
