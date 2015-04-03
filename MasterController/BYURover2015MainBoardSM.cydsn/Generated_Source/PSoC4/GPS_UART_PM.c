/*******************************************************************************
* File Name: GPS_UART_PM.c
* Version 1.20
*
* Description:
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "GPS_UART.h"
#include "GPS_UART_PVT.h"

#if(GPS_UART_SCB_MODE_I2C_INC)
    #include "GPS_UART_I2C_PVT.h"
#endif /* (GPS_UART_SCB_MODE_I2C_INC) */

#if(GPS_UART_SCB_MODE_EZI2C_INC)
    #include "GPS_UART_EZI2C_PVT.h"
#endif /* (GPS_UART_SCB_MODE_EZI2C_INC) */

#if(GPS_UART_SCB_MODE_SPI_INC || GPS_UART_SCB_MODE_UART_INC)
    #include "GPS_UART_SPI_UART_PVT.h"
#endif /* (GPS_UART_SCB_MODE_SPI_INC || GPS_UART_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG || \
   (GPS_UART_SCB_MODE_I2C_CONST_CFG   && (!GPS_UART_I2C_WAKE_ENABLE_CONST))   || \
   (GPS_UART_SCB_MODE_EZI2C_CONST_CFG && (!GPS_UART_EZI2C_WAKE_ENABLE_CONST)) || \
   (GPS_UART_SCB_MODE_SPI_CONST_CFG   && (!GPS_UART_SPI_WAKE_ENABLE_CONST))   || \
   (GPS_UART_SCB_MODE_UART_CONST_CFG  && (!GPS_UART_UART_WAKE_ENABLE_CONST)))

    GPS_UART_BACKUP_STRUCT GPS_UART_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: GPS_UART_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component to enter Deep Sleep.
*  The “Enable wakeup from Sleep Mode” selection has an influence on
*  this function implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void GPS_UART_Sleep(void)
{
#if(GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG)

    if(GPS_UART_SCB_WAKE_ENABLE_CHECK)
    {
        if(GPS_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            GPS_UART_I2CSaveConfig();
        }
        else if(GPS_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            GPS_UART_EzI2CSaveConfig();
        }
    #if(!GPS_UART_CY_SCBIP_V1_I2C_ONLY)
        else if(GPS_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            GPS_UART_SpiSaveConfig();
        }
        else if(GPS_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            GPS_UART_UartSaveConfig();
        }
    #endif /* (!GPS_UART_CY_SCBIP_V1_I2C_ONLY) */
        else
        {
            /* Unknown mode: do nothing */
        }
    }
    else
    {
        GPS_UART_backup.enableState = (uint8) GPS_UART_GET_CTRL_ENABLED;

        if(0u != GPS_UART_backup.enableState)
        {
            GPS_UART_Stop();
        }
    }

#else

    #if (GPS_UART_SCB_MODE_I2C_CONST_CFG && GPS_UART_I2C_WAKE_ENABLE_CONST)
        GPS_UART_I2CSaveConfig();

    #elif (GPS_UART_SCB_MODE_EZI2C_CONST_CFG && GPS_UART_EZI2C_WAKE_ENABLE_CONST)
        GPS_UART_EzI2CSaveConfig();

    #elif (GPS_UART_SCB_MODE_SPI_CONST_CFG && GPS_UART_SPI_WAKE_ENABLE_CONST)
        GPS_UART_SpiSaveConfig();

    #elif (GPS_UART_SCB_MODE_UART_CONST_CFG && GPS_UART_UART_WAKE_ENABLE_CONST)
        GPS_UART_UartSaveConfig();

    #else

        GPS_UART_backup.enableState = (uint8) GPS_UART_GET_CTRL_ENABLED;

        if(0u != GPS_UART_backup.enableState)
        {
            GPS_UART_Stop();
        }

    #endif /* defined (GPS_UART_SCB_MODE_I2C_CONST_CFG) && (GPS_UART_I2C_WAKE_ENABLE_CONST) */

#endif /* (GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: GPS_UART_Wakeup
********************************************************************************
*
* Summary:
*  Prepares the component for the Active mode operation after exiting Deep Sleep.
*  The “Enable wakeup from Sleep Mode” option has an influence on this function
*  implementation.
*  This function should not be called after exiting Sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void GPS_UART_Wakeup(void)
{
#if(GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG)

    if(GPS_UART_SCB_WAKE_ENABLE_CHECK)
    {
        if(GPS_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            GPS_UART_I2CRestoreConfig();
        }
        else if(GPS_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            GPS_UART_EzI2CRestoreConfig();
        }
    #if(!GPS_UART_CY_SCBIP_V1_I2C_ONLY)
        else if(GPS_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            GPS_UART_SpiRestoreConfig();
        }
        else if(GPS_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            GPS_UART_UartRestoreConfig();
        }
    #endif /* (!GPS_UART_CY_SCBIP_V1_I2C_ONLY) */
        else
        {
            /* Unknown mode: do nothing */
        }
    }
    else
    {
        if(0u != GPS_UART_backup.enableState)
        {
            GPS_UART_Enable();
        }
    }

#else

    #if (GPS_UART_SCB_MODE_I2C_CONST_CFG  && GPS_UART_I2C_WAKE_ENABLE_CONST)
        GPS_UART_I2CRestoreConfig();

    #elif (GPS_UART_SCB_MODE_EZI2C_CONST_CFG && GPS_UART_EZI2C_WAKE_ENABLE_CONST)
        GPS_UART_EzI2CRestoreConfig();

    #elif (GPS_UART_SCB_MODE_SPI_CONST_CFG && GPS_UART_SPI_WAKE_ENABLE_CONST)
        GPS_UART_SpiRestoreConfig();

    #elif (GPS_UART_SCB_MODE_UART_CONST_CFG && GPS_UART_UART_WAKE_ENABLE_CONST)
        GPS_UART_UartRestoreConfig();

    #else

        if(0u != GPS_UART_backup.enableState)
        {
            GPS_UART_Enable();
        }

    #endif /* (GPS_UART_I2C_WAKE_ENABLE_CONST) */

#endif /* (GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
