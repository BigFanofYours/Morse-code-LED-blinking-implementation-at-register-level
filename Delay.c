#include "Delay.h"

void Delay(void)
{
	for(volatile uint32_t i = 0; i < 1000000; i++);  // ~1 second delay
};