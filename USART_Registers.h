#ifndef USART_REGISTERS_H
#define USART_REGISTERS_H

#include <stdint.h>

typedef struct{
	volatile uint32_t USART_SR;
	volatile uint32_t USART_DR;
	volatile uint32_t USART_BRR;
	volatile uint32_t USART_CR1;
	volatile uint32_t USART_CR2;
	volatile uint32_t USART_CR3;
	volatile uint32_t USART_GTPR;
}USART_Typedef;

#define USART1_BASE (0x40011000UL)

#define USART1 ((USART_Typedef *) USART1_BASE)

#endif