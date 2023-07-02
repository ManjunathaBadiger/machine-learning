
/* MQ-3 Alcohol Sensor Circuit with Arduino */
/*SHUBHAM GUPTA - EMBEDDED ENGINEER*/



void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(10,HIGH);
  Serial.begin(115200);
  Serial.setTimeout(1);
  pinMode(AOUTpin, INPUT);//sets the pin as an input to the arduino
  for(i=2;i<=5;i++)
  {
  pinMode(i,OUTPUT);//sets the pin as an output of the arduino
  }
}

void loop() {
  while (!Serial.available());
  x = Serial.readString().toInt();
  if(x==1){
//    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    delay(500);
    digitalWrite(9,LOW);
    delay(500);}
  if(x==0){
    digitalWrite(9,LOW);
    }  


  alco_high=0; // initially alcohol level is zero
  alco_low = 1023; // low threshold is 1023

        for(i=200; i>0; i--){
        data[i] = data[i-1]; // decrement of data
        
      if(data[i]>alco_high)
      alco_high=data[i];
      if(data[i]<alco_low)
      alco_low=data[i];
      }
    data[0]= analogRead(AOUTpin);//reads the analaog value from the alcohol sensor's AOUT pin
    mapped=map(data[0],0,1023,0,600);
    Serial.print("Alcohol value: ");
    Serial.println(mapped);//prints the alcohol value
    delay(100);

    if(mapped >= 300){
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);}
  else{
  digitalWrite(9,LOW);
  }


}
