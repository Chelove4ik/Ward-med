#include <TimerOne.h> 

int val = 0;
char port[2] = "A2";

void sendData(){                                              
  val = analogRead(port);                     
  Serial.println(val);
}

void setup() {
  Serial.begin(9600);                     
  Timer1.initialize(3000);                  
  Timer1.attachInterrupt(sendData);     
}

void loop() {
}
