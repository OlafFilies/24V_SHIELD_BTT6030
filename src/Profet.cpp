/*!
 * \name        
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     0.1.1
 * \brief       
 * \details
 * 
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 * disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "Profet.h"

Profet::Profet()
{
}

Profet::~Profet()
{

}

Profet::begin()
{
    init();
    initGPIO(Profet0);
    initGPIO(Profet1);
    initGPIO(Profet2);
}

Profet::end()
{
    
}


/**
 * @brief isr_profet0() - Interrupt Service Routine PROFET0
 *
 * handles the period and compare events of the PWM for the PROFET0
 *
 * -PERIOD: turn off channel 1
 * -COMPARE: turn on channel 1
 */
void isr_profet0(void){
	if(PWM_GetInterruptStatus(&PWM_PROFET0_C1, PWM_INTERRUPT_PERIODMATCH)){
		PWM_ClearEvent(&PWM_PROFET0_C1, PWM_INTERRUPT_PERIODMATCH);
		//PERIOD:
		Profet0.channel1.on = FALSE;
	}
	if(PWM_GetInterruptStatus(&PWM_PROFET0_C1, PWM_INTERRUPT_COMPAREMATCH)){
		PWM_ClearEvent(&PWM_PROFET0_C1, PWM_INTERRUPT_COMPAREMATCH);
		//Compare:
		Profet0.channel1.on = TRUE;
	}
}



/**
 * @brief isr_profet1() - Interrupt Service Routine PROFET 1
 *
 * handles the period and compare events of the PWMs for the PROFET 1
 *
 * -PERIOD_c0: turn off channel 0
 * -COMPARE_c0: turn on channel 0
 * -PERIOD_c1: turn off channel 1
 * -COMPARE_c1: turn on channel 1
 */
void isr_profet1(void){
	if(PWM_GetInterruptStatus(&PWM_PROFET1_C0, PWM_INTERRUPT_COMPAREMATCH)){
		PWM_ClearEvent(&PWM_PROFET1_C0, PWM_INTERRUPT_COMPAREMATCH);
		//Comparec0:
		Profet1.channel0.on = TRUE;
	}
	if(PWM_GetInterruptStatus(&PWM_PROFET1_C0, PWM_INTERRUPT_PERIODMATCH)){
		PWM_ClearEvent(&PWM_PROFET1_C0, PWM_INTERRUPT_PERIODMATCH);
		//PERIODc0:
		Profet1.channel0.on = FALSE;
	}
	if(PWM_GetInterruptStatus(&PWM_PROFET1_C1, PWM_INTERRUPT_COMPAREMATCH)){
		PWM_ClearEvent(&PWM_PROFET1_C1, PWM_INTERRUPT_COMPAREMATCH);
		//Comparec1:
		DIGITAL_IO_SetOutputHigh(&IN1_P1);
		Profet1.channel1.on = TRUE;
	}
	if(PWM_GetInterruptStatus(&PWM_PROFET1_C1, PWM_INTERRUPT_PERIODMATCH)){
		PWM_ClearEvent(&PWM_PROFET1_C1, PWM_INTERRUPT_PERIODMATCH);
		//PERIODc1:
		DIGITAL_IO_SetOutputLow(&IN1_P1);
		Profet1.channel1.on = FALSE;
	}

}


/**
 * @brief isr_profet2() - Interrupt Service Routine PROFET 2
 *
 * handles the period and compare events of the PWM for the PROFET 2
 *
 * -PERIOD: turn off
 * -COMPARE: turn on
 */
void isr_profet2(void){
	if(PWM_GetInterruptStatus(&PWM_PROFET2, PWM_INTERRUPT_PERIODMATCH)){
		PWM_ClearEvent(&PWM_PROFET2, PWM_INTERRUPT_PERIODMATCH);
		//PERIOD:
		DIGITAL_IO_SetOutputLow(&IN_P2);
		Profet2.channel0.on = FALSE;
	}
	if(PWM_GetInterruptStatus(&PWM_PROFET2, PWM_INTERRUPT_COMPAREMATCH)){
		PWM_ClearEvent(&PWM_PROFET2, PWM_INTERRUPT_COMPAREMATCH);
		//Compare:
		DIGITAL_IO_SetOutputHigh(&IN_P2);
		Profet2.channel0.on = TRUE;
	}
}



