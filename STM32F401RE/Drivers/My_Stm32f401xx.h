
#ifndef INC_MY_STM32F401XX_H_
#define INC_MY_STM32F401XX_H_

#define <stdint.h>
/*

BASE ADRESSES OF THE FLASH AND SRAM MEMORIES OF STM32F401XX

*/


#define FLASH_BASE_ADDR             0x08000000U
#define SYS_MEM_BASE_ADDR           0x1FFF0000U // Read Only Memory (ROM)
#define SRAM1_BASE_ADDR             0x20000000U // 96KB




/* BUS BASE ADDRESSES */
#define AHB2_BUS_ADDR               0x50000000U 
#define AHB1_BUS_ADDR               0x40020000U
#define APB2_BUS_ADDR               0x40010000U
#define APB1_BUS_ADDR               0x40000000U


/* GPIO PERIPHERAL BASE ADDRESSES */

#define GPIOA_BASE_ADDR             (AHB1_BUS_ADDR + 0x0000)U
#define GPIOB_BASE_ADDR             (AHB1_BUS_ADDR + 0x0400)U
#define GPIOC_BASE_ADDR             (AHB1_BUS_ADDR + 0x0800)U
#define GPIOD_BASE_ADDR             (AHB1_BUS_ADDR + 0x0C00)U
#define GPIOE_BASE_ADDR             (AHB1_BUS_ADDR + 0x1000)U
#define GPIOH_BASE_ADDR             (AHB1_BUS_ADDR + 0x1C00)U

/* EXTERNAL PERIPHERAL (EXTI) BASE ADDRESSES */

#define EXTI_BASE_ADDR              (APB2_BUS_ADDR + 0x3C00)U

/* STRUCTURES */

typedef struct {
    
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFR[2];
    
}GPIO_Reg_Map;

/* MACROS FOR PERIPHERAL */

#define GPIOA           ((GPIO_Reg_Map*)GPIOA_BASE_ADDR);
#define GPIOB           ((GPIO_Reg_Map*)GPIOB_BASE_ADDR);
#define GPIOC           ((GPIO_Reg_Map*)GPIOC_BASE_ADDR);
#define GPIOD           ((GPIO_Reg_Map*)GPIOD_BASE_ADDR);
#define GPIOE           ((GPIO_Reg_Map*)GPIOE_BASE_ADDR);
#define GPIOH           ((GPIO_Reg_Map*)GPIOH_BASE_ADDR);

#endif
