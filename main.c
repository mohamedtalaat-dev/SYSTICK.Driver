/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include  "MGPIO_Interface.h"
#include  "MGPIO_Interface.h"
#include "MRCC_Interface.h"
#include  "MRCC_Config.h"
#include "SYSTICK_Interface.h"



int
main(void )
{
	MRCC_voidInit();
		MRCC_voidPeripheralEnable(AHB_1,GPIOA);
		MGPIO_voidSetPinMode(PORTA,PIN1,OUTPUT);
		MGPIO_voidSetPullType(PORTA,PIN1,PULL_UP );
		MGPIO_voidSetOutputSpeed(PORTA,PIN1 , LOW_SPEED);
  while (1)
    {
	  MGPIO_voidSetPinValue(PORTA,PIN1,HIGH);
	  SYSTICK_voidDelay_ms(1000);
	  MGPIO_voidSetPinValue(PORTA,PIN1,LOW);
	  SYSTICK_voidDelay_ms(1000);

    }
}


// ----------------------------------------------------------------------------
