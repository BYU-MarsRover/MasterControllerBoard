/*******************************************************************************
* File Name: UART_2_PM.c
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

#include "UART_2.h"
#include "UART_2_PVT.h"

#if(UART_2_SCB_MODE_I2C_INC)
    #include "UART_2_I2C_PVT.h"
#endif /* (UART_2_SCB_MODE_I2C_INC) */

#if(UART_2_SCB_MODE_EZI2C_INC)
    #include "UART_2_EZI2C_PVT.h"
#endif /* (UART_2_SCB_MODE_EZI2C_INC) */

#if(UART_2_SCB_MODE_SPI_INC || UART_2_SCB_MODE_UART_INC)
    #include "UART_2_SPI_UART_PVT.h"
#endif /* (UART_2_SCB_MODE_SPI_INC || UART_2_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(UART_2_SCB_MODE_UNCONFIG_CONST_CFG || \
   (UART_2_SCB_MODE_I2C_CONST_CFG   && (!UART_2_I2C_WAKE_ENABLE_CONST))   || \
   (UART_2_SCB_MODE_EZI2C_CONST_CFG && (!UART_2_EZI2C_WAKE_ENABLE_CONST)) || \
   (UART_2_SCB_MODE_SPI_CONST_CFG   && (!UART_2_SPI_WAKE_ENABLE_CONST))   || \
   (UART_2_SCB_MODE_UART_CONST_CFG  && (!UART_2_UART_WAKE_ENABLE_CONST)))

    UART_2_BACKUP_STRUCT UART_2_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: UART_2_Sleep
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
void UART_2_Sleep(void)
{
#if(UART_2_SCB_MODE_UNCONFIG_CONST_CFG)

    if(UART_2_SCB_WAKE_ENABLE_CHECK)
    {
        if(UART_2_SCB_MODE_I2C_RUNTM_CFG)
        {
            UART_2_I2CSaveConfig();
        }
        else if(UART_2_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            UART_2_EzI2CSaveConfig();
        }
    #if(!UART_2_CY_SCBIP_V1_I2C_ONLY)
        else if(UART_2_SCB_MODE_SPI_RUNTM_CFG)
        {
            UART_2_SpiSaveConfig();
        }
        else if(UART_2_SCB_MODE_UART_RUNTM_CFG)
        {
            UART_2_UartSaveConfig();
        }
    #endif /* (!UART_2_CY_SCBIP_V1_I2C_ONLY) */
        else
        {
            /* Unknown mode: do nothing */
        }
    }
    else
    {
        UART_2_backup.enableState = (uint8) UART_2_GET_CTRL_ENABLED;

        if(0u != UART_2_backup.enableState)
        {
            UART_2_Stop();
        }
    }

#else

    #if (UART_2_SCB_MODE_I2C_CONST_CFG && UART_2_I2C_WAKE_ENABLE_CONST)
        UART_2_I2CSaveConfig();

    #elif (UART_2_SCB_MODE_EZI2C_CONST_CFG && UART_2_EZI2C_WAKE_ENABLE_CONST)
        UART_2_EzI2CSaveConfig();

    #elif (UART_2_SCB_MODE_SPI_CONST_CFG && UART_2_SPI_WAKE_ENABLE_CONST)
        UART_2_SpiSaveConfig();

    #elif (UART_2_SCB_MODE_UART_CONST_CFG && UART_2_UART_WAKE_ENABLE_CONST)
        UART_2_UartSaveConfig();

    #else

        UART_2_backup.enableState = (uint8) UART_2_GET_CTRL_ENABLED;

        if(0u != UART_2_backup.enableState)
        {
            UART_2_Stop();
        }

    #endif /* defined (UART_2_SCB_MODE_I2C_CONST_CFG) && (UART_2_I2C_WAKE_ENABLE_CONST) */

#endif /* (UART_2_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UART_2_Wakeup
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
void UART_2_Wakeup(void)
{
#if(UART_2_SCB_MODE_UNCONFIG_CONST_CFG)

    if(UART_2_SCB_WAKE_ENABLE_CHECK)
    {
        if(UART_2_SCB_MODE_I2C_RUNTM_CFG)
        {
            UART_2_I2CRestoreConfig();
        }
        else if(UART_2_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            UART_2_EzI2CRestoreConfig();
        }
    #if(!UART_2_CY_SCBIP_V1_I2C_ONLY)
        else if(UART_2_SCB_MODE_SPI_RUNTM_CFG)
        {
            UART_2_SpiRestoreConfig();
        }
        else if(UART_2_SCB_MODE_UART_RUNTM_CFG)
        {
            UART_2_UartRestoreConfig();
        }
    #endif /* (!UART_2_CY_SCBIP_V1_I2C_ONLY) */
        else
        {
            /* Unknown mode: do nothing */
        }
    }
    else
    {
        if(0u != UART_2_backup.enableState)
        {
            UART_2_Enable();
        }
    }

#else

    #if (UART_2_SCB_MODE_I2C_CONST_CFG  && UART_2_I2C_WAKE_ENABLE_CONST)
        UART_2_I2CRestoreConfig();

    #elif (UART_2_SCB_MODE_EZI2C_CONST_CFG && UART_2_EZI2C_WAKE_ENABLE_CONST)
        UART_2_EzI2CRestoreConfig();

    #elif (UART_2_SCB_MODE_SPI_CONST_CFG && UART_2_SPI_WAKE_ENABLE_CONST)
        UART_2_SpiRestoreConfig();

    #elif (UART_2_SCB_MODE_UART_CONST_CFG && UART_2_UART_WAKE_ENABLE_CONST)
        UART_2_UartRestoreConfig();

    #else

        if(0u != UART_2_backup.enableState)
        {
            UART_2_Enable();
        }

    #endif /* (UART_2_I2C_WAKE_ENABLE_CONST) */

#endif /* (UART_2_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
