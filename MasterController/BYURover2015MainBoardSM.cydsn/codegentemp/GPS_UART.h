/*******************************************************************************
* File Name: GPS_UART.h
* Version 1.20
*
* Description:
*  This file provides constants and parameter values for the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2013-2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_GPS_UART_H)
#define CY_SCB_GPS_UART_H

#include <cydevice_trm.h>
#include <cyfitter.h>
#include <cytypes.h>
#include <CyLib.h>


/***************************************
*  Conditional Compilation Parameters
****************************************/

#define GPS_UART_CY_SCBIP_V0 (CYIPBLOCK_m0s8scb_VERSION == 0u)
#define GPS_UART_CY_SCBIP_V1 (CYIPBLOCK_m0s8scb_VERSION >= 1u)

#if(GPS_UART_CY_SCBIP_V1)
    #define GPS_UART_CY_SCBIP_V1_I2C_ONLY   (1u) /* SCB IP V1 supports only I2C */
#else
    #define GPS_UART_CY_SCBIP_V1_I2C_ONLY   (0u) /* SCB IP V0 supports I2C, SPI, UART */
#endif /* (GPS_UART_CY_SCBIP_V1) */

#define GPS_UART_SCB_MODE                     (4u)

/* SCB modes enum */
#define GPS_UART_SCB_MODE_I2C                 (0x01u)
#define GPS_UART_SCB_MODE_SPI                 (0x02u)
#define GPS_UART_SCB_MODE_UART                (0x04u)
#define GPS_UART_SCB_MODE_EZI2C               (0x08u)
#define GPS_UART_SCB_MODE_UNCONFIG            (0xFFu)

/* Condition compilation depends on operation mode: Unconfigured implies apply to all modes */
#define GPS_UART_SCB_MODE_I2C_CONST_CFG       (GPS_UART_SCB_MODE_I2C       == GPS_UART_SCB_MODE)
#define GPS_UART_SCB_MODE_SPI_CONST_CFG       (GPS_UART_SCB_MODE_SPI       == GPS_UART_SCB_MODE)
#define GPS_UART_SCB_MODE_UART_CONST_CFG      (GPS_UART_SCB_MODE_UART      == GPS_UART_SCB_MODE)
#define GPS_UART_SCB_MODE_EZI2C_CONST_CFG     (GPS_UART_SCB_MODE_EZI2C     == GPS_UART_SCB_MODE)
#define GPS_UART_SCB_MODE_UNCONFIG_CONST_CFG  (GPS_UART_SCB_MODE_UNCONFIG  == GPS_UART_SCB_MODE)

/* Condition compilation for includes */
#define GPS_UART_SCB_MODE_I2C_INC       (0u !=(GPS_UART_SCB_MODE_I2C       & GPS_UART_SCB_MODE))
#define GPS_UART_SCB_MODE_EZI2C_INC     (0u !=(GPS_UART_SCB_MODE_EZI2C     & GPS_UART_SCB_MODE))
#if(!GPS_UART_CY_SCBIP_V1_I2C_ONLY)
#define GPS_UART_SCB_MODE_SPI_INC       (0u !=(GPS_UART_SCB_MODE_SPI       & GPS_UART_SCB_MODE))
#define GPS_UART_SCB_MODE_UART_INC      (0u !=(GPS_UART_SCB_MODE_UART      & GPS_UART_SCB_MODE))
#else
#define GPS_UART_SCB_MODE_SPI_INC       (0u)
#define GPS_UART_SCB_MODE_UART_INC      (0u)
#endif /* ((!GPS_UART_CY_SCBIP_V1_I2C_ONLY) */

/* Interrupts remove options */
#define GPS_UART_REMOVE_SCB_IRQ             (1u)
#define GPS_UART_SCB_IRQ_INTERNAL           (0u == GPS_UART_REMOVE_SCB_IRQ)

#define GPS_UART_REMOVE_UART_RX_WAKEUP_IRQ  (1u)
#define GPS_UART_UART_RX_WAKEUP_IRQ         (0u == GPS_UART_REMOVE_UART_RX_WAKEUP_IRQ)

/* SCB interrupt enum */
#define GPS_UART_SCB_INTR_MODE_NONE     (0u)
#define GPS_UART_SCB_INTR_MODE_INTERNAL (1u)
#define GPS_UART_SCB_INTR_MODE_EXTERNAL (2u)

/* Bootloader communication interface enable */
#define GPS_UART_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_GPS_UART) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))


/***************************************
*       Includes
****************************************/

#include "GPS_UART_PINS.h"


/***************************************
*       Type Definitions
***************************************/

typedef struct
{
    uint8 enableState;
} GPS_UART_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

/* Start and Stop APIs */
void GPS_UART_Init(void);
void GPS_UART_Enable(void);
void GPS_UART_Start(void);
void GPS_UART_Stop(void);

/* Sleep and Wakeup APis */
void GPS_UART_Sleep(void);
void GPS_UART_Wakeup(void);

/* Custom interrupt handler */
void GPS_UART_SetCustomInterruptHandler(cyisraddress func);

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (GPS_UART_BTLDR_COMM_ENABLED)
    /* Bootloader Physical layer functions */
    void GPS_UART_CyBtldrCommStart(void);
    void GPS_UART_CyBtldrCommStop (void);
    void GPS_UART_CyBtldrCommReset(void);
    cystatus GPS_UART_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus GPS_UART_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    #if(CYDEV_BOOTLOADER_IO_COMP == CyBtldr_GPS_UART)
        #define CyBtldrCommStart    GPS_UART_CyBtldrCommStart
        #define CyBtldrCommStop     GPS_UART_CyBtldrCommStop
        #define CyBtldrCommReset    GPS_UART_CyBtldrCommReset
        #define CyBtldrCommWrite    GPS_UART_CyBtldrCommWrite
        #define CyBtldrCommRead     GPS_UART_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_GPS_UART) */

#endif /*defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_GPS_UART) || \
                                                    (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface)) */

/* Interface to internal interrupt component */
#if(GPS_UART_SCB_IRQ_INTERNAL)
    #define GPS_UART_EnableInt()        CyIntEnable      (GPS_UART_ISR_NUMBER)
    #define GPS_UART_DisableInt()       CyIntDisable     (GPS_UART_ISR_NUMBER)
    #define GPS_UART_ClearPendingInt()  CyIntClearPending(GPS_UART_ISR_NUMBER)
#endif /* (GPS_UART_SCB_IRQ_INTERNAL) */

#if(GPS_UART_UART_RX_WAKEUP_IRQ)
    #define GPS_UART_RxWakeEnableInt()        CyIntEnable      (GPS_UART_RX_WAKE_ISR_NUMBER)
    #define GPS_UART_RxWakeDisableInt()       CyIntDisable     (GPS_UART_RX_WAKE_ISR_NUMBER)
    #define GPS_UART_RxWakeClearPendingInt()  CyIntClearPending(GPS_UART_RX_WAKE_ISR_NUMBER)
#endif /* (GPS_UART_UART_RX_WAKEUP_IRQ) */

/* Get interrupt cause */
#define GPS_UART_GetInterruptCause()    (GPS_UART_INTR_CAUSE_REG)

/* APIs to service INTR_RX register */
#define GPS_UART_SetRxInterruptMode(interruptMask)     GPS_UART_WRITE_INTR_RX_MASK(interruptMask)
#define GPS_UART_ClearRxInterruptSource(interruptMask) GPS_UART_CLEAR_INTR_RX(interruptMask)
#define GPS_UART_SetRxInterrupt(interruptMask)         GPS_UART_SET_INTR_RX(interruptMask)
#define GPS_UART_GetRxInterruptSource()                (GPS_UART_INTR_RX_REG)
#define GPS_UART_GetRxInterruptMode()                  (GPS_UART_INTR_RX_MASK_REG)
#define GPS_UART_GetRxInterruptSourceMasked()          (GPS_UART_INTR_RX_MASKED_REG)

/* APIs to service INTR_TX register */
#define GPS_UART_SetTxInterruptMode(interruptMask)     GPS_UART_WRITE_INTR_TX_MASK(interruptMask)
#define GPS_UART_ClearTxInterruptSource(interruptMask) GPS_UART_CLEAR_INTR_TX(interruptMask)
#define GPS_UART_SetTxInterrupt(interruptMask)         GPS_UART_SET_INTR_TX(interruptMask)
#define GPS_UART_GetTxInterruptSource()                (GPS_UART_INTR_TX_REG)
#define GPS_UART_GetTxInterruptMode()                  (GPS_UART_INTR_TX_MASK_REG)
#define GPS_UART_GetTxInterruptSourceMasked()          (GPS_UART_INTR_TX_MASKED_REG)

/* APIs to service INTR_MASTER register */
#define GPS_UART_SetMasterInterruptMode(interruptMask)    GPS_UART_WRITE_INTR_MASTER_MASK(interruptMask)
#define GPS_UART_ClearMasterInterruptSource(interruptMask) GPS_UART_CLEAR_INTR_MASTER(interruptMask)
#define GPS_UART_SetMasterInterrupt(interruptMask)         GPS_UART_SET_INTR_MASTER(interruptMask)
#define GPS_UART_GetMasterInterruptSource()                (GPS_UART_INTR_MASTER_REG)
#define GPS_UART_GetMasterInterruptMode()                  (GPS_UART_INTR_MASTER_MASK_REG)
#define GPS_UART_GetMasterInterruptSourceMasked()          (GPS_UART_INTR_MASTER_MASKED_REG)

/* APIs to service INTR_SLAVE register */
#define GPS_UART_SetSlaveInterruptMode(interruptMask)     GPS_UART_WRITE_INTR_SLAVE_MASK(interruptMask)
#define GPS_UART_ClearSlaveInterruptSource(interruptMask) GPS_UART_CLEAR_INTR_SLAVE(interruptMask)
#define GPS_UART_SetSlaveInterrupt(interruptMask)         GPS_UART_SET_INTR_SLAVE(interruptMask)
#define GPS_UART_GetSlaveInterruptSource()                (GPS_UART_INTR_SLAVE_REG)
#define GPS_UART_GetSlaveInterruptMode()                  (GPS_UART_INTR_SLAVE_MASK_REG)
#define GPS_UART_GetSlaveInterruptSourceMasked()          (GPS_UART_INTR_SLAVE_MASKED_REG)


/**********************************
*     Vars with External Linkage
**********************************/

extern uint8 GPS_UART_initVar;


/***************************************
*              Registers
***************************************/

#define GPS_UART_CTRL_REG               (*(reg32 *) GPS_UART_SCB__CTRL)
#define GPS_UART_CTRL_PTR               ( (reg32 *) GPS_UART_SCB__CTRL)

#define GPS_UART_STATUS_REG             (*(reg32 *) GPS_UART_SCB__STATUS)
#define GPS_UART_STATUS_PTR             ( (reg32 *) GPS_UART_SCB__STATUS)

#if(!GPS_UART_CY_SCBIP_V1_I2C_ONLY)
    #define GPS_UART_SPI_CTRL_REG           (*(reg32 *) GPS_UART_SCB__SPI_CTRL)
    #define GPS_UART_SPI_CTRL_PTR           ( (reg32 *) GPS_UART_SCB__SPI_CTRL)

    #define GPS_UART_SPI_STATUS_REG         (*(reg32 *) GPS_UART_SCB__SPI_STATUS)
    #define GPS_UART_SPI_STATUS_PTR         ( (reg32 *) GPS_UART_SCB__SPI_STATUS)

    #define GPS_UART_UART_CTRL_REG          (*(reg32 *) GPS_UART_SCB__UART_CTRL)
    #define GPS_UART_UART_CTRL_PTR          ( (reg32 *) GPS_UART_SCB__UART_CTRL)

    #define GPS_UART_UART_TX_CTRL_REG       (*(reg32 *) GPS_UART_SCB__UART_TX_CTRL)
    #define GPS_UART_UART_TX_CTRL_PTR       ( (reg32 *) GPS_UART_SCB__UART_RX_CTRL)

    #define GPS_UART_UART_RX_CTRL_REG       (*(reg32 *) GPS_UART_SCB__UART_RX_CTRL)
    #define GPS_UART_UART_RX_CTRL_PTR       ( (reg32 *) GPS_UART_SCB__UART_RX_CTRL)

    #define GPS_UART_UART_RX_STATUS_REG     (*(reg32 *) GPS_UART_SCB__UART_RX_STATUS)
    #define GPS_UART_UART_RX_STATUS_PTR     ( (reg32 *) GPS_UART_SCB__UART_RX_STATUS)
#endif /* (!GPS_UART_CY_SCBIP_V1_I2C_ONLY) */

#define GPS_UART_I2C_CTRL_REG           (*(reg32 *) GPS_UART_SCB__I2C_CTRL)
#define GPS_UART_I2C_CTRL_PTR           ( (reg32 *) GPS_UART_SCB__I2C_CTRL)

#define GPS_UART_I2C_STATUS_REG         (*(reg32 *) GPS_UART_SCB__I2C_STATUS)
#define GPS_UART_I2C_STATUS_PTR         ( (reg32 *) GPS_UART_SCB__I2C_STATUS)

#define GPS_UART_I2C_MASTER_CMD_REG     (*(reg32 *) GPS_UART_SCB__I2C_M_CMD)
#define GPS_UART_I2C_MASTER_CMD_PTR     ( (reg32 *) GPS_UART_SCB__I2C_M_CMD)

