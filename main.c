#include "GPIO.h"
#include "Delay.h"
#include "RCC.h"
#include "USART.h"

const char UART_TX_OK[] = "TX OK\r\n"; 


int main(void)
{
	RCC_Init();
	GPIO_LEDInit();
	GPIO_USART1Init();
	USART1_Init();
	USART1_Enable();
	while(1)	
	{
		USART1_Transmit(UART_TX_OK);
		Delay();
		/*GPIO_WritePin();  // Set pins HIGH
		Delay();
		GPIO_ResetPin();  // Set pins LOW
		Delay();*/
	}
}