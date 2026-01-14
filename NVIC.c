#include "NVIC.h"

void NVIC_IRQEnable(IRQn_Typedef IRQn)
{
	NVIC->NVIC_ISER[IRQn / 32] |= (1UL << (IRQn % 32)); 
}

void NVIC_IRQDisable(IRQn_Typedef IRQn)
{
	NVIC->NVIC_ICER[IRQn / 32] |= (1UL << (IRQn % 32));
}