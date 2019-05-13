/*
* Bluetooth BT-06 / BT-05 Arduino Tutorial 
* by Dicson Pan @PastorEdu
* VCC：接Arduino的5V。
* GND：接Arduino的GND。
* TXD：发送端，一般表示为自己的发送端，接Arduino的RX。
* RXD：接收端，一般表示为自己的接收端，接Arduino的TX。
*/
void setup()
{
   Serial.begin(9600);        //串口波特率 
}
void loop()
{
  while(Serial.available())   //判断缓冲器状态。
   {  
     char c=Serial.read();    //读取串口
      if(c=='A')               //判断串口是否等于A
      {
        Serial.println("Hello World");//   串口输出数据并带回车符。
      }
   }
}
