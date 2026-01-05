#ifndef USART_H
#define USART_H

#include "USART_Registers.h"
#include "RCC_Register.h"
#include "GPIO.h"

void USART1_Transmitter_Init(void);
void USART1_SendChar(uint8_t data);
void USART1_Transmit(const char *data);

#endif