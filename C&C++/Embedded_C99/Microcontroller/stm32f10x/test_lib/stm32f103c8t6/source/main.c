#include <rcc.h>
#include <gpio.h>
#include <led.h>

//void main()
//{
//  
//  //turn on clock for GPIOC
//  RCC.APB2_ENR.BITS.IOPB = 1;
//  RCC.APB2_ENR.BITS.IOPC = 1;
//  //config GPIOB.b12 to OUTPUT
//  GPIO_Mode(&GPIOB,(1UL << 12), GPIO_MODE_OUTPUT_PUSHPULL_10MHz);
//  GPIO_Mode(&GPIOC,(1UL << 13), GPIO_MODE_OUTPUT_PUSHPULL_10MHz);
//  while(1)
//  {
//    GPIOB.BSRR.REG = (1UL << 12);
//    for (unsigned long i = 0; i < 100000; i++);
//    GPIOB.BSRR.REG = (1UL << (12 + 16)); // Clear bit 12
//    for (unsigned long i = 0; i < 100000; i++);
//    GPIOC.BSRR.REG = (1UL << 13);
//    for (unsigned long i = 0; i < 100000; i++);
//    GPIOC.BSRR.REG = (1UL << 13+16);
//     for (unsigned long i = 0; i < 100000; i++);
//  }
//}
__root unsigned char blink =0;

void CFG_LED(unsigned int LedIndex, unsigned int Value)
{
  switch (LedIndex)
  {
    case 0: GPIOB.ODR.BITS.b12=Value; break;
    case 1: GPIOB.ODR.BITS.b12=Value; break;
    case 2: GPIOB.ODR.BITS.b12=Value; break;
    case 3: GPIOB.ODR.BITS.b12=Value; break;    
  }
}
void main()
{
    RCC.APB2_ENR.BITS.IOPB = 1;
    GPIO_Mode(&GPIOB,(1UL << 12), GPIO_MODE_OUTPUT_PUSHPULL_10MHz);
    //init led
    Led_Begin();
    while(1)
    {
      if (blink)
      {
        blink=0;
        led_Blink(0,5,10);
      }
      //GPIOB.ODR.REG = ~ GPIOB.ODR.REG;
      Led_Process((void*)0);
      for (unsigned long i = 0; i < 100000; i++);
    }
}