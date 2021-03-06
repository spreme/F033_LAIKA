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
/** \file uart.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "uart.h"
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
 ** \brief	UART_ConfigRunMode
 **			????????????????????
 ** \param [in] uart: UART0??UART1
 **				Baudrate:??????
 **				WordLength:(1)UART_WLS_5
 **							(2)UART_WLS_6
 **							(3)UART_WLS_7
 **							(4)UART_WLS_8
 **				Parity:	(1)UART_PARITY_NONE
 **						(2)UART_PARITY_ODD
 **						(3)UART_PARITY_EVEN
 **						(4)UART_PARITY_FORCE_1
 **					 	(5)UART_PARITY_FORCE_0
 **				StopBit:(1)UART_STOP_BIT_1
 **						(2)UART_STOP_BIT_2
 ** \return  none
 ** \note	
*****************************************************************************/
void UART_ConfigRunMode(UART_T* uart,uint32_t Baudrate,uint32_t WordLength, 
						uint32_t Parity, uint32_t StopBit)
{
	uart->LCR &= ~(UART_LCR_WLS_Msk | UART_LCR_SBS_Msk|UART_LCR_PEN_Msk|UART_LCR_PSEL_Msk);
	uart->LCR |= WordLength | Parity | StopBit;
	uart->DLR = SystemAPBClock /16/Baudrate;
}

/*****************************************************************************
 ** \brief	UART_WriteTHR
 **			????????????????
 ** \param [in] uart: UART0??UART1
 **				value: 8bit
 ** \return  none
 ** \note	
*****************************************************************************/
void UART_WriteTHR(UART_T* uart, uint32_t value)
{
	uart->THR = value;
}
/*****************************************************************************
 ** \brief	UART_ReadRBR
 **			????????????????
 ** \param [in] uart: UART0??UART1
 ** \return  8bit data
 ** \note	
*****************************************************************************/
uint32_t  UART_ReadRBR(UART_T* uart)
{
	return (uart->RBR);
}

