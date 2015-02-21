/*******************************************************************************
* File Name: UART_2.c
* Version 1.20
*
* Description:
*  This file provides the source code to the API for the SCB Component.
*
* Note:
*
*******************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

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
*    Run Time Configuration Vars
***************************************/

/* Stores internal component configuration for unconfigured mode */
#if(UART_2_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common config vars */
    uint8 UART_2_scbMode = UART_2_SCB_MODE_UNCONFIG;
    uint8 UART_2_scbEnableWake;
    uint8 UART_2_scbEnableIntr;

    /* I2C config vars */
    uint8 UART_2_mode;
    uint8 UART_2_acceptAddr;

    /* SPI/UART config vars */
    volatile uint8 * UART_2_rxBuffer;
    uint8  UART_2_rxDataBits;
    uint32 UART_2_rxBufferSize;

    volatile uint8 * UART_2_txBuffer;
    uint8  UART_2_txDataBits;
    uint32 UART_2_txBufferSize;

    /* EZI2C config vars */
    uint8 UART_2_numberOfAddr;
    uint8 UART_2_subAddrSize;
#endif /* (UART_2_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Common SCB Vars
***************************************/

uint8 UART_2_initVar = 0u;

#if !defined (CY_REMOVE_UART_2_CUSTOM_INTR_HANDLER)
    cyisraddress UART_2_customIntrHandler = NULL;
#endif /* !defined (CY_REMOVE_UART_2_CUSTOM_INTR_HANDLER) */


/***************************************
*    Private Function Prototypes
***************************************/

static void UART_2_ScbEnableIntr(void);
static void UART_2_ScbModeStop(void);


/*******************************************************************************
* Function Name: UART_2_Init
********************************************************************************
*
* Summary:
*  Initializes the SCB component to operate in one of the selected configurations:
*  I2C, SPI, UART or EZ I2C.
*  When the configuration is set to “Unconfigured SCB”, this function does
*  not do any initialization. Use mode-specific initialization APIs instead:
*  SCB_I2CInit, SCB_SpiInit, SCB_UartInit or SCB_EzI2CInit.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_2_Init(void)
{
#if(UART_2_SCB_MODE_UNCONFIG_CONST_CFG)
    if(UART_2_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        UART_2_initVar = 0u; /* Clear init var */
    }
    else
    {
        /* Initialization was done before call */
    }

#elif(UART_2_SCB_MODE_I2C_CONST_CFG)
    UART_2_I2CInit();

#elif(UART_2_SCB_MODE_SPI_CONST_CFG)
    UART_2_SpiInit();

#elif(UART_2_SCB_MODE_UART_CONST_CFG)
    UART_2_UartInit();

#elif(UART_2_SCB_MODE_EZI2C_CONST_CFG)
    UART_2_EzI2CInit();

#endif /* (UART_2_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UART_2_Enable
********************************************************************************
*
* Summary:
*  Enables the SCB component operation.
*  The SCB configuration should be not changed when the component is enabled.
*  Any configuration changes should be made after disabling the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_2_Enable(void)
{
#if(UART_2_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Enable SCB block, only if it is already configured */
    if(!UART_2_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        UART_2_CTRL_REG |= UART_2_CTRL_ENABLED;

        UART_2_ScbEnableIntr();
    }
#else
    UART_2_CTRL_REG |= UART_2_CTRL_ENABLED;

    UART_2_ScbEnableIntr();
#endif /* (UART_2_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UART_2_Start
********************************************************************************
*
* Summary:
*  Invokes SCB_Init() and SCB_Enable().
*  After this function call, the component is enabled and ready for operation.
*  When configuration is set to “Unconfigured SCB”, the component must first be
*  initialized to operate in one of the following configurations: I2C, SPI, UART
*  or EZ I2C. Otherwise this function does not enable the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  UART_2_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void UART_2_Start(void)
{
    if(0u == UART_2_initVar)
    {
        UART_2_Init();
        UART_2_initVar = 1u; /* Component was initialized */
    }

    UART_2_Enable();
}


/*******************************************************************************
* Function Name: UART_2_Stop
********************************************************************************
*
* Summary:
*  Disables the SCB component and its interrupt.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_2_Stop(void)
{
#if(UART_2_SCB_IRQ_INTERNAL)
    UART_2_DisableInt();
#endif /* (UART_2_SCB_IRQ_INTERNAL) */

    UART_2_CTRL_REG &= (uint32) ~UART_2_CTRL_ENABLED;  /* Disable SCB block */

#if(UART_2_SCB_IRQ_INTERNAL)
    UART_2_ClearPendingInt();
#endif /* (UART_2_SCB_IRQ_INTERNAL) */

    UART_2_ScbModeStop(); /* Calls scbMode specific Stop function */
}


