#include <TimerOne.h> 

int GSR = 0;
int BPM = 0, oldpulse = 0, pulses = 0, T = 0, Td = 0, BPMold = 0,pulse_per_sec = 0, sum_pulse = 0, i = 0;
bool flag = false;
char GSRport[2] = "A2", BPMport[2] = "A0";

int speed = 9600;

void sendPulse(){    
  BPM = map(analogRead(BPMport), 0, 1023, 0, 256);
  if (BPM > BPMold && !flag)
  {
    flag = true;
  }

  if (BPM < BPMold && flag)
  {
    flag = false;
    pulses ++;
    if (pulses == 1)
    {
      T = millis();
      delay(3000);
    }
    if (pulses == 2)
    {
      Td = millis() - T;
      pulses = 0;
    }
    pulse_per_sec = 1000.0 / Td * 60;
    if (i < 7)
    {
      sum_pulse += pulse_per_sec;
      i++;
    }
    else
    {
       double ans = sum_pulse/7.0;
       if ((ans < 150) && (ans > 25))
      {
            Serial.print("BPM ");
            Serial.println(int(ans));
      }
      oldpulse = int(ans);
      sum_pulse = 0;
      i = 0;
    }
  }
  BPMold = BPM;
}

void sendGSR() {
  delay(3000);               
  GSR = analogRead(GSRport); 
  Serial.print("GSR ");                    
  Serial.println(GSR);
}

void setup() {
  Serial.begin(speed);                     
  Timer1.initialize(3000);                  
  Timer1.attachInterrupt(sendPulse);     
}

void loop() {
  sendGSR();
} 
