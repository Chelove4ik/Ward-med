#include <TimerOne.h>                                                                                                  
int val = 0;
int i=0;
//T1=0;
//T2=0;                                
void sendData() 
{                                                                                        
  Serial.write("A0");                                                                                                          
  val = analogRead(A0);                                                              
  Serial.write(map(val, 0, 1023, 0, 255));
  if (val>480) 
  {
    i++;
    
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
