/*******************************************************************************
* Copyright (C) 2019 China Micro Semiconductor Limited Company. All Rights Reserved.
*
* This software is owned and published by:
* CMS LLC, No 2609-10, Taurus Plaza, TaoyuanRoad, NanshanDistrict, Shenzhen, China.
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with CMS
* components. This software is licensed by CMS to be adapted only
* for use in systems utilizing CMS components. CMS shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. CMS is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/

/****************************************************************************/
/** \file adc1.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "adc1.h"
/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
*****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
*****************************************************************************/

/****************************************************************************/
/*	Local type definitions('typedef')
*****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
*****************************************************************************/


/****************************************************************************/
/*	Local function prototypes('static')
*****************************************************************************/

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/

/*****************************************************************************
 ** \brief	ADC1_ConfigRunMode
 **			????ADC????????
 ** \param [in] ConvertMode:(1)ADC1_CONVERT_SINGLE			
 **							(2)ADC1_CONVERT_CONTINUOUS
 **				ClkDiv :(1)ADC1_CLK_DIV_1
 **						(2)ADC1_CLK_DIV_2
 **						(3)ADC1_CLK_DIV_4
 **						(4)ADC1_CLK_DIV_8
 **						(5)ADC1_CLK_DIV_16
 **						(6)ADC1_CLK_DIV_32
 **						(7)ADC1_CLK_DIV_64
 **						(8)ADC1_CLK_DIV_128
 **				HoldTime:(1)ADC1_HOLD_3P5_CLK
 **						 (2)ADC1_HOLD_4P5_CLK
 **						 (3)ADC1_HOLD_6P5_CLK
 **						 (4)ADC1_HOLD_10P5_CLK
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_ConfigRunMode(uint32_t ConvertMode, uint32_t ClkDiv,uint32_t HoldTime)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->CON &= ~(ADC1_CON_ADCMS_Msk|ADC1_CON_ADCDIV_Msk|ADC1_CON_ADCSHT_Msk);
	ADC1->CON |= ConvertMode |  ClkDiv | HoldTime;	
	ADC1->LOCK = 0x00;
}

/*****************************************************************************
 ** \brief	ADC1_EnableScanChannel
 **			????ADC1????????
 ** \param [in] ChannelMask: ADC1_CH_0_MSK ~ ADC1_CH_30_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_EnableScanChannel(uint32_t ChannelMask)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->SCAN |= ChannelMask;
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_DisableScanChannel
 **			????ADC1????????
 ** \param [in] ChannelMask: ADC1_CH_0_MSK ~ ADC1_CH_30_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_DisableScanChannel(uint32_t ChannelMask)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->SCAN &= ~(ChannelMask);
	ADC1->LOCK = 0x00;	
}

/*****************************************************************************
 ** \brief	ADC1_SetAN30Channel
 **			????AN30??????????
 ** \param [in] AN30Channel: (1)ADC1_CH_30_BG 
 **							 (2)ADC1_CH_30_OP0O
 **							 (3)ADC1_CH_30_OP1O
 **							 (4)ADC1_CH_30_PGA0O
 **							 (5)ADC1_CH_30_PGA1O
 **							 (6)ADC1_CH_30_VREF_VSS
 **							 (7)ADC1_CH_30_VREF_VDD
 **							 (8)ADC1_CH_30_VSS
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_SetAN30Channel(uint32_t AN30Channel)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON &= ~(ADC1_CON_ADCICHS_Msk);
	ADC1->CON |= AN30Channel;		
	ADC1->LOCK = 0x00;		
}

/*****************************************************************************
 ** \brief	ADC1_GetResult
 **			????ADC1????????
 ** \param [in] Channel: ADC1_CH_0 ~ ADC1_CH_30
 ** \return  12 bits Value
 ** \note	
*****************************************************************************/
uint32_t ADC1_GetResult(uint32_t Channel)
{
	return(ADC1->DATA[Channel]);
}

