#include <TimerOne.h> 

int BPM = 0, GSR = 0;
int speed = 9600;

void sendData(){    
  Serial.print("BPM ");
  Serial.println(random(60, 100));                                          
  GSR = analogRead(A2); 
  Serial.print("GSR ");                    
  Serial.println(GSR);
}

void setup() {
  Serial.begin(speed);                     
  Timer1.initialize(3000);                  
  Timer1.attachInterrupt(sendData);     
}

void loop() {
} 
