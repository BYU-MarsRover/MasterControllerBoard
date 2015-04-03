/*******************************************************************************
* File Name: GPS_UART_BOOT.c
* Version 1.20
*
* Description:
*  This file provides the source code to the API for the bootloader
*  communication support in SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "GPS_UART.h"

#if(GPS_UART_SCB_MODE_I2C_INC)
    #include "GPS_UART_I2C.h"
#endif /* (GPS_UART_SCB_MODE_I2C_INC) */

#if(GPS_UART_SCB_MODE_EZI2C_INC)
    #include "GPS_UART_EZI2C.h"
#endif /* (GPS_UART_SCB_MODE_EZI2C_INC) */

#if(GPS_UART_SCB_MODE_SPI_INC || GPS_UART_SCB_MODE_UART_INC)
    #include "GPS_UART_SPI_UART.h"
#endif /* (GPS_UART_SCB_MODE_SPI_INC || GPS_UART_SCB_MODE_UART_INC) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_GPS_UART) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/*******************************************************************************
* Function Name: GPS_UART_CyBtldrCommStart
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommStart function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void GPS_UART_CyBtldrCommStart(void)
{
    #if(GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG)
        if(GPS_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            GPS_UART_I2CCyBtldrCommStart();
        }
        else if(GPS_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            GPS_UART_SpiCyBtldrCommStart();
        }
        else if(GPS_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            GPS_UART_UartCyBtldrCommStart();
        }
        else if(GPS_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
             GPS_UART_EzI2CCyBtldrCommStart();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(GPS_UART_SCB_MODE_I2C_CONST_CFG)
        GPS_UART_I2CCyBtldrCommStart();

    #elif(GPS_UART_SCB_MODE_SPI_CONST_CFG)
        GPS_UART_SpiCyBtldrCommStart();

    #elif(GPS_UART_SCB_MODE_UART_CONST_CFG)
        GPS_UART_UartCyBtldrCommStart();

    #elif(GPS_UART_SCB_MODE_EZI2C_CONST_CFG)
        GPS_UART_EzI2CCyBtldrCommStart();

    #else
        /* Do nothing */

    #endif /* (GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: GPS_UART_CyBtldrCommStop
********************************************************************************
*
* Summary:
*  Calls CyBtldrCommStop function function of the bootloader communication
*  component for selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void GPS_UART_CyBtldrCommStop(void)
{
    #if(GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG)
        if(GPS_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            GPS_UART_I2CCyBtldrCommStop();
        }
        else if(GPS_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            GPS_UART_SpiCyBtldrCommStop();
        }
        else if(GPS_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            GPS_UART_UartCyBtldrCommStop();
        }
        else if(GPS_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            GPS_UART_EzI2CCyBtldrCommStop();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(GPS_UART_SCB_MODE_I2C_CONST_CFG)
        GPS_UART_I2CCyBtldrCommStop();

    #elif(GPS_UART_SCB_MODE_SPI_CONST_CFG)
        GPS_UART_SpiCyBtldrCommStop();

    #elif(GPS_UART_SCB_MODE_UART_CONST_CFG)
        GPS_UART_UartCyBtldrCommStop();

    #elif(GPS_UART_SCB_MODE_EZI2C_CONST_CFG)
        GPS_UART_EzI2CCyBtldrCommStop();

    #else
        /* Do nothing */

    #endif /* (GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: GPS_UART_CyBtldrCommReset
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommReset function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void GPS_UART_CyBtldrCommReset(void)
{
    #if(GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG)
        if(GPS_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            GPS_UART_I2CCyBtldrCommReset();
        }
        else if(GPS_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            GPS_UART_SpiCyBtldrCommReset();
        }
        else if(GPS_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            GPS_UART_UartCyBtldrCommReset();
        }
        else if(GPS_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            GPS_UART_EzI2CCyBtldrCommReset();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(GPS_UART_SCB_MODE_I2C_CONST_CFG)
        GPS_UART_I2CCyBtldrCommReset();

    #elif(GPS_UART_SCB_MODE_SPI_CONST_CFG)
        GPS_UART_SpiCyBtldrCommReset();

    #elif(GPS_UART_SCB_MODE_UART_CONST_CFG)
        GPS_UART_UartCyBtldrCommReset();

    #elif(GPS_UART_SCB_MODE_EZI2C_CONST_CFG)
        GPS_UART_EzI2CCyBtldrCommReset();

    #else
        /* Do nothing */

    #endif /* (GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: GPS_UART_CyBtldrCommRead
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommRead function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  pData:    Pointer to storage for the block of data to be read from the
*            bootloader host
*  size:     Number of bytes to be read.
*  count:    Pointer to the variable to write the number of bytes actually
*            read.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus GPS_UART_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG)
        if(GPS_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = GPS_UART_I2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(GPS_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = GPS_UART_SpiCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(GPS_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            status = GPS_UART_UartCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(GPS_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = GPS_UART_EzI2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode: return status */
        }

    #elif(GPS_UART_SCB_MODE_I2C_CONST_CFG)
        status = GPS_UART_I2CCyBtldrCommRead(pData, size, count, timeOut);

    #elif(GPS_UART_SCB_MODE_SPI_CONST_CFG)
        status = GPS_UART_SpiCyBtldrCommRead(pData, size, count, timeOut);

    #elif(GPS_UART_SCB_MODE_UART_CONST_CFG)
        status = GPS_UART_UartCyBtldrCommRead(pData, size, count, timeOut);

    #elif(GPS_UART_SCB_MODE_EZI2C_CONST_CFG)
        status = GPS_UART_EzI2CCyBtldrCommRead(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode: return status */

    #endif /* (GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}


/*******************************************************************************
* Function Name: GPS_UART_CyBtldrCommWrite
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommWrite  function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  pData:    Pointer to the block of data to be written to the bootloader host.
*  size:     Number of bytes to be written.
*  count:    Pointer to the variable to write the number of bytes actually
*            written.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus GPS_UART_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG)
        if(GPS_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = GPS_UART_I2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(GPS_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = GPS_UART_SpiCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(GPS_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            status = GPS_UART_UartCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(GPS_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = GPS_UART_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode */
        }
    #elif(GPS_UART_SCB_MODE_I2C_CONST_CFG)
        status = GPS_UART_I2CCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(GPS_UART_SCB_MODE_SPI_CONST_CFG)
        status = GPS_UART_SpiCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(GPS_UART_SCB_MODE_UART_CONST_CFG)
        status = GPS_UART_UartCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(GPS_UART_SCB_MODE_EZI2C_CONST_CFG)
        status = GPS_UART_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode */

    #endif /* (GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_GPS_UART) || \
                                                    (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface)) */


/* [] END OF FILE */
