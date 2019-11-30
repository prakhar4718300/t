
#include <SoftwareSerial.h>
int x;
int y;
float Time = 0;
float Frequency = 0;
float Water = 0;
float Total = 0;
float LS = 0;
const int input = A0;



void setup() 
{
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(input,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
x = pulseIn(input, HIGH);
y = pulseIn(input, LOW);
Time = x + y; 
Frequency = 1000000/Time;
Water = Frequency/7.5;
LS = Water/60;
if (Frequency >= 0)
{
if(isinf(Frequency))
{
  

Serial.print("VOL : 0");
Serial.print("Total");
Serial.print(Total);
Serial.print("L     ");
}
else
{
  

Total = Total + LS;

Serial.print("VOL : ");
Serial.print(Water);
Serial.print("Total");
Serial.print(Total);
Serial.print("L");
Serial.print("      ");

  
  
  
  
}
}
delay(1000);
}
