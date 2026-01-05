/**
  ******************************************************************************
  * @file    system_stm32f4xx.c
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M4 Device Peripheral Access Layer System Source File.
  ******************************************************************************
  */

#include <stdint.h>

/* System Control Block Base Address and Registers */
#define SCB_BASE            (0xE000ED00UL)
#define SCB_CPACR           (*(volatile uint32_t *)(SCB_BASE + 0x88))
#define SCB_VTOR            (*(volatile uint32_t *)(SCB_BASE + 0x08))

#define FLASH_BASE          0x08000000UL
#define SRAM_BASE           0x20000000UL

/* FPU Configuration */
#define __FPU_PRESENT       1
#define __FPU_USED          1

/* Vector Table Configuration */
#define VECT_TAB_OFFSET     0x00

/* System Core Clock Variable */
uint32_t SystemCoreClock = 16000000;  // 16 MHz HSI

/* Prescaler tables (required by some toolchains) */
const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t APBPrescTable[8]  = {0, 0, 0, 0, 1, 2, 3, 4};

/**
  * @brief  Setup the microcontroller system
  *         Initialize the FPU setting and vector table location
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
  /* FPU settings - Enable CP10 and CP11 coprocessors */
  #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB_CPACR |= ((3UL << 10*2)|(3UL << 11*2));
  #endif

  /* Configure the Vector Table location - default in Flash */
  SCB_VTOR = FLASH_BASE | VECT_TAB_OFFSET;
}

/**
  * @brief  Update SystemCoreClock variable
  * @param  None
  * @retval None
  */
void SystemCoreClockUpdate(void)
{
  SystemCoreClock = 16000000;  // Using HSI clock
}
