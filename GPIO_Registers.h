#ifndef GPIO_Registers_H
#define GPIO_Registers_H

#include <stdint.h>

typedef struct
{
  volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00 */
  volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04 */
  volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08 */
  volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C */
  volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10 */
  volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14 */
  volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18 */
  volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C */
  volatile uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

/* GPIO Base Addresses */
#define GPIOA_BASE    (0x40020000UL)
#define GPIOB_BASE    (0x40020400UL)
#define GPIOC_BASE    (0x40020800UL)
#define GPIOD_BASE    (0x40020C00UL)
#define GPIOE_BASE    (0x40021000UL)

/* GPIO Peripheral Pointers */
#define GPIOA         ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB         ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC         ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD         ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE         ((GPIO_TypeDef *) GPIOE_BASE)

#endif