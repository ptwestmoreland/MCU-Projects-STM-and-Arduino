

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 12; i <= 13; ++i){
    digitalWrite(i, HIGH);
    delay(200);
    digitalWrite(i, LOW);
    delay(100);
    digitalWrite(i, HIGH);
    delay(200);
    digitalWrite(i, LOW);
    delay(100);
  }

}
