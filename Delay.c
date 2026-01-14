#include "Delay.h"

void Delay(uint32_t DelaySec)
{
	for(volatile uint32_t i = 0; i < (DelaySec * 100000); i++);  // ~1 second delay
};