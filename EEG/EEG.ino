#include <fft.h> 
#include <TimerOne.h>                      
#define num 256                        // зададим число оцифрованных значений сигнала ЭЭГ, которое будет отправлено в функцию для разложения в спектр
int8_t result[num], data[num];             // массивы для накопления данных
int  i = 0, k=0;                            // переменная-счетчик 
int val = 0;
float alpha = 0;
float alpha_old=0;
int8_t sum = 0;            
void sendData()
{
  val=analogRead(A0);
  data[i]=val/8;
  if (i==256) 
  {
    for (int k=0;k<256;k++)
    {
     data[k]=data[k]- sum/num;
    }
    i=0;
    sum=0;
    fix_fft(data,result,8,0);
    
  } else 
  {
    sum=sum+data[i];
    i++;
  }                        
  val = analogRead(A0);                                             
  data[i] = val/8;
  alpha_old=alpha;
  alpha=0;
  for (int z=4;z<8;z++)
  {
     alpha+=sqrt(data[i]*data[i]+result[i]*result[i]);
     alpha=0.3*alpha+0.7*alpha_old;
  }
  Serial.print("EEG ");
  Serial.println(alpha);  
}

void setup() 
{
  Serial.begin(9600);
  Timer1.initialize(3000);                 
  Timer1.attachInterrupt(sendData);              
}

void loop() 
{
  
}
  
    