#define GPS_UART_I2C_SLAVE_CMD_REG      (*(reg32 *) GPS_UART_SCB__I2C_S_CMD)
#define GPS_UART_I2C_SLAVE_CMD_PTR      ( (reg32 *) GPS_UART_SCB__I2C_S_CMD)

#define GPS_UART_I2C_CFG_REG            (*(reg32 *) GPS_UART_SCB__I2C_CFG)
#define GPS_UART_I2C_CFG_PTR            ( (reg32 *) GPS_UART_SCB__I2C_CFG)

#define GPS_UART_TX_CTRL_REG            (*(reg32 *) GPS_UART_SCB__TX_CTRL)
#define GPS_UART_TX_CTRL_PTR            ( (reg32 *) GPS_UART_SCB__TX_CTRL)

#define GPS_UART_TX_FIFO_CTRL_REG       (*(reg32 *) GPS_UART_SCB__TX_FIFO_CTRL)
#define GPS_UART_TX_FIFO_CTRL_PTR       ( (reg32 *) GPS_UART_SCB__TX_FIFO_CTRL)

#define GPS_UART_TX_FIFO_STATUS_REG     (*(reg32 *) GPS_UART_SCB__TX_FIFO_STATUS)
#define GPS_UART_TX_FIFO_STATUS_PTR     ( (reg32 *) GPS_UART_SCB__TX_FIFO_STATUS)

#define GPS_UART_TX_FIFO_WR_REG         (*(reg32 *) GPS_UART_SCB__TX_FIFO_WR)
#define GPS_UART_TX_FIFO_WR_PTR         ( (reg32 *) GPS_UART_SCB__TX_FIFO_WR)

#define GPS_UART_RX_CTRL_REG            (*(reg32 *) GPS_UART_SCB__RX_CTRL)
#define GPS_UART_RX_CTRL_PTR            ( (reg32 *) GPS_UART_SCB__RX_CTRL)

#define GPS_UART_RX_FIFO_CTRL_REG       (*(reg32 *) GPS_UART_SCB__RX_FIFO_CTRL)
#define GPS_UART_RX_FIFO_CTRL_PTR       ( (reg32 *) GPS_UART_SCB__RX_FIFO_CTRL)

#define GPS_UART_RX_FIFO_STATUS_REG     (*(reg32 *) GPS_UART_SCB__RX_FIFO_STATUS)
#define GPS_UART_RX_FIFO_STATUS_PTR     ( (reg32 *) GPS_UART_SCB__RX_FIFO_STATUS)

#define GPS_UART_RX_MATCH_REG           (*(reg32 *) GPS_UART_SCB__RX_MATCH)
#define GPS_UART_RX_MATCH_PTR           ( (reg32 *) GPS_UART_SCB__RX_MATCH)

#define GPS_UART_RX_FIFO_RD_REG         (*(reg32 *) GPS_UART_SCB__RX_FIFO_RD)
#define GPS_UART_RX_FIFO_RD_PTR         ( (reg32 *) GPS_UART_SCB__RX_FIFO_RD)

#define GPS_UART_RX_FIFO_RD_SILENT_REG  (*(reg32 *) GPS_UART_SCB__RX_FIFO_RD_SILENT)
#define GPS_UART_RX_FIFO_RD_SILENT_PTR  ( (reg32 *) GPS_UART_SCB__RX_FIFO_RD_SILENT)

#define GPS_UART_EZBUF_DATA00_REG       (*(reg32 *) GPS_UART_SCB__EZ_DATA00)
#define GPS_UART_EZBUF_DATA00_PTR       ( (reg32 *) GPS_UART_SCB__EZ_DATA00)

#define GPS_UART_INTR_CAUSE_REG         (*(reg32 *) GPS_UART_SCB__INTR_CAUSE)
#define GPS_UART_INTR_CAUSE_PTR         ( (reg32 *) GPS_UART_SCB__INTR_CAUSE)

#define GPS_UART_INTR_I2C_EC_REG        (*(reg32 *) GPS_UART_SCB__INTR_I2C_EC)
#define GPS_UART_INTR_I2C_EC_PTR        ( (reg32 *) GPS_UART_SCB__INTR_I2C_EC)

#define GPS_UART_INTR_I2C_EC_MASK_REG   (*(reg32 *) GPS_UART_SCB__INTR_I2C_EC_MASK)
#define GPS_UART_INTR_I2C_EC_MASK_PTR   ( (reg32 *) GPS_UART_SCB__INTR_I2C_EC_MASK)

#define GPS_UART_INTR_I2C_EC_MASKED_REG (*(reg32 *) GPS_UART_SCB__INTR_I2C_EC_MASKED)
#define GPS_UART_INTR_I2C_EC_MASKED_PTR ( (reg32 *) GPS_UART_SCB__INTR_I2C_EC_MASKED)

#if(!GPS_UART_CY_SCBIP_V1_I2C_ONLY)
    #define GPS_UART_INTR_SPI_EC_REG        (*(reg32 *) GPS_UART_SCB__INTR_SPI_EC)
    #define GPS_UART_INTR_SPI_EC_PTR        ( (reg32 *) GPS_UART_SCB__INTR_SPI_EC)

    #define GPS_UART_INTR_SPI_EC_MASK_REG   (*(reg32 *) GPS_UART_SCB__INTR_SPI_EC_MASK)
    #define GPS_UART_INTR_SPI_EC_MASK_PTR   ( (reg32 *) GPS_UART_SCB__INTR_SPI_EC_MASK)

    #define GPS_UART_INTR_SPI_EC_MASKED_REG (*(reg32 *) GPS_UART_SCB__INTR_SPI_EC_MASKED)
    #define GPS_UART_INTR_SPI_EC_MASKED_PTR ( (reg32 *) GPS_UART_SCB__INTR_SPI_EC_MASKED)
#endif /* (!GPS_UART_CY_SCBIP_V1_I2C_ONLY) */

#define GPS_UART_INTR_MASTER_REG        (*(reg32 *) GPS_UART_SCB__INTR_M)
#define GPS_UART_INTR_MASTER_PTR        ( (reg32 *) GPS_UART_SCB__INTR_M)

#define GPS_UART_INTR_MASTER_SET_REG    (*(reg32 *) GPS_UART_SCB__INTR_M_SET)
#define GPS_UART_INTR_MASTER_SET_PTR    ( (reg32 *) GPS_UART_SCB__INTR_M_SET)

#define GPS_UART_INTR_MASTER_MASK_REG   (*(reg32 *) GPS_UART_SCB__INTR_M_MASK)
#define GPS_UART_INTR_MASTER_MASK_PTR   ( (reg32 *) GPS_UART_SCB__INTR_M_MASK)

#define GPS_UART_INTR_MASTER_MASKED_REG (*(reg32 *) GPS_UART_SCB__INTR_M_MASKED)
#define GPS_UART_INTR_MASTER_MASKED_PTR ( (reg32 *) GPS_UART_SCB__INTR_M_MASKED)

#define GPS_UART_INTR_SLAVE_REG         (*(reg32 *) GPS_UART_SCB__INTR_S)
#define GPS_UART_INTR_SLAVE_PTR         ( (reg32 *) GPS_UART_SCB__INTR_S)

#define GPS_UART_INTR_SLAVE_SET_REG     (*(reg32 *) GPS_UART_SCB__INTR_S_SET)
#define GPS_UART_INTR_SLAVE_SET_PTR     ( (reg32 *) GPS_UART_SCB__INTR_S_SET)

#define GPS_UART_INTR_SLAVE_MASK_REG    (*(reg32 *) GPS_UART_SCB__INTR_S_MASK)
#define GPS_UART_INTR_SLAVE_MASK_PTR    ( (reg32 *) GPS_UART_SCB__INTR_S_MASK)

#define GPS_UART_INTR_SLAVE_MASKED_REG  (*(reg32 *) GPS_UART_SCB__INTR_S_MASKED)
#define GPS_UART_INTR_SLAVE_MASKED_PTR  ( (reg32 *) GPS_UART_SCB__INTR_S_MASKED)

#define GPS_UART_INTR_TX_REG            (*(reg32 *) GPS_UART_SCB__INTR_TX)
#define GPS_UART_INTR_TX_PTR            ( (reg32 *) GPS_UART_SCB__INTR_TX)

#define GPS_UART_INTR_TX_SET_REG        (*(reg32 *) GPS_UART_SCB__INTR_TX_SET)
#define GPS_UART_INTR_TX_SET_PTR        ( (reg32 *) GPS_UART_SCB__INTR_TX_SET)

#define GPS_UART_INTR_TX_MASK_REG       (*(reg32 *) GPS_UART_SCB__INTR_TX_MASK)
#define GPS_UART_INTR_TX_MASK_PTR       ( (reg32 *) GPS_UART_SCB__INTR_TX_MASK)

#define GPS_UART_INTR_TX_MASKED_REG     (*(reg32 *) GPS_UART_SCB__INTR_TX_MASKED)
#define GPS_UART_INTR_TX_MASKED_PTR     ( (reg32 *) GPS_UART_SCB__INTR_TX_MASKED)

#define GPS_UART_INTR_RX_REG            (*(reg32 *) GPS_UART_SCB__INTR_RX)
#define GPS_UART_INTR_RX_PTR            ( (reg32 *) GPS_UART_SCB__INTR_RX)

#define GPS_UART_INTR_RX_SET_REG        (*(reg32 *) GPS_UART_SCB__INTR_RX_SET)
#define GPS_UART_INTR_RX_SET_PTR        ( (reg32 *) GPS_UART_SCB__INTR_RX_SET)

#define GPS_UART_INTR_RX_MASK_REG       (*(reg32 *) GPS_UART_SCB__INTR_RX_MASK)
#define GPS_UART_INTR_RX_MASK_PTR       ( (reg32 *) GPS_UART_SCB__INTR_RX_MASK)

#define GPS_UART_INTR_RX_MASKED_REG     (*(reg32 *) GPS_UART_SCB__INTR_RX_MASKED)
#define GPS_UART_INTR_RX_MASKED_PTR     ( (reg32 *) GPS_UART_SCB__INTR_RX_MASKED)


/***************************************
*        Registers Constants
***************************************/

#if(GPS_UART_SCB_IRQ_INTERNAL)
    #define GPS_UART_ISR_NUMBER     ((uint8) GPS_UART_SCB_IRQ__INTC_NUMBER)
    #define GPS_UART_ISR_PRIORITY   ((uint8) GPS_UART_SCB_IRQ__INTC_PRIOR_NUM)
#endif /* (GPS_UART_SCB_IRQ_INTERNAL) */

#if(GPS_UART_UART_RX_WAKEUP_IRQ)
    #define GPS_UART_RX_WAKE_ISR_NUMBER     ((uint8) GPS_UART_RX_WAKEUP_IRQ__INTC_NUMBER)
    #define GPS_UART_RX_WAKE_ISR_PRIORITY   ((uint8) GPS_UART_RX_WAKEUP_IRQ__INTC_PRIOR_NUM)
#endif /* (GPS_UART_UART_RX_WAKEUP_IRQ) */

/* GPS_UART_CTRL_REG */
#define GPS_UART_CTRL_OVS_POS           (0u)  /* [3:0]   Oversampling factor                 */
#define GPS_UART_CTRL_EC_AM_MODE_POS    (8u)  /* [8]     Externally clocked address match    */
#define GPS_UART_CTRL_EC_OP_MODE_POS    (9u)  /* [9]     Externally clocked operation mode   */
#define GPS_UART_CTRL_EZBUF_MODE_POS    (10u) /* [10]    EZ buffer is enabled                */
#define GPS_UART_CTRL_ADDR_ACCEPT_POS   (16u) /* [16]    Put matched address in RX FIFO      */
#define GPS_UART_CTRL_BLOCK_POS         (17u) /* [17]    Ext and Int logic to resolve colide */
#define GPS_UART_CTRL_MODE_POS          (24u) /* [25:24] Operation mode                      */
#define GPS_UART_CTRL_ENABLED_POS       (31u) /* [31]    Enable SCB block                    */
#define GPS_UART_CTRL_OVS_MASK          ((uint32) 0x0Fu)
#define GPS_UART_CTRL_EC_AM_MODE        ((uint32) 0x01u << GPS_UART_CTRL_EC_AM_MODE_POS)
#define GPS_UART_CTRL_EC_OP_MODE        ((uint32) 0x01u << GPS_UART_CTRL_EC_OP_MODE_POS)
#define GPS_UART_CTRL_EZBUF_MODE        ((uint32) 0x01u << GPS_UART_CTRL_EZBUF_MODE_POS)
#define GPS_UART_CTRL_ADDR_ACCEPT       ((uint32) 0x01u << GPS_UART_CTRL_ADDR_ACCEPT_POS)
#define GPS_UART_CTRL_BLOCK             ((uint32) 0x01u << GPS_UART_CTRL_BLOCK_POS)
#define GPS_UART_CTRL_MODE_MASK         ((uint32) 0x03u << GPS_UART_CTRL_MODE_POS)
#define GPS_UART_CTRL_MODE_I2C          ((uint32) 0x00u)
#define GPS_UART_CTRL_MODE_SPI          ((uint32) 0x01u << GPS_UART_CTRL_MODE_POS)
#define GPS_UART_CTRL_MODE_UART         ((uint32) 0x02u << GPS_UART_CTRL_MODE_POS)
#define GPS_UART_CTRL_ENABLED           ((uint32) 0x01u << GPS_UART_CTRL_ENABLED_POS)