/*****************************************************************************
 ** \brief	UART_EnableCTSInt
 **			????CTS????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_EnableCTSInt(UART_T* uart)
{
	uart->IER |= UART_IER_CTSIE_Msk;
}

/*****************************************************************************
 ** \brief	UART_DisableCTSInt
 **			????CTS????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_DisableCTSInt(UART_T* uart)
{
	uart->IER &= ~(UART_IER_CTSIE_Msk);
}
/*****************************************************************************
 ** \brief	UART_EnableRTSInt
 **			????RTS????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_EnableRTSInt(UART_T* uart)
{
	uart->IER |= UART_IER_RTSIE_Msk;
}
/*****************************************************************************
 ** \brief	UART_DisableRTSInt
 **			????RTS????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_DisableRTSInt(UART_T* uart)
{
	uart->IER &= ~(UART_IER_RTSIE_Msk);
}

/*****************************************************************************
 ** \brief	UART_EnableXOFInt
 **			????XOFF????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_EnableXOFInt(UART_T* uart)
{
	uart->IER |= UART_IER_XOFIE_Msk;
}
/*****************************************************************************
 ** \brief	UART_DisableXOFInt
 **			????XOF????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_DisableXOFInt(UART_T* uart)
{
	uart->IER &= ~(UART_IER_XOFIE_Msk);
}

/*****************************************************************************
 ** \brief	UART_EnableModemInt
 **			????Modem????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_EnableModemInt(UART_T* uart)
{
	uart->IER |= UART_IER_MDSIE_Msk;
}
/*****************************************************************************
 ** \brief	UART_DisableModemInt
 **			????Modem????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_DisableModemInt(UART_T* uart)
{
	uart->IER &= ~(UART_IER_MDSIE_Msk);
}

/*****************************************************************************
 ** \brief	UART_EnableRxLineInt
 **			??????????????????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_EnableRxLineInt(UART_T* uart)
{
	uart->IER |= UART_IER_RLSIE_Msk;
}

/*****************************************************************************
 ** \brief	UART_DisableRxLineInt
 **			??????????????????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_DisableRxLineInt(UART_T* uart)
{
	uart->IER &= ~(UART_IER_RLSIE_Msk);
}

/*****************************************************************************
 ** \brief	UART_EnableTHREInt
 **			????????????????????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_EnableTHREInt(UART_T* uart)
{
	uart->IER |=UART_IER_THREIE_Msk;
}
/*****************************************************************************
 ** \brief	UART_DisableTHREInt
 **			????????????????????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_DisableTHREInt(UART_T* uart)
{
	uart->IER &= ~(UART_IER_THREIE_Msk);
}
/*****************************************************************************
 ** \brief	UART_EnableRBRInt
 **			????????????????????????????????????????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void  UART_EnableRBRInt(UART_T* uart)
{
	uart->IER |= UART_IER_RBRIE_Msk;
}
/*****************************************************************************
 ** \brief	UART_DisableRBRInt
 **			????????????????????????????????????????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void  UART_DisableRBRInt(UART_T* uart)
{
	uart->IER &= ~(UART_IER_RBRIE_Msk);	
}


/*****************************************************************************
 ** \brief	UART_EnableAuto
 **			????xx????????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void  UART_EnableAuto(UART_T* uart)
{
	uart->EFR |= UART_EFR_AUTOIEN_Msk;
}
/*****************************************************************************
 ** \brief	UART_DisableAuto
 **			????xx????????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void  UART_DisableAuto(UART_T* uart)
{
	uart->EFR &= ~(UART_EFR_AUTOIEN_Msk);
}

/*****************************************************************************
 ** \brief	UART_EnableFIFO
 **			????FIFO????
 ** \param [in] uart: UART0??UART1
 ** 			TxLevel: (1)FIFO_L0_1BYTE (2)FIFO_L1_4BYTE (3)FIFO_L2_8BYTE (4)FIFO_L3_14BYTE
 ** 			RxLevel: (1)FIFO_L0_1BYTE (2)FIFO_L1_4BYTE (3)FIFO_L2_8BYTE (4)FIFO_L3_14BYTE
 **				TxFIFOReset: (1)FIFO_RST_EN (2)FIFO_RST_DIS
 **				RxFIFOReset: (1)FIFO_RST_EN (2)FIFO_RST_DIS
 ** \return  none
 ** \note	FCR????????????????????????FCR??????????????
*****************************************************************************/
void UART_EnableFIFO(UART_T* uart, uint32_t TxFIFOLvel, uint32_t RxFIFOLvel, uint32_t TxFIFOReset, uint32_t RxFIFOReset)
{
	uart->FCR = (RxFIFOLvel<<UART_FCR_RXTL_Pos) |(TxFIFOLvel<<UART_FCR_TXTL_Pos)|(TxFIFOReset<<UART_FCR_TXFIFORST_Pos)|(RxFIFOReset<<UART_FCR_RXFIFORST_Pos)| UART_FCR_FIFOEN_Msk;
}
/*****************************************************************************
 ** \brief	UART_DisableFIFO
 **			????FIFO????
 ** \param [in] uart: UART0??UART1
 ** \return  none
 ** \note	
*****************************************************************************/
void UART_DisableFIFO(UART_T* uart)
{
	uart->FCR = 0;
}

