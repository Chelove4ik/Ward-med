#include <TimerOne.h> 

int val = 0;
char port[2] = "A2";
int speed = 9600;

void sendData(){                                              
  val = analogRead(port);                     
  Serial.println(val);
}

void setup() {
  Serial.begin(speed);                     
  Timer1.initialize(3000);                  
  Timer1.attachInterrupt(sendData);     
}

void loop() {
}
