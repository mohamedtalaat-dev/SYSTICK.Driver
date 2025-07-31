/*
 * MRCC_Interface.h
 *
 *  Created on: Jul 19, 2025
 *      Author: Dell
 */

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_

void MRCC_voidInit(void);

void MRCC_voidPeripheralEnable(u8 Copy_u8Bus,u8 Copy_u8Peripheral);

void MRCC_voidPeripheralDisable(u8 Copy_u8Bus,u8 Copy_u8Peripheral);

typedef enum {
	AHB_1 =0 ,
	AHB_2,
	APB_1,
	APB_2
}peripheral_Bus;

typedef enum{
	GPIOA=0,
	GPIOB,
	GPIOC,
	CRC=12,
	DMA1=21,
	DMO2
}AHB1_Peripheral;

typedef enum{
	OTGFSRST=7
}AHB2_Peripheral;

typedef enum{
	TIM2=0,
	TIM3,
	TIM4,
	TIM5,
	WWDG=11,
	SPI2=14,
	SPI3,
	USART2=17,
	I2C1=21,
	I2C2,
	I2C3,
	PWR=28

}APB1_Peripheral;


typedef enum{
	TIM1=0,
	USART1=4,
	USART6,
	ADC1=8,
	SDIO=11,
	SPI1,
	SPI4,
	SYSCFG,
	TIM9=16,
	TIM10,
	TIM11


}APB2_Peripheral;



#endif /* MRCC_INTERFACE_H_ */