/*****************************************************************************
 ** \brief	ADC1_EnableHardwareTrigger
 **			????????????ADC1????????
 ** \param [in] TriggerSource: (1)ADC1_TG_EXT_FALLING
 **							(2)ADC1_TG_EXT_RISING
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_EnableHardwareTrigger(uint32_t TriggerSource)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	switch(TriggerSource)
	{
		case ADC1_TG_EXT_FALLING:
		case ADC1_TG_EXT_RISING:
			ADC1->HWTG |= TriggerSource;
			break;
		default:
			break;
	}	
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_DisableHardwareTrigger
 **			????????????ADC1????????
 ** \param [in] TriggerSource: (1)ADC1_TG_EXT_FALLING
 **								(2)ADC1_TG_EXT_RISING
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_DisableHardwareTrigger(uint32_t TriggerSource)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	switch(TriggerSource)
	{
		case ADC1_TG_EXT_FALLING:
		case ADC1_TG_EXT_RISING:
			ADC1->HWTG &= ~(ADC1_HWTG_ADCEXTEN_Msk);
			break;
		default:
			break;
	}	
	ADC1->LOCK = 0x00;	
}

/*****************************************************************************
 ** \brief	ADC1_EnableCompare
 **			????ADC1????????
 ** \param [in]none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_EnableCompare(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->CMP0	|= ADC1_CMP0_ADCCMP0EN_Msk;
	ADC1->LOCK = 0x00;		
}
/*****************************************************************************
 ** \brief	ADC1_DisableCompare
 **			????ADC1????????
 ** \param [in] Compare : ADC1_CMP0 ??ADC1_CMP1
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_DisableCompare(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->CMP0	&= ~(ADC1_CMP0_ADCCMP0EN_Msk);
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_ConfigCompare
 **			????ADC1????????
 ** \param [in]  CmpMode:(1)ADC1_CMP_LESS_THAN_RESULT
 **						(2)ADC1_CMP_NOT_LESS_THAN_RESULT
 **				 CmpCount: 0x00~0xf  ????????????
 **				 CmpChannel: ADC1_CH_0 ~ ADC1_CH_30
 **				 CmpData : 12 bit ??????
 ** \return  none
 ** \note	????????????????ADCCMPxMCNT+1??????????ADC??????????
*****************************************************************************/
void ADC1_ConfigCompare( uint32_t CmpMode, uint32_t CmpCount,  
						uint32_t CmpChannel, uint32_t CmpData)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;
	ADC1->CMP0	&= ~(ADC1_CMP0_ADCCMP0COND_Msk | ADC1_CMP0_ADCCMP0MCNT_Msk|
							 ADC1_CMP0_ADCCMP0CHS_Msk | ADC1_CMP0_ADCCMP0DATA_Msk);
	ADC1->CMP0	|= CmpMode | ((0xf & CmpCount)<<ADC1_CMP0_ADCCMP0MCNT_Pos) | ((0x1f& CmpChannel)<<ADC1_CMP0_ADCCMP0CHS_Pos)|
							(0xfff & CmpData) ;
	ADC1->LOCK = 0x00;		
}

/*****************************************************************************
 ** \brief	ADC1_GetCompareResult
 **			????ADC1??????????
 ** \param [in] Compare : ADC1_CMP0 ??ADC1_CMP1
 ** \return  1 /0
 ** \note	
*****************************************************************************/
uint32_t ADC1_GetCompareResult(uint32_t Compare)
{
	return((ADC1->CMP0 & ADC1_CMP0_ADCCMP0O_Msk)? 1:0);
}


/*****************************************************************************
 ** \brief	ADC1_Start
 **			????ADC1
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_Start(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON |= ADC1_CON_ADCEN_Msk;
	ADC1->LOCK = 0x00;		
}
/*****************************************************************************
 ** \brief	ADC1_Stop
 **			????ADC1
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_Stop(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON &= ~(ADC1_CON_ADCEN_Msk);
	ADC1->LOCK = 0x00;		
}

/*****************************************************************************
 ** \brief	ADC1_StartAdjust
 **			????ADC1????
 ** \param [in] none
** \return  none
 ** \note	
*****************************************************************************/
void ADC1_StartAdjust(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON2 |= (ADC1_CON2_ADCCALEN_Msk);
	ADC1->LOCK = 0x00;	
	while(ADC1->CON2 & ADC1_CON2_ADCCALEN_Msk);
}

