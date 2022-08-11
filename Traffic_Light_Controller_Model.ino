 int redLED = 2; // set red LED to pin2 
 int yellowLED = 7;
 int greenLED = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  pinMode(greenLED,OUTPUT);

 

}

void loop() {
  // put your main code here, to run repeatedly:

  /* the traffic light controller will begin witht the red light
   *  on, it will remain that way for 4 seconds, then the green light
   *  will come on for 6 seconds then the yellow light comes on for 2.
   */

   digitalWrite(redLED,HIGH);
   delay(4000); // stay in redlight on state for 4 sec 
   digitalWrite(redLED,LOW); // turn off 
   delay(1000); // pause
   digitalWrite(greenLED,HIGH);
   delay(6000);
   digitalWrite(greenLED,LOW);
   delay(1000);
   digitalWrite(yellowLED,HIGH);
   delay(2000);
   digitalWrite(yellowLED,LOW);
   delay(1000);
   // repeat 

}
