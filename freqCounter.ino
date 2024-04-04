
#include <LiquidCrystal.h>
/* 
Program converts an input signal into a  square wave wave with an op amp in positive feedback configuration. A 
Comparator or a specialized IC would also work. The square wave period is then measured with built in functions. 
This period by default is in microseconds. We convert this into seconds and then takes its inverse to find the 
frequency of the digital signal. This frequency is equal to the frequency of the input analog signal. The frequency 
is displayed on a simple LCD 
*/
LiquidCrystal lcd(11, 7, 5, 4, 3, 2); // initiialize LCD 
// global declarations 
const int inputPin = 13; // digital input signal pin (square wave)
int timeHigh = 0; 
int timeLow = 0; 
float periodMicroseconds = 0.0; 
float periodSeconds = 0.0;
float frequency; // Calculated Frequency
void setup() 
{
  pinMode(inputPin, INPUT);

  lcd.begin(16, 2);

}

void loop() 
{
   lcd.setCursor(0, 0);
   lcd.print("Frequency: ");
   lcd.setCursor(0, 1);
   lcd.print(" ");
   timeHigh = pulseIn(inputPin, HIGH); // counts time from low to high to low transition 
   timeLow = pulseIn(inputPin, LOW);
   periodMicroseconds = timeHigh + timeLow;
   periodSeconds = periodMicroseconds*10e-6;
   frequency = 1/periodSeconds;
   lcd.setCursor(0, 1);
   lcd.print(frequency);
   lcd.print(" Hz");
   delay(500);
} // end loop 
