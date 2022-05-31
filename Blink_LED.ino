/* This is my first microcontroller project using the arduino R3 board  it
its purpose is to blink the built in LED*/

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
