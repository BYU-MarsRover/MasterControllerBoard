/*******************************************************************************
* File Name: UART_2_SPI_UART_PVT.h
* Version 1.20
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_PVT_UART_2_H)
#define CY_SCB_SPI_UART_PVT_UART_2_H

#include "UART_2_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if(UART_2_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  UART_2_rxBufferHead;
    extern volatile uint32  UART_2_rxBufferTail;
    extern volatile uint8   UART_2_rxBufferOverflow;
#endif /* (UART_2_INTERNAL_RX_SW_BUFFER_CONST) */

#if(UART_2_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  UART_2_txBufferHead;
    extern volatile uint32  UART_2_txBufferTail;
#endif /* (UART_2_INTERNAL_TX_SW_BUFFER_CONST) */

#if(UART_2_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 UART_2_rxBufferInternal[UART_2_RX_BUFFER_SIZE];
#endif /* (UART_2_INTERNAL_RX_SW_BUFFER) */

#if(UART_2_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 UART_2_txBufferInternal[UART_2_TX_BUFFER_SIZE];
#endif /* (UART_2_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

#if(UART_2_SCB_MODE_SPI_CONST_CFG)
    void UART_2_SpiInit(void);
#endif /* (UART_2_SCB_MODE_SPI_CONST_CFG) */

#if(UART_2_SPI_WAKE_ENABLE_CONST)
    void UART_2_SpiSaveConfig(void);
    void UART_2_SpiRestoreConfig(void);
#endif /* (UART_2_SPI_WAKE_ENABLE_CONST) */

#if(UART_2_SCB_MODE_UART_CONST_CFG)
    void UART_2_UartInit(void);
#endif /* (UART_2_SCB_MODE_UART_CONST_CFG) */

#if(UART_2_UART_WAKE_ENABLE_CONST)
    void UART_2_UartSaveConfig(void);
    void UART_2_UartRestoreConfig(void);
#endif /* (UART_2_UART_WAKE_ENABLE_CONST) */

/* Interrupt processing */
#define UART_2_SpiUartEnableIntRx(intSourceMask)  UART_2_SetRxInterruptMode(intSourceMask)
#define UART_2_SpiUartEnableIntTx(intSourceMask)  UART_2_SetTxInterruptMode(intSourceMask)
uint32  UART_2_SpiUartDisableIntRx(void);
uint32  UART_2_SpiUartDisableIntTx(void);

#endif /* (CY_SCB_SPI_UART_PVT_UART_2_H) */


/* [] END OF FILE */
