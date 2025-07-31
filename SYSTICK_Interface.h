/*
 * SYSTICK_Interface.h
 *
 *  Created on: Jul 26, 2025
 *      Author: Dell
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

typedef enum{
	Disable=0,
	Enable

}Interrupt_State;

void  SYSTICK_voidInit(void);
void SYSTICK_voidConfigerInterruptState(Interrupt_State Copy_uddtState);
void  SYSTICK_voidStart(u32 Copy_u2TicksValue);
void SYSTICK_voidDelay_ms(u32 Copy_u32DelayTime);
void SYSTICK_voidDelay_us(u32 Copy_u32DelayTime);

u32 SYSTICK_u32ELapsedTime();
u32  SYSTICK_u32GetRemainingTime();



#endif /* SYSTICK_INTERFACE_H_ */
