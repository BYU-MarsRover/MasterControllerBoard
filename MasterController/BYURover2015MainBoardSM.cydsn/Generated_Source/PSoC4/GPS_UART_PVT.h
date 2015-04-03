/*******************************************************************************
* File Name: .h
* Version 1.20
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component.
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

#if !defined(CY_SCB_PVT_GPS_UART_H)
#define CY_SCB_PVT_GPS_UART_H

#include "GPS_UART.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define GPS_UART_SetI2CExtClkInterruptMode(interruptMask) GPS_UART_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define GPS_UART_ClearI2CExtClkInterruptSource(interruptMask) GPS_UART_CLEAR_INTR_I2C_EC(interruptMask)
#define GPS_UART_GetI2CExtClkInterruptSource()                (GPS_UART_INTR_I2C_EC_REG)
#define GPS_UART_GetI2CExtClkInterruptMode()                  (GPS_UART_INTR_I2C_EC_MASK_REG)
#define GPS_UART_GetI2CExtClkInterruptSourceMasked()          (GPS_UART_INTR_I2C_EC_MASKED_REG)

#if(!GPS_UART_CY_SCBIP_V1_I2C_ONLY)
/* APIs to service INTR_SPI_EC register */
#define GPS_UART_SetSpiExtClkInterruptMode(interruptMask) GPS_UART_WRITE_INTR_SPI_EC_MASK(interruptMask)
#define GPS_UART_ClearSpiExtClkInterruptSource(interruptMask) GPS_UART_CLEAR_INTR_SPI_EC(interruptMask)
#define GPS_UART_GetExtSpiClkInterruptSource()                 (GPS_UART_INTR_SPI_EC_REG)
#define GPS_UART_GetExtSpiClkInterruptMode()                   (GPS_UART_INTR_SPI_EC_MASK_REG)
#define GPS_UART_GetExtSpiClkInterruptSourceMasked()           (GPS_UART_INTR_SPI_EC_MASKED_REG)
#endif /* (!GPS_UART_CY_SCBIP_V1_I2C_ONLY) */

#if(GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void GPS_UART_SetPins(uint32 mode, uint32 subMode, uint32 uartTxRx);
#endif /* (GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if !defined (CY_REMOVE_GPS_UART_CUSTOM_INTR_HANDLER)
    extern cyisraddress GPS_UART_customIntrHandler;
#endif /* !defined (CY_REMOVE_GPS_UART_CUSTOM_INTR_HANDLER) */

extern GPS_UART_BACKUP_STRUCT GPS_UART_backup;

#if(GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common config vars */
    extern uint8 GPS_UART_scbMode;
    extern uint8 GPS_UART_scbEnableWake;
    extern uint8 GPS_UART_scbEnableIntr;

    /* I2C config vars */
    extern uint8 GPS_UART_mode;
    extern uint8 GPS_UART_acceptAddr;

    /* SPI/UART config vars */
    extern volatile uint8 * GPS_UART_rxBuffer;
    extern uint8   GPS_UART_rxDataBits;
    extern uint32  GPS_UART_rxBufferSize;

    extern volatile uint8 * GPS_UART_txBuffer;
    extern uint8   GPS_UART_txDataBits;
    extern uint32  GPS_UART_txBufferSize;

    /* EZI2C config vars */
    extern uint8 GPS_UART_numberOfAddr;
    extern uint8 GPS_UART_subAddrSize;
#endif /* (GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*  Conditional Macro
****************************************/

#if(GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Define run time operation mode */
    #define GPS_UART_SCB_MODE_I2C_RUNTM_CFG     (GPS_UART_SCB_MODE_I2C      == GPS_UART_scbMode)
    #define GPS_UART_SCB_MODE_SPI_RUNTM_CFG     (GPS_UART_SCB_MODE_SPI      == GPS_UART_scbMode)
    #define GPS_UART_SCB_MODE_UART_RUNTM_CFG    (GPS_UART_SCB_MODE_UART     == GPS_UART_scbMode)
    #define GPS_UART_SCB_MODE_EZI2C_RUNTM_CFG   (GPS_UART_SCB_MODE_EZI2C    == GPS_UART_scbMode)
    #define GPS_UART_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (GPS_UART_SCB_MODE_UNCONFIG == GPS_UART_scbMode)

    /* Define wakeup enable */
    #define GPS_UART_SCB_WAKE_ENABLE_CHECK        (0u != GPS_UART_scbEnableWake)
#endif /* (GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG) */

#endif /* (CY_SCB_PVT_GPS_UART_H) */


/* [] END OF FILE */
