/*
 * MRCC_Program.c
 *
 *  Created on: Jul 19, 2025
 *      Author: Dell
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_Config.h"
#include "MRCC_Interface.h"
#include "MRCC_Private.h"

void MRCC_voidInit(void){
#if SYS_Clock == HSI
	/*turn on HSI*/
	SET_BIT(RCC->CR,HSION);
	/*wait for stability */
	while(!GET_BIT(RCC->CR,HSIRDY)){

	}
	/*Select HSI as the System clock */
	//CLR_BIT(RCC->CFGR,0);
	//CLR_BIT(RCC->CFGR,1);
	RCC->CFGR &= ~3;
	RCC->CFGR |=0;

#elif SYS_Clock==HSE
#if HSE_SOURCE_TYPE == MECHANICAL
	CLR_BIT(RCC->CR,HSEBYP);
#elif HSE_SOURCE_TYPE == ELECTRICAL
	SET_BIT(RCC->CR,HSEBYP);
#endif
	/*turn on HSE*/
	SET_BIT(RCC->CR,HSEON);
	/*wait for stability */
	while(!GET_BIT(RCC->CR,HSERDY)){

	}


	/*Select HSE as the System clock */
	//CLR_BIT(RCC->CFGR,0);
	//SET_BIT(RCC->CFGR,1);
	RCC->CFGR &= ~3;
	RCC->CFGR |=1;

	/*TURN OFF HSI */
	SET_BIT(RCC->CR,HSION);

#elif SYS_Clock==PLL_HSI
	/*turn on HSI*/
		SET_BIT(RCC->CR,HSION);
		/*wait for stability */
		while(!GET_BIT(RCC->CR,HSIRDY)){

		}
		/*SELECT FOR PLL HSI */
		CLR_BIT(RCC->PLLCFGR,PLLSRC);
		/*TURN PLL ON */
		SET_BIT(RCC->CR,PLLON);
		/*Wait for stability */
		while(!GET_BIT(RCC->CR,PLLRDY)){

				}
		/*select pll */
		RCC->CFGR &=~3;
		RCC->CFGR |=2;


#elif SYS_Clock==PLL_HSE
#if HSE_SOURCE_TYPE == MECHANICAL
	CLR_BIT(RCC->CR,HSEBYP);
#elif HSE_SOURCE_TYPE == ELECTRICAL
	SET_BIT(RCC->CR,HSEBYP);
#endif
	/*turn on HSE*/
	SET_BIT(RCC->CR,HSEON);
	/*wait for stability */
	while(!GET_BIT(RCC->CR,HSERDY)){

	}
	/*SELECT FOR PLL HSE */
	SET_ BIT(RCC->PLLCFGR,PLLSRC);

	/*TURN PLL ON */
	SET_BIT(RCC->CR,PLLON);

	/*Wait for stability */

	while(!GET_BIT(RCC->CR,PLLRDY)){

					}

	/*select pll */
			RCC->CFGR &=~3;
			RCC->CFGR |=2;
	/*TURN OFF HSI */
		SET_BIT(RCC->CR,HSION);



#endif
}

void MRCC_voidPeripheralEnable(u8 Copy_u8Bus,u8 Copy_u8Peripheral)
{
	switch(Copy_u8Bus)
	{
	case AHB_1: SET_BIT(RCC->AHB1ENR,Copy_u8Peripheral ); break;

	case AHB_2: SET_BIT(RCC->AHB2ENR,Copy_u8Peripheral ); break;

	case APB_1: SET_BIT(RCC->APB1ENR,Copy_u8Peripheral ); break;

	case APB_2: SET_BIT(RCC->APB2ENR,Copy_u8Peripheral ); break;

	}

}

void MRCC_voidPeripheralDisable(u8 Copy_u8Bus,u8 Copy_u8Peripheral)
{

	switch(Copy_u8Bus)
	{
	case AHB_1: CLR_BIT(RCC->AHB1ENR,Copy_u8Peripheral ); break;

	case AHB_2: CLR_BIT(RCC->AHB2ENR,Copy_u8Peripheral ); break;

	case APB_1: CLR_BIT(RCC->APB1ENR,Copy_u8Peripheral ); break;

	case APB_2: CLR_BIT(RCC->APB2ENR,Copy_u8Peripheral ); break;

	}

}


