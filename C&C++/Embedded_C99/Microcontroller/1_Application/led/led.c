#include <led.h>
#include <config.h>
__no_init Led_TypeDef Led[NUMBER_OF_LED];
void Led_Begin()
{
  for (unsigned int i=0;i < NUMBER_OF_LED ;i++)
  {
    Led[i].IsOn         =0;
    CFG_LED(i,0);
    Led[i].Times        =0;
    Led[i].EdgeTime     =0;
    Led[i].CountEdgeTime=0;
  }
}
void Led_Process(void(*FisishFunction)())
{
  for (unsigned int i=0;i < NUMBER_OF_LED ;i++)
  {
    if (Led[i].Times)
    {
      if(Led[i].CountEdgeTime++ >= Led[i].EdgeTime)
      {
        Led[i].CountEdgeTime =0;
        Led[i].IsOn = !Led[i].IsOn;
        //turn on/off led
        CFG_LED(i,Led[i].IsOn);
        if (Led[i].Times != 255)
        {
          if (!(--Led[i].Times) && FisishFunction)
            FisishFunction();
        }
      }
    }
  }
}
void led_Blink(unsigned int LedIndex,unsigned int Times,unsigned int EdgeTime)
{
  
    Led[LedIndex].IsOn = 0;
    CFG_LED(LedIndex,0);
    Led[LedIndex].CountEdgeTime =0;
    Led[LedIndex].EdgeTime = EdgeTime;
    Led[LedIndex].Times = Times*2;
}