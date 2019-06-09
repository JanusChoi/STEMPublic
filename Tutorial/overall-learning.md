# 通用教程

## 0. 目录

-   [通用教程](#通用教程)
    -   [0. 目录](#0-目录)
    -   [1. 准备工作](#1-准备工作)
        -   [1.1 安装软件](#11-安装软件)
        -   [1.2 学习fritzing](#12-学习fritzing)
    -   [2. 单个传感器测试教程](#2-单个传感器测试教程)
        -   [2.1 LED小灯](#21-led小灯)
        -   [2.2 HC-SR501](#22-hc-sr501)
        -   [2.3 蜂鸣器模块](#23-蜂鸣器模块)
        -   [2.4 开关类](#24-开关类)
        -   [2.5 脉搏传感器](#25-脉搏传感器)
        -   [2.6 A9G开发板](#26-A9G开发板)
        -   [2.7 温湿度传感器](#27-温湿度传感器)
        -   [2.8 红外体温计](#28-红外体温计)
        -   [2.9 彩色显示屏](#29-彩色显示屏)
        -   [2.10 OLED显示屏](#210-OLED显示屏)
        -   [2.11 震动马达模块](#211-震动马达模块)
    -   [3. 套件测试教程](#3-套件测试教程)

## 1. 准备工作

### 1.1 安装软件

- fritzing [Windows64位板下载](http://fritzing.org/download/0.9.3b/windows-64bit/fritzing.0.9.3b.64.pc.zip)
- Windows平台安装mind+ [下载地址](http://mindplus.cc/download.html)
- Fusion360   (课上已安装)
- Cura        (课上已安装)
- Arduino IDE (课上已安装)

### 1.2 学习fritzing

学会使用 fritzing 来绘制电路图

请查看以下教程自学：

- [官方英文](http://fritzing.org/learning/tutorials)
- [搜索B站](https://www.bilibili.com/video/av17886787/)

先学会在上面画：nano 连 面包板 连 LED灯 的电路图即可

## 2. 单个传感器测试教程

### 2.1 LED小灯

1. 认识LED小灯，小灯两条针脚一长一短，长针是正极，短针是负极，可以用“长正短负”的口诀来记住。
2. 尝试接线，LED小灯可以连接在任意两个D口上，在这个例子中，用的是D5和D6端口。
![](http://ww3.sinaimg.cn/large/006tNc79gy1g3o4bywo9lj30na0kewg6.jpg)
3. 打开Arduino IDE，编写以下代码，注意不要复制粘贴，注释也要抄上
```
/*
LED小灯测试代码

setup函数是每个Arduino都必须带有的，他会告诉Arduino需要启动那些针脚，这些针脚是用来输出还是输入的
在这个例子里面，D5和D6都是输出
注意每一行代码的结束都以分号结尾
*/
int LED = 5; // 在程序的头部写好所有你需要用到的针脚编号，这是良好的编程习惯

void setup() {
  pinMode(LED, OUTPUT); //把5这个针脚设置为输出端口
}

// loop函数也是Arduino程序必须带有的，这里面的程序Arduino会不断地重复执行，loop的意思就是循环
void loop() {
  digitalWrite(LED, HIGH);   // 给针脚5一个高电平，这时灯会亮起来
  delay(1000);                       // 等待1000毫秒，即1秒
  digitalWrite(LED, LOW);    // 给针脚5一个低电平，这时灯会灭掉
  delay(1000);                       // 等待1000毫秒，即1秒
}
```

4. 连接上Arduino Nano，然后上传代码（这个步骤我们在课堂上做过）
5. 观察LED小灯，是不是一亮一灭

### 2.2 HC-SR501

人体红外感应模块

1. 了解模块的接口如下
- VCC 接 nano的 5V
- GND 接 nano的 GND
- OUT 接 nano的 D2

2. 编写以下代码并且尝试理解，像上一个例子一样为以下程序的每一步添加注释
如果有代码不懂，马上尝试使用搜索引擎找到答案
```
int Sensor= 2;
void setup() {
   Serial.begin(9600);
   pinMode(Sensor, INPUT);
}
void loop() {
   int SensorState = digitalRead(Sensor);
   Serial.println(SensorState);
   delay(100);      
}
```

3. 在工具中打开串口监视器查看程序都输出了什么，这个数值当人在附近移动时会如何变化
4. 测试一下，如果用一个纸盒盖住传感器，会发生什么
5. 作业：尝试通过搜索引擎了解这个电子模块的工作原理
- 电子模块上面有两个可调节的东西，是用来调什么的？
- 为什么它能够检测到人体？

### 2.3 蜂鸣器模块

1. 了解蜂鸣器接口如下：
- VCC 接 nano的 5V
- GND 接 nano的 GND
- OUT 接 nano的 D13

2. 了解蜂鸣器工作原理，才能理解后面的代码

蜂鸣器是通过控制振动频率来发出相应的音调的，就像体检时的音叉，又好像敲响装着不同水量的瓶子一样。所以要使蜂鸣器按照我们的设定去响，第一步是要把振动频率跟音调定义出来。具体的对应关系可以点击 [链接](http://pages.mtu.edu/~suits/notefreqs.html) 了解。

第二步是我们要编写程序让蜂鸣器响起来，比如说让他响起一段小星星的节奏。那么每一个音符都会涉及三个参数：
- noteFrequency 音符频率，是Do Re 还是Mi Fa So
- noteDuration 音符长度，这个音要响多久
- silentDuration 静止长度，这个音响完之后要静下来多久，后两个参数组合起来就是“节奏”

我们通过 ```void _tone (float noteFrequency, long noteDuration, int silentDuration)``` 这个函数来控制一个音符，那么小星星的乐谱在程序里面看起来就是这样子的：
```
_tone(note_C0,50,30);
_tone(note_C0,50,30);
_tone(note_G0,50,30);
_tone(note_G0,50,30);
_tone(note_A0,50,30);
_tone(note_A0,50,30);
_tone(note_G0,50,30);
```

3. 测试并理解代码

代码比较长，点击[链接](https://github.com/JanusChoi/STEMPublic/blob/master/Arduino/Buzzer_Simple_Test/Buzzer_Simple_Test.ino) 获取。
“#define” 部分的代码可以复制到IDE中，后面的部分需要手动键入，有助于理解程序

4. 解决问题
- 有没有发现蜂鸣器奏出来的小星星很难听？这是因为节奏不对，那么要怎样调整？修改一些参数试试看吧
- 报警的音符应该是怎样响的？利用搜索引擎找一下蜂鸣器报警的代码，试试看

### 2.4 开关类
按压式开关，Dpdt开关


### 2.5 脉搏传感器

1. 了解Q333脉搏传感器接线如下
- + 接 nano的 3.3V
- - 接 nano的 GND
- S 接 nano的 A0

2. 安装库文件

使用“ 项目 -> 加载库  -> 管理库工具 ” 添加相关包

- 搜索 PulseSensor 并安装

3. 在Arduino IDE中输入以下示例程序

```
/*  示例代码
By @PastorEdu
--------描述------------------------------------------
1) 在串口监视器中显示脉搏BPM值
2) 当脉搏被检测到时输出: "♥  A HeartBeat Happened !"
2) 使用了PulseSensor库的对象
4) 内置pin13小灯会跟随脉搏闪动
--------------------------------------------------------------------*/

#define USE_ARDUINO_INTERRUPTS true    // 设置这个参数以获得更准确的读数
#include <PulseSensorPlayground.h>     // 导入库文件
//  Variables
const int PulseWire = 0;       // 设置A0
const int LED13 = 13;          // 设置LED端口
int Threshold = 550;           // 信息阈值，默认550
PulseSensorPlayground pulseSensor;  // 创建一个PulseSensorPlayground类，名字叫pulseSensor

void setup() {  

  Serial.begin(9600);          // 设置串口波特率，与串口监视器相关

  pulseSensor.analogInput(PulseWire);  //输入信号
  pulseSensor.blinkOnPulse(LED13);       //调用函数与LED联动
  pulseSensor.setThreshold(Threshold);  //设置阈值

  // 这里使用条件语句是为了更严谨，先判断是否有检测到脉搏
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");
  }
}

void loop() {
  int myBPM = pulseSensor.getBeatsPerMinute();  // 返回BPM值

  if (pulseSensor.sawStartOfBeat()) {            // 重复检测是否有检测到脉搏
    Serial.println("♥  A HeartBeat Happened ! "); // 检测到后输出通知
    Serial.print("BPM: ");                        
    Serial.println(myBPM);                        // 显示BPM值
  }
  delay(20);                    // 等待20毫秒后继续
}
```

### 2.6 A9G开发板

此开发板为安可信科技开发的GSM/GPRS+GPS模块，功能非常强大，可以单独使用。感兴趣的同学可以在网上搜寻更多相关资料，本教程提供用Arduino进行相关开发的示例。

1. 了解接线：

A9G的引脚说明图

![](http://ww2.sinaimg.cn/large/006tNc79ly1g3uvwkappwj30ml0ghn1y.jpg)

与nano的接线

- VUSB 接 nano的5V
- GND  接 nano的GND
- D2   接 AT_TX
- D3   接 AT_RX

使用前请将一张SIM卡放入开发板背后的槽中，上推揭开之后放入。

2. 示例代码

代码比较长，点击[链接](https://github.com/JanusChoi/STEMPublic/blob/master/Arduino/a9g_test/a9g_test.ino) 获取。

接线完成后，先不要上传代码，请仔细查看代码内容，注意修改
```
Serial1.println("AT+CMGS=13513551355"); //这里要改成你能收到短信的电话号码
```
这里的信息。

上传代码后观察串口监视器，该程序会发一条短信到你设定的手机号码

3. 练习
- 试试修改你的短信内容
- 在网上搜索“AT指令”了解更多相关内容
- 尝试自己完成发送中文短信的代码（示例中有）

### 2.7 温湿度传感器

1. 了解DHXX系列温湿度传感器接线如下
- VCC 接 nano的 5V
- GND 接 nano的 GND
- DATA 接 nano的 D2

2. 安装库文件

使用“ 项目 -> 加载库  -> 管理库工具 ” 添加相关包

- 搜索 DHT sensor library 并安装
- 搜索 Adafruit Unified Sensor 并安装

3. 在Arduino IDE中输入以下示例程序

```
/*
* DHT humidity and temperature Arduino Tutorial
* by Dicson Pan @PastorEdu
*/

#include "DHT.h"

#define DHTPIN 2     // 本例中使用D2

// 根据你的传感器型号注释以下代码
// 本利使用DHT22，故DHT22那一行代码没有被注释

//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// 初始化DHT传感器
DHT dht(DHTPIN, DHTTYPE);

// NOTE: For working with a faster chip, like an Arduino Due or Teensy, you
// might need to increase the threshold for cycle counts considered a 1 or 0.
// You can do this by passing a 3rd parameter for this threshold.  It's a bit
// of fiddling to find the right value, but in general the faster the CPU the
// higher the value.  The default for a 16mhz AVR is a value of 6.  For an
// Arduino Due that runs at 84mhz a value of 30 works.
// Example to initialize DHT sensor for Arduino Due:
//DHT dht(DHTPIN, DHTTYPE, 30);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  dht.begin();
}

void loop() {
  // 等待2秒
  delay(2000);

  // 读数需用时大约250毫秒

  float h = dht.readHumidity();        // 读取湿度数值
  float t = dht.readTemperature();     // 读取温度数值（摄氏度）
  float f = dht.readTemperature(true); // 读取温度数值（华氏度）

  // 检查是否有检测失败
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // 计算热度
  float hi = dht.computeHeatIndex(f, h);

  Serial.print("Humidity: ");
  Serial.print(h);   //输出湿度
  Serial.print(" %");
  Serial.print("\t");
  Serial.print("Temperature: ");
  Serial.print(t);   //输出温度
  Serial.println(" *C ");
  //Serial.print(f);
 // Serial.print(" *F\t");
 // Serial.print("Heat index: ");
 // Serial.print(hi);  //输出热度
 // Serial.println(" *F");
}
```

3. 上传测试代码并尝试理解
- 打开串口监视器观察传感器输出的数值
- 试试用手握住传感器，温度是不是变高了？

4. 通过搜索引擎去了解温湿度传感器的工作原理

### 2.8 红外体温计

MLX90615

### 2.9 彩色显示屏

1. 接线说明
 RS(DC)    - D08
 RST       - D09
 CS        - D10
 SDA(MOSI) - D11
 CLK(SCK)  - D13

2. 安装库文件
使用“ 项目 -> 加载库  -> 管理库工具 ” 添加相关包

- 搜索 Adafruit_GFX 并安装
- 搜索 Adafruit_ST7735 并安装
- 搜索 Adafruit_ST7789

使用这里的[代码](https://github.com/JanusChoi/STEMPublic/blob/master/Arduino/tftlcdst7735_test/tftlcdst7735_test.ino)进行测试学习。

保留你所需要的功能，比如显示文字则是代码中的```// large block of text```那部分。

### 2.10 OLED显示屏

### 2.11 震动马达模块

基本上和使用LED小灯一样简单，只要给IN一个高电平，就能让它实现震动，建议参考LED小灯的教程来尝试。
或使用如下代码，需要自行补充注释。

```
/*
示例代码
*/
#define Sensor_IN 5; //在这里补充注释

void setup() {
  pinMode(Sensor_IN, OUTPUT); //在这里补充注释
}

void loop() {
  digitalWrite(Sensor_IN, HIGH);   //在这里补充注释
  delay(1000);
  digitalWrite(Sensor_IN, LOW);    //在这里补充注释
  delay(1000);
}
```


## 3. 套件测试教程

### 3.1 麦克纳姆轮车

1. 套件说明
- 小车底盘及外壳
- 麦克纳姆轮 4个
- 带霍尔编码器电机 + 联轴器 4个
- L298N四路电机板
- Arduino Nano + 扩展板

2. 了解L298N

这是一个两路L298N的针脚说明，在本作品中采用的是四路L298N电机板（N路的意思是可以控制N个电机），相当于把两个电机板拼接在一起使用

![](http://ww3.sinaimg.cn/large/006tNc79ly1g3ux7cwc8nj30jy0cg0ui.jpg)

L298N是通过三个输出和两个输出来控制马达的，三个输入为
- IN1 对应图中的Input 1
- IN2 对应图中的Input 2
- EN1 对应图中的Enable A

两个输出为
- OUT1 对应图中的 MotorA的一端
- OUT2 对应图中的 MotorA的一端

其中IN1和IN2是控制马达转动方向的，EN1则是PWM信号负责驱动马达转动的，比如
- IN1=1 IN2=0 EN1=255 时，马达以正方向，255的速度转动
- IN1=0 IN2=0 EN1=255 时，马达以反方向，255的速度转动

3. 接线说明

单个马达调试接线：

| Arduino板载 | L298N | 连接内容     | 备注                    |
| -------- | ------- | ------------ | ----------------------- |
| 2        | IN1     | 马达方向      |           |
| 4        | IN2     | 马达方向      |           |
| 3        | EN1     | 马达PMW      |           |
|          | VCC     | 12V电源正极   |           |
|          | GND     | 12V电源负极   |           |
| 5V       | 5V      |              |           |
| GND      | GND     |              |           |
|          | OUT1    | 马达正极      |           |
|          | OUT2    | 马达负极      |           |

整车接线

| Arduino板载 | L298N | 连接内容     | 备注                    |
| -------- | ------- | ------------ | ----------------------- |
| 2        | IN1     | 右前马达      |           |
| 4        | IN2     | 右前马达      |           |
| 3        | EN1     | 右前马达PMW   |           |
| 7        | IN3     | 左前马达      |           |
| 6        | IN4     | 左前马达      |           |
| 5        | EN2     | 左前马达PWM   |           |
| 9        | IN5     | 右后马达      |           |
| 8        | IN6     | 右后马达      |           |
| 10       | EN3     | 右后马达PWM   |           |
| 12       | IN7     | 左后马达      |           |
| 13       | IN8     | 左后马达      |           |
| 11       | EN4     | 左后马达PWM   |           |
|          | VCC     | 12V电源正极   |           |
|          | GND     | 12V电源负极   |           |
| 5V       | 5V      |              |           |
| GND      | GND     |              |           |
|          | OUT1    | 右前马达正极   |           |
|          | OUT2    | 右前马达负极   |           |
|          | OUT3    | 左前马达正极   |           |
|          | OUT4    | 左前马达负极   |           |
|          | OUT5    | 右后马达正极   |           |
|          | OUT6    | 右后马达负极   |           |
|          | OUT7    | 左后马达正极   |           |
|          | OUT8    | 左后马达负极   |           |

编码器说明：

![](http://ww2.sinaimg.cn/large/006tNc79ly1g3ux2d6dm0j30u00ljmya.jpg)

M1 和 M2 是电机的正负极，只需接入这两个就可以让电机转动起来了。
中间的四条线都是霍尔编码器使用的，其中由上往下说明如下：
- 5V负极：接nano的GND
- A相：接nano的A0（或A0~A7的其中一个）
- B相：接nano的A1（或A0~A7的其中一个）
- 5V正极：接nano的5V（使用扩展板后有大量的5V和GND针脚可用）

对此感兴趣的同学可到网上搜索更多有关“霍尔传感器测速原理”进行深入了解。

3. 测试单个马达的示例程序(含霍尔编程器测速代码)

```
/*
 * Code developped by @PastorEdu
 */

//单个马达测试代码 For Nano
//Define the Pins
#define pinIN1 2     //nano的D2 接上 L298N的IN1
#define pinIN2 4     //nano的D4 接上 L298N的IN2
#define pinPWM 3     //nano的D3 接上 L298N的EN1
#define pinA A0      //编码器的A相 接上 nano的A0
#define pinB A1      //编码器的B相 接上 nano的A1

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
  SpeedCheck();
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
```
