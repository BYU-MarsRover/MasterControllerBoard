/*******************************************************************************
* File Name: UART_PINS.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PINS_UART_H)
#define CY_SCB_PINS_UART_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define UART_REMOVE_UART_RX_WAKE_PIN        (1u)
#define UART_REMOVE_MOSI_SCL_RX_WAKE_PIN    (1u)
#define UART_REMOVE_MOSI_SCL_RX_PIN         (1u)
#define UART_REMOVE_MISO_SDA_TX_PIN         (1u)
#define UART_REMOVE_SCLK_PIN                (1u)
#define UART_REMOVE_SS0_PIN                 (1u)
#define UART_REMOVE_SS1_PIN                 (1u)
#define UART_REMOVE_SS2_PIN                 (1u)
#define UART_REMOVE_SS3_PIN                 (1u)
#define UART_REMOVE_I2C_PINS                (1u)
#define UART_REMOVE_SPI_SLAVE_PINS          (1u)

#define UART_UART_RX_WAKE_PIN       (0u == UART_REMOVE_UART_RX_WAKE_PIN)
#define UART_MOSI_SCL_RX_WAKE_PIN   (0u == UART_REMOVE_MOSI_SCL_RX_WAKE_PIN)
#define UART_MOSI_SCL_RX_PIN        (0u == UART_REMOVE_MOSI_SCL_RX_PIN)
#define UART_MISO_SDA_TX_PIN        (0u == UART_REMOVE_MISO_SDA_TX_PIN)
#define UART_SCLK_PIN               (0u == UART_REMOVE_SCLK_PIN)
#define UART_SS0_PIN                (0u == UART_REMOVE_SS0_PIN)
#define UART_SS1_PIN                (0u == UART_REMOVE_SS1_PIN)
#define UART_SS2_PIN                (0u == UART_REMOVE_SS2_PIN)
#define UART_SS3_PIN                (0u == UART_REMOVE_SS3_PIN)
#define UART_I2C_PINS               (0u == UART_REMOVE_I2C_PINS)
#define UART_SPI_SLAVE_PINS         (0u == UART_REMOVE_SPI_SLAVE_PINS)


/***************************************
*             Includes
****************************************/

#if(UART_UART_RX_WAKE_PIN)
    #include "UART_rx_wake.h"
#endif /* (UART_UART_RX_WAKE_PIN) */

#if(UART_MOSI_SCL_RX_WAKE_PIN)
    #include "UART_spi_mosi_i2c_scl_uart_rx_wake.h"
#endif /* (UART_MOSI_SCL_RX_WAKE_PIN) */

#if(UART_MOSI_SCL_RX_PIN)
    #include "UART_spi_mosi_i2c_scl_uart_rx.h"
#endif /* (UART_MOSI_SCL_RX_PIN) */

#if(UART_MISO_SDA_TX_PIN)
    #include "UART_spi_miso_i2c_sda_uart_tx.h"
#endif /* (UART_MISO_SDA_TX_PIN_PIN) */

#if(UART_SCLK_PIN)
    #include "UART_spi_sclk.h"
#endif /* (UART_SCLK_PIN) */

#if(UART_SS0_PIN)
    #include "UART_spi_ss0.h"
#endif /* (UART_SS1_PIN) */

#if(UART_SS1_PIN)
    #include "UART_spi_ss1.h"
#endif /* (UART_SS1_PIN) */

#if(UART_SS2_PIN)
    #include "UART_spi_ss2.h"
#endif /* (UART_SS2_PIN) */

#if(UART_SS3_PIN)
    #include "UART_spi_ss3.h"
#endif /* (UART_SS3_PIN) */

#if(UART_I2C_PINS)
    #include "UART_scl.h"
    #include "UART_sda.h"
#endif /* (UART_I2C_PINS) */


/***************************************
*              Registers
***************************************/

#if(UART_MOSI_SCL_RX_WAKE_PIN)
    #define UART_MOSI_SCL_RX_WAKE_HSIOM_REG  \
                                                (*(reg32 *) UART_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM)
    #define UART_MOSI_SCL_RX_WAKE_HSIOM_PTR  \
                                                ( (reg32 *) UART_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM)
    #define UART_MOSI_SCL_RX_WAKE_HSIOM_MASK \
                                                (UART_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM_MASK)
    #define UART_MOSI_SCL_RX_WAKE_HSIOM_POS  \
                                                (UART_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM_SHIFT)

    #define UART_MOSI_SCL_RX_WAKE_INTCFG_REG    (*(reg32 *) \
                                                              UART_spi_mosi_i2c_scl_uart_rx_wake__0__INTCFG)
    #define UART_MOSI_SCL_RX_WAKE_INTCFG_PTR    ( (reg32 *) \
                                                              UART_spi_mosi_i2c_scl_uart_rx_wake__0__INTCFG)

    #define UART_INTCFG_TYPE_MASK                  (0x03u)
    #define UART_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS  (UART_spi_mosi_i2c_scl_uart_rx_wake__SHIFT)
    #define UART_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK ((uint32)                                           \
                                                                    ((uint32) UART_INTCFG_TYPE_MASK << \
                                                                    UART_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS))
