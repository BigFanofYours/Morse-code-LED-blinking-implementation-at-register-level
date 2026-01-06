#include "NVIC.h"

void USART1_NVICIRQEnable(IRQn_Typedef IRQn)
{
	NVIC->NVIC_ISER[IRQn / 32] |= (1UL << (IRQn % 32)); 
}