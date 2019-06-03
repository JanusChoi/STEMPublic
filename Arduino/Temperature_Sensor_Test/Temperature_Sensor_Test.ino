// demo of Starter Kit V2.0 - Grove Temperature Sensor
//

const int pinTemp = A0;      // pin of temperature sensor

float temperature;
float temp;
int B=3975;                  // B value of the thermistor
float resistance;

void setup()
{
    Serial.begin(9600);     //Baud rate for the serial communication of Arduino
    pinMode(A0,INPUT);      //Setting the A0 pin as input pin to take data from the temperature sensor 
    
}

void loop()
{
    int val = analogRead(pinTemp);                               // get analog value
    double DigitalValue = analogRead(0);
    double Voltage_Value = (DigitalValue/1023)*5.00;
    double Rt_Value = (3.3 - Voltage_Value)/Voltage_Value*100;
    resistance=(float)(1023-val)*10000/val;                      // get resistance
    temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;     // calc temperature when connect to 5v
    temp=1/(log(Rt_Value/10000)/B+1/298.15)-273.15;     // calc temperature when connect to 3.3v
    Serial.println(Voltage_Value);
    Serial.println(Rt_Value);
    Serial.println(temperature);
    Serial.println(temp);
    
    delay(1000);          // delay 1s
}
