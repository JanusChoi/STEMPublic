## 智能防盗器 By 严伟菠
### 作品清单
- 作品创意灵感：word文档
- 作品演示视频：视频格式为 MP4、AVI、MOV 等，建议不超过 5 分钟
- 制作说明文档：word文档，包含至少 5 个步骤的作品制作过程，每 个步骤包括至少 1 张图片和简要文字说明
    - 步骤一：使用 fritzing 画出接线图
    - 步骤二：硬件接线
    - 步骤三：调试程序
    - 步骤四：制作三维外观
    - 步骤五：拼装，完成
- 硬件清单：Excel表格
- 软件源代码：Arduino ino 代码文件，放在mind+中另存一个代码文件即可

### 作品制作教程

#### 1. 准备工作

请先完成[通用教程](./overall-learning.md)中的“准备工作”部分（利用教程中的目录或使用Ctrl+F快捷键快速找到想要学习的内容）


#### 2. 根据代码文件逐一测试传感器

请先完成[通用教程](./overall-learning.md)中的以下部分（利用教程中的目录或使用Ctrl+F快捷键快速找到想要学习的内容）

1. LED小灯
2. HC-SR501 人体红外感应电子模块
3. 蜂鸣器模块

#### 3. 代码整合

现在你已经学会使用作品所需的几个电子器件了，那么要把三个东西组合在一个程序里面要怎么做？
先用文字写下你的程序逻辑，例如：

当红外线传感器返回值（SensorState）大于某个数值时，让LED灯开始闪烁，同时让蜂鸣器也响起来

以下为整合示例，请尝试自行理解：
```
/*
 * Anty Thief Alarm Arduino Tutorial
 * by Dicson Pan @PastorEdu
 * 人体检测out口接4
 *
*/

#define OUT 4
#define BUZZER 3

void setup() {
  pinMode(OUT, INPUT);
  pinMode(BUZZER, OUTPUT);
  //digitalWrite(BUZZER, HIGH);
  Serial.begin(9600);
  Serial.println("Begin to detect");
}

void loop() {
  if (digitalRead(OUT)) {
    Serial.println("Alarm!!!Somebody's outthere!!!");
    alarmSound();
  }
  //delay(200);
}

void alarmSound(void) {
  tone(BUZZER, 647);
  delay(150);
  tone(BUZZER, 1295);
  delay(100);
  //digitalWrite(BUZZER, HIGH);
}
```

#### 4. 外观设计
外形参考：

原型及设计文档已交给同学

需要用Fusion360修改的地方：
- 不需要那么大的喇叭，可以把整体造型弄得更小
- 留出电池和开关的位置

#### 5. 3D打印

#### 6. 拼装

#### 7. 完善你的作品制作文档

#### 8. 拍摄一个视频介绍你的作品
