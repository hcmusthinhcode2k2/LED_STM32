#ifndef _GPIO_H_
#define _GPIO_H_

#include <define.h>
#include <rcc.h>
typedef struct
{
  BUNION(CRL, unsigned long,                    //              0x4444'4444     Port configuration register
      MODE_0                            , 2,    //0-1           0                       0: Input mode (reset state)
                                                //                                      1: Output mode, max speed 10 MHz.
                                                //                                      2: Output mode, max speed 2 MHz.
                                                //                                      3: Output mode, max speed 50 MHz
       CNF_0                            , 2,    //2-3           1               In input mode:
                                                //                                      0: Analog mode
                                                //                                      1: Floating input (reset state)
                                                //                                      2: Input with pull-up / pull-down
                                                //                              In output mode:
                                                //                                      0: General purpose output push-pull
                                                //                                      1: General purpose output Open-drain
                                                //                                      2: Alternate function output Push-pull
                                                //                                      3: Alternate function output Open-drain
      MODE_1                            , 2,    //4-5
       CNF_1                            , 2,    //6-7
      MODE_2                            , 2,    //8-9
       CNF_2                            , 2,    //10-11
      MODE_3                            , 2,    //12-13
       CNF_3                            , 2,    //14-15
      MODE_4                            , 2,    //16-17
       CNF_4                            , 2,    //18-19
      MODE_5                            , 2,    //20-21
       CNF_5                            , 2,    //22-23
      MODE_6                            , 2,    //24-25
       CNF_6                            , 2,    //26-27
      MODE_7                            , 2,    //28-29
       CNF_7                            , 2);   //30-31
  BUNION(CRH, unsigned long,                    //              0x4444'4444     
      MODE_8                            , 2,    //0-1
       CNF_8                            , 2,    //2-3
      MODE_9                            , 2,    //4-5
       CNF_9                            , 2,    //6-7
      MODE_10                           , 2,    //8-9
       CNF_10                           , 2,    //10-11
      MODE_11                           , 2,    //12-13
       CNF_11                           , 2,    //14-15
      MODE_12                           , 2,    //16-17
       CNF_12                           , 2,    //18-19
      MODE_13                           , 2,    //20-21
       CNF_13                           , 2,    //22-23
      MODE_14                           , 2,    //24-25
       CNF_14                           , 2,    //26-27
      MODE_15                           , 2,    //28-29
       CNF_15                           , 2);   //30-31   
  BUNION(IDR, unsigned long,                    //              0x0000'----     Port input data register
      xBITS_B(b, 0, 15, 1),                     //
      _reserved                         , 16);  //
  BUNION(ODR, unsigned long,                    //              0x0000'0000     Port output data register
      xBITS_B(b, 0, 15, 1),                     //
      _reserved                         , 16);  //
  union
  {
    unsigned long REG;
    struct
    {
      xBUNION(BSR, unsigned short, b, 0, 15, 1);//              0x0000          Write 1 to set pin output, set has priority 
      xBUNION(BR, unsigned short, b, 0, 15, 1); //              0x0000          Write 1 to clear pin output
    };
  } BSRR;                                       //                              Port bit set/reset register
  BUNION(BRR, unsigned long,                    //              0x0000'0000     Port bit reset register, Write 1 to clear pin output
      xBITS_B(b, 0, 15, 1),                     //
      _reserved                         , 16);  //
  BUNION(LCKR, unsigned long,                   //              0x0000'0000     Port configuration lock register
      xBITS_B(b, 0, 15, 1),                     //
      LOCK                              , 1,    //16            0               LOCK key writing sequence: write 1 -> 0 -> 1 -> read 0 -> 1
      _reserved                         , 15);  //
} GPIO_TypeDef;
 
__root __no_init volatile   RCC_TypeDef RCC    @ 0x40021000;
__root __no_init volatile   GPIO_TypeDef GPIOA @ 0x40010800;
__root __no_init volatile   GPIO_TypeDef GPIOB @ 0x40010C00;
__root __no_init volatile   GPIO_TypeDef GPIOC @ 0x40011000;

typedef enum
{
  GPIO_MODE_INPUT_ANALOG                = (0 << 2) | 0,
  GPIO_MODE_INPUT_FLOAT                 = (1 << 2) | 0,
  GPIO_MODE_INPUT_PULL                  = (2 << 2) | 0,
  
  GPIO_MODE_OUTPUT_PUSHPULL_10MHz       = (0 << 2) | 1,
  GPIO_MODE_OUTPUT_OPEN_10MHz           = (1 << 2) | 1,
  GPIO_MODE_AF_OUTPUT_PUSHPULL_10MHz    = (2 << 2) | 1,
  GPIO_MODE_AF_OUTPUT_OPEN_10MHz        = (3 << 2) | 1,
  
  GPIO_MODE_OUTPUT_PUSHPULL_2MHz        = (0 << 2) | 2,
  GPIO_MODE_OUTPUT_OPEN_2MHz            = (1 << 2) | 2,
  GPIO_MODE_AF_OUTPUT_PUSHPULL_2MHz     = (2 << 2) | 2,
  GPIO_MODE_AF_OUTPUT_OPEN_2MHz         = (3 << 2) | 2,
  
  GPIO_MODE_OUTPUT_PUSHPULL_50MHz       = (0 << 2) | 3,
  GPIO_MODE_OUTPUT_OPEN_50MHz           = (1 << 2) | 3,
  GPIO_MODE_AF_OUTPUT_PUSHPULL_50MHz    = (2 << 2) | 3,
  GPIO_MODE_AF_OUTPUT_OPEN_50MHz        = (3 << 2) | 3,  
} GPIO_MODE;

void GPIO_Mode(volatile GPIO_TypeDef* GPIO,unsigned int PIN,GPIO_MODE Mode);

#endif 