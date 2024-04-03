const int size = 10;
const int analogPin = A0;
double avg[size] = {0}; // declare array for moving average filter 

void replace(double val)
{
  for(int i = 1; i < size - 1; ++i)
  {
     avg[i - 1] = avg[i]; // shift 

  }
  avg[size - 1] = val; // push new data point on to array
} // end shifting function 
double takeAvg()
{
  double sum = 0.0;
  for(int i = 0; i < size; ++i)
  {
    sum += avg[i];

  }

  return sum/size; // return average of data set 

} // end compute average function 
void setup() 
{
  pinMode(analogPin,INPUT);
  Serial.begin(9600);
  delay(10);
  

}

void loop() 
{
  double currentSample = 0.0;
  currentSample = analogRead(analogPin);
  delayMicroseconds(300);
  replace(currentSample); // call function data isnt good until ten temperature samples are taken 
  Serial.println(takeAvg());
 
} // end 
