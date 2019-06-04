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
[官方英文](http://fritzing.org/learning/tutorials)
[搜索B站](https://www.bilibili.com/video/av17886787/)

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
