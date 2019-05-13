/*
* ULN2003 and 28BYJ-48 Stepper Motor Arduino Tutorial
* by Dicson Pan @PastorEdu
* arduino的8、9、10、11分别对应uln2003的IN1、2、3、4
* 另外，最好外接一个5V左右的电源
* 28BYJ-48步进电机的齿轮减速比为64：1，15转速约转/分钟，一些软件采用某些手段和高电压电源（如12伏直流）也能达到约25转/分钟的转速。
* 4步控制信号序列：11.25度/步，32步旋转一周。
*/
//使用arduino IDE自带的Stepper.h库
#include <Stepper.h>

// 这里设置步进电机旋转一圈是多少步
#define STEPS 100

//设置步进电机的步数和引脚
Stepper stepper(STEPS, 8, 10, 9, 11);

void setup()
{
  // 设置点击的转速：每分钟为90步
  stepper.setSpeed(90);
  // 初始化串口
  Serial.begin(9600);
}

void loop()
{
    // 顺时针旋转一周
    Serial.println("顺时针");
    stepper.step(2048); //4步模式下旋转一周用2048 步。
    delay(500);

    // 逆時针旋转半周
    Serial.println("逆时针");
    stepper.step(-1024); //4步模式下旋转一周用2048 步。
    delay(500);
}