/*******************************************************************************
* Function Name: UART_2_SetCustomInterruptHandler
********************************************************************************
*
* Summary:
*  Registers a function to be called by the internal interrupt handler.
*  First the function that is registered is called, then the internal interrupt
*  handler performs any operations such as software buffer management functions
*  before the interrupt returns.  It is the user's responsibility not to break the
*  software buffer operations. Only one custom handler is supported, which is
*  the function provided by the most recent call.
*  At initialization time no custom handler is registered.
*
* Parameters:
*  func: Pointer to the function to register.
*        The value NULL indicates to remove the current custom interrupt
*        handler.
*
* Return:
*  None
*
*******************************************************************************/
void UART_2_SetCustomInterruptHandler(cyisraddress func)
{
#if !defined (CY_REMOVE_UART_2_CUSTOM_INTR_HANDLER)
    UART_2_customIntrHandler = func; /* Register interrupt handler */
#else
    if(NULL != func)
    {
        /* Suppress compiler warning */
    }
#endif /* !defined (CY_REMOVE_UART_2_CUSTOM_INTR_HANDLER) */
}


/*******************************************************************************
* Function Name: UART_2_ScbModeEnableIntr
********************************************************************************
*
* Summary:
*  Enables an interrupt for a specific mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void UART_2_ScbEnableIntr(void)
{
#if(UART_2_SCB_IRQ_INTERNAL)
    #if(UART_2_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Enable interrupt in the NVIC */
        if(0u != UART_2_scbEnableIntr)
        {
            UART_2_EnableInt();
        }
    #else
        UART_2_EnableInt();

    #endif /* (UART_2_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (UART_2_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: UART_2_ScbModeStop