/* GPS_UART_STATUS_REG */
#define GPS_UART_STATUS_EC_BUSY_POS     (0u)  /* [0] Bus busy. Externaly clocked loigc access to EZ memory */
#define GPS_UART_STATUS_EC_BUSY         ((uint32) 0x0Fu)

/* GPS_UART_SPI_CTRL_REG  */
#define GPS_UART_SPI_CTRL_CONTINUOUS_POS        (0u)  /* [0]     Continuous or Separated SPI data transfers */
#define GPS_UART_SPI_CTRL_SELECT_PRECEDE_POS    (1u)  /* [1]     Precedes or coincides start of data frame  */
#define GPS_UART_SPI_CTRL_CPHA_POS              (2u)  /* [2]     SCLK phase                                 */
#define GPS_UART_SPI_CTRL_CPOL_POS              (3u)  /* [3]     SCLK polarity                              */
#define GPS_UART_SPI_CTRL_LATE_MISO_SAMPLE_POS  (4u)  /* [4]     Late MISO sample enabled                   */
#define GPS_UART_SPI_CTRL_LOOPBACK_POS          (16u) /* [16]    Local loopback control enabled             */
#define GPS_UART_SPI_CTRL_MODE_POS              (24u) /* [25:24] Submode of SPI operation                   */
#define GPS_UART_SPI_CTRL_SLAVE_SELECT_POS      (26u) /* [27:26] Selects SPI SS signal                      */
#define GPS_UART_SPI_CTRL_MASTER_MODE_POS       (31u) /* [31]    Master mode enabled                        */
#define GPS_UART_SPI_CTRL_CONTINUOUS            ((uint32) 0x01u)
#define GPS_UART_SPI_CTRL_SELECT_PRECEDE        ((uint32) 0x01u << GPS_UART_SPI_CTRL_SELECT_PRECEDE_POS)
#define GPS_UART_SPI_CTRL_SCLK_MODE_MASK        ((uint32) 0x03u << GPS_UART_SPI_CTRL_CPHA_POS)
#define GPS_UART_SPI_CTRL_CPHA                  ((uint32) 0x01u << GPS_UART_SPI_CTRL_CPHA_POS)
#define GPS_UART_SPI_CTRL_CPOL                  ((uint32) 0x01u << GPS_UART_SPI_CTRL_CPOL_POS)
#define GPS_UART_SPI_CTRL_LATE_MISO_SAMPLE      ((uint32) 0x01u << \
                                                                    GPS_UART_SPI_CTRL_LATE_MISO_SAMPLE_POS)
#define GPS_UART_SPI_CTRL_LOOPBACK              ((uint32) 0x01u << GPS_UART_SPI_CTRL_LOOPBACK_POS)
#define GPS_UART_SPI_CTRL_MODE_MASK             ((uint32) 0x03u << GPS_UART_SPI_CTRL_MODE_POS)
#define GPS_UART_SPI_CTRL_MODE_MOTOROLA         ((uint32) 0x00u)
#define GPS_UART_SPI_CTRL_MODE_TI               ((uint32) 0x01u << GPS_UART_CTRL_MODE_POS)
#define GPS_UART_SPI_CTRL_MODE_NS               ((uint32) 0x02u << GPS_UART_CTRL_MODE_POS)
#define GPS_UART_SPI_CTRL_SLAVE_SELECT_MASK     ((uint32) 0x03u << GPS_UART_SPI_CTRL_SLAVE_SELECT_POS)
#define GPS_UART_SPI_CTRL_SLAVE_SELECT0         ((uint32) 0x00u)
#define GPS_UART_SPI_CTRL_SLAVE_SELECT1         ((uint32) 0x01u << GPS_UART_SPI_CTRL_SLAVE_SELECT_POS)
#define GPS_UART_SPI_CTRL_SLAVE_SELECT2         ((uint32) 0x02u << GPS_UART_SPI_CTRL_SLAVE_SELECT_POS)
#define GPS_UART_SPI_CTRL_SLAVE_SELECT3         ((uint32) 0x03u << GPS_UART_SPI_CTRL_SLAVE_SELECT_POS)
#define GPS_UART_SPI_CTRL_MASTER                ((uint32) 0x01u << GPS_UART_SPI_CTRL_MASTER_MODE_POS)
#define GPS_UART_SPI_CTRL_SLAVE                 ((uint32) 0x00u)

/* GPS_UART_SPI_STATUS_REG  */
#define GPS_UART_SPI_STATUS_BUS_BUSY_POS    (0u)  /* [0]    Bus busy - slave selected */
#define GPS_UART_SPI_STATUS_EZBUF_ADDR_POS  (8u)  /* [15:8] EzAddress                 */
#define GPS_UART_SPI_STATUS_BUS_BUSY        ((uint32) 0x01u)
#define GPS_UART_SPI_STATUS_EZBUF_ADDR_MASK ((uint32) 0xFFu << GPS_UART_I2C_STATUS_EZBUF_ADDR_POS)

/* GPS_UART_UART_CTRL */
#define GPS_UART_UART_CTRL_LOOPBACK_POS         (16u) /* [16] Loopback     */
#define GPS_UART_UART_CTRL_MODE_POS             (24u) /* [24] UART subMode */
#define GPS_UART_UART_CTRL_LOOPBACK             ((uint32) 0x01u << GPS_UART_UART_CTRL_LOOPBACK_POS)
#define GPS_UART_UART_CTRL_MODE_UART_STD        ((uint32) 0x00u)
#define GPS_UART_UART_CTRL_MODE_UART_SMARTCARD  ((uint32) 0x01u << GPS_UART_UART_CTRL_MODE_POS)
#define GPS_UART_UART_CTRL_MODE_UART_IRDA       ((uint32) 0x02u << GPS_UART_UART_CTRL_MODE_POS)
#define GPS_UART_UART_CTRL_MODE_MASK            ((uint32) 0x03u << GPS_UART_UART_CTRL_MODE_POS)

/* GPS_UART_UART_TX_CTRL */
#define GPS_UART_UART_TX_CTRL_STOP_BITS_POS         (0u)  /* [2:0] Stop bits: (Stop bits + 1) * 0.5 period */
#define GPS_UART_UART_TX_CTRL_PARITY_POS            (4u)  /* [4]   Parity bit                              */
#define GPS_UART_UART_TX_CTRL_PARITY_ENABLED_POS    (5u)  /* [5]   Parity enable                           */
#define GPS_UART_UART_TX_CTRL_RETRY_ON_NACK_POS     (8u)  /* [8]   Smart Card: re-send frame on NACK       */
#define GPS_UART_UART_TX_CTRL_ONE_STOP_BIT          ((uint32) 0x01u)
#define GPS_UART_UART_TX_CTRL_ONE_HALF_STOP_BITS    ((uint32) 0x02u)
#define GPS_UART_UART_TX_CTRL_TWO_STOP_BITS         ((uint32) 0x03u)
#define GPS_UART_UART_TX_CTRL_STOP_BITS_MASK        ((uint32) 0x07u)
#define GPS_UART_UART_TX_CTRL_PARITY                ((uint32) 0x01u << \
                                                                    GPS_UART_UART_TX_CTRL_PARITY_POS)
#define GPS_UART_UART_TX_CTRL_PARITY_ENABLED        ((uint32) 0x01u << \
                                                                    GPS_UART_UART_TX_CTRL_PARITY_ENABLED_POS)
#define GPS_UART_UART_TX_CTRL_RETRY_ON_NACK         ((uint32) 0x01u << \
                                                                    GPS_UART_UART_TX_CTRL_RETRY_ON_NACK_POS)

/* GPS_UART_UART_RX_CTRL */
#define GPS_UART_UART_RX_CTRL_STOP_BITS_POS             (0u)  /* [2:0] Stop bits: (Stop bits + 1) * 0.5 prd   */
#define GPS_UART_UART_RX_CTRL_PARITY_POS                (4u)  /* [4]   Parity bit                             */
#define GPS_UART_UART_RX_CTRL_PARITY_ENABLED_POS        (5u)  /* [5]   Parity enable                          */
#define GPS_UART_UART_RX_CTRL_POLARITY_POS              (6u)  /* [6]   IrDA: inverts polarity of RX signal    */
#define GPS_UART_UART_RX_CTRL_DROP_ON_PARITY_ERR_POS    (8u)  /* [8]   Drop and lost RX FIFO on parity error  */
#define GPS_UART_UART_RX_CTRL_DROP_ON_FRAME_ERR_POS     (9u)  /* [9]   Drop and lost RX FIFO on frame error   */
#define GPS_UART_UART_RX_CTRL_MP_MODE_POS               (10u) /* [10]  Multi-processor mode                   */
#define GPS_UART_UART_RX_CTRL_LIN_MODE_POS              (12u) /* [12]  Lin mode: applicable for UART Standart */
#define GPS_UART_UART_RX_CTRL_SKIP_START_POS            (13u) /* [13]  Skip start not: only for UART Standart */
#define GPS_UART_UART_RX_CTRL_BREAK_WIDTH_POS           (16u) /* [19:16]  Break width: (Break width + 1)      */
#define GPS_UART_UART_TX_CTRL_ONE_STOP_BIT              ((uint32) 0x01u)
#define GPS_UART_UART_TX_CTRL_ONE_HALF_STOP_BITS        ((uint32) 0x02u)
#define GPS_UART_UART_TX_CTRL_TWO_STOP_BITS             ((uint32) 0x03u)
#define GPS_UART_UART_RX_CTRL_STOP_BITS_MASK            ((uint32) 0x07u)
#define GPS_UART_UART_RX_CTRL_PARITY                    ((uint32) 0x01u << \
                                                                    GPS_UART_UART_RX_CTRL_PARITY_POS)
#define GPS_UART_UART_RX_CTRL_PARITY_ENABLED            ((uint32) 0x01u << \
                                                                    GPS_UART_UART_RX_CTRL_PARITY_ENABLED_POS)
#define GPS_UART_UART_RX_CTRL_POLARITY                  ((uint32) 0x01u << \
                                                                    GPS_UART_UART_RX_CTRL_POLARITY_POS)
#define GPS_UART_UART_RX_CTRL_DROP_ON_PARITY_ERR        ((uint32) 0x01u << \
                                                                   GPS_UART_UART_RX_CTRL_DROP_ON_PARITY_ERR_POS)
#define GPS_UART_UART_RX_CTRL_DROP_ON_FRAME_ERR         ((uint32) 0x01u << \
                                                                    GPS_UART_UART_RX_CTRL_DROP_ON_FRAME_ERR_POS)
#define GPS_UART_UART_RX_CTRL_MP_MODE                   ((uint32) 0x01u << \
                                                                    GPS_UART_UART_RX_CTRL_MP_MODE_POS)
#define GPS_UART_UART_RX_CTRL_LIN_MODE                  ((uint32) 0x01u << \
                                                                    GPS_UART_UART_RX_CTRL_LIN_MODE_POS)
#define GPS_UART_UART_RX_CTRL_SKIP_START                ((uint32) 0x01u << \
                                                                    GPS_UART_UART_RX_CTRL_SKIP_START_POS)
#define GPS_UART_UART_RX_CTRL_BREAK_WIDTH_MASK          ((uint32) 0x0Fu << \
                                                                    GPS_UART_UART_RX_CTRL_BREAK_WIDTH_POS)
/* GPS_UART_UART_RX_STATUS_REG */
#define GPS_UART_UART_RX_STATUS_BR_COUNTER_POS     (0u)  /* [11:0] Baute Rate counter */
#define GPS_UART_UART_RX_STATUS_BR_COUNTER_MASK    ((uint32) 0xFFFu)

/* GPS_UART_I2C_CTRL */
#define GPS_UART_I2C_CTRL_HIGH_PHASE_OVS_POS           (0u)   /* [3:0] Oversampling factor high: masrer only */
#define GPS_UART_I2C_CTRL_LOW_PHASE_OVS_POS            (4u)   /* [7:4] Oversampling factor low:  masrer only */
#define GPS_UART_I2C_CTRL_M_READY_DATA_ACK_POS         (8u)   /* [8]   Master ACKs data wgile RX FIFO != FULL*/
#define GPS_UART_I2C_CTRL_M_NOT_READY_DATA_NACK_POS    (9u)   /* [9]   Master NACKs data if RX FIFO ==  FULL */
#define GPS_UART_I2C_CTRL_S_GENERAL_IGNORE_POS         (11u)  /* [11]  Slave ignores General call            */
#define GPS_UART_I2C_CTRL_S_READY_ADDR_ACK_POS         (12u)  /* [12]  Slave ACKs Address if RX FIFO != FULL */
#define GPS_UART_I2C_CTRL_S_READY_DATA_ACK_POS         (13u)  /* [13]  Slave ACKs data while RX FIFO == FULL */
#define GPS_UART_I2C_CTRL_S_NOT_READY_ADDR_NACK_POS    (14u)  /* [14]  Slave NACKs address if RX FIFO == FULL*/
#define GPS_UART_I2C_CTRL_S_NOT_READY_DATA_NACK_POS    (15u)  /* [15]  Slave NACKs data if RX FIFO is  FULL  */
#define GPS_UART_I2C_CTRL_LOOPBACK_POS                 (16u)  /* [16]  Loopback                              */
#define GPS_UART_I2C_CTRL_SLAVE_MODE_POS               (30u)  /* [30]  Slave mode enabled                    */
#define GPS_UART_I2C_CTRL_MASTER_MODE_POS              (31u)  /* [31]  Master mode enabled                   */
#define GPS_UART_I2C_CTRL_HIGH_PHASE_OVS_MASK  ((uint32) 0x0Fu)
#define GPS_UART_I2C_CTRL_LOW_PHASE_OVS_MASK   ((uint32) 0x0Fu << \
                                                                GPS_UART_I2C_CTRL_LOW_PHASE_OVS_POS)