#endif /* (UART_MOSI_SCL_RX_WAKE_PIN) */

#if(UART_MOSI_SCL_RX_PIN)
    #define UART_MOSI_SCL_RX_HSIOM_REG      (*(reg32 *) UART_spi_mosi_i2c_scl_uart_rx__0__HSIOM)
    #define UART_MOSI_SCL_RX_HSIOM_PTR      ( (reg32 *) UART_spi_mosi_i2c_scl_uart_rx__0__HSIOM)
    #define UART_MOSI_SCL_RX_HSIOM_MASK     (UART_spi_mosi_i2c_scl_uart_rx__0__HSIOM_MASK)
    #define UART_MOSI_SCL_RX_HSIOM_POS      (UART_spi_mosi_i2c_scl_uart_rx__0__HSIOM_SHIFT)
#endif /* (UART_MOSI_SCL_RX_PIN) */

#if(UART_MISO_SDA_TX_PIN)
    #define UART_MISO_SDA_TX_HSIOM_REG      (*(reg32 *) UART_spi_miso_i2c_sda_uart_tx__0__HSIOM)
    #define UART_MISO_SDA_TX_HSIOM_PTR      ( (reg32 *) UART_spi_miso_i2c_sda_uart_tx__0__HSIOM)
    #define UART_MISO_SDA_TX_HSIOM_MASK     (UART_spi_miso_i2c_sda_uart_tx__0__HSIOM_MASK)
    #define UART_MISO_SDA_TX_HSIOM_POS      (UART_spi_miso_i2c_sda_uart_tx__0__HSIOM_SHIFT)
#endif /* (UART_MISO_SDA_TX_PIN_PIN) */

#if(UART_SCLK_PIN)
    #define UART_SCLK_HSIOM_REG     (*(reg32 *) UART_spi_sclk__0__HSIOM)
    #define UART_SCLK_HSIOM_PTR     ( (reg32 *) UART_spi_sclk__0__HSIOM)
    #define UART_SCLK_HSIOM_MASK    (UART_spi_sclk__0__HSIOM_MASK)
    #define UART_SCLK_HSIOM_POS     (UART_spi_sclk__0__HSIOM_SHIFT)
#endif /* (UART_SCLK_PIN) */

#if(UART_SS0_PIN)
    #define UART_SS0_HSIOM_REG      (*(reg32 *) UART_spi_ss0__0__HSIOM)
    #define UART_SS0_HSIOM_PTR      ( (reg32 *) UART_spi_ss0__0__HSIOM)
    #define UART_SS0_HSIOM_MASK     (UART_spi_ss0__0__HSIOM_MASK)
    #define UART_SS0_HSIOM_POS      (UART_spi_ss0__0__HSIOM_SHIFT)
#endif /* (UART_SS1_PIN) */

#if(UART_SS1_PIN)
    #define UART_SS1_HSIOM_REG      (*(reg32 *) UART_spi_ss1__0__HSIOM)
    #define UART_SS1_HSIOM_PTR      ( (reg32 *) UART_spi_ss1__0__HSIOM)
    #define UART_SS1_HSIOM_MASK     (UART_spi_ss1__0__HSIOM_MASK)
    #define UART_SS1_HSIOM_POS      (UART_spi_ss1__0__HSIOM_SHIFT)
#endif /* (UART_SS1_PIN) */

#if(UART_SS2_PIN)
    #define UART_SS2_HSIOM_REG     (*(reg32 *) UART_spi_ss2__0__HSIOM)
    #define UART_SS2_HSIOM_PTR     ( (reg32 *) UART_spi_ss2__0__HSIOM)
    #define UART_SS2_HSIOM_MASK    (UART_spi_ss2__0__HSIOM_MASK)
    #define UART_SS2_HSIOM_POS     (UART_spi_ss2__0__HSIOM_SHIFT)
#endif /* (UART_SS2_PIN) */

#if(UART_SS3_PIN)
    #define UART_SS3_HSIOM_REG     (*(reg32 *) UART_spi_ss3__0__HSIOM)
    #define UART_SS3_HSIOM_PTR     ( (reg32 *) UART_spi_ss3__0__HSIOM)
    #define UART_SS3_HSIOM_MASK    (UART_spi_ss3__0__HSIOM_MASK)
    #define UART_SS3_HSIOM_POS     (UART_spi_ss3__0__HSIOM_SHIFT)
#endif /* (UART_SS3_PIN) */

