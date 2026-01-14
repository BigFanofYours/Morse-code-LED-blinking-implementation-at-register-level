#ifndef IRQ_H
#define IRQ_H

#include "USART_Registers.h"
#include "stdint.h"

typedef enum
{
	USART1_IRQn = 37
}IRQn_Typedef;

#define USART1_RXNE 					(1UL << 5)

void USART1_IRQHandler(void);

#endif