#define GPS_UART_I2C_CTRL_M_READY_DATA_ACK      ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CTRL_M_READY_DATA_ACK_POS)
#define GPS_UART_I2C_CTRL_M_NOT_READY_DATA_NACK ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CTRL_M_NOT_READY_DATA_NACK_POS)
#define GPS_UART_I2C_CTRL_S_GENERAL_IGNORE      ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CTRL_S_GENERAL_IGNORE_POS)
#define GPS_UART_I2C_CTRL_S_READY_ADDR_ACK      ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CTRL_S_READY_ADDR_ACK_POS)
#define GPS_UART_I2C_CTRL_S_READY_DATA_ACK      ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CTRL_S_READY_DATA_ACK_POS)
#define GPS_UART_I2C_CTRL_S_NOT_READY_ADDR_NACK ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CTRL_S_NOT_READY_ADDR_NACK_POS)
#define GPS_UART_I2C_CTRL_S_NOT_READY_DATA_NACK ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CTRL_S_NOT_READY_DATA_NACK_POS)
#define GPS_UART_I2C_CTRL_LOOPBACK              ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CTRL_LOOPBACK_POS)
#define GPS_UART_I2C_CTRL_SLAVE_MODE            ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CTRL_SLAVE_MODE_POS)
#define GPS_UART_I2C_CTRL_MASTER_MODE           ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CTRL_MASTER_MODE_POS)
#define GPS_UART_I2C_CTRL_SLAVE_MASTER_MODE_MASK    ((uint32) 0x03u << \
                                                                GPS_UART_I2C_CTRL_SLAVE_MODE_POS)

/* GPS_UART_I2C_STATUS_REG  */
#define GPS_UART_I2C_STATUS_BUS_BUSY_POS    (0u)  /* [0]    Bus busy: internally clocked */
#define GPS_UART_I2C_STATUS_S_READ_POS      (4u)  /* [4]    Slave is read by master      */
#define GPS_UART_I2C_STATUS_M_READ_POS      (5u)  /* [5]    Master reads Slave           */
#define GPS_UART_I2C_STATUS_EZBUF_ADDR_POS  (8u)  /* [15:8] EZAddress                    */
#define GPS_UART_I2C_STATUS_BUS_BUSY        ((uint32) 0x01u)
#define GPS_UART_I2C_STATUS_S_READ          ((uint32) 0x01u << GPS_UART_I2C_STATUS_S_READ_POS)
#define GPS_UART_I2C_STATUS_M_READ          ((uint32) 0x01u << GPS_UART_I2C_STATUS_M_READ_POS)
#define GPS_UART_I2C_STATUS_EZBUF_ADDR_MASK ((uint32) 0xFFu << GPS_UART_I2C_STATUS_EZBUF_ADDR_POS)

/* GPS_UART_I2C_MASTER_CMD_REG */
#define GPS_UART_I2C_MASTER_CMD_M_START_POS             (0u)  /* [0] Master generate Start                */
#define GPS_UART_I2C_MASTER_CMD_M_START_ON_IDLE_POS     (1u)  /* [1] Master generate Start if bus is free */
#define GPS_UART_I2C_MASTER_CMD_M_ACK_POS               (2u)  /* [2] Master generate ACK                  */
#define GPS_UART_I2C_MASTER_CMD_M_NACK_POS              (3u)  /* [3] Master generate NACK                 */
#define GPS_UART_I2C_MASTER_CMD_M_STOP_POS              (4u)  /* [4] Master generate Stop                 */
#define GPS_UART_I2C_MASTER_CMD_M_START         ((uint32) 0x01u)
#define GPS_UART_I2C_MASTER_CMD_M_START_ON_IDLE ((uint32) 0x01u << \
                                                                   GPS_UART_I2C_MASTER_CMD_M_START_ON_IDLE_POS)
#define GPS_UART_I2C_MASTER_CMD_M_ACK           ((uint32) 0x01u << \
                                                                   GPS_UART_I2C_MASTER_CMD_M_ACK_POS)
#define GPS_UART_I2C_MASTER_CMD_M_NACK          ((uint32) 0x01u << \
                                                                    GPS_UART_I2C_MASTER_CMD_M_NACK_POS)
#define GPS_UART_I2C_MASTER_CMD_M_STOP          ((uint32) 0x01u << \
                                                                    GPS_UART_I2C_MASTER_CMD_M_STOP_POS)

/* GPS_UART_I2C_SLAVE_CMD_REG  */
#define GPS_UART_I2C_SLAVE_CMD_S_ACK_POS    (0u)  /* [0] Slave generate ACK  */
#define GPS_UART_I2C_SLAVE_CMD_S_NACK_POS   (1u)  /* [1] Slave generate NACK */
#define GPS_UART_I2C_SLAVE_CMD_S_ACK        ((uint32) 0x01u)
#define GPS_UART_I2C_SLAVE_CMD_S_NACK       ((uint32) 0x01u << GPS_UART_I2C_SLAVE_CMD_S_NACK_POS)

#define GPS_UART_I2C_SLAVE_CMD_S_ACK_POS    (0u)  /* [0] Slave generate ACK  */
#define GPS_UART_I2C_SLAVE_CMD_S_NACK_POS   (1u)  /* [1] Slave generate NACK */
#define GPS_UART_I2C_SLAVE_CMD_S_ACK        ((uint32) 0x01u)
#define GPS_UART_I2C_SLAVE_CMD_S_NACK       ((uint32) 0x01u << GPS_UART_I2C_SLAVE_CMD_S_NACK_POS)
/* GPS_UART_I2C_CFG  */
#define GPS_UART_I2C_CFG_SDA_FILT_HYS_POS           (0u)  /* [1:0]   Trim bits for the I2C SDA filter         */
#define GPS_UART_I2C_CFG_SDA_FILT_TRIM_POS          (2u)  /* [3:2]   Trim bits for the I2C SDA filter         */
#define GPS_UART_I2C_CFG_SCL_FILT_HYS_POS           (4u)  /* [5:4]   Trim bits for the I2C SCL filter         */
#define GPS_UART_I2C_CFG_SCL_FILT_TRIM_POS          (6u)  /* [7:6]   Trim bits for the I2C SCL filter         */
#define GPS_UART_I2C_CFG_SDA_FILT_OUT_HYS_POS       (8u)  /* [9:8]   Trim bits for I2C SDA filter output path */
#define GPS_UART_I2C_CFG_SDA_FILT_OUT_TRIM_POS      (10u) /* [11:10] Trim bits for I2C SDA filter output path */
#define GPS_UART_I2C_CFG_SDA_FILT_HS_POS            (16u) /* [16]    '0': 50 ns filter, '1': 10 ns filter     */
#define GPS_UART_I2C_CFG_SDA_FILT_ENABLED_POS       (17u) /* [17]    I2C SDA filter enabled                   */
#define GPS_UART_I2C_CFG_SCL_FILT_HS_POS            (24u) /* [24]    '0': 50 ns filter, '1': 10 ns filter     */
#define GPS_UART_I2C_CFG_SCL_FILT_ENABLED_POS       (25u) /* [25]    I2C SCL filter enabled                   */
#define GPS_UART_I2C_CFG_SDA_FILT_OUT_HS_POS        (26u) /* [26]    '0': 50ns filter, '1': 10 ns filter      */
#define GPS_UART_I2C_CFG_SDA_FILT_OUT_ENABLED_POS   (27u) /* [27]    I2C SDA output delay filter enabled      */
#define GPS_UART_I2C_CFG_SDA_FILT_HYS_MASK          ((uint32) 0x00u)
#define GPS_UART_I2C_CFG_SDA_FILT_TRIM_MASK         ((uint32) 0x03u << \
                                                                GPS_UART_I2C_CFG_SDA_FILT_TRIM_POS)
#define GPS_UART_I2C_CFG_SCL_FILT_HYS_MASK          ((uint32) 0x03u << \
                                                                GPS_UART_I2C_CFG_SCL_FILT_HYS_POS)
#define GPS_UART_I2C_CFG_SCL_FILT_TRIM_MASK         ((uint32) 0x03u << \
                                                                GPS_UART_I2C_CFG_SCL_FILT_TRIM_POS)
#define GPS_UART_I2C_CFG_SDA_FILT_OUT_HYS_MASK      ((uint32) 0x03u << \
                                                                GPS_UART_I2C_CFG_SDA_FILT_OUT_HYS_POS)
#define GPS_UART_I2C_CFG_SDA_FILT_OUT_TRIM_MASK     ((uint32) 0x03u << \
                                                                GPS_UART_I2C_CFG_SDA_FILT_OUT_TRIM_POS)
#define GPS_UART_I2C_CFG_SDA_FILT_HS                ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CFG_SDA_FILT_HS_POS)
#define GPS_UART_I2C_CFG_SDA_FILT_ENABLED           ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CFG_SDA_FILT_ENABLED_POS)
#define GPS_UART_I2C_CFG_SCL_FILT_HS                ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CFG_SCL_FILT_HS_POS)
#define GPS_UART_I2C_CFG_SCL_FILT_ENABLED           ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CFG_SCL_FILT_ENABLED_POS)
#define GPS_UART_I2C_CFG_SDA_FILT_OUT_HS            ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CFG_SDA_FILT_OUT_HS_POS)
#define GPS_UART_I2C_CFG_SDA_FILT_OUT_ENABLED       ((uint32) 0x01u << \
                                                                GPS_UART_I2C_CFG_SDA_FILT_OUT_ENABLED_POS)

/* GPS_UART_TX_CTRL_REG */
#define GPS_UART_TX_CTRL_DATA_WIDTH_POS     (0u)  /* [3:0] Dataframe width: (Data width - 1) */
#define GPS_UART_TX_CTRL_MSB_FIRST_POS      (8u)  /* [8]   MSB first shifter-out             */
#define GPS_UART_TX_CTRL_ENABLED_POS        (31u) /* [31]  Transmitter enabled               */
#define GPS_UART_TX_CTRL_DATA_WIDTH_MASK    ((uint32) 0x0Fu)
#define GPS_UART_TX_CTRL_MSB_FIRST          ((uint32) 0x01u << GPS_UART_TX_CTRL_MSB_FIRST_POS)
#define GPS_UART_TX_CTRL_LSB_FIRST          ((uint32) 0x00u)
#define GPS_UART_TX_CTRL_ENABLED            ((uint32) 0x01u << GPS_UART_TX_CTRL_ENABLED_POS)

/* GPS_UART_TX_CTRL_FIFO_REG */
#define GPS_UART_TX_FIFO_CTRL_TRIGGER_LEVEL_POS     (0u)  /* [2:0] Trigger level                              */
#define GPS_UART_TX_FIFO_CTRL_CLEAR_POS             (16u) /* [16]  Clear TX FIFO: claared after set           */
#define GPS_UART_TX_FIFO_CTRL_FREEZE_POS            (17u) /* [17]  Freeze TX FIFO: HW do not inc read pointer */
#define GPS_UART_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK    ((uint32) 0x07u)
#define GPS_UART_TX_FIFO_CTRL_CLEAR                 ((uint32) 0x01u << GPS_UART_TX_FIFO_CTRL_CLEAR_POS)
#define GPS_UART_TX_FIFO_CTRL_FREEZE                ((uint32) 0x01u << GPS_UART_TX_FIFO_CTRL_FREEZE_POS)

/* GPS_UART_TX_FIFO_STATUS_REG */
#define GPS_UART_TX_FIFO_STATUS_USED_POS    (0u)  /* [3:0]   Amount of entries in TX FIFO */
#define GPS_UART_TX_FIFO_SR_VALID_POS       (15u) /* [15]    Shifter status of TX FIFO    */
#define GPS_UART_TX_FIFO_STATUS_RD_PTR_POS  (16u) /* [18:16] TX FIFO read pointer         */
#define GPS_UART_TX_FIFO_STATUS_WR_PTR_POS  (24u) /* [26:24] TX FIFO write pointer        */
#define GPS_UART_TX_FIFO_STATUS_USED_MASK   ((uint32) 0x0Fu)
#define GPS_UART_TX_FIFO_SR_VALID           ((uint32) 0x01u << GPS_UART_TX_FIFO_SR_VALID_POS)
#define GPS_UART_TX_FIFO_STATUS_RD_PTR_MASK ((uint32) 0x07u << GPS_UART_TX_FIFO_STATUS_RD_PTR_POS)
#define GPS_UART_TX_FIFO_STATUS_WR_PTR_MASK ((uint32) 0x07u << GPS_UART_TX_FIFO_STATUS_WR_PTR_POS)

