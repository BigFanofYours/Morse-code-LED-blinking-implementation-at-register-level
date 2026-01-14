#include "USART.h"

void USART1_Enable(void)
{
	USART1->USART_CR1 |= (1UL << 13U);
}

void USART1_Init(void)
{
	// Oversampling, word length, stop bit and baud rate config
	USART1->USART_CR1 &= ~((1UL << 12U) | (1UL << 15U));
	USART1->USART_CR2 &= ~(3UL << 12U);
	USART1->USART_BRR |= 0x683;
	
	// Enable RXNEIE for RX
	USART1->USART_CR1 |= (1UL << 5U);
	
	// Enable RE and TE bit for RX and TX
	USART1->USART_CR1 |= ((1UL << 2U) | (1UL << 3U));
	
	// Enable interrupt for USART1 RX
	NVIC_IRQEnable(USART1_IRQn);
}

void USART1_SendChar(uint8_t data)
{
	while(!(USART1->USART_SR & (1UL << 7)))
	{
		
	}
	USART1->USART_DR = data;
}

void USART1_Transmit(const char *data)
{
	while(*data)
	{
		USART1_SendChar(*data);
		data++;
	}
}


