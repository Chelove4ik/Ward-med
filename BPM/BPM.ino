#include <TimerOne.h> 
int oldpulse=0;
int val = 0;                                 
bool flag=false;
int pulses = 0;
int T = 0;
int Td = 0, valold=0;
int puls_per_sec = 0, sumpuls=0, i=0;
void sendData() {
  val =map(analogRead(A0),0,1023,0,256);
  if (val > valold && !flag){
    flag = true;
  }

  if (val < valold && flag){
    flag = false;
    pulses++;
    if (pulses == 1){
      T = millis();
      delay(3000);
    }
    if (pulses == 2){
      Td = millis()-T;
      pulses = 0;
    }
    puls_per_sec = 1000.0/Td*60;
    if (i<7)
    {
    sumpuls+=puls_per_sec;
    i++;
    }else
  {
    if ((abs((sumpuls/7.0)-oldpulse)<25) && (sumpuls/7.0<150))
    {
    Serial.println(sumpuls/7.0);
    }
    oldpulse=sumpuls/7.0;
    sumpuls=0;
    i=0;
  }
  }
  valold=val;
}


void setup() {
  pinMode(pin, OUTPUT);
  while(!Serial);
  Serial.begin(9600);                    
 
  Timer1.initialize(3000);                 

  Timer1.attachInterrupt(sendData);        
}

void loop() {
}
