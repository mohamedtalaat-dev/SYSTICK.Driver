/*
 * SYSTICK_Program.c
 *
 *  Created on: Jul 26, 2025
 *      Author: Dell
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK_Interface.h"
#include "SYSTICK_Config.h"
#include "SYSTICK_Private.h"


void  SYSTICK_voidInit(void)
{
#if  SYSTICK_CLOCK_SOUECE == AHB_DVIDED_BY_8
	{
		SET_BIT(SYSTICK->CTRL,2);
	}
#elif SYSTICK_CLOCK_SOUECE==AHB
	{
		CLR_BIT(SYSTICK->CTRL,2);
	}
#endif
}
void SYSTICK_voidConfigerInterruptState(Interrupt_State Copy_uddtState)
{
	if(Copy_uddtState == Disable)
	{
		CLR_BIT(SYSTICK->CTRL,1);
	}

	else if(Copy_uddtState == Enable )
		{
			SET_BIT(SYSTICK->CTRL,1);
		}
}
void  SYSTICK_voidStart(u32 Copy_u2TicksValue)
{
	SYSTICK->LOAD = Copy_u2TicksValue;
	SYSTICK->VAL =0;
	SET_BIT(SYSTICK->CTRL,0);

}
void SYSTICK_voidDelay_ms(u32 Copy_u32DelayTime)
{
	SYSTICK_voidStart(Copy_u32DelayTime*2000);
	while (!GET_BIT(SYSTICK->CTRL, 16)){
	}
	CLR_BIT(SYSTICK->CTRL,0);
}
void SYSTICK_voidDelay_us(u32 Copy_u32DelayTime)
{
	SYSTICK_voidStart(Copy_u32DelayTime*2);
		while (!GET_BIT(SYSTICK->CTRL, 16)){
		}
		CLR_BIT(SYSTICK->CTRL,0);
}

u32 SYSTICK_u32ELapsedTime()
{
	return ((SYSTICK->LOAD)-(SYSTICK->VAL));

}
u32  SYSTICK_u32GetRemainingTime()
{
	return (SYSTICK->VAL);

}
