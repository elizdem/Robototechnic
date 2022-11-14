const int GREEN = 11;             
const int YELLOW = 12;
const int RED = 13;   

const int TIMEPICK = 5000; //������ �������� ����������.

void setup()
{
	//��������� ��� ����� � ��������� ������ ����������
	pinMode(GREEN, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(RED, OUTPUT); 

	//������������� ��������� �������� �����������
	digitalWrite(GREEN, LOW);
	digitalWrite(YELLOW, LOW);
	digitalWrite(RED, LOW);
}  

void loop()
{
	digitalWrite(GREEN, HIGH); //���������� ������            
	delay(TIMEPICK);            

	digitalWrite(GREEN, LOW); //����������� ������
	digitalWrite(YELLOW, HIGH); //���������� �����        
	delay(TIMEPICK);            

	digitalWrite(YELLOW, LOW); //����������� �����
	digitalWrite(RED, HIGH); //���������� �������    
	delay(TIMEPICK);                           
	digitalWrite(RED, LOW); //����������� �������
}