/* GPS_UART_TX_FIFO_WR_REG */
#define GPS_UART_TX_FIFO_WR_POS    (0u)  /* [15:0] Data written into TX FIFO */
#define GPS_UART_TX_FIFO_WR_MASK   ((uint32) 0xFFu)

/* GPS_UART_RX_CTRL_REG */
#define GPS_UART_RX_CTRL_DATA_WIDTH_POS     (0u)  /* [3:0] Dataframe width: (Data width - 1) */
#define GPS_UART_RX_CTRL_MSB_FIRST_POS      (8u)  /* [8]   MSB first shifter-out             */
#define GPS_UART_RX_CTRL_MEDIAN_POS         (9u)  /* [9]   Median filter                     */
#define GPS_UART_RX_CTRL_ENABLED_POS        (31u) /* [31]  Receiver enabled                  */
#define GPS_UART_RX_CTRL_DATA_WIDTH_MASK    ((uint32) 0x0Fu)
#define GPS_UART_RX_CTRL_MSB_FIRST          ((uint32) 0x01u << GPS_UART_RX_CTRL_MSB_FIRST_POS)
#define GPS_UART_RX_CTRL_LSB_FIRST          ((uint32) 0x00u)
#define GPS_UART_RX_CTRL_MEDIAN             ((uint32) 0x01u << GPS_UART_RX_CTRL_MEDIAN_POS)
#define GPS_UART_RX_CTRL_ENABLED            ((uint32) 0x01u << GPS_UART_RX_CTRL_ENABLED_POS)


/* GPS_UART_RX_FIFO_CTRL_REG */
#define GPS_UART_RX_FIFO_CTRL_TRIGGER_LEVEL_POS     (0u)   /* [2:0] Trigger level                            */
#define GPS_UART_RX_FIFO_CTRL_CLEAR_POS             (16u)  /* [16]  Clear RX FIFO: claar after set           */
#define GPS_UART_RX_FIFO_CTRL_FREEZE_POS            (17u)  /* [17]  Freeze RX FIFO: HW writes has not effect */
#define GPS_UART_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK    ((uint32) 0x07u)
#define GPS_UART_RX_FIFO_CTRL_CLEAR                 ((uint32) 0x01u << GPS_UART_RX_FIFO_CTRL_CLEAR_POS)
#define GPS_UART_RX_FIFO_CTRL_FREEZE                ((uint32) 0x01u << GPS_UART_RX_FIFO_CTRL_FREEZE_POS)

/* GPS_UART_RX_FIFO_STATUS_REG */
#define GPS_UART_RX_FIFO_STATUS_USED_POS    (0u)   /* [3:0]   Amount of entries in RX FIFO */
#define GPS_UART_RX_FIFO_SR_VALID_POS       (15u)  /* [15]    Shifter status of RX FIFO    */
#define GPS_UART_RX_FIFO_STATUS_RD_PTR_POS  (16u)  /* [18:16] RX FIFO read pointer         */
#define GPS_UART_RX_FIFO_STATUS_WR_PTR_POS  (24u)  /* [26:24] RX FIFO write pointer        */
#define GPS_UART_RX_FIFO_STATUS_USED_MASK   ((uint32) 0x0Fu)
#define GPS_UART_RX_FIFO_SR_VALID           ((uint32) 0x01u << GPS_UART_RX_FIFO_SR_VALID_POS)
#define GPS_UART_RX_FIFO_STATUS_RD_PTR_MASK ((uint32) 0x07u << GPS_UART_RX_FIFO_STATUS_RD_PTR_POS)
#define GPS_UART_RX_FIFO_STATUS_WR_PTR_MASK ((uint32) 0x07u << GPS_UART_RX_FIFO_STATUS_WR_PTR_POS)

/* GPS_UART_RX_MATCH_REG */
#define GPS_UART_RX_MATCH_ADDR_POS     (0u)  /* [7:0]   Slave address                        */
#define GPS_UART_RX_MATCH_MASK_POS     (16u) /* [23:16] Slave address mask: 0 - doesn't care */
#define GPS_UART_RX_MATCH_ADDR_MASK    ((uint32) 0xFFu)
#define GPS_UART_RX_MATCH_MASK_MASK    ((uint32) 0xFFu << GPS_UART_RX_MATCH_MASK_POS)

/* GPS_UART_RX_FIFO_WR_REG */
#define GPS_UART_RX_FIFO_RD_POS    (0u)  /* [15:0] Data read from RX FIFO */
#define GPS_UART_RX_FIFO_RD_MASK   ((uint32) 0xFFu)

/* GPS_UART_RX_FIFO_RD_SILENT_REG */
#define GPS_UART_RX_FIFO_RD_SILENT_POS     (0u)  /* [15:0] Data read from RX FIFO: not remove data from FIFO */
#define GPS_UART_RX_FIFO_RD_SILENT_MASK    ((uint32) 0xFFu)

/* GPS_UART_RX_FIFO_RD_SILENT_REG */
#define GPS_UART_RX_FIFO_RD_SILENT_POS     (0u)  /* [15:0] Data read from RX FIFO: not remove data from FIFO */
#define GPS_UART_RX_FIFO_RD_SILENT_MASK    ((uint32) 0xFFu)

/* GPS_UART_EZBUF_DATA_REG */
#define GPS_UART_EZBUF_DATA_POS   (0u)  /* [7:0] Data from Ez Memory */
#define GPS_UART_EZBUF_DATA_MASK  ((uint32) 0xFFu)

/*  GPS_UART_INTR_CAUSE_REG */
#define GPS_UART_INTR_CAUSE_MASTER_POS  (0u)  /* [0] Master interrupt active                 */
#define GPS_UART_INTR_CAUSE_SLAVE_POS   (1u)  /* [1] Slave interrupt active                  */
#define GPS_UART_INTR_CAUSE_TX_POS      (2u)  /* [2] Transmitter interrupt active            */
#define GPS_UART_INTR_CAUSE_RX_POS      (3u)  /* [3] Receiver interrupt active               */
#define GPS_UART_INTR_CAUSE_I2C_EC_POS  (4u)  /* [4] Externally clock I2C interrupt active   */
#define GPS_UART_INTR_CAUSE_SPI_EC_POS  (5u)  /* [5] Externally clocked SPI interrupt active */
#define GPS_UART_INTR_CAUSE_MASTER      ((uint32) 0x01u)
#define GPS_UART_INTR_CAUSE_SLAVE       ((uint32) 0x01u << GPS_UART_INTR_CAUSE_SLAVE_POS)
#define GPS_UART_INTR_CAUSE_TX          ((uint32) 0x01u << GPS_UART_INTR_CAUSE_TX_POS)
#define GPS_UART_INTR_CAUSE_RX          ((uint32) 0x01u << GPS_UART_INTR_CAUSE_RX_POS)
#define GPS_UART_INTR_CAUSE_I2C_EC      ((uint32) 0x01u << GPS_UART_INTR_CAUSE_I2C_EC_POS)
#define GPS_UART_INTR_CAUSE_SPI_EC      ((uint32) 0x01u << GPS_UART_INTR_CAUSE_SPI_EC_POS)

/* GPS_UART_INTR_SPI_EC_REG, GPS_UART_INTR_SPI_EC_MASK_REG, GPS_UART_INTR_SPI_EC_MASKED_REG */
#define GPS_UART_INTR_SPI_EC_WAKE_UP_POS          (0u)  /* [0] Address match: triggers wakeup of chip */
#define GPS_UART_INTR_SPI_EC_EZBUF_STOP_POS       (1u)  /* [1] Externally clocked Stop detected       */
#define GPS_UART_INTR_SPI_EC_EZBUF_WRITE_STOP_POS (2u)  /* [2] Externally clocked Write Stop detected */
#define GPS_UART_INTR_SPI_EC_WAKE_UP              ((uint32) 0x01u)
#define GPS_UART_INTR_SPI_EC_EZBUF_STOP           ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_SPI_EC_EZBUF_STOP_POS)
#define GPS_UART_INTR_SPI_EC_EZBUF_WRITE_STOP     ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_SPI_EC_EZBUF_WRITE_STOP_POS)

/* GPS_UART_INTR_I2C_EC, GPS_UART_INTR_I2C_EC_MASK, GPS_UART_INTR_I2C_EC_MASKED */
#define GPS_UART_INTR_I2C_EC_WAKE_UP_POS          (0u)  /* [0] Address match: triggers wakeup of chip */
#define GPS_UART_INTR_I2C_EC_EZBUF_STOP_POS       (1u)  /* [1] Externally clocked Stop detected       */
#define GPS_UART_INTR_I2C_EC_EZBUF_WRITE_STOP_POS (2u)  /* [2] Externally clocked Write Stop detected */
#define GPS_UART_INTR_I2C_EC_WAKE_UP              ((uint32) 0x01u)
#define GPS_UART_INTR_I2C_EC_EZBUF_STOP           ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_I2C_EC_EZBUF_STOP_POS)
#define GPS_UART_INTR_I2C_EC_EZBUF_WRITE_STOP     ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_I2C_EC_EZBUF_WRITE_STOP_POS)

/* GPS_UART_INTR_MASTER, GPS_UART_INTR_MASTER_SET,
   GPS_UART_INTR_MASTER_MASK, GPS_UART_INTR_MASTER_MASKED */
#define GPS_UART_INTR_MASTER_I2C_ARB_LOST_POS   (0u)  /* [0] Master lost arbitration                          */
#define GPS_UART_INTR_MASTER_I2C_NACK_POS       (1u)  /* [1] Master receives NACK: address or write to slave  */
#define GPS_UART_INTR_MASTER_I2C_ACK_POS        (2u)  /* [2] Master receives NACK: address or write to slave  */
#define GPS_UART_INTR_MASTER_I2C_STOP_POS       (4u)  /* [4] Master detects the Stop: only self generated Stop*/
#define GPS_UART_INTR_MASTER_I2C_BUS_ERROR_POS  (8u)  /* [8] Master detects bus error: misplaced Start or Stop*/
#define GPS_UART_INTR_MASTER_SPI_DONE_POS       (9u)  /* [9] Master complete trasfer: Only for SPI            */
#define GPS_UART_INTR_MASTER_I2C_ARB_LOST       ((uint32) 0x01u)
#define GPS_UART_INTR_MASTER_I2C_NACK           ((uint32) 0x01u << GPS_UART_INTR_MASTER_I2C_NACK_POS)
#define GPS_UART_INTR_MASTER_I2C_ACK            ((uint32) 0x01u << GPS_UART_INTR_MASTER_I2C_ACK_POS)
#define GPS_UART_INTR_MASTER_I2C_STOP           ((uint32) 0x01u << GPS_UART_INTR_MASTER_I2C_STOP_POS)
#define GPS_UART_INTR_MASTER_I2C_BUS_ERROR      ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_MASTER_I2C_BUS_ERROR_POS)
#define GPS_UART_INTR_MASTER_SPI_DONE           ((uint32) 0x01u << GPS_UART_INTR_MASTER_SPI_DONE_POS)

/*
* GPS_UART_INTR_SLAVE, GPS_UART_INTR_SLAVE_SET,
* GPS_UART_INTR_SLAVE_MASK, GPS_UART_INTR_SLAVE_MASKED
*/
#define GPS_UART_INTR_SLAVE_I2C_ARB_LOST_POS         (0u)  /* [0]  Slave lost arbitration                   */
#define GPS_UART_INTR_SLAVE_I2C_NACK_POS             (1u)  /* [1]  Slave receives NACK: master reads data   */
#define GPS_UART_INTR_SLAVE_I2C_ACK_POS              (2u)  /* [2]  Slave receives ACK: master reads data    */
#define GPS_UART_INTR_SLAVE_I2C_WRITE_STOP_POS       (3u)  /* [3]  Slave detects end of write transaction   */
#define GPS_UART_INTR_SLAVE_I2C_STOP_POS             (4u)  /* [4]  Slave detects end of transaction intened */
#define GPS_UART_INTR_SLAVE_I2C_START_POS            (5u)  /* [5]  Slave detects Start                      */
#define GPS_UART_INTR_SLAVE_I2C_ADDR_MATCH_POS       (6u)  /* [6]  Slave address matches                    */
#define GPS_UART_INTR_SLAVE_I2C_GENERAL_POS          (7u)  /* [7]  General call received                    */
#define GPS_UART_INTR_SLAVE_I2C_BUS_ERROR_POS        (8u)  /* [8]  Slave detects bus error                  */
#define GPS_UART_INTR_SLAVE_SPI_EZBUF_WRITE_STOP_POS (9u)  /* [9]  Slave write complete: Only for SPI       */
#define GPS_UART_INTR_SLAVE_SPI_EZBUF_STOP_POS       (10u) /* [10] Slave end of transaciton: Only for SPI   */
#define GPS_UART_INTR_SLAVE_SPI_BUS_ERROR_POS        (11u) /* [11] Slave detects bus error: Only for SPI    */
#define GPS_UART_INTR_SLAVE_I2C_ARB_LOST             ((uint32) 0x01u)
#define GPS_UART_INTR_SLAVE_I2C_NACK                 ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_SLAVE_I2C_NACK_POS)
#define GPS_UART_INTR_SLAVE_I2C_ACK                  ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_SLAVE_I2C_ACK_POS)
#define GPS_UART_INTR_SLAVE_I2C_WRITE_STOP           ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_SLAVE_I2C_WRITE_STOP_POS)
#define GPS_UART_INTR_SLAVE_I2C_STOP                 ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_SLAVE_I2C_STOP_POS)
#define GPS_UART_INTR_SLAVE_I2C_START                ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_SLAVE_I2C_START_POS)
#define GPS_UART_INTR_SLAVE_I2C_ADDR_MATCH           ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_SLAVE_I2C_ADDR_MATCH_POS)
#define GPS_UART_INTR_SLAVE_I2C_GENERAL              ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_SLAVE_I2C_GENERAL_POS)
#define GPS_UART_INTR_SLAVE_I2C_BUS_ERROR            ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_SLAVE_I2C_BUS_ERROR_POS)
#define GPS_UART_INTR_SLAVE_SPI_EZBUF_WRITE_STOP     ((uint32) 0x01u << \
                                                                   GPS_UART_INTR_SLAVE_SPI_EZBUF_WRITE_STOP_POS)
