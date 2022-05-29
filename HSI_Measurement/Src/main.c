


#include <stdint.h>
#include <stdio.h>

/*
 * EXPLANE PROJECT
 * MCO register inside the RCC Clock configuration register
 * MCO connects to PA8 phycisal.
 * GPIOA peripheral is connected to AHB1
 *
 */
#define RCC_BASE_ADDR 					0x40023800UL
#define RCC_CFGR_ADDR_OFFSET 			0x08UL
#define RCC_AHB1RSTR_OFFSET 			0x10UL
#define RCC_CFGR_ADDR 					( RCC_BASE_ADDR + RCC_CFGR_ADDR_OFFSET )
#define RCC_AHB1RSTR_ADDR 				(RCC_BASE_ADDR+RCC_AHB1RSTR_OFFSET)


#define GPIOA_BASE_ADDR 				0x40020000UL
#define GPIOx_AFRH_OFFSET 				0x24UL
#define GPIOx_AFRH_ADDR  				GPIOA_BASE_ADDR+0x24UL


int main(void)
{
    uint32_t *pRccConfigReg = (uint32_t*)RCC_CFGR_ADDR;
    uint32_t *pRccAHB1RSTRReg = (uint32_t*)RCC_AHB1RSTR_ADDR;
    uint32_t *pGPIOModeReg = (uint32_t*)GPIOA_BASE_ADDR;
    uint32_t *pGPIOAAFRHReg = (uint32_t*)GPIOx_AFRH_ADDR;
    //pRccConfigReg &= pRccConfigReg ~(0x3 << 21);
    //MCO1 bits set to 00 for MCO1 over the RCC clock configuration register
    *pRccConfigReg &= ~(1<<21);
    *pRccConfigReg &= ~(1<<22);

    //Clock for GPIOA peripheral
    //We should open the AHB1 bus clock for GPIOA

    *pRccAHB1RSTRReg |= (1<<0);

    //Defined alternate function mode for GPIOA pin 8
    //Firstly clear the bits after that sets these bits
    *pGPIOModeReg &= (1<<16);
    *pGPIOModeReg &= (1<<17);

    *pGPIOModeReg |= (1<<16);
    *pGPIOModeReg |= (1<<17);

    //Set AF0 for alternate mode MCO1

    *pGPIOAAFRHReg &= ~(0xf <<0);


    for(;;);




}
