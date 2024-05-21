/*
 * Sensors.c
 *
 *  Created on: May 11, 2024
 *      Author: 20110
 */
/*#include"util/delay.h"
#include"MCAL/DIO/Header/DIO_Interface.h"
#include"MCAL/ADC/Header/ADC_Interface.h"
#include"HAL/Lcd/Header/Lcd_Interface.h"
void main()
{

	// Set sensor pin direction as input
	DIO_SelectDirectionForPin(DIO_GroupA,4,Input);

	// Set Leds pins direction as output

	DIO_SelectDirectionForPin(DIO_GroupB,DIO_Pin0,Output);
	DIO_SelectDirectionForPin(DIO_GroupB,DIO_Pin1,Output);
	DIO_SelectDirectionForPin(DIO_GroupB,DIO_Pin2,Output);


	ADC_Init();
	Lcd_init();

	u16 Digital_Volt = 0;
	u16 Temp_Value   = 0 ;
	u16 Analog_Volt  = 0 ;
	//u16 value = "hello";


	while(1)
	{
		Digital_Volt =ADC_get_DigitalValue(SingleEndedInput0); // 0
		Analog_Volt = ((u32) Digital_Volt *5000UL)/1024UL;
		Temp_Value = Analog_Volt /10 ;
		//Lcd_SendString(&value);

		if (Temp_Value <= 25 )
		{
			DIO_SelectOutputTypeForPin(DIO_GroupB,DIO_Pin0,High);
			DIO_SelectOutputTypeForPin(DIO_GroupB,DIO_Pin1,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupB,DIO_Pin2,Low);
//			_delay_ms(1000);

		}
		else if (Temp_Value > 60)
		{
			DIO_SelectOutputTypeForPin(DIO_GroupB,DIO_Pin0,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupB,DIO_Pin1,High);
			DIO_SelectOutputTypeForPin(DIO_GroupB,DIO_Pin2,Low);

//			_delay_ms(1000);
		}
		else if (Temp_Value >25 && Temp_Value <=40 )
		{
			DIO_SelectOutputTypeForPin(DIO_GroupB,DIO_Pin0,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupB,DIO_Pin1,Low);
			DIO_SelectOutputTypeForPin(DIO_GroupB,DIO_Pin2,High);
			//			_delay_ms(1000);
		}

	}

}*/
