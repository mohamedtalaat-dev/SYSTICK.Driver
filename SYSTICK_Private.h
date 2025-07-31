/*
 * SYSTICK_Private.h
 *
 *  Created on: Jul 26, 2025
 *      Author: Dell
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS  0xE000E010


typedef struct
{
	u32  CTRL;
	u32  LOAD;
	u32  VAL;
	u32  CALIB;

}SYSTICK_t;

#define  SYSTICK  ((volatile SYSTICK_t*)SYSTICK_BASE_ADDRESS)


#define AHB_DVIDED_BY_8  0
#define AHB             1



#endif /* SYSTICK_PRIVATE_H_ */
