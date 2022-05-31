/* This is my first project in the exciting world of microcontrollers and embedded computing. This code runs the same test that the Arduino development 
team uses to verify the functionality of the board before it is shipped out. 
It is a simple program that blinks the built in LED connected to pin 13 by turning it on and off every 1 second. 
Demonstration is on my YouTube channel listed in the readme file. */

//attatches specific pin to project variable
int led = 13; //assigns pin 13 (built in LED) as led

//declares pins as input or output:
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT); //declares pin 13 as output pin

}

//repeats process as long as board has power
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH); //drives onboard LED and turns on
  delay(1000); //delay 1000 ms = 1 second
  digitalWrite(led, LOW); //turn LED at pin 13 off 
  delay(1000); //delay by 1 second before repeating process

}
