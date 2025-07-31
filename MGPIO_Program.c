/*
 * MGPIO_Program.c
 *
 *  Created on: Jul 21, 2025
 *      Author: Dell
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MGPIO_Private.h"
#include "MGPIO_Interface.h"
#include "MGPIO_Confg.h"


void MGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	switch (Copy_u8Port)
	{
	case PORTA:
		GPIOA->MODER &= ~(0b11 << (Copy_u8Pin * 2));          // Clear the 2 bits
		GPIOA->MODER |=  ((Copy_u8Mode & 0b11) << (Copy_u8Pin * 2)); // Set new mode
		break;

	case PORTB:
		GPIOB->MODER &= ~(0b11 << (Copy_u8Pin * 2));
		GPIOB->MODER |=  ((Copy_u8Mode & 0b11) << (Copy_u8Pin * 2));
		break;

	case PORTC:
		GPIOC->MODER &= ~(0b11 << (Copy_u8Pin * 2));
		GPIOC->MODER |=  ((Copy_u8Mode & 0b11) << (Copy_u8Pin * 2));
		break;

	default:

		break;
	}
}


void MGPIO_voidSetOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Type)
{
	switch (Copy_u8Port)
	{
	case PORTA:
		if (Copy_u8Type == PUSH_PULL)
		{
			CLR_BIT(GPIOA->OTYPER, Copy_u8Pin); // 0 = Push-Pull
		}
		else if (Copy_u8Type == OPEN_DRAIN)
		{
			SET_BIT(GPIOA->OTYPER, Copy_u8Pin); // 1 = Open-Drain
		}
		break;

	case PORTB:
		if (Copy_u8Type == PUSH_PULL)
		{
			CLR_BIT(GPIOB->OTYPER, Copy_u8Pin);
		}
		else if (Copy_u8Type == OPEN_DRAIN)
		{
			SET_BIT(GPIOB->OTYPER, Copy_u8Pin);
		}
		break;

	case PORTC:
		if (Copy_u8Type == PUSH_PULL)
		{
			CLR_BIT(GPIOC->OTYPER, Copy_u8Pin);
		}
		else if (Copy_u8Type == OPEN_DRAIN)
		{
			SET_BIT(GPIOC->OTYPER, Copy_u8Pin);
		}
		break;

	default:
		// Optional: Handle invalid port
		break;
	}
}

void MGPIO_voidSetOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Speed)
{
	switch (Copy_u8Port)
	{
	case PORTA:
		GPIOA->OSPEEDER &= ~(0b11 << (Copy_u8Pin * 2));                 // Clear
		GPIOA->OSPEEDER |=  ((Copy_u8Speed & 0b11) << (Copy_u8Pin * 2)); // Set
		break;

	case PORTB:
		GPIOB->OSPEEDER &= ~(0b11 << (Copy_u8Pin * 2));
		GPIOB->OSPEEDER |=  ((Copy_u8Speed & 0b11) << (Copy_u8Pin * 2));
		break;

	case PORTC:
		GPIOC->OSPEEDER &= ~(0b11 << (Copy_u8Pin * 2));
		GPIOC->OSPEEDER |=  ((Copy_u8Speed & 0b11) << (Copy_u8Pin * 2));
		break;

	default:
		// Optional: handle error
		break;
	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
#if SET_PINVALUE == ODR_RG
	switch(Copy_u8Port)
	{
	case PORTA:
		if(Copy_u8Value == HIGH)
			SET_BIT(GPIOA->ODR, Copy_u8Pin);
		else
			CLR_BIT(GPIOA->ODR, Copy_u8Pin);
		break;

	case PORTB:
		if(Copy_u8Value == HIGH)
			SET_BIT(GPIOB->ODR, Copy_u8Pin);
		else
			CLR_BIT(GPIOB->ODR, Copy_u8Pin);
		break;

	case PORTC:
		if(Copy_u8Value == HIGH)
			SET_BIT(GPIOC->ODR, Copy_u8Pin);
		else
			CLR_BIT(GPIOC->ODR, Copy_u8Pin);
		break;
	}

#elif SET_PINVALUE == BSRR_RG
	switch(Copy_u8Port)
	{
	case PORTA:
		if(Copy_u8Value == HIGH)
			BSRR_SET(GPIOA, Copy_u8Pin);
		else
			BSRR_RESET(GPIOA, Copy_u8Pin);
		break;

	case PORTB:
		if(Copy_u8Value == HIGH)
			BSRR_SET(GPIOB, Copy_u8Pin);
		else
			BSRR_RESET(GPIOB, Copy_u8Pin);
		break;

	case PORTC:
		if(Copy_u8Value == HIGH)
			BSRR_SET(GPIOC, Copy_u8Pin);
		else
			BSRR_RESET(GPIOC, Copy_u8Pin);
		break;
	}
#endif
}

void MGPIO_voidSetPullType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Pull)
{
	switch (Copy_u8Port)
	{
	case PORTA:
		GPIOA->PUPDR &= ~(0b11 << (Copy_u8Pin * 2));                // Clear the 2 bits
		GPIOA->PUPDR |=  ((Copy_u8Pull & 0b11) << (Copy_u8Pin * 2)); // Set new pull type
		break;

	case PORTB:
		GPIOB->PUPDR &= ~(0b11 << (Copy_u8Pin * 2));
		GPIOB->PUPDR |=  ((Copy_u8Pull & 0b11) << (Copy_u8Pin * 2));
		break;

	case PORTC:
		GPIOC->PUPDR &= ~(0b11 << (Copy_u8Pin * 2));
		GPIOC->PUPDR |=  ((Copy_u8Pull & 0b11) << (Copy_u8Pin * 2));
		break;

	default:
		// Optional: handle invalid port
		break;
	}
}


u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8PinValue = 0;

	if (Copy_u8Port == PORTA)
	{
		Local_u8PinValue = GET_BIT(GPIOA->IDR, Copy_u8Pin);
	}
	else if (Copy_u8Port == PORTB)
	{
		Local_u8PinValue = GET_BIT(GPIOB->IDR, Copy_u8Pin);
	}
	else if (Copy_u8Port == PORTC)
	{
		Local_u8PinValue = GET_BIT(GPIOC->IDR, Copy_u8Pin);
	}
	else
	{
		// Optional: You may handle invalid port ID here.
		Local_u8PinValue = 0;
	}

	return Local_u8PinValue;
}

void MGPIO_voidConfigAlernateFunc(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Alrtrnate){

	switch (Copy_u8Port)
	{
	case PORTA:
		if (Copy_u8Pin<=7)
		{
			GPIOA->AFRL &= ~(15 << (Copy_u8Pin * 4));          // Clear the 4 bits
			GPIOA->AFRL |=  (Copy_u8Alrtrnate  << (Copy_u8Pin * 4)); // Set new mode

		}

		else if (Copy_u8Pin<=15)
		{
			GPIOA->AFRH &= ~(15 << (Copy_u8Pin-8) * 4);          // Clear the 4 bits
			GPIOA->AFRH |=  (Copy_u8Alrtrnate  << (Copy_u8Pin * 4)); // Set new mode

		}

		break;

	case PORTB:
		if (Copy_u8Pin<=7)
				{
					GPIOB->AFRL &= ~(15 << (Copy_u8Pin * 4));          // Clear the 4 bits
					GPIOB->AFRL |=  (Copy_u8Alrtrnate  << (Copy_u8Pin * 4)); // Set new mode

				}

		else if (Copy_u8Pin<=15)
				{
					GPIOB->AFRH &= ~(15 << (Copy_u8Pin-8) * 4);          // Clear the 4 bits
					GPIOB->AFRH |=  (Copy_u8Alrtrnate  << (Copy_u8Pin * 4)); // Set new mode

				}
		break;

	case PORTC:
		if (Copy_u8Pin<=7)
				{
					GPIOC->AFRL &= ~(15 << (Copy_u8Pin * 4));          // Clear the 4 bits
					GPIOC->AFRL |=  (Copy_u8Alrtrnate  << (Copy_u8Pin * 4)); // Set new mode

				}

		else if (Copy_u8Pin<=15)
				{
					GPIOC->AFRH &= ~(15 << (Copy_u8Pin-8) *4 );          // Clear the 4 bits
					GPIOC->AFRH |=  (Copy_u8Alrtrnate  << (Copy_u8Pin * 4)); // Set new mode

				}
		break;

	default:

		break;
	}
}