/*****************************************************************************
 ** \brief	UART_EnableRTS
**			??????????????????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void  UART_EnableRTS(UART_T* uart)
{
	uart->EFR |= UART_EFR_AUTORTS_Msk;
}
/*****************************************************************************
 ** \brief	UART_DisableRTS
 **			??????????????????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void  UART_DisableRTS(UART_T* uart)
{
	uart->EFR &= ~(UART_EFR_AUTORTS_Msk);
}
/*****************************************************************************
 ** \brief	UART_EnableCTS
**			??????????????????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void  UART_EnableCTS(UART_T* uart)
{
	uart->EFR |= UART_EFR_AUTOCTS_Msk;
}

/*****************************************************************************
 ** \brief	UART_DisableCTS
 **			??????????????????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void  UART_DisableCTS(UART_T* uart)
{
	uart->EFR &= ~(UART_EFR_AUTOCTS_Msk);
}
/*****************************************************************************
 ** \brief	UART_GetCTSState
 **			????CTS????????????
 ** \param [in] uart: UART0??UART1
 ** \return 0????????   1????????
 ** \note	
*****************************************************************************/
uint32_t  UART_GetCTSState(UART_T* uart)
{
	return((uart->MSR & UART_MSR_CTS_Msk) ? 1:0);
}

/*****************************************************************************
 ** \brief	UART_RTSSet
 **			RTS????????????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_RTSSet(UART_T* uart)
{
	uart->MCR &= ~(UART_MCR_RTS_Msk);
}
/*****************************************************************************
 ** \brief	UART_RTSClean
 **			RTS????????????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_RTSClean(UART_T* uart)
{
	uart->MCR |= UART_MCR_RTS_Msk;
}

/*****************************************************************************
 ** \brief	UART_SetXON1AndXOFF1
 **			????XON1??XOFF1
 ** \param [in] uart: UART0??UART1
 **				Xon1 ??8????
 **				Xoff1: 8????
 ** \return none
 ** \note	
*****************************************************************************/
void UART_SetXON1AndXOFF1(UART_T* uart, uint8_t Xon1, uint8_t Xoff1)
{
	uart->XON1 = Xon1;
	uart->XOFF1 = Xoff1;
}

/*****************************************************************************
 ** \brief	UART_SetXON2AndXOFF2
 **			RTS????????????
 ** \param [in] uart: UART0??UART1
 **				Xon2 ??8????
 **				Xoff2: 8????
 ** \return none
 ** \note	
*****************************************************************************/
void UART_SetXON2AndXOFF2(UART_T* uart, uint8_t Xon2, uint8_t Xoff2)
{
	uart->XON2 = Xon2;
	uart->XOFF2 = Xoff2;
}
/*****************************************************************************
 ** \brief	UART_EnableXONAndXOFF
 **			????XON_XOFF????
 ** \param [in] uart: UART0??UART1
 **				Mode: (1)UART_USE_XON1_XOFF1
 **					  (2)UART_USE_XON2_XOFF2
 **					  (3)UART_USE_BOTH_XON_XOFF
 **						?????????????????????????????? ?????? XON1 ??????
 **                     ???????????? XON2 ???????? XON ?????? ????????????????????????????
 **                     ?????????? ?? XOFF1 ?????????????????? XOFF2 ???????? XOFF ??????
 ** \return none
 ** \note	
*****************************************************************************/
void UART_EnableXONAndXOFF(UART_T* uart, uint32_t Mode)
{
	uart->EFR  &= ~(UART_EFR_RXSWFC_Msk);
	uart->EFR |= Mode;
}
/*****************************************************************************
 ** \brief	UART_DisableXONAndXOFF
 **			????XON_XOFF????
 ** \param [in] uart: UART0??UART1
 ** \return none
 ** \note	
*****************************************************************************/
void UART_DisableXONAndXOFF(UART_T* uart)
{
	uart->EFR  &= ~(UART_EFR_RXSWFC_Msk);
}
/*****************************************************************************
 ** \brief	UART_GetXONAndXOFFState
 **			????XON??XOFF????
 ** \param [in] uart: UART0??UART1
 ** \return 0????????XON????  1????????XOFF????
 ** \note	
*****************************************************************************/
uint32_t  UART_GetXONAndXOFFState(UART_T* uart)
{
	return((uart->MCR & UART_MCR_XOFFS_Msk) ? 1:0);
}

