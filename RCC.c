#include "RCC.h"

void RCC_Init(void)
{
	volatile uint32_t temp;
	
	// Enable clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	// Read back to ensure clock is enabled
	temp = RCC->AHB1ENR;
	temp = RCC->APB2ENR;
	(void)temp;
}