#define GPS_UART_INTR_SLAVE_SPI_EZBUF_STOP           ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_SLAVE_SPI_EZBUF_STOP_POS)
#define GPS_UART_INTR_SLAVE_SPI_BUS_ERROR           ((uint32) 0x01u << \
                                                                    GPS_UART_INTR_SLAVE_SPI_BUS_ERROR_POS)

/*
* GPS_UART_INTR_TX, GPS_UART_INTR_TX_SET,
* GPS_UART_INTR_TX_MASK, GPS_UART_INTR_TX_MASKED
*/
#define GPS_UART_INTR_TX_TRIGGER_POS        (0u)  /* [0]  Trigger on TX FIFO entires                       */
#define GPS_UART_INTR_TX_NOT_FULL_POS       (1u)  /* [1]  TX FIFO is not full                              */
#define GPS_UART_INTR_TX_EMPTY_POS          (4u)  /* [4]  TX FIFO is empty                                 */
#define GPS_UART_INTR_TX_OVERFLOW_POS       (5u)  /* [5]  Attempt to write to a full TX FIFO               */
#define GPS_UART_INTR_TX_UNDERFLOW_POS      (6u)  /* [6]  Attempt to read from an empty TX FIFO            */
#define GPS_UART_INTR_TX_BLOCKED_POS        (7u)  /* [7]  No access to the EZ memory                       */
#define GPS_UART_INTR_TX_UART_NACK_POS      (8u)  /* [8]  UART transmitter received a NACK: SmartCard mode */
#define GPS_UART_INTR_TX_UART_DONE_POS      (9u)  /* [9]  UART transmitter done even                       */
#define GPS_UART_INTR_TX_UART_ARB_LOST_POS  (10u) /* [10] UART lost arbitration: LIN or SmartCard          */
#define GPS_UART_INTR_TX_TRIGGER            ((uint32) 0x01u)
#define GPS_UART_INTR_TX_NOT_FULL           ((uint32) 0x01u << GPS_UART_INTR_TX_NOT_FULL_POS)
#define GPS_UART_INTR_TX_EMPTY              ((uint32) 0x01u << GPS_UART_INTR_TX_EMPTY_POS)
#define GPS_UART_INTR_TX_OVERFLOW           ((uint32) 0x01u << GPS_UART_INTR_TX_OVERFLOW_POS)
#define GPS_UART_INTR_TX_UNDERFLOW          ((uint32) 0x01u << GPS_UART_INTR_TX_UNDERFLOW_POS)
#define GPS_UART_INTR_TX_BLOCKED            ((uint32) 0x01u << GPS_UART_INTR_TX_BLOCKED_POS)
#define GPS_UART_INTR_TX_UART_NACK          ((uint32) 0x01u << GPS_UART_INTR_TX_UART_NACK_POS)
#define GPS_UART_INTR_TX_UART_DONE          ((uint32) 0x01u << GPS_UART_INTR_TX_UART_DONE_POS)
#define GPS_UART_INTR_TX_UART_ARB_LOST      ((uint32) 0x01u << GPS_UART_INTR_TX_UART_ARB_LOST_POS)

/*
* GPS_UART_INTR_RX, GPS_UART_INTR_RX_SET,
* GPS_UART_INTR_RX_MASK, GPS_UART_INTR_RX_MASKED
*/
#define GPS_UART_INTR_RX_TRIGGER_POS        (0u)   /* [0]  Trigger on RX FIFO entires            */
#define GPS_UART_INTR_RX_NOT_EMPTY_POS      (2u)   /* [2]  RX FIFO is not empty                  */
#define GPS_UART_INTR_RX_FULL_POS           (3u)   /* [3]  RX FIFO is full                       */
#define GPS_UART_INTR_RX_OVERFLOW_POS       (5u)   /* [5]  Attempt to write to a full RX FIFO    */
#define GPS_UART_INTR_RX_UNDERFLOW_POS      (6u)   /* [6]  Attempt to read from an empty RX FIFO */
#define GPS_UART_INTR_RX_BLOCKED_POS        (7u)   /* [7]  No access to the EZ memory            */
#define GPS_UART_INTR_RX_FRAME_ERROR_POS    (8u)   /* [8]  Frame error in received data frame    */
#define GPS_UART_INTR_RX_PARITY_ERROR_POS   (9u)   /* [9]  Parity error in received data frame   */
#define GPS_UART_INTR_RX_BAUD_DETECT_POS    (10u)  /* [10] LIN baudrate detection is completed   */
#define GPS_UART_INTR_RX_BREAK_DETECT_POS   (11u)  /* [11] Break detection is successful         */
#define GPS_UART_INTR_RX_TRIGGER            ((uint32) 0x01u)
#define GPS_UART_INTR_RX_NOT_EMPTY          ((uint32) 0x01u << GPS_UART_INTR_RX_NOT_EMPTY_POS)
#define GPS_UART_INTR_RX_FULL               ((uint32) 0x01u << GPS_UART_INTR_RX_FULL_POS)
#define GPS_UART_INTR_RX_OVERFLOW           ((uint32) 0x01u << GPS_UART_INTR_RX_OVERFLOW_POS)
#define GPS_UART_INTR_RX_UNDERFLOW          ((uint32) 0x01u << GPS_UART_INTR_RX_UNDERFLOW_POS)
#define GPS_UART_INTR_RX_BLOCKED            ((uint32) 0x01u << GPS_UART_INTR_RX_BLOCKED_POS)
#define GPS_UART_INTR_RX_FRAME_ERROR        ((uint32) 0x01u << GPS_UART_INTR_RX_FRAME_ERROR_POS)
#define GPS_UART_INTR_RX_PARITY_ERROR       ((uint32) 0x01u << GPS_UART_INTR_RX_PARITY_ERROR_POS)
#define GPS_UART_INTR_RX_BAUD_DETECT        ((uint32) 0x01u << GPS_UART_INTR_RX_BAUD_DETECT_POS)
#define GPS_UART_INTR_RX_BREAK_DETECT       ((uint32) 0x01u << GPS_UART_INTR_RX_BREAK_DETECT_POS)

/* Define all interupt soureces */
#define GPS_UART_INTR_I2C_EC_ALL    (GPS_UART_INTR_I2C_EC_WAKE_UP    | \
                                             GPS_UART_INTR_I2C_EC_EZBUF_STOP | \
                                             GPS_UART_INTR_I2C_EC_EZBUF_WRITE_STOP)

#define GPS_UART_INTR_SPI_EC_ALL    (GPS_UART_INTR_SPI_EC_WAKE_UP    | \
                                             GPS_UART_INTR_SPI_EC_EZBUF_STOP | \
                                             GPS_UART_INTR_SPI_EC_EZBUF_WRITE_STOP)

#define GPS_UART_INTR_MASTER_ALL    (GPS_UART_INTR_MASTER_I2C_ARB_LOST  | \
                                             GPS_UART_INTR_MASTER_I2C_NACK      | \
                                             GPS_UART_INTR_MASTER_I2C_ACK       | \
                                             GPS_UART_INTR_MASTER_I2C_STOP      | \
                                             GPS_UART_INTR_MASTER_I2C_BUS_ERROR | \
                                             GPS_UART_INTR_MASTER_SPI_DONE )

#define GPS_UART_INTR_SLAVE_ALL     (GPS_UART_INTR_SLAVE_I2C_ARB_LOST      | \
                                             GPS_UART_INTR_SLAVE_I2C_NACK          | \
                                             GPS_UART_INTR_SLAVE_I2C_ACK           | \
                                             GPS_UART_INTR_SLAVE_I2C_WRITE_STOP    | \
                                             GPS_UART_INTR_SLAVE_I2C_STOP          | \
                                             GPS_UART_INTR_SLAVE_I2C_START         | \
                                             GPS_UART_INTR_SLAVE_I2C_ADDR_MATCH    | \
                                             GPS_UART_INTR_SLAVE_I2C_GENERAL       | \
                                             GPS_UART_INTR_SLAVE_I2C_BUS_ERROR     | \
                                             GPS_UART_INTR_SLAVE_SPI_EZBUF_WRITE_STOP | \
                                             GPS_UART_INTR_SLAVE_SPI_EZBUF_STOP       | \
                                             GPS_UART_INTR_SLAVE_SPI_BUS_ERROR)

#define GPS_UART_INTR_TX_ALL        (GPS_UART_INTR_TX_TRIGGER   | \
                                             GPS_UART_INTR_TX_NOT_FULL  | \
                                             GPS_UART_INTR_TX_EMPTY     | \
                                             GPS_UART_INTR_TX_OVERFLOW  | \
                                             GPS_UART_INTR_TX_UNDERFLOW | \
                                             GPS_UART_INTR_TX_BLOCKED   | \
                                             GPS_UART_INTR_TX_UART_NACK | \
                                             GPS_UART_INTR_TX_UART_DONE | \
                                             GPS_UART_INTR_TX_UART_ARB_LOST)

#define GPS_UART_INTR_RX_ALL        (GPS_UART_INTR_RX_TRIGGER      | \
                                             GPS_UART_INTR_RX_NOT_EMPTY    | \
                                             GPS_UART_INTR_RX_FULL         | \
                                             GPS_UART_INTR_RX_OVERFLOW     | \
                                             GPS_UART_INTR_RX_UNDERFLOW    | \
                                             GPS_UART_INTR_RX_BLOCKED      | \
                                             GPS_UART_INTR_RX_FRAME_ERROR  | \
                                             GPS_UART_INTR_RX_PARITY_ERROR | \
                                             GPS_UART_INTR_RX_BAUD_DETECT  | \
                                             GPS_UART_INTR_RX_BREAK_DETECT)

/* General usage HW definitions */
#define GPS_UART_ONE_BYTE_WIDTH (8u)   /* Number of bits in one byte           */
#define GPS_UART_FIFO_SIZE      (8u)   /* Size of TX or RX FIFO: defined by HW */
#define GPS_UART_EZBUFFER_SIZE  (32u)  /* EZ Buffer size: defined by HW        */

/* I2C and EZI2C slave address defines */
#define GPS_UART_I2C_SLAVE_ADDR_POS    (0x01u)    /* 7-bit address shift */
#define GPS_UART_I2C_SLAVE_ADDR_MASK   (0xFEu)    /* 8-bit address mask */

/* OVS constants for IrDA Low Power operation */
#define GPS_UART_CTRL_OVS_IRDA_LP_OVS16     (0x00u)
#define GPS_UART_CTRL_OVS_IRDA_LP_OVS32     (0x01u)
#define GPS_UART_CTRL_OVS_IRDA_LP_OVS48     (0x02u)
#define GPS_UART_CTRL_OVS_IRDA_LP_OVS96     (0x03u)
#define GPS_UART_CTRL_OVS_IRDA_LP_OVS192    (0x04u)
#define GPS_UART_CTRL_OVS_IRDA_LP_OVS768    (0x05u)
#define GPS_UART_CTRL_OVS_IRDA_LP_OVS1536   (0x06u)

/* OVS constant for IrDA */
#define GPS_UART_CTRL_OVS_IRDA_OVS16        (GPS_UART_UART_IRDA_LP_OVS16)


/***************************************
*    SCB Common Macro Definitions
***************************************/

/* Re-enables the SCB IP. The clear enable bit has a different effect on the scb IP depending on the version.* CY_SCBIP_V0: resets state, status, TX and RX FIFOs.
* CY_SCBIP_V1 or later: resets state, status, TX and RX FIFOs and interrupt sources.
*/
#define GPS_UART_SCB_SW_RESET \
                        do{           \
                            GPS_UART_CTRL_REG &= ((uint32) ~GPS_UART_CTRL_ENABLED); \
                            GPS_UART_CTRL_REG |= ((uint32)  GPS_UART_CTRL_ENABLED); \
                        }while(0)

/* TX FIFO macro */
#define GPS_UART_CLEAR_TX_FIFO \
                            do{        \
                                GPS_UART_TX_FIFO_CTRL_REG |= ((uint32)  GPS_UART_TX_FIFO_CTRL_CLEAR); \
                                GPS_UART_TX_FIFO_CTRL_REG &= ((uint32) ~GPS_UART_TX_FIFO_CTRL_CLEAR); \
                            }while(0)

