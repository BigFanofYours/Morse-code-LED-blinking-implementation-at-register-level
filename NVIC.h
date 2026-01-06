#ifndef NVIC_H
#define NVIC_H

#include "NVIC_Registers.h"
#include "IRQ.h"

void USART1_NVICIRQEnable(IRQn_Typedef IRQn);

#endif