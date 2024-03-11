#ifndef _LED_H_
#define _LED_H_


typedef struct
{
  unsigned char IsOn;
  unsigned char Times;
  unsigned char EdgeTime;
  unsigned char CountEdgeTime;
}Led_TypeDef;

void Led_Begin();
void Led_Process(void(*FisishFunction)(unsigned int LedIndex));
void led_Blink(unsigned int LedIndex,unsigned int Times,unsigned int EdgeTime);

#endif