#define GPS_UART_GET_TX_FIFO_ENTRIES    (GPS_UART_TX_FIFO_STATUS_REG & \
                                                 GPS_UART_TX_FIFO_STATUS_USED_MASK)

#define GPS_UART_GET_TX_FIFO_SR_VALID   ((0u != (GPS_UART_TX_FIFO_STATUS_REG & \
                                                         GPS_UART_TX_FIFO_SR_VALID)) ? (1u) : (0u))

/* RX FIFO macro */
#define GPS_UART_CLEAR_RX_FIFO \
                            do{        \
                                GPS_UART_RX_FIFO_CTRL_REG |= ((uint32)  GPS_UART_RX_FIFO_CTRL_CLEAR); \
                                GPS_UART_RX_FIFO_CTRL_REG &= ((uint32) ~GPS_UART_RX_FIFO_CTRL_CLEAR); \
                            }while(0)

#define GPS_UART_GET_RX_FIFO_ENTRIES    (GPS_UART_RX_FIFO_STATUS_REG & \
                                                    GPS_UART_RX_FIFO_STATUS_USED_MASK)

#define GPS_UART_GET_RX_FIFO_SR_VALID   ((0u != (GPS_UART_RX_FIFO_STATUS_REG & \
                                                         GPS_UART_RX_FIFO_SR_VALID)) ? (1u) : (0u))

/* Write interrupt source: set sourceMask bits in GPS_UART_INTR_X_MASK_REG */
#define GPS_UART_WRITE_INTR_I2C_EC_MASK(sourceMask) \
                                                do{         \
                                                    GPS_UART_INTR_I2C_EC_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_WRITE_INTR_SPI_EC_MASK(sourceMask) \
                                                do{         \
                                                    GPS_UART_INTR_SPI_EC_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_WRITE_INTR_MASTER_MASK(sourceMask) \
                                                do{         \
                                                    GPS_UART_INTR_MASTER_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_WRITE_INTR_SLAVE_MASK(sourceMask)  \
                                                do{         \
                                                    GPS_UART_INTR_SLAVE_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_WRITE_INTR_TX_MASK(sourceMask)     \
                                                do{         \
                                                    GPS_UART_INTR_TX_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_WRITE_INTR_RX_MASK(sourceMask)     \
                                                do{         \
                                                    GPS_UART_INTR_RX_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

/* Enable interrupt source: set sourceMask bits in GPS_UART_INTR_X_MASK_REG */
#define GPS_UART_ENABLE_INTR_I2C_EC(sourceMask) \
                                                do{     \
                                                    GPS_UART_INTR_I2C_EC_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_ENABLE_INTR_SPI_EC(sourceMask) \
                                                do{     \
                                                    GPS_UART_INTR_SPI_EC_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_ENABLE_INTR_MASTER(sourceMask) \
                                                do{     \
                                                    GPS_UART_INTR_MASTER_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_ENABLE_INTR_SLAVE(sourceMask)  \
                                                do{     \
                                                    GPS_UART_INTR_SLAVE_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_ENABLE_INTR_TX(sourceMask)     \
                                                do{     \
                                                    GPS_UART_INTR_TX_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_ENABLE_INTR_RX(sourceMask)     \
                                                do{     \
                                                    GPS_UART_INTR_RX_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

/* Disable interrupt source: clear sourceMask bits in GPS_UART_INTR_X_MASK_REG */
#define GPS_UART_DISABLE_INTR_I2C_EC(sourceMask) \
                                do{                      \
                                    GPS_UART_INTR_I2C_EC_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#define GPS_UART_DISABLE_INTR_SPI_EC(sourceMask) \
                                do{                      \
                                    GPS_UART_INTR_SPI_EC_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                 }while(0)

#define GPS_UART_DISABLE_INTR_MASTER(sourceMask) \
                                do{                      \
                                GPS_UART_INTR_MASTER_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#define GPS_UART_DISABLE_INTR_SLAVE(sourceMask) \
                                do{                     \
                                    GPS_UART_INTR_SLAVE_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#define GPS_UART_DISABLE_INTR_TX(sourceMask)    \
                                do{                     \
                                    GPS_UART_INTR_TX_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                 }while(0)

#define GPS_UART_DISABLE_INTR_RX(sourceMask)    \
                                do{                     \
                                    GPS_UART_INTR_RX_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

/* Set interrupt sources: write sourceMask bits in GPS_UART_INTR_X_SET_REG */
#define GPS_UART_SET_INTR_MASTER(sourceMask)    \
                                                do{     \
                                                    GPS_UART_INTR_MASTER_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_SET_INTR_SLAVE(sourceMask) \
                                                do{ \
                                                    GPS_UART_INTR_SLAVE_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_SET_INTR_TX(sourceMask)    \
                                                do{ \
                                                    GPS_UART_INTR_TX_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_SET_INTR_RX(sourceMask)    \
                                                do{ \
                                                    GPS_UART_INTR_RX_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

/* Clear interrupt sources: write sourceMask bits in GPS_UART_INTR_X_REG */
#define GPS_UART_CLEAR_INTR_I2C_EC(sourceMask)  \
                                                do{     \
                                                    GPS_UART_INTR_I2C_EC_REG = (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_CLEAR_INTR_SPI_EC(sourceMask)  \
                                                do{     \
                                                    GPS_UART_INTR_SPI_EC_REG = (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_CLEAR_INTR_MASTER(sourceMask)  \
                                                do{     \
                                                    GPS_UART_INTR_MASTER_REG = (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_CLEAR_INTR_SLAVE(sourceMask)   \
                                                do{     \
                                                    GPS_UART_INTR_SLAVE_REG  = (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_CLEAR_INTR_TX(sourceMask)      \
                                                do{     \
                                                    GPS_UART_INTR_TX_REG     = (uint32) (sourceMask); \
                                                }while(0)

#define GPS_UART_CLEAR_INTR_RX(sourceMask)      \
                                                do{     \
                                                    GPS_UART_INTR_RX_REG     = (uint32) (sourceMask); \
                                                }while(0)

/* Return true if sourceMask is set in GPS_UART_INTR_CAUSE_REG */
#define GPS_UART_CHECK_CAUSE_INTR(sourceMask)    (0u != (GPS_UART_INTR_CAUSE_REG & (sourceMask)))

/* Return true if sourceMask is set in INTR_X_MASKED_REG */
#define GPS_UART_CHECK_INTR_I2C_EC(sourceMask)  (0u != (GPS_UART_INTR_I2C_EC_REG & (sourceMask)))
#define GPS_UART_CHECK_INTR_SPI_EC(sourceMask)  (0u != (GPS_UART_INTR_SPI_EC_REG & (sourceMask)))
#define GPS_UART_CHECK_INTR_MASTER(sourceMask)  (0u != (GPS_UART_INTR_MASTER_REG & (sourceMask)))
#define GPS_UART_CHECK_INTR_SLAVE(sourceMask)   (0u != (GPS_UART_INTR_SLAVE_REG  & (sourceMask)))
#define GPS_UART_CHECK_INTR_TX(sourceMask)      (0u != (GPS_UART_INTR_TX_REG     & (sourceMask)))
#define GPS_UART_CHECK_INTR_RX(sourceMask)      (0u != (GPS_UART_INTR_RX_REG     & (sourceMask)))

/* Return true if sourceMask is set in GPS_UART_INTR_X_MASKED_REG */
#define GPS_UART_CHECK_INTR_I2C_EC_MASKED(sourceMask)   (0u != (GPS_UART_INTR_I2C_EC_MASKED_REG & \
                                                                       (sourceMask)))
#define GPS_UART_CHECK_INTR_SPI_EC_MASKED(sourceMask)   (0u != (GPS_UART_INTR_SPI_EC_MASKED_REG & \
                                                                       (sourceMask)))
#define GPS_UART_CHECK_INTR_MASTER_MASKED(sourceMask)   (0u != (GPS_UART_INTR_MASTER_MASKED_REG & \
                                                                       (sourceMask)))
#define GPS_UART_CHECK_INTR_SLAVE_MASKED(sourceMask)    (0u != (GPS_UART_INTR_SLAVE_MASKED_REG  & \
                                                                       (sourceMask)))
#define GPS_UART_CHECK_INTR_TX_MASKED(sourceMask)       (0u != (GPS_UART_INTR_TX_MASKED_REG     & \
                                                                       (sourceMask)))
#define GPS_UART_CHECK_INTR_RX_MASKED(sourceMask)       (0u != (GPS_UART_INTR_RX_MASKED_REG     & \
                                                                       (sourceMask)))

/* Return true if sourceMask is set in GPS_UART_CTRL_REG: generaly is used to check enable bit */
#define GPS_UART_GET_CTRL_ENABLED    (0u != (GPS_UART_CTRL_REG & GPS_UART_CTRL_ENABLED))

#define GPS_UART_CHECK_SLAVE_AUTO_ADDR_NACK     (0u != (GPS_UART_I2C_CTRL_REG & \
                                                                GPS_UART_I2C_CTRL_S_NOT_READY_DATA_NACK))


/***************************************
*      I2C Macro Definitions
***************************************/

/* Enable auto ACK/NACK */
#define GPS_UART_ENABLE_SLAVE_AUTO_ADDR_NACK \
                            do{                      \
                                GPS_UART_I2C_CTRL_REG |= GPS_UART_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define GPS_UART_ENABLE_SLAVE_AUTO_DATA_ACK \
                            do{                     \
                                GPS_UART_I2C_CTRL_REG |= GPS_UART_I2C_CTRL_S_READY_DATA_ACK; \
                            }while(0)

#define GPS_UART_ENABLE_SLAVE_AUTO_DATA_NACK \
                            do{                      \
                                GPS_UART_I2C_CTRL_REG |= GPS_UART_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define GPS_UART_ENABLE_MASTER_AUTO_DATA_ACK \
                            do{                      \
                                GPS_UART_I2C_CTRL_REG |= GPS_UART_I2C_CTRL_M_READY_DATA_ACK; \
                            }while(0)

#define GPS_UART_ENABLE_MASTER_AUTO_DATA_NACK \
                            do{                       \
                                GPS_UART_I2C_CTRL_REG |= GPS_UART_I2C_CTRL_M_NOT_READY_DATA_NACK; \
                            }while(0)

/* Disable auto ACK/NACK */
#define GPS_UART_DISABLE_SLAVE_AUTO_ADDR_NACK \
                            do{                       \
                                GPS_UART_I2C_CTRL_REG &= ~GPS_UART_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define GPS_UART_DISABLE_SLAVE_AUTO_DATA_ACK \
                            do{                      \
                                GPS_UART_I2C_CTRL_REG &= ~GPS_UART_I2C_CTRL_S_READY_DATA_ACK; \
                            }while(0)

#define GPS_UART_DISABLE_SLAVE_AUTO_DATA_NACK \
                            do{                       \
                                GPS_UART_I2C_CTRL_REG &= ~GPS_UART_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define GPS_UART_DISABLE_MASTER_AUTO_DATA_ACK \
                            do{                       \
                                GPS_UART_I2C_CTRL_REG &= ~GPS_UART_I2C_CTRL_M_READY_DATA_ACK; \
                            }while(0)

#define GPS_UART_DISABLE_MASTER_AUTO_DATA_NACK \
                            do{                        \
                                GPS_UART_I2C_CTRL_REG &= ~GPS_UART_I2C_CTRL_M_NOT_READY_DATA_NACK; \
                            }while(0)

/* Enable Slave autoACK/NACK Data */
#define GPS_UART_ENABLE_SLAVE_AUTO_DATA \
                            do{                 \
                                GPS_UART_I2C_CTRL_REG |= (GPS_UART_I2C_CTRL_S_READY_DATA_ACK |      \
                                                                  GPS_UART_I2C_CTRL_S_NOT_READY_DATA_NACK); \
                            }while(0)

/* Disable Slave autoACK/NACK Data */
#define GPS_UART_DISABLE_SLAVE_AUTO_DATA \
                            do{                  \
                                GPS_UART_I2C_CTRL_REG &= ((uint32) \
                                                                  ~(GPS_UART_I2C_CTRL_S_READY_DATA_ACK |       \
                                                                    GPS_UART_I2C_CTRL_S_NOT_READY_DATA_NACK)); \
                            }while(0)

/* Disable Master autoACK/NACK Data */
#define GPS_UART_DISABLE_MASTER_AUTO_DATA \
                            do{                   \
                                GPS_UART_I2C_CTRL_REG &= ((uint32) \
                                                                  ~(GPS_UART_I2C_CTRL_M_READY_DATA_ACK |       \
                                                                    GPS_UART_I2C_CTRL_M_NOT_READY_DATA_NACK)); \
                            }while(0)

/* Master commands */
#define GPS_UART_I2C_MASTER_GENERATE_START \
                            do{                    \
                                GPS_UART_I2C_MASTER_CMD_REG = GPS_UART_I2C_MASTER_CMD_M_START_ON_IDLE; \
                            }while(0)

#define GPS_UART_I2C_MASTER_CLEAR_START \
                            do{                 \
                                GPS_UART_I2C_MASTER_CMD_REG =  ((uint32) 0u); \
                            }while(0)

#define GPS_UART_I2C_MASTER_GENERATE_RESTART GPS_UART_I2CReStartGeneration()

#define GPS_UART_I2C_MASTER_GENERATE_STOP \
                            do{                   \
                                GPS_UART_I2C_MASTER_CMD_REG =                                            \
                                    (GPS_UART_I2C_MASTER_CMD_M_STOP |                                    \
                                        (GPS_UART_CHECK_I2C_STATUS(GPS_UART_I2C_STATUS_M_READ) ? \
                                            (GPS_UART_I2C_MASTER_CMD_M_NACK) : (0u)));                   \
                            }while(0)

#define GPS_UART_I2C_MASTER_GENERATE_ACK \
                            do{                  \
                                GPS_UART_I2C_MASTER_CMD_REG = GPS_UART_I2C_MASTER_CMD_M_ACK; \
                            }while(0)

#define GPS_UART_I2C_MASTER_GENERATE_NACK \
                            do{                   \
                                GPS_UART_I2C_MASTER_CMD_REG = GPS_UART_I2C_MASTER_CMD_M_NACK; \
                            }while(0)

/* Slave commands */
#define GPS_UART_I2C_SLAVE_GENERATE_ACK \
                            do{                 \
                                GPS_UART_I2C_SLAVE_CMD_REG = GPS_UART_I2C_SLAVE_CMD_S_ACK; \
                            }while(0)

#define GPS_UART_I2C_SLAVE_GENERATE_NACK \
                            do{                  \
                                GPS_UART_I2C_SLAVE_CMD_REG = GPS_UART_I2C_SLAVE_CMD_S_NACK; \
                            }while(0)

#define GPS_UART_I2C_SLAVE_CLEAR_NACK \
                            do{               \
                                GPS_UART_I2C_SLAVE_CMD_REG = 0u; \
                            }while(0)

/* Return 8-bit address. The input address should be 7-bits */
#define GPS_UART_GET_I2C_8BIT_ADDRESS(addr) (((uint32) ((uint32) (addr) << \
                                                                    GPS_UART_I2C_SLAVE_ADDR_POS)) & \
                                                                        GPS_UART_I2C_SLAVE_ADDR_MASK)

#define GPS_UART_GET_I2C_7BIT_ADDRESS(addr) ((uint32) (addr) >> GPS_UART_I2C_SLAVE_ADDR_POS)

/* Adjust SDA filter Trim settings */
#define GPS_UART_DEFAULT_I2C_CFG_SDA_FILT_TRIM  (0x02u)
#define GPS_UART_EC_AM_I2C_CFG_SDA_FILT_TRIM    (0x03u)

#define GPS_UART_SET_I2C_CFG_SDA_FILT_TRIM(sdaTrim) \
        do{                                                 \
            GPS_UART_I2C_CFG_REG =                  \
                            ((GPS_UART_I2C_CFG_REG & (uint32) ~GPS_UART_I2C_CFG_SDA_FILT_TRIM_MASK) | \
                             ((uint32) ((uint32) (sdaTrim) <<GPS_UART_I2C_CFG_SDA_FILT_TRIM_POS)));           \
        }while(0)

/* Return slave select number from SPI_CTRL register */
#define GPS_UART_GET_SPI_CTRL_SS(activeSelect) (((uint32) ((uint32) (activeSelect) << \
                                                                    GPS_UART_SPI_CTRL_SLAVE_SELECT_POS)) & \
                                                                        GPS_UART_SPI_CTRL_SLAVE_SELECT_MASK)

/* Return true if bit is set in GPS_UART_I2C_STATUS_REG */
#define GPS_UART_CHECK_I2C_STATUS(sourceMask)   (0u != (GPS_UART_I2C_STATUS_REG & (sourceMask)))

/* Return true if bit is set in GPS_UART_SPI_STATUS_REG */
#define GPS_UART_CHECK_SPI_STATUS(sourceMask)   (0u != (GPS_UART_SPI_STATUS_REG & (sourceMask)))


/***************************************
*       SCB Init Macros Definitions
***************************************/

/* GPS_UART_CTRL */
#define GPS_UART_GET_CTRL_OVS(oversample)   ((((uint32) (oversample)) - 1u) & GPS_UART_CTRL_OVS_MASK)

#define GPS_UART_GET_CTRL_EC_OP_MODE(opMode)        ((0u != (opMode)) ? \
                                                                (GPS_UART_CTRL_EC_OP_MODE)  : (0u))

#define GPS_UART_GET_CTRL_EC_AM_MODE(amMode)        ((0u != (amMode)) ? \
                                                                (GPS_UART_CTRL_EC_AM_MODE)  : (0u))

#define GPS_UART_GET_CTRL_BLOCK(block)              ((0u != (block))  ? \
                                                                (GPS_UART_CTRL_BLOCK)       : (0u))

#define GPS_UART_GET_CTRL_ADDR_ACCEPT(acceptAddr)   ((0u != (acceptAddr)) ? \
                                                                (GPS_UART_CTRL_ADDR_ACCEPT) : (0u))

/* GPS_UART_I2C_CTRL */
#define GPS_UART_GET_I2C_CTRL_HIGH_PHASE_OVS(oversampleHigh) (((uint32) (oversampleHigh) - 1u) & \
                                                                        GPS_UART_I2C_CTRL_HIGH_PHASE_OVS_MASK)

#define GPS_UART_GET_I2C_CTRL_LOW_PHASE_OVS(oversampleLow)   (((uint32) (((uint32) (oversampleLow) - 1u) << \
                                                                    GPS_UART_I2C_CTRL_LOW_PHASE_OVS_POS)) &  \
                                                                    GPS_UART_I2C_CTRL_LOW_PHASE_OVS_MASK)

#define GPS_UART_GET_I2C_CTRL_S_NOT_READY_ADDR_NACK(wakeNack) ((0u != (wakeNack)) ? \
                                                            (GPS_UART_I2C_CTRL_S_NOT_READY_ADDR_NACK) : (0u))

#define GPS_UART_GET_I2C_CTRL_SL_MSTR_MODE(mode)    ((uint32) ((uint32)(mode) << \
                                                                    GPS_UART_I2C_CTRL_SLAVE_MODE_POS))

/* GPS_UART_SPI_CTRL */
#define GPS_UART_GET_SPI_CTRL_CONTINUOUS(separate)  ((0u != (separate)) ? \
                                                                (GPS_UART_SPI_CTRL_CONTINUOUS) : (0u))

