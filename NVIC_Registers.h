#ifndef NVIC_REGISTERS_H
#define NVIC_REGISTERS_H

#include <stdint.h>

typedef struct 
{
	volatile uint32_t NVIC_ISER[3];
	volatile uint32_t NVIC_ICER[3];
	volatile uint32_t NVIC_ISPR[3];
	volatile uint32_t NVIC_ICPR[3];
	volatile uint32_t NVIC_IABR[3];
	volatile uint32_t NVIC_IPR[3];
	volatile uint32_t STIR;
}NVIC_Typedef;

#define NVIC_BASE 		(0xE000E100UL)

#define NVIC 					((NVIC_Typedef*) NVIC_BASE)

#endif