#if(UART_I2C_PINS)
    #define UART_SCL_HSIOM_REG     (*(reg32 *) UART_scl__0__HSIOM)
    #define UART_SCL_HSIOM_PTR     ( (reg32 *) UART_scl__0__HSIOM)
    #define UART_SCL_HSIOM_MASK    (UART_scl__0__HSIOM_MASK)
    #define UART_SCL_HSIOM_POS     (UART_scl__0__HSIOM_SHIFT)
    
    #define UART_SDA_HSIOM_REG     (*(reg32 *) UART_sda__0__HSIOM)
    #define UART_SDA_HSIOM_PTR     ( (reg32 *) UART_sda__0__HSIOM)
    #define UART_SDA_HSIOM_MASK    (UART_sda__0__HSIOM_MASK)
    #define UART_SDA_HSIOM_POS     (UART_sda__0__HSIOM_SHIFT)
#endif /* (UART_I2C_PINS) */


/***************************************
*        Registers Constants
***************************************/

/* Pins constanst */
#define UART_HSIOM_DEF_SEL      (0x00u)
#define UART_HSIOM_GPIO_SEL     (0x00u)
#define UART_HSIOM_UART_SEL     (0x09u)
#define UART_HSIOM_I2C_SEL      (0x0Eu)
#define UART_HSIOM_SPI_SEL      (0x0Fu)

#define UART_SCB_PINS_NUMBER            (7u)
#define UART_MOSI_SCL_RX_PIN_INDEX      (0u) /* RX pins without interrupt */
#define UART_MOSI_SCL_RX_WAKE_PIN_INDEX (0u) /* RX pin with interrupt     */
#define UART_MISO_SDA_TX_PIN_INDEX      (1u)
#define UART_SCLK_PIN_INDEX             (2u)
#define UART_SS0_PIN_INDEX              (3u)
#define UART_SS1_PIN_INDEX              (4u)
#define UART_SS2_PIN_INDEX              (5u)
#define UART_SS3_PIN_INDEX              (6u)

#define UART_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin DM defines */
#define UART_PIN_DM_ALG_HIZ  (0u)
#define UART_PIN_DM_DIG_HIZ  (1u)
#define UART_PIN_DM_OD_LO    (4u)
#define UART_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

#define UART_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        /* Sets new bits-mask */                 \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

#define UART_SET_HSIOM_SEL(reg, mask, pos, sel) UART_SET_REGISTER_BITS(reg, mask, pos, sel)
#define UART_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        UART_SET_REGISTER_BITS(reg, mask, pos, intType)


/* UART_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  UART_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* Unconfigured SCB: scl singnal */
#if(UART_MOSI_SCL_RX_WAKE_PIN)
    #define UART_SET_I2C_SCL_DR(val) \
                            UART_spi_mosi_i2c_scl_uart_rx_wake_Write(val)

    #define UART_SET_I2C_SCL_HSIOM_SEL(sel) \
                    UART_SET_HSIOM_SEL(UART_MOSI_SCL_RX_WAKE_HSIOM_REG,  \
                                                   UART_MOSI_SCL_RX_WAKE_HSIOM_MASK, \
                                                   UART_MOSI_SCL_RX_WAKE_HSIOM_POS,  \
                                                   (sel))

#elif(UART_MOSI_SCL_RX_PIN)
    #define UART_SET_I2C_SCL_DR(val) \
                            UART_spi_mosi_i2c_scl_uart_rx_Write(val)
                            

    #define UART_SET_I2C_SCL_HSIOM_SEL(sel) \
                            UART_SET_HSIOM_SEL(UART_MOSI_SCL_RX_HSIOM_REG,  \
                                                           UART_MOSI_SCL_RX_HSIOM_MASK, \
                                                           UART_MOSI_SCL_RX_HSIOM_POS,  \
                                                           (sel))
#else
    #if(!UART_I2C_PINS)
        #define UART_SET_I2C_SCL_DR(val) \
                                                 do{ ; }while(0)
        #define UART_SET_I2C_SCL_HSIOM_SEL(sel) \
                                                        do{ ; }while(0)
        
    #endif /* (!UART_I2C_PINS) */
#endif /* (UART_MOSI_SCL_RX_PIN) */

/* SCB I2C: scl singal */
#if(UART_I2C_PINS)
    #define UART_SET_I2C_SCL_DR(val) UART_scl_Write(val)
    
    #define UART_SET_I2C_SCL_HSIOM_SEL(sel) \
                          UART_SET_HSIOM_SEL(UART_SCL_HSIOM_REG,  \
                                                         UART_SCL_HSIOM_MASK, \
                                                         UART_SCL_HSIOM_POS,  \
                                                         (sel))
    
#endif /* (UART_I2C_PINS) */


#endif /* (CY_SCB_PINS_UART_H) */


/* [] END OF FILE */
