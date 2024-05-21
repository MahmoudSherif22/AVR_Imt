/*
 * ADC_Interface.h
 *
 *  Created on: May 10, 2024
 *      Author: 20110
 */

#ifndef MCAL_ADC_HEADER_ADC_INTERFACE_H_
#define MCAL_ADC_HEADER_ADC_INTERFACE_H_

#include"../../../COMMON/Stdtype.h"
#include"ADC_Register.h"
#include"ADC_Private.h"
#include"ADC_Config.h"

void ADC_Init();
u16 ADC_get_DigitalValue(u8 channel);

#endif /* MCAL_ADC_HEADER_ADC_INTERFACE_H_ */
