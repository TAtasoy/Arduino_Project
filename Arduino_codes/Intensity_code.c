#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3,2);

int Turbidity_Sensor_Pin = A2;
float Turbidity_Sensor_Voltage;
int samples = 600;
float ntu;

void setup ()
{
	Serial.begin(9600);
	pinMode(Turbidity_Sensor_Pin, INPUT);
	lcd.begin(16,2);
	
	
}

void loop()
{

	Turbidity_Sensor_Voltage = 0;
	
	for(int i=0; i<samples; i++)
	{
		Turbidity_Sensor_Voltage += ((float)analogRead(Turbidity_Sensor_Pin)/1023)*5;
		
	}	
	
	Turbidity_Sensor_Voltage = Turbidity_Sensor_Voltage/samples
	
	
	Turbidity_Sensor_Voltage = round_to_dp(Turbidity_Sensor_Voltage,2);
	if(Turbidity_Sensor_Voltage < 2.5) {
		ntu = 3000;
	} else {
		ntu = -1120.4*square(Turbidity_Sensor_Voltage)+ 5742.3*Turbidity_Sensor_Voltage - 4352.9;
	}	