/*****************************************************************************
 ** \brief	ADC1_EnableAdjust
 **			????ADC1??????????????ADC????
 ** \param [in] none
 ** \return   none
 ** \note	
*****************************************************************************/
void ADC1_EnableAdjust(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON2 &= ~(ADC1_CON2_ADCCALCONV_Msk);
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_DisableAdjust
 **			????ADC1??????????????ADC????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_DisableAdjust(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON2 |= (ADC1_CON2_ADCCALCONV_Msk);
	ADC1->LOCK = 0x00;
}

/*****************************************************************************
 ** \brief	ADC1_EnableReset
 **			????ADC1
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_EnableReset(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON |= ADC1_CON_ADCRST_Msk;
	ADC1->LOCK = 0x00;		
}

/*****************************************************************************
 ** \brief	ADC1_GetConvertErrorFlag
 **			????ADC1 ??????????????
 ** \param [in] none
 ** \return  1 ??????????????	0????????
 ** \note	
*****************************************************************************/
uint32_t ADC1_GetConvertErrorFlag(void)
{
	return((ADC1->CON & ADC1_CON_ADCCONVER_Msk)? 1:0);	
}
/*****************************************************************************
 ** \brief	ADC1_GetAdjustErrorFlag
 **			????ADC1 ??????????????
 ** \param [in] none
 ** \return  1 ??????????????	0????????
 ** \note	
*****************************************************************************/
uint32_t ADC1_GetAdjustErrorFlag(void)
{
	return((ADC1->CON & ADC1_CON_ADCCALERR_Msk)? 1:0);	
}

/*****************************************************************************
 ** \brief	ADC1_ClearConvertErrorFlag
 **			????ADC1 ??????????????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_ClearConvertErrorFlag(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON |= ADC1_CON_ADCCONVERRCLR_Msk;
	ADC1->LOCK = 0x00;		
}
/*****************************************************************************
 ** \brief	ADC1_ClearAdjustErrorFlag
 **			????ADC1 ??????????????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_ClearAdjustErrorFlag(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->CON |= ADC1_CON_ADCCALERRCLR_Msk;
	ADC1->LOCK = 0x00;	
}

/*****************************************************************************
 ** \brief	ADC1_EnableCompareInt
 **			????ADC1????????
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void ADC1_EnableCompareInt(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->IMSC |= ADC1_IMSC_IMSC31_Msk;
	ADC1->LOCK = 0x00;		
}
/*****************************************************************************
 ** \brief	ADC1_DisableCompareInt
 **			????ADC1????????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_DisableCompareInt(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->IMSC &= ~(ADC1_IMSC_IMSC31_Msk);
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_GetCompareIntFlag
 **			????ADC1??????????????????????????????
 ** \param [in] none
 ** \return  1:???????????????????? 0????????
 ** \note	
*****************************************************************************/
uint32_t ADC1_GetCompareIntFlag(void)
{
	return((ADC1->MIS & ADC1_MIS_MIS31_Msk)? 1:0);
}
/*****************************************************************************
 ** \brief	ADC1_ClearCompareIntFlag
 **			????ADC1??????????????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_ClearCompareIntFlag(void)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->ICLR |= (ADC1_ICLR_ICLR31_Msk);
	ADC1->LOCK = 0x00;	
}

/*****************************************************************************
 ** \brief	ADC1_EnableChannelInt
 **			????ADC1????n????
 ** \param [in]ChannelMask: ADC1_CH_0_MSK ~ ADC1_CH_30_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_EnableChannelInt(uint32_t ChannelMask)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->IMSC |= ChannelMask ;
	ADC1->LOCK = 0x00;	
}
/*****************************************************************************
 ** \brief	ADC1_DisableChannelInt
 **			????ADC1????n????
 ** \param [in] ChannelMask: ADC1_CH_0_MSK ~ ADC1_CH_30_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_DisableChannelInt(uint32_t ChannelMask)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->IMSC &= ~(ChannelMask);
	ADC1->LOCK = 0x00;
}
/*****************************************************************************
 ** \brief	ADC1_GetChannelIntFlag
 **			????ADC1????n??????????????????????????
 ** \param [in] Channel:ADC1_CH_0 ~ ADC1_CH_30
 ** \return  1:???????????????????? 0????????
 ** \note	
*****************************************************************************/
uint32_t ADC1_GetChannelIntFlag(uint32_t Channel)
{
	return((ADC1->MIS & (0x1UL<<Channel))? 1:0);	
}
/*****************************************************************************
 ** \brief	ADC1_ClearChannelIntFlag
 **			????ADC1????n??????????
 ** \param [in] Channel:ADC1_CH_0 ~ ADC1_CH_30
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC1_ClearChannelIntFlag(uint32_t Channel)
{
	ADC1->LOCK = ADC1_LOCK_WRITE_KEY;	
	ADC1->ICLR |= (0x01UL<< Channel);
	ADC1->LOCK = 0x00;			
}

/*****************************************************************************
 ** \brief	ADCInit
 **			????????ADC1????
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADCInit(void)
{
	/*
	(1)????ADC1????
	*/
	SYS_EnablePeripheralClk(SYS_CLK_ADC1_MSK);
	ADC1_ConfigRunMode(ADC1_CONVERT_SINGLE,ADC1_CLK_DIV_8,ADC1_HOLD_10P5_CLK);			/*??????????????*/

	/*
	(2)????ADC1????????
	*/	
	ADC1_EnableScanChannel(ADC1_CH_0_MSK);						/*ADC1_CH_13_MSK  ??????????????AN0 */	
	SYS_SET_IOCFG(IOP00CFG,SYS_IOCFG_P00_AN0);					/*????P0??????????*/
	
//	/*
//	(4)????ADC1????
//	*/		
//	
//	ADC1_EnableChannelInt(ADC1_CH_0_MSK);						/*??AN0????????*/	
//	NVIC_EnableIRQ(ADC1_IRQn);
//	/*
//	(5)??????????
//	*/	
//	NVIC_SetPriority(ADC1_IRQn,2);					/*??????0~3?? 0??????3????*/	
	/*
	(6)????ADC1
	*/		
	ADC1_Start();
	/*
	(7)????ADC1????
	*/		
	ADC1_StartAdjust();
	/*
	(8)????ADC1????????ADC????
	*/	
	ADC1_EnableAdjust();
}



