/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>





#define RCC_BASE		        0x40021000UL
#define RCC_APB2ENR		*(volatile uint32_t *)(RCC_BASE + 0x18)


//GPIO
//A & B fully included in LQFP48 package

#define GPIOA_BASE		0x40010800UL
#define GPIOA_CRL		*(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH		*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_IDR		*(volatile uint32_t *)(GPIOA_BASE + 0x08)
#define GPIOA_ODR		*(volatile uint32_t *)(GPIOA_BASE + 0x0C)


#define GPIO_PIN13		((uint16_t)0x2000) //PIN 13 selected
#define GPIO_PIN1		((uint16_t)0x0002) //PIN 1 selected



#define GPIOB_BASE		0x40010C00UL
#define GPIOB_CRL		*(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_CRH		*(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_IDR		*(volatile uint32_t *)(GPIOB_BASE + 0x08)
#define GPIOB_ODR		*(volatile uint32_t *)(GPIOB_BASE + 0x0C)
#define GPIOB_BSRR		*(volatile uint32_t *)(GPIOB_BASE + 0x10)
#define GPIOB_BRR		*(volatile uint32_t *)(GPIOB_BASE + 0x40)
#define GPIOB_LCKR		*(volatile uint32_t *)(GPIOB_BASE + 0x80)

void CLK_INIT(void);
void GPIO_INIT(void);

void CLK_INIT()
{
	RCC_APB2ENR  |= (1<<2); //GPIOA init
	RCC_APB2ENR  |= (1<<3); //GPIOB init
}

void GPIO_INIT()
{
	GPIOA_CRL=0;
	GPIOA_CRH=0;
	GPIOA_ODR=0;

	GPIOB_CRL=0;
	GPIOB_CRH=0;
	GPIOB_ODR=0;

	//PIN A1: INPUT (MODE[1:0]=00) & CNF1 = 01: Floating input (reset state)
	GPIOA_CRL |= (0x4 << 4);

	//PIN A13: INPUT (MODE[1:0]=00) & CNF13 = 01: Floating input (reset state)
	GPIOA_CRH |= (0x4 << 20);


	//PIN B1: OUTPUT (MODE[1:0]=01)->10MHz & CNF1 = 00: General purpose output push-pull
	GPIOB_CRL |= (0x1 << 4);

	//PIN B13: OUTPUT (MODE[1:0]=01)->10MHz & CNF13 = 01: 01: General purpose output Open-drain
	GPIOB_CRH |= (0x5 << 20);

}

void wait_ms(uint32_t time)
{
	uint32_t i, j;
	for (i=0;i<time;i++)
		for(j=0;j<255;j++);

}

int main (void)
{
	CLK_INIT();

	GPIO_INIT();


	while(1)
	{
		if( ((GPIOA_IDR & (1<<1)) >>1) == 0 )
		{
			GPIOB_ODR ^= 1<<1;
			while(((GPIOA_IDR & (1<<1)) >>1)==0); //single pressing

		}
		if( ((GPIOA_IDR & (1<<13)) >>13) == 1)
		{
			GPIOB_ODR ^= 1<<13;

		}
		wait_ms(2);
	}
}