#define GPS_UART_GET_SPI_CTRL_SELECT_PRECEDE(mode)  ((0u != (mode)) ? \
                                                                      (GPS_UART_SPI_CTRL_SELECT_PRECEDE) : (0u))

#define GPS_UART_GET_SPI_CTRL_SCLK_MODE(mode)       (((uint32) ((uint32) (mode) << \
                                                                        GPS_UART_SPI_CTRL_CPHA_POS)) & \
                                                                        GPS_UART_SPI_CTRL_SCLK_MODE_MASK)

#define GPS_UART_GET_SPI_CTRL_LATE_MISO_SAMPLE(lateMiso) ((0u != (lateMiso)) ? \
                                                                    (GPS_UART_SPI_CTRL_LATE_MISO_SAMPLE) : (0u))

#define GPS_UART_GET_SPI_CTRL_SUB_MODE(mode)        (((uint32) (((uint32) (mode)) << \
                                                                        GPS_UART_SPI_CTRL_MODE_POS)) & \
                                                                        GPS_UART_SPI_CTRL_MODE_MASK)

#define GPS_UART_GET_SPI_CTRL_SLAVE_SELECT(select)  (((uint32) ((uint32) (select) << \
                                                                      GPS_UART_SPI_CTRL_SLAVE_SELECT_POS)) & \
                                                                      GPS_UART_SPI_CTRL_SLAVE_SELECT_MASK)

#define GPS_UART_GET_SPI_CTRL_MASTER_MODE(mode)     ((0u != (mode)) ? \
                                                                (GPS_UART_SPI_CTRL_MASTER) : (0u))

/* GPS_UART_UART_CTRL */
#define GPS_UART_GET_UART_CTRL_MODE(mode)           (((uint32) ((uint32) (mode) << \
                                                                            GPS_UART_UART_CTRL_MODE_POS)) & \
                                                                                GPS_UART_UART_CTRL_MODE_MASK)

/* GPS_UART_UART_RX_CTRL */
#define GPS_UART_GET_UART_RX_CTRL_MODE(stopBits)    (((uint32) (stopBits) - 1u) & \
                                                                        GPS_UART_UART_RX_CTRL_STOP_BITS_MASK)

#define GPS_UART_GET_UART_RX_CTRL_PARITY(parity)    ((0u != (parity)) ? \
                                                                    (GPS_UART_UART_RX_CTRL_PARITY) : (0u))

#define GPS_UART_GET_UART_RX_CTRL_POLARITY(polarity)    ((0u != (polarity)) ? \
                                                                    (GPS_UART_UART_RX_CTRL_POLARITY) : (0u))

#define GPS_UART_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(dropErr) ((0u != (dropErr)) ? \
                                                        (GPS_UART_UART_RX_CTRL_DROP_ON_PARITY_ERR) : (0u))

#define GPS_UART_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(dropErr) ((0u != (dropErr)) ? \
                                                        (GPS_UART_UART_RX_CTRL_DROP_ON_FRAME_ERR) : (0u))

#define GPS_UART_GET_UART_RX_CTRL_MP_MODE(mpMode)   ((0u != (mpMode)) ? \
                                                        (GPS_UART_UART_RX_CTRL_MP_MODE) : (0u))

/* GPS_UART_UART_TX_CTRL */
#define GPS_UART_GET_UART_TX_CTRL_MODE(stopBits)    (((uint32) (stopBits) - 1u) & \
                                                                GPS_UART_UART_RX_CTRL_STOP_BITS_MASK)

#define GPS_UART_GET_UART_TX_CTRL_PARITY(parity)    ((0u != (parity)) ? \
                                                               (GPS_UART_UART_TX_CTRL_PARITY) : (0u))

#define GPS_UART_GET_UART_TX_CTRL_RETRY_NACK(nack)  ((0u != (nack)) ? \
                                                               (GPS_UART_UART_TX_CTRL_RETRY_ON_NACK) : (0u))

/* GPS_UART_RX_CTRL */
#define GPS_UART_GET_RX_CTRL_DATA_WIDTH(dataWidth)  (((uint32) (dataWidth) - 1u) & \
                                                                GPS_UART_RX_CTRL_DATA_WIDTH_MASK)

#define GPS_UART_GET_RX_CTRL_BIT_ORDER(bitOrder)    ((0u != (bitOrder)) ? \
                                                                (GPS_UART_RX_CTRL_MSB_FIRST) : (0u))

#define GPS_UART_GET_RX_CTRL_MEDIAN(filterEn)       ((0u != (filterEn)) ? \
                                                                (GPS_UART_RX_CTRL_MEDIAN) : (0u))

/* GPS_UART_RX_MATCH */
#define GPS_UART_GET_RX_MATCH_ADDR(addr)    ((uint32) (addr) & GPS_UART_RX_MATCH_ADDR_MASK)
#define GPS_UART_GET_RX_MATCH_MASK(mask)    (((uint32) ((uint32) (mask) << \
                                                            GPS_UART_RX_MATCH_MASK_POS)) & \
                                                            GPS_UART_RX_MATCH_MASK_MASK)

/* GPS_UART_RX_FIFO_CTRL */
#define GPS_UART_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(level)  ((uint32) (level) & \
                                                                    GPS_UART_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK)

/* GPS_UART_TX_CTRL */
#define GPS_UART_GET_TX_CTRL_DATA_WIDTH(dataWidth)  (((uint32) (dataWidth) - 1u) & \
                                                                GPS_UART_RX_CTRL_DATA_WIDTH_MASK)

#define GPS_UART_GET_TX_CTRL_BIT_ORDER(bitOrder)    ((0u != (bitOrder)) ? \
                                                                (GPS_UART_TX_CTRL_MSB_FIRST) : (0u))

/* GPS_UART_TX_FIFO_CTRL */
#define GPS_UART_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(level)  ((uint32) (level) & \
                                                                    GPS_UART_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK)

/* Clears register: configuration and interrupt mask */
#define GPS_UART_CLEAR_REG          ((uint32) (0u))
#define GPS_UART_NO_INTR_SOURCES    ((uint32) (0u))
#define GPS_UART_DUMMY_PARAM        ((uint32) (0u))
#define GPS_UART_SUBMODE_SPI_SLAVE  ((uint32) (0u))

/* Return in case I2C read error */
#define GPS_UART_I2C_INVALID_BYTE   ((uint32) 0xFFFFFFFFu)
#define GPS_UART_CHECK_VALID_BYTE   ((uint32) 0x80000000u)


/***************************************
*       Obsolete definitions
***************************************/

/* The following definitions are for version compatibility.
* They are obsolete in SCB v1_20. Please do not use them in new projects
*/
#define GPS_UART_CHECK_INTR_EC_I2C(sourceMask)  GPS_UART_CHECK_INTR_I2C_EC(sourceMask)
#define GPS_UART_CHECK_INTR_EC_SPI(sourceMask)  GPS_UART_CHECK_INTR_SPI_EC(sourceMask)

#endif /* (CY_SCB_GPS_UART_H) */


/* [] END OF FILE */