********************************************************************************
*
* Summary:
*  Calls the Stop function for a specific operation mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void UART_2_ScbModeStop(void)
{
#if(UART_2_SCB_MODE_UNCONFIG_CONST_CFG)
    if(UART_2_SCB_MODE_I2C_RUNTM_CFG)
    {
        UART_2_I2CStop();
    }
    else if(UART_2_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        UART_2_EzI2CStop();
    }
    else
    {
        /* Do nohing for other modes */
    }
#elif(UART_2_SCB_MODE_I2C_CONST_CFG)
    UART_2_I2CStop();

#elif(UART_2_SCB_MODE_EZI2C_CONST_CFG)
    UART_2_EzI2CStop();

#endif /* (UART_2_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if(UART_2_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: UART_2_SetPins
    ********************************************************************************
    *
    * Summary:
    *  Sets the pins settings accordingly to the selected operation mode.
    *  Only available in the Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when a specific mode of operation
    *  is selected in design time.
    *
    * Parameters:
    *  mode:      Mode of SCB operation.
    *  subMode:   Sub-mode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  uartTxRx:  Direction for UART.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UART_2_SetPins(uint32 mode, uint32 subMode, uint32 uartTxRx)
    {
        uint32 hsiomSel [UART_2_SCB_PINS_NUMBER];
        uint32 pinsDm   [UART_2_SCB_PINS_NUMBER];
        uint32 pinsInBuf = 0u;

        uint32 i;

        /* Set default HSIOM to GPIO and Drive Mode to Analog Hi-Z */
        for(i = 0u; i < UART_2_SCB_PINS_NUMBER; i++)
        {
            hsiomSel[i]  = UART_2_HSIOM_DEF_SEL;
            pinsDm[i]    = UART_2_PIN_DM_ALG_HIZ;
        }

        if((UART_2_SCB_MODE_I2C   == mode) ||
           (UART_2_SCB_MODE_EZI2C == mode))
        {
            hsiomSel[UART_2_MOSI_SCL_RX_PIN_INDEX] = UART_2_HSIOM_I2C_SEL;
            hsiomSel[UART_2_MISO_SDA_TX_PIN_INDEX] = UART_2_HSIOM_I2C_SEL;

            pinsDm[UART_2_MOSI_SCL_RX_PIN_INDEX] = UART_2_PIN_DM_OD_LO;
            pinsDm[UART_2_MISO_SDA_TX_PIN_INDEX] = UART_2_PIN_DM_OD_LO;
        }
    #if(!UART_2_CY_SCBIP_V1_I2C_ONLY)
        else if(UART_2_SCB_MODE_SPI == mode)
        {
            hsiomSel[UART_2_MOSI_SCL_RX_PIN_INDEX] = UART_2_HSIOM_SPI_SEL;
            hsiomSel[UART_2_MISO_SDA_TX_PIN_INDEX] = UART_2_HSIOM_SPI_SEL;
            hsiomSel[UART_2_SCLK_PIN_INDEX]        = UART_2_HSIOM_SPI_SEL;

            if(UART_2_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[UART_2_MOSI_SCL_RX_PIN_INDEX] = UART_2_PIN_DM_DIG_HIZ;
                pinsDm[UART_2_MISO_SDA_TX_PIN_INDEX] = UART_2_PIN_DM_STRONG;
                pinsDm[UART_2_SCLK_PIN_INDEX]        = UART_2_PIN_DM_DIG_HIZ;

            #if(UART_2_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[UART_2_SS0_PIN_INDEX] = UART_2_HSIOM_SPI_SEL;
                pinsDm  [UART_2_SS0_PIN_INDEX] = UART_2_PIN_DM_DIG_HIZ;
            #endif /* (UART_2_SS1_PIN) */

            #if(UART_2_MISO_SDA_TX_PIN)
                /* Disable input buffer */
                 pinsInBuf |= UART_2_MISO_SDA_TX_PIN_MASK;
            #endif /* (UART_2_MISO_SDA_TX_PIN_PIN) */
            }
            else /* (Master) */
            {
                pinsDm[UART_2_MOSI_SCL_RX_PIN_INDEX] = UART_2_PIN_DM_STRONG;
                pinsDm[UART_2_MISO_SDA_TX_PIN_INDEX] = UART_2_PIN_DM_DIG_HIZ;
                pinsDm[UART_2_SCLK_PIN_INDEX]        = UART_2_PIN_DM_STRONG;

            #if(UART_2_SS0_PIN)
                hsiomSel [UART_2_SS0_PIN_INDEX] = UART_2_HSIOM_SPI_SEL;
                pinsDm   [UART_2_SS0_PIN_INDEX] = UART_2_PIN_DM_STRONG;
                pinsInBuf                                |= UART_2_SS0_PIN_MASK;
            #endif /* (UART_2_SS0_PIN) */

            #if(UART_2_SS1_PIN)
                hsiomSel [UART_2_SS1_PIN_INDEX] = UART_2_HSIOM_SPI_SEL;
                pinsDm   [UART_2_SS1_PIN_INDEX] = UART_2_PIN_DM_STRONG;
                pinsInBuf                                |= UART_2_SS1_PIN_MASK;
            #endif /* (UART_2_SS1_PIN) */

            #if(UART_2_SS2_PIN)
                hsiomSel [UART_2_SS2_PIN_INDEX] = UART_2_HSIOM_SPI_SEL;
                pinsDm   [UART_2_SS2_PIN_INDEX] = UART_2_PIN_DM_STRONG;
                pinsInBuf                                |= UART_2_SS2_PIN_MASK;
            #endif /* (UART_2_SS2_PIN) */

            #if(UART_2_SS3_PIN)
                hsiomSel [UART_2_SS3_PIN_INDEX] = UART_2_HSIOM_SPI_SEL;
                pinsDm   [UART_2_SS3_PIN_INDEX] = UART_2_PIN_DM_STRONG;
                pinsInBuf                                |= UART_2_SS3_PIN_MASK;
            #endif /* (UART_2_SS2_PIN) */

                /* Disable input buffers */
            #if(UART_2_MOSI_SCL_RX_PIN)
                pinsInBuf |= UART_2_MOSI_SCL_RX_PIN_MASK;
            #endif /* (UART_2_MOSI_SCL_RX_PIN) */

             #if(UART_2_MOSI_SCL_RX_WAKE_PIN)
                pinsInBuf |= UART_2_MOSI_SCL_RX_WAKE_PIN_MASK;
            #endif /* (UART_2_MOSI_SCL_RX_WAKE_PIN) */

            #if(UART_2_SCLK_PIN)
                pinsInBuf |= UART_2_SCLK_PIN_MASK;
            #endif /* (UART_2_SCLK_PIN) */
            }
        }
        else /* UART */
        {
            if(UART_2_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
                hsiomSel[UART_2_MISO_SDA_TX_PIN_INDEX] = UART_2_HSIOM_UART_SEL;
                pinsDm  [UART_2_MISO_SDA_TX_PIN_INDEX] = UART_2_PIN_DM_OD_LO;
            }
            else /* Standard or IrDA */
            {
                if(0u != (UART_2_UART_RX & uartTxRx))
                {
                    hsiomSel[UART_2_MOSI_SCL_RX_PIN_INDEX] = UART_2_HSIOM_UART_SEL;
                    pinsDm  [UART_2_MOSI_SCL_RX_PIN_INDEX] = UART_2_PIN_DM_DIG_HIZ;
                }

                if(0u != (UART_2_UART_TX & uartTxRx))
                {
                    hsiomSel[UART_2_MISO_SDA_TX_PIN_INDEX] = UART_2_HSIOM_UART_SEL;
                    pinsDm  [UART_2_MISO_SDA_TX_PIN_INDEX] = UART_2_PIN_DM_STRONG;

                #if(UART_2_MISO_SDA_TX_PIN)
                     pinsInBuf |= UART_2_MISO_SDA_TX_PIN_MASK;
                #endif /* (UART_2_MISO_SDA_TX_PIN_PIN) */
                }
            }
        }
    #endif /* (!UART_2_CY_SCBIP_V1_I2C_ONLY) */

    /* Configure pins: set HSIOM, DM and InputBufEnable */
    /* Note: the DR register settigns do not effect the pin output if HSIOM is other than GPIO */

    #if(UART_2_MOSI_SCL_RX_PIN)
        UART_2_SET_HSIOM_SEL(UART_2_MOSI_SCL_RX_HSIOM_REG,
                                       UART_2_MOSI_SCL_RX_HSIOM_MASK,
                                       UART_2_MOSI_SCL_RX_HSIOM_POS,
                                       hsiomSel[UART_2_MOSI_SCL_RX_PIN_INDEX]);

        UART_2_spi_mosi_i2c_scl_uart_rx_SetDriveMode((uint8) pinsDm[UART_2_MOSI_SCL_RX_PIN_INDEX]);

        UART_2_SET_INP_DIS(UART_2_spi_mosi_i2c_scl_uart_rx_INP_DIS,
                                     UART_2_spi_mosi_i2c_scl_uart_rx_MASK,
                                     (0u != (pinsInBuf & UART_2_MOSI_SCL_RX_PIN_MASK)));
    #endif /* (UART_2_MOSI_SCL_RX_PIN) */

    #if(UART_2_MOSI_SCL_RX_WAKE_PIN)
        UART_2_SET_HSIOM_SEL(UART_2_MOSI_SCL_RX_WAKE_HSIOM_REG,
                                       UART_2_MOSI_SCL_RX_WAKE_HSIOM_MASK,
                                       UART_2_MOSI_SCL_RX_WAKE_HSIOM_POS,
                                       hsiomSel[UART_2_MOSI_SCL_RX_WAKE_PIN_INDEX]);

        UART_2_spi_mosi_i2c_scl_uart_rx_wake_SetDriveMode((uint8)
                                                               pinsDm[UART_2_MOSI_SCL_RX_WAKE_PIN_INDEX]);

        UART_2_SET_INP_DIS(UART_2_spi_mosi_i2c_scl_uart_rx_wake_INP_DIS,
                                     UART_2_spi_mosi_i2c_scl_uart_rx_wake_MASK,
                                     (0u != (pinsInBuf & UART_2_MOSI_SCL_RX_WAKE_PIN_MASK)));

         /* Set interrupt on falling edge */
        UART_2_SET_INCFG_TYPE(UART_2_MOSI_SCL_RX_WAKE_INTCFG_REG,
                                        UART_2_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK,
                                        UART_2_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS,
                                        UART_2_INTCFG_TYPE_FALLING_EDGE);
    #endif /* (UART_2_MOSI_SCL_RX_WAKE_PIN) */

    #if(UART_2_MISO_SDA_TX_PIN)
        UART_2_SET_HSIOM_SEL(UART_2_MISO_SDA_TX_HSIOM_REG,
                                       UART_2_MISO_SDA_TX_HSIOM_MASK,
                                       UART_2_MISO_SDA_TX_HSIOM_POS,
                                       hsiomSel[UART_2_MISO_SDA_TX_PIN_INDEX]);

        UART_2_spi_miso_i2c_sda_uart_tx_SetDriveMode((uint8) pinsDm[UART_2_MISO_SDA_TX_PIN_INDEX]);

        UART_2_SET_INP_DIS(UART_2_spi_miso_i2c_sda_uart_tx_INP_DIS,
                                     UART_2_spi_miso_i2c_sda_uart_tx_MASK,
                                    (0u != (pinsInBuf & UART_2_MISO_SDA_TX_PIN_MASK)));
    #endif /* (UART_2_MOSI_SCL_RX_PIN) */

    #if(UART_2_SCLK_PIN)
        UART_2_SET_HSIOM_SEL(UART_2_SCLK_HSIOM_REG, UART_2_SCLK_HSIOM_MASK,
                                       UART_2_SCLK_HSIOM_POS, hsiomSel[UART_2_SCLK_PIN_INDEX]);

        UART_2_spi_sclk_SetDriveMode((uint8) pinsDm[UART_2_SCLK_PIN_INDEX]);

        UART_2_SET_INP_DIS(UART_2_spi_sclk_INP_DIS,
                             UART_2_spi_sclk_MASK,
                            (0u != (pinsInBuf & UART_2_SCLK_PIN_MASK)));
    #endif /* (UART_2_SCLK_PIN) */

    #if(UART_2_SS0_PIN)
        UART_2_SET_HSIOM_SEL(UART_2_SS0_HSIOM_REG, UART_2_SS0_HSIOM_MASK,
                                       UART_2_SS0_HSIOM_POS, hsiomSel[UART_2_SS0_PIN_INDEX]);

        UART_2_spi_ss0_SetDriveMode((uint8) pinsDm[UART_2_SS0_PIN_INDEX]);

        UART_2_SET_INP_DIS(UART_2_spi_ss0_INP_DIS,
                                     UART_2_spi_ss0_MASK,
                                     (0u != (pinsInBuf & UART_2_SS0_PIN_MASK)));
    #endif /* (UART_2_SS1_PIN) */

    #if(UART_2_SS1_PIN)
        UART_2_SET_HSIOM_SEL(UART_2_SS1_HSIOM_REG, UART_2_SS1_HSIOM_MASK,
                                       UART_2_SS1_HSIOM_POS, hsiomSel[UART_2_SS1_PIN_INDEX]);

        UART_2_spi_ss1_SetDriveMode((uint8) pinsDm[UART_2_SS1_PIN_INDEX]);

        UART_2_SET_INP_DIS(UART_2_spi_ss1_INP_DIS,
                                     UART_2_spi_ss1_MASK,
                                     (0u != (pinsInBuf & UART_2_SS1_PIN_MASK)));
    #endif /* (UART_2_SS1_PIN) */

    #if(UART_2_SS2_PIN)
        UART_2_SET_HSIOM_SEL(UART_2_SS2_HSIOM_REG, UART_2_SS2_HSIOM_MASK,
                                       UART_2_SS2_HSIOM_POS, hsiomSel[UART_2_SS2_PIN_INDEX]);

        UART_2_spi_ss2_SetDriveMode((uint8) pinsDm[UART_2_SS2_PIN_INDEX]);

        UART_2_SET_INP_DIS(UART_2_spi_ss2_INP_DIS,
                                     UART_2_spi_ss2_MASK,
                                     (0u != (pinsInBuf & UART_2_SS2_PIN_MASK)));
    #endif /* (UART_2_SS2_PIN) */

    #if(UART_2_SS3_PIN)
        UART_2_SET_HSIOM_SEL(UART_2_SS3_HSIOM_REG,  UART_2_SS3_HSIOM_MASK,
                                       UART_2_SS3_HSIOM_POS, hsiomSel[UART_2_SS3_PIN_INDEX]);

        UART_2_spi_ss3_SetDriveMode((uint8) pinsDm[UART_2_SS3_PIN_INDEX]);

        UART_2_SET_INP_DIS(UART_2_spi_ss3_INP_DIS,
                                     UART_2_spi_ss3_MASK,
                                     (0u != (pinsInBuf & UART_2_SS3_PIN_MASK)));
    #endif /* (UART_2_SS3_PIN) */
    }

#endif /* (UART_2_SCB_MODE_UNCONFIG_CONST_CFG) */


/* [] END OF FILE */