/**
* @brief isr_adcFinished() - Interrupt Service Routine for the ADC
*
* This interrupt is triggered when the ADC finished conversion of one channel.
* Since the XMC1100 has only one global Register for all ADC measurements. It's necessary to check which channel was converted.
* The ADC is configured to continuously convert the channels, but the result register is only overwritten after a read.
* Here is the mapping between the measurement channel and the PROFET:
* channel 0 - IS of PROFET0
* channel 1 - IS of PROFET1
* channel 2 - IS of PROFET2
*
* When a channel is converted and its corresponding PROFET channel is switched on, the load current is calculated out of the ADC result and stored in the corresponding global ProfetStatus variable.
* This value could then be used to implement a protection strategy. e.g. turn the channel off after an over current shutdown happened x times in a row.
*
*/
void isr_adcFinished(void){
	static bool dselen = FALSE;
	static uint8_t i = 0;
	uint8_t channel;
	uint32_t convres, vis, iis;
	
	uint32_t result = ADC_MEASUREMENT_GetDetailedResult(&SENSE_MEASUREMENT);
	channel = (result & VADC_GLOBRES_CHNR_Msk) >> VADC_GLOBRES_CHNR_Pos;
	convres = (result & VADC_GLOBRES_RESULT_Msk) >>((uint32_t)SENSE_MEASUREMENT.iclass_config_handle->conversion_mode_standard * (uint32_t)2);
	
	
	switch(channel){
	case 0: //PROFET0
		if(dselen && Profet0.channel1.on){
			convres = convres*100000; //increase number to avoid losing important digits during division
			vis = convres/ADCFACT;	  //Voltage from ADCresult
			iis = vis/RIS; //IS current = Vis / RIS; I = U/R)
			Profet0.channel1.current = (iis*Profet0.kilis)/100; //Iis * kilis = Iout divide by 100 to get it in mA
		}else if(Profet0.channel0.on){
			convres = convres*100000; //increase number to avoid losing important digits during division
			vis = convres/ADCFACT;	//Voltage from ADCresult
			iis = vis/RIS; //IS current = Vis / RIS; I = U/R)
			Profet0.channel0.current = (iis*Profet0.kilis)/100; //Iis * kilis = Iout divide by 100 to get it in mA
		}
		break;
	case 1: //PROFET1
		if(dselen && Profet1.channel1.on){
			convres = convres*100000; //increase number to avoid losing important digits during division
			vis = convres/ADCFACT;	  //Voltage from ADCresult
			iis = vis/RIS; //IS current = Vis / RIS; I = U/R)
			Profet1.channel1.current = (iis*Profet1.kilis)/100; //Iis * kilis = Iout divide by 100 to get it in mA
		}else if(Profet1.channel0.on){
			convres = convres*100000; //increase number to avoid losing important digits during division
			vis = convres/ADCFACT;
			iis = vis/RIS; //IS current = Vis / RIS; I = U/R)
			Profet1.channel0.current = (iis*Profet1.kilis)/100; //Iis * kilis = Iout divide by 100 to get it in mA
		}
		break;
	case 2: //PROFET2
		if(Profet2.channel0.on){
			convres = convres*100000; //increase number to avoid losing important digits during division
			vis = convres/ADCFACT; //Voltage from ADCresult
			iis = vis/RIS; //IS current = Vis / RIS; I = U/R)
			Profet2.channel0.current = (iis*Profet2.kilis)/100; //Iis * kilis = Iout divide by 100 to get it in mA
		}
	}

	if(i++ >= 2){ // 3 Results measured (PROFET0..2) toggle the DSEL Pins to measure now the other channels.
				  // DSEL high: channel 1 of PROFET0&1, DSEL low channel 0 of PROFET0&1. PROFET2 has only one channel and therefore no DSEL PIN.
		dselen = !dselen;
		i = 0;
		if(dselen){
			DIGITAL_IO_SetOutputHigh(&DSEL_P0);
			DIGITAL_IO_SetOutputHigh(&DSEL_P1);
		}else{
			DIGITAL_IO_SetOutputLow(&DSEL_P0);
			DIGITAL_IO_SetOutputLow(&DSEL_P1);
		}
	}
}