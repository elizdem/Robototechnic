#include "SoftwareSerial.h"
SoftwareSerial altserSerial(2,3);

void findSin(){
	int count = 0;
	int minimum = 1023;
	int maximum = 0;
	while(count != 1024)
	{
		altserSerial.println(analogRead(A0));

		if(count == 0){
			count++;
			continue;
		}
		if(analogRead(A0) > maximum){
			maximum = analogRead(A0);
		}
		if(analogRead(A0) < minimum){
			minimum = analogRead(A0);
		}
		count++;
	}
	altserSerial.println(minimum);
	altserSerial.println(maximum);
}
void findSaw()
{
	int count = 0;
	int minimum = 1023;
	int maximum = 0;
	while(count != 1024)
	{
		Serial.println(analogRead(A1));

		if(count == 0){
			count++;
			continue;
		}
		if(analogRead(A1) > maximum){
			maximum = analogRead(A1);
		}
		if(analogRead(A1) < minimum){
			minimum = analogRead(A1);
		}
		count++;
	}
	Serial.println(minimum);
	Serial.println(maximum);

}

void setup()
{
	Serial.begin(4800);
	Serial.println("LR ¹2 DEMKO ÈÂÒ-2");
	findSaw();
	Serial.end();

	altserSerial.begin(9600);
	altserSerial.println("LR ¹2 DEMKO ÈÂÒ-2");
	findSin();
	altserSerial.end();

}

void loop()
{
}

