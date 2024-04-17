const int LED1 = 5; // succesive PWM pins 
const int LED2 = 6; // LED pins, get high portion of PWM signal 
// could choose to not use succesive ones and write logic in loop that skips irrelevant pins 
void setup() 
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() 
{
  for(int i = LED1; i <= LED2; ++i){
    if(i == LED1){
      for(int Duty = 0; Duty < 256; ++Duty){
        analogWrite(LED1, Duty);
      }
    }
    //delay(1000);
    if(i == LED2){
        for(int Duty = 255; Duty >= 0; --Duty){
         analogWrite(LED2, Duty);
       }
    }
  }

  
}
