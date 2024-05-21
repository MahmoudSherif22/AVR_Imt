/*
 * Steppermoto_Program.c
 *
 *  Created on: May 19, 2024
 *      Author: 20110
 */


#include<util/delay.h>
#include"../Header/Steppermotor_Interface.h"

void StepperMotor_Init()
{

	DIO_SelectDirectionForPin(StepperMotorGroup,StepperMotor_Blue,Output)   ;
	DIO_SelectDirectionForPin(StepperMotorGroup,StepperMotor_Bink,Output)   ;
	DIO_SelectDirectionForPin(StepperMotorGroup,StepperMotor_Yellow,Output) ;
	DIO_SelectDirectionForPin(StepperMotorGroup,StepperMotor_Orange,Output) ;

}


void StepperMotorON_AntiClkWise(u8 StepType, u16 Angle)
{
	u16 Iteration_Num = 0;
	if(StepType == FullStep)
	{
		//Iteration_Num = (u16)(Angle/(float)0,1757)/4 ;
		Iteration_Num = (u16)(Angle / (float)0.1757) / 4;

		for(int counter = 0 ;counter <Iteration_Num; counter++)
		{
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,High);
			_delay_ms(10);

			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,High);
			_delay_ms(10);

			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,High);
			_delay_ms(10);

			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,Low);
			_delay_ms(10);

		}
	}
	else if (StepType == HalfStep)
	{

		Iteration_Num = (Angle/(float)0.08789)/4 ;
		for(int counter = 0 ;counter <Iteration_Num; counter++)
		{
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,High);
			_delay_ms(10);

			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,High);
			_delay_ms(10);

			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,High);
			_delay_ms(10);

			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,Low);
			_delay_ms(10);

		}
	}

}

void StepperMotorON_ClkWise(u8 StepType, u16 Angle)
{
	u16 Iteration_Num = 0;
	if(StepType == FullStep){
		//Iteration_Num = (u16)(Angle/(float)0.1757)/4 ;
		Iteration_Num = (u16)(Angle / (float)0.1757) / 4;

		for(int counter = 0 ;counter <Iteration_Num; counter++)
		{
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,Low);
			_delay_ms(10);

			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,High);
			_delay_ms(10);

			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,High);
			_delay_ms(10);

			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,High);
			_delay_ms(10);

		}
	}
	else if (StepType == HalfStep)
	{
		Iteration_Num = (Angle/(float)0.08789)/4 ;
		for(int counter = 0 ;counter <Iteration_Num; counter++)
		{
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,High);
			_delay_ms(10);

			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,High);
			_delay_ms(10);

			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,High);
			_delay_ms(10);

			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Blue,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,High);
			DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,Low);
			_delay_ms(10);

		}
	}
}
void StepperMotorOFF()
{
	DIO_SelectOutputTypeForPin(DIO_GroupD,DIO_Pin0,Low);
	DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Bink,Low);
	DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Yellow,Low);
	DIO_SelectOutputTypeForPin(DIO_GroupD,StepperMotor_Orange,Low);
}
