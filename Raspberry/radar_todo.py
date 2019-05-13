'''
* Radar for Raspberry pi
* by Todo-写上你的名字
* 接线参考（Board）：

* 超声波传感器 Todo-定义好接线Pin
 vcc
 gnd
 trig
 echo

* 舵机 Todo-定义好接线Pin
 vcc
 gnd
 pwm
'''
import time
import RPi.GPIO as GPIO
# Todo-参数定义，需与接线相匹配
Trig_Pin =
Echo_Pin =
Servo =

GPIO.setmode(GPIO.BOARD)
GPIO.setup(Trig_Pin, GPIO.OUT, initial = GPIO.LOW)
GPIO.setup(Echo_Pin, GPIO.IN)
GPIO.setup(Servo, GPIO.OUT)

# Todo-启动舵机代码

time.sleep(2)

def distance():
	# Todo-定义距离传感器获取距离函数

try:
	while True:
		# Todo-结合舵机转动和传感器取值代码

except KeyboardInterrupt:
	GPIO.cleanup()
