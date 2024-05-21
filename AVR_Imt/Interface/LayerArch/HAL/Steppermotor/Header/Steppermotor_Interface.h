/*
 * Steppermotor_Interface.h
 *
 *  Created on: Apr 26, 2024
 *      Author: 20110
 */

#ifndef HAL_STEPPERMOTOR_HEADER_STEPPERMOTOR_INTERFACE_H_
#define HAL_STEPPERMOTOR_HEADER_STEPPERMOTOR_INTERFACE_H_

#include"../../../COMMON/Stdtype.h"
#include"../../../MCAL/DIO/Header/DIO_Interface.h"
#include"../Header/Steppermotor_Private.h"
#include"../Header/Steppermotor_Config.h"

void StepperMotor_Init();
void StepperMotorON_ClkWise(u8 StepType, u16 Angle);
void StepperMotorON_AntiClkWise(u8 StepType, u16 Angle);
void StepperMotorOFF();


#endif /* HAL_STEPPERMOTOR_HEADER_STEPPERMOTOR_INTERFACE_H_ */
