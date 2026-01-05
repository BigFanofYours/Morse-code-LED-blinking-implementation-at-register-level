#ifndef GPIO_H
#define GPIO_H

#include "RCC_Register.h"
#include "GPIO_Registers.h"

void GPIO_LEDInit(void);
void GPIO_USART1Init(void);
void GPIO_WritePin(void);
void GPIO_ResetPin(void);
void GPIO_TogglePin(void);

#endif