#include "GPIO.h"
#include "Delay.h"
#include "RCC.h"
#include "USART.h"
#include "NVIC.h"

// Definitions

// Global variables
volatile uint8_t RX_BUFFER[256];
const char UART_TX_OK[] = "TX OK\r\n";
const char UART_RX_OK[] = "RX OK\r\n";
volatile uint16_t RX_MainIndex = 0;
volatile uint16_t RX_IRQIndex = 0;
volatile uint8_t RX_SequenceReady = 0;

//Function declarations
void RX_DataProcessing(void);
void RX_DataProcessing1(void);

int main(void)
{
	RCC_Init();
	GPIO_LEDInit();
	GPIO_USART1Init();
	USART1_Init();
	USART1_Enable();
	GPIO_ResetPin();
	GPIO_TogglePin();
	while(1)	
	{
		if(RX_SequenceReady == 1)
		{
			//USART1_Transmit(UART_RX_OK);
			//RX_DataProcessing1();
			RX_SequenceReady = 0;
			RX_IRQIndex = 0;
		}
	}
}

void RX_DataProcessing(void)
{
	NVIC_IRQDisable(USART1_IRQn);
	for(RX_MainIndex = 0; RX_MainIndex <= RX_IRQIndex; RX_MainIndex++)
	{
		
	}
	NVIC_IRQEnable(USART1_IRQn);
}

// Function for manual debugging USART1 RX
/*void RX_DataProcessing1(void)
{
	for(RX_MainIndex = 0; RX_MainIndex <= RX_IRQIndex; RX_MainIndex++)
	{
		if(RX_BUFFER[RX_MainIndex] == 'E')
		{
			GPIO_TogglePin();
			Delay(2);
		}
		else if(RX_BUFFER[RX_MainIndex] == 'm')
		{
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
		}
		else if(RX_BUFFER[RX_MainIndex] == 'e')
		{
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
		}
		else if(RX_BUFFER[RX_MainIndex] == 'r')
		{
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
		}
		else if(RX_BUFFER[RX_MainIndex] == 'g')
		{
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
		}
		else if(RX_BUFFER[RX_MainIndex] == 'n')
		{
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
		}
		else if(RX_BUFFER[RX_MainIndex] == 'c')
		{
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
		}
		else if(RX_BUFFER[RX_MainIndex] == 'y')
		{
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
			GPIO_TogglePin();
			Delay(2);
		}
	}
}*/
