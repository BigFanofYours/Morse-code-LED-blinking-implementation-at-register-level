#include "GPIO.h"

void GPIO_LEDInit(void)
{
	// Configure PA6 as output
	GPIOA->MODER &= ~(3UL << (6 * 2));
	GPIOA->MODER |= (1UL << (6 * 2));
	GPIOA->OTYPER &= ~(1UL << 6);
	GPIOA->PUPDR &= ~(3UL << (6 * 2));
	GPIOA->OSPEEDR &= ~(3UL << (6 * 2));
	
	// Configure PA7 as output
	GPIOA->MODER &= ~(3UL << (7 * 2));
	GPIOA->MODER |= (1UL << (7 * 2));
	GPIOA->OTYPER &= ~(1UL << 7);
	GPIOA->PUPDR &= ~(3UL << (7 * 2));
	GPIOA->OSPEEDR &= ~(3UL << (7 * 2));
	
	// Set initial state to LOW
	GPIOA->BSRR = ((1UL << 22) | (1UL << 23));
}

void GPIO_USART1Init(void)
{
	// Configure PA9, PA10 as USART1 output
	GPIOA->MODER &= ~((3UL << (9 * 2)) | (3UL << (10 * 2)));
	GPIOA->MODER |= ((2UL << (9 * 2)) | (2UL << (10 * 2)));
	GPIOA->OTYPER &= ~((1UL << 9) | (1UL << 10));
	GPIOA->PUPDR &= ~((3UL << (9 * 2)) | (3UL << (10 * 2)));
	GPIOA->OSPEEDR |= ((3UL << (9 * 2)) | (3UL << (10 * 2)));
	GPIOA->AFR[1] |= ((GPIOA->AFR[1] & ~((0xFUL << 4) | (0xFUL << 8))) | (7UL << 4) | (7UL << 8));
}

void GPIO_WritePin(void)
{
	GPIOA->BSRR = ((1UL << 6) | (1UL << 7));   // PA6 and PA7 HIGH (set bits)
}

void GPIO_ResetPin(void)
{
	GPIOA->BSRR = ((1UL << 22) | (1UL << 23));  // PA6 and PA7 LOW (reset bits)
}

void GPIO_TogglePin(void)
{
	GPIOA->ODR ^= (1UL << 6);   // Toggle PA6
	GPIOA->ODR ^= (1UL << 7);   // Toggle PA7
}





