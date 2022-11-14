#include "SoftwareSerial.h"

int sensorRead;
int h;
bool oldStates;
bool mode;

void setup()
{
	pinMode(2, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);

	Serial.begin(9600); 
	oldStates = digitalRead(7);
}

void loop()
{

	if (Serial.available() > 0) 
	{	    
		String s = Serial.readString();
		if (s=="nofunc") mode = false;
		else if (s=="func") mode = true;		 
	}

	if(digitalRead(7) != oldStates) 
	{
		mode = digitalRead(7);
		oldStates = mode;
	}

	if(digitalRead(6))
	{
		digitalWrite(2, HIGH);
		digitalWrite(4, HIGH);

		digitalWrite(13, LOW);
		tone(8, 1000);
		digitalWrite(12, HIGH);
	}
	else 
	{
		digitalWrite(2, LOW);
		digitalWrite(4, LOW);

		digitalWrite(12, LOW);
		tone(8, 0);
		digitalWrite(13, HIGH);
	}

	if(mode)
	{
		analogWrite(9, map(analogRead(A1), 0, 1023, 0, 255));
		analogWrite(5,  map(analogRead(A2), 0, 1023, 0, 255));
	}
	else 
	{
		sensorRead = analogRead(A0);	
		h = map(sensorRead, 0, 1023, 0, 255);
		analogWrite(9, h);
		analogWrite(5, h);
	}
}
