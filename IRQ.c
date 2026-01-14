#include "IRQ.h"
#include "GPIO.h"

extern volatile uint8_t RX_BUFFER[256];
extern volatile uint16_t RX_IRQIndex;
extern volatile uint8_t RX_SequenceReady;

void USART1_IRQHandler(void)
{
	if(USART1->USART_SR & USART1_RXNE)
	{
		uint8_t data;
		data = USART1->USART_DR;
		if(RX_IRQIndex <= 255)
		{
			RX_BUFFER[RX_IRQIndex++] = data;
			if(data == '\n')
			{
				RX_SequenceReady = 1;
			}
		}
	}
}
