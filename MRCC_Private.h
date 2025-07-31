/*
 * MRCC_Private.h
 *
 *  Created on: Jul 19, 2025
 *      Author: Dell
 */

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

#define Base_Address   0x40023800

typedef struct {
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 Reserved_1;
	u32 Reserved_2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 Reserved_3;
	u32 Reserved_4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 Reserved_5;
	u32 Reserved_6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 Reserved_7;
	u32 Reserved_8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 Reserved_9;
	u32 Reserved_10;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 Reserved_11;
	u32 Reserved_12;
	u32 BDCR;
	u32 CSR;
	u32 Reserved_13;
	u32 Reserved_14;
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 DCKCFGR;

}RCC_t;

#define RCC  ((volatile RCC_t*)Base_Address)

#define HSI   0
#define HSE   1
#define PLL_HSI   2
#define PLL_HSE   3

#define  HSION    0
#define  HSIRDY   1
#define  HSEON    16
#define  HSERDY   17
#define  PLLON    24
#define  PLLRDY   25
#define  PLLSRC   22


#define ELECTRICAL 1
#define MECHANICAL 2
#define HSEBYP     18


#endif /* MRCC_PRIVATE_H_ */
