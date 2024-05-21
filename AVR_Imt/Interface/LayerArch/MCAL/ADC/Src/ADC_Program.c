/*
 * ADC_Program.c
 *
 *  Created on: May 10, 2024
 *      Author: 20110
 */

#include"../../../COMMON/Bitmath.h"
#include"../Header/ADC_Interface.h"
static u8 Prescaller =ADC_PrescalerMode;
static u8 IntrruptFlag = 0 ;


#if ADC_ModeSelect==AutoMode
static u8 sourceTrigger = ADC_TriggerSource ;

#endif


#if ADC_InterruptState==ADC_InterruptEnable
static void(*ADC_GlobalCallBack)(u16 DigitalVolt)=Null;
#endif

void ADC_Init()
{

	// ADCMUX
	//Reference Selection

#if ADC_RefernceSelection == ExternalAref
	ClrBit(ADC_ADMUX,ADC_REFS1);
	ClrBit(ADC_ADMUX,ADC_REFS0);

#elif ADC_RefernceSelection == AVCC
	ClrBit(ADC_ADMUX,ADC_REFS1);
	SetBit(ADC_ADMUX,ADC_REFS0);
#elif ADC_RefernceSelection == InternalAref
	SetBit(ADC_ADMUX,ADC_REFS1);
	SetBit(ADC_ADMUX,ADC_REFS0);
#else
#error "Invalid Option"
#endif



	//ADjustment
#if ADC_AdjustSelect == RightAdjust
	ClrBit(ADC_ADMUX,ADC_ADLAR);

#elif ADC_AdjustSelect == LeftAdjust
	SetBit(ADC_ADMUX,ADC_ADLAR);
#else
#error "Invalid Option"
#endif

	// Prescaler

	Prescaller &=  0x07;
	ADC_ADCSRA &= 0xF8;  // devision by 2 0x00
	ADC_ADCSRA |= Prescaller; // 0x01


	// ADCSRA
	// mode

#if ADC_ModeSelect == AutoTrigger
	SetBit(ADC_ADCSRA , ADC_ADATE);
	sourceTrigger &=0xE0;
	ADC_SFIOR &=0x1F;
	ADC_SFIOR |=sourceTrigger;
#elif ADC_ModeSelect == SingleMode
	ClrBit(ADC_ADCSRA , ADC_ADATE);
#else
#error "Wrong"
#endif



	//Intrrupt


#if ADC_IntrruptMode == ADC_InterruptEnable
	SetBit(ADC_ADCSRA,ADC_ADIE);
	IntrruptFlag = 1 ; // should be ADIF ?
#elif  ADC_IntrruptMode == ADC_Interruptdisable
	ClrBit(ADC_ADCSRA,ADC_ADIE);
	IntrruptFlag = 0 ;
#else
#error "Invalid Option"
#endif


	// Source mode
	//Enable for ADC


	SetBit(ADC_ADCSRA,ADC_ADEN);// Enable
#if ADC_ModeSelect==AutoTrigger
	if(sourceTrigger == FreeRunning)
	{
		SetBit(ADC_ADCSRA,ADC_ADSC);
	}
#endif


}

u16 ADC_get_DigitalValue(InputChannelSelection channel)
{




	channel &=   0x1F;
	ADC_ADMUX &= 0xE0;
	ADC_ADMUX |= channel;

	u8 flagState=0;
	u16 Digital_Value = 0;
#if ADC_ModeSelect == SingleMode
	SetBit(ADC_ADCSRA,ADC_ADSC);
#endif
do{
	flagState= GetBit(ADC_ADCSRA,ADC_ADIF);
}while(flagState == 0);

	Digital_Value = ADC_DATA;
	SetBit(ADC_ADCSRA,ADC_ADIF);
	return Digital_Value;

}
