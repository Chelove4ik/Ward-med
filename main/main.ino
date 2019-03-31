#include <TimerOne.h>                                                                                                  
int val = 0;
int i=0;
int pulse=0;
int sumdelT=0;
int T1=0;
int T2=0;                                
void sendData() 
{                                                                                        
  //Serial.write("A0");                                                                                                          
  val = analogRead(A0);                                                              
 // Serial.write(map(val, 0, 1023, 0, 255));
  if (val>480) 
  {
    i++;
    if (i%2==0) 
    {
    T2=millis();
    sumdelT+=T2-T1;
    } else if (i%2>0)
    {
     T1=millis();
    }
    if (i>=10) 
    {
      pulse=1.0/sumdelT*100.0;    
      Serial.println(pulse); 
      sumdelT=0;  
    }
  }                                            
}
void setup() {            
  Serial.begin(9600);                     
  Timer1.initialize(3000);                  
  Timer1.attachInterrupt(sendData);         
}
void loop() 
{
}
