#ifndef NVIC_H
#define NVIC_H

#include "NVIC_Registers.h"
#include "IRQ.h"

void NVIC_IRQEnable(IRQn_Typedef IRQn);
void NVIC_IRQDisable(IRQn_Typedef IRQn);

#endif