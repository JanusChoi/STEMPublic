int ASignal = A0;

void setup() {
pinMode(ASignal, INPUT);
Serial.begin(9600);
}

void loop() {
int sensorValue = analogRead(ASignal);
Serial.print("rain=");
Serial.println(sensorValue);
delay(1000);
}
