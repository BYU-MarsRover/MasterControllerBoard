/*******************************************************************************
* File Name: UART_2_BOOT.c
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

#include "UART_2.h"

#if(UART_2_SCB_MODE_I2C_INC)
    #include "UART_2_I2C.h"
#endif /* (UART_2_SCB_MODE_I2C_INC) */

#if(UART_2_SCB_MODE_EZI2C_INC)
    #include "UART_2_EZI2C.h"
#endif /* (UART_2_SCB_MODE_EZI2C_INC) */

#if(UART_2_SCB_MODE_SPI_INC || UART_2_SCB_MODE_UART_INC)
    #include "UART_2_SPI_UART.h"
#endif /* (UART_2_SCB_MODE_SPI_INC || UART_2_SCB_MODE_UART_INC) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_2) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/*******************************************************************************
* Function Name: UART_2_CyBtldrCommStart
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
void UART_2_CyBtldrCommStart(void)
{
    #if(UART_2_SCB_MODE_UNCONFIG_CONST_CFG)
        if(UART_2_SCB_MODE_I2C_RUNTM_CFG)
        {
            UART_2_I2CCyBtldrCommStart();
        }
        else if(UART_2_SCB_MODE_SPI_RUNTM_CFG)
        {
            UART_2_SpiCyBtldrCommStart();
        }
        else if(UART_2_SCB_MODE_UART_RUNTM_CFG)
        {
            UART_2_UartCyBtldrCommStart();
        }
        else if(UART_2_SCB_MODE_EZI2C_RUNTM_CFG)
        {
             UART_2_EzI2CCyBtldrCommStart();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(UART_2_SCB_MODE_I2C_CONST_CFG)
        UART_2_I2CCyBtldrCommStart();

    #elif(UART_2_SCB_MODE_SPI_CONST_CFG)
        UART_2_SpiCyBtldrCommStart();

    #elif(UART_2_SCB_MODE_UART_CONST_CFG)
        UART_2_UartCyBtldrCommStart();

    #elif(UART_2_SCB_MODE_EZI2C_CONST_CFG)
        UART_2_EzI2CCyBtldrCommStart();

    #else
        /* Do nothing */

    #endif /* (UART_2_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UART_2_CyBtldrCommStop
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
void UART_2_CyBtldrCommStop(void)
{
    #if(UART_2_SCB_MODE_UNCONFIG_CONST_CFG)
        if(UART_2_SCB_MODE_I2C_RUNTM_CFG)
        {
            UART_2_I2CCyBtldrCommStop();
        }
        else if(UART_2_SCB_MODE_SPI_RUNTM_CFG)
        {
            UART_2_SpiCyBtldrCommStop();
        }
        else if(UART_2_SCB_MODE_UART_RUNTM_CFG)
        {
            UART_2_UartCyBtldrCommStop();
        }
        else if(UART_2_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            UART_2_EzI2CCyBtldrCommStop();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(UART_2_SCB_MODE_I2C_CONST_CFG)
        UART_2_I2CCyBtldrCommStop();

    #elif(UART_2_SCB_MODE_SPI_CONST_CFG)
        UART_2_SpiCyBtldrCommStop();

    #elif(UART_2_SCB_MODE_UART_CONST_CFG)
        UART_2_UartCyBtldrCommStop();

    #elif(UART_2_SCB_MODE_EZI2C_CONST_CFG)
        UART_2_EzI2CCyBtldrCommStop();

    #else
        /* Do nothing */

    #endif /* (UART_2_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UART_2_CyBtldrCommReset
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
void UART_2_CyBtldrCommReset(void)
{
    #if(UART_2_SCB_MODE_UNCONFIG_CONST_CFG)
        if(UART_2_SCB_MODE_I2C_RUNTM_CFG)
        {
            UART_2_I2CCyBtldrCommReset();
        }
        else if(UART_2_SCB_MODE_SPI_RUNTM_CFG)
        {
            UART_2_SpiCyBtldrCommReset();
        }
        else if(UART_2_SCB_MODE_UART_RUNTM_CFG)
        {
            UART_2_UartCyBtldrCommReset();
        }
        else if(UART_2_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            UART_2_EzI2CCyBtldrCommReset();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(UART_2_SCB_MODE_I2C_CONST_CFG)
        UART_2_I2CCyBtldrCommReset();

    #elif(UART_2_SCB_MODE_SPI_CONST_CFG)
        UART_2_SpiCyBtldrCommReset();

    #elif(UART_2_SCB_MODE_UART_CONST_CFG)
        UART_2_UartCyBtldrCommReset();

    #elif(UART_2_SCB_MODE_EZI2C_CONST_CFG)
        UART_2_EzI2CCyBtldrCommReset();

    #else
        /* Do nothing */

    #endif /* (UART_2_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UART_2_CyBtldrCommRead
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
cystatus UART_2_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(UART_2_SCB_MODE_UNCONFIG_CONST_CFG)
        if(UART_2_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = UART_2_I2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(UART_2_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = UART_2_SpiCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(UART_2_SCB_MODE_UART_RUNTM_CFG)
        {
            status = UART_2_UartCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(UART_2_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = UART_2_EzI2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode: return status */
        }

    #elif(UART_2_SCB_MODE_I2C_CONST_CFG)
        status = UART_2_I2CCyBtldrCommRead(pData, size, count, timeOut);

    #elif(UART_2_SCB_MODE_SPI_CONST_CFG)
        status = UART_2_SpiCyBtldrCommRead(pData, size, count, timeOut);

    #elif(UART_2_SCB_MODE_UART_CONST_CFG)
        status = UART_2_UartCyBtldrCommRead(pData, size, count, timeOut);

    #elif(UART_2_SCB_MODE_EZI2C_CONST_CFG)
        status = UART_2_EzI2CCyBtldrCommRead(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode: return status */

    #endif /* (UART_2_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}


/*******************************************************************************
* Function Name: UART_2_CyBtldrCommWrite
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
cystatus UART_2_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(UART_2_SCB_MODE_UNCONFIG_CONST_CFG)
        if(UART_2_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = UART_2_I2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(UART_2_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = UART_2_SpiCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(UART_2_SCB_MODE_UART_RUNTM_CFG)
        {
            status = UART_2_UartCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(UART_2_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = UART_2_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode */
        }
    #elif(UART_2_SCB_MODE_I2C_CONST_CFG)
        status = UART_2_I2CCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(UART_2_SCB_MODE_SPI_CONST_CFG)
        status = UART_2_SpiCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(UART_2_SCB_MODE_UART_CONST_CFG)
        status = UART_2_UartCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(UART_2_SCB_MODE_EZI2C_CONST_CFG)
        status = UART_2_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode */

    #endif /* (UART_2_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_2) || \
                                                    (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface)) */


/* [] END OF FILE */
