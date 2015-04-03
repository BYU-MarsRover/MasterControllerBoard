/*******************************************************************************
* File Name: GPS_UART_PINS.h
* Version 1.20
*
* Description:
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PINS_GPS_UART_H)
#define CY_SCB_PINS_GPS_UART_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define GPS_UART_REMOVE_MOSI_SCL_RX_WAKE_PIN    (1u)
#define GPS_UART_REMOVE_MOSI_SCL_RX_PIN         (1u)
#define GPS_UART_REMOVE_MISO_SDA_TX_PIN         (1u)
#define GPS_UART_REMOVE_SCLK_PIN                (1u)
#define GPS_UART_REMOVE_SS0_PIN                 (1u)
#define GPS_UART_REMOVE_SS1_PIN                 (1u)
#define GPS_UART_REMOVE_SS2_PIN                 (1u)
#define GPS_UART_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define GPS_UART_REMOVE_I2C_PINS                (1u)
#define GPS_UART_REMOVE_SPI_MASTER_PINS         (1u)
#define GPS_UART_REMOVE_SPI_SLAVE_PINS          (1u)
#define GPS_UART_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define GPS_UART_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define GPS_UART_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define GPS_UART_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define GPS_UART_REMOVE_UART_TX_PIN             (1u)
#define GPS_UART_REMOVE_UART_RX_TX_PIN          (1u)
#define GPS_UART_REMOVE_UART_RX_PIN             (0u)
#define GPS_UART_REMOVE_UART_RX_WAKE_PIN        (1u)

/* Unconfigured pins */
#define GPS_UART_MOSI_SCL_RX_WAKE_PIN   (0u == GPS_UART_REMOVE_MOSI_SCL_RX_WAKE_PIN)
#define GPS_UART_MOSI_SCL_RX_PIN        (0u == GPS_UART_REMOVE_MOSI_SCL_RX_PIN)
#define GPS_UART_MISO_SDA_TX_PIN        (0u == GPS_UART_REMOVE_MISO_SDA_TX_PIN)
#define GPS_UART_SCLK_PIN               (0u == GPS_UART_REMOVE_SCLK_PIN)
#define GPS_UART_SS0_PIN                (0u == GPS_UART_REMOVE_SS0_PIN)
#define GPS_UART_SS1_PIN                (0u == GPS_UART_REMOVE_SS1_PIN)
#define GPS_UART_SS2_PIN                (0u == GPS_UART_REMOVE_SS2_PIN)
#define GPS_UART_SS3_PIN                (0u == GPS_UART_REMOVE_SS3_PIN)

/* Mode defined pins */
#define GPS_UART_I2C_PINS               (0u == GPS_UART_REMOVE_I2C_PINS)
#define GPS_UART_SPI_MASTER_PINS        (0u == GPS_UART_REMOVE_SPI_MASTER_PINS)
#define GPS_UART_SPI_SLAVE_PINS         (0u == GPS_UART_REMOVE_SPI_SLAVE_PINS)
#define GPS_UART_SPI_MASTER_SS0_PIN     (0u == GPS_UART_REMOVE_SPI_MASTER_SS0_PIN)
#define GPS_UART_SPI_MASTER_SS1_PIN     (0u == GPS_UART_REMOVE_SPI_MASTER_SS1_PIN)
#define GPS_UART_SPI_MASTER_SS2_PIN     (0u == GPS_UART_REMOVE_SPI_MASTER_SS2_PIN)
#define GPS_UART_SPI_MASTER_SS3_PIN     (0u == GPS_UART_REMOVE_SPI_MASTER_SS3_PIN)
#define GPS_UART_UART_TX_PIN            (0u == GPS_UART_REMOVE_UART_TX_PIN)
#define GPS_UART_UART_RX_TX_PIN         (0u == GPS_UART_REMOVE_UART_RX_TX_PIN)
#define GPS_UART_UART_RX_PIN            (0u == GPS_UART_REMOVE_UART_RX_PIN)
#define GPS_UART_UART_RX_WAKE_PIN       (0u == GPS_UART_REMOVE_UART_RX_WAKE_PIN)


/***************************************
*             Includes
****************************************/

#if(GPS_UART_MOSI_SCL_RX_WAKE_PIN)
    #include "GPS_UART_spi_mosi_i2c_scl_uart_rx_wake.h"
#endif /* (GPS_UART_MOSI_SCL_RX_WAKE_PIN) */

#if(GPS_UART_MOSI_SCL_RX_PIN)
    #include "GPS_UART_spi_mosi_i2c_scl_uart_rx.h"
#endif /* (GPS_UART_MOSI_SCL_RX_PIN) */

#if(GPS_UART_MISO_SDA_TX_PIN)
    #include "GPS_UART_spi_miso_i2c_sda_uart_tx.h"
#endif /* (GPS_UART_MISO_SDA_TX_PIN_PIN) */

#if(GPS_UART_SCLK_PIN)
    #include "GPS_UART_spi_sclk.h"
#endif /* (GPS_UART_SCLK_PIN) */

#if(GPS_UART_SS0_PIN)
    #include "GPS_UART_spi_ss0.h"
#endif /* (GPS_UART_SS1_PIN) */

#if(GPS_UART_SS1_PIN)
    #include "GPS_UART_spi_ss1.h"
#endif /* (GPS_UART_SS1_PIN) */

#if(GPS_UART_SS2_PIN)
    #include "GPS_UART_spi_ss2.h"
#endif /* (GPS_UART_SS2_PIN) */

#if(GPS_UART_SS3_PIN)
    #include "GPS_UART_spi_ss3.h"
#endif /* (GPS_UART_SS3_PIN) */

#if(GPS_UART_I2C_PINS)
    #include "GPS_UART_scl.h"
    #include "GPS_UART_sda.h"
#endif /* (GPS_UART_I2C_PINS) */

#if(GPS_UART_SPI_MASTER_PINS)
    #include "GPS_UART_sclk_m.h"
    #include "GPS_UART_mosi_m.h"
    #include "GPS_UART_miso_m.h"
#endif /* (GPS_UART_SPI_MASTER_PINS) */

#if(GPS_UART_SPI_SLAVE_PINS)
    #include "GPS_UART_sclk_s.h"
    #include "GPS_UART_mosi_s.h"
    #include "GPS_UART_miso_s.h"
    #include "GPS_UART_ss_s.h"
#endif /* (GPS_UART_SPI_SLAVE_PINS) */

#if(GPS_UART_SPI_MASTER_SS0_PIN)
    #include "GPS_UART_ss0_m.h"
#endif /* (GPS_UART_SPI_MASTER_SS0_PIN) */

#if(GPS_UART_SPI_MASTER_SS1_PIN)
    #include "GPS_UART_ss1_m.h"
#endif /* (GPS_UART_SPI_MASTER_SS1_PIN) */

#if(GPS_UART_SPI_MASTER_SS2_PIN)
    #include "GPS_UART_ss2_m.h"
#endif /* (GPS_UART_SPI_MASTER_SS2_PIN) */

#if(GPS_UART_SPI_MASTER_SS3_PIN)
    #include "GPS_UART_ss3_m.h"
#endif /* (GPS_UART_SPI_MASTER_SS3_PIN) */

#if(GPS_UART_UART_TX_PIN)
    #include "GPS_UART_tx.h"
#endif /* (GPS_UART_UART_TX_PIN) */

#if(GPS_UART_UART_RX_TX_PIN)
    #include "GPS_UART_rx_tx.h"
#endif /* (GPS_UART_UART_RX_TX_PIN) */

#if(GPS_UART_UART_RX_PIN)
    #include "GPS_UART_rx.h"
#endif /* (GPS_UART_UART_RX_PIN) */

#if(GPS_UART_UART_RX_WAKE_PIN)
    #include "GPS_UART_rx_wake.h"
#endif /* (GPS_UART_UART_RX_WAKE_PIN) */


/***************************************
*              Registers
***************************************/

#if(GPS_UART_MOSI_SCL_RX_WAKE_PIN)
    #define GPS_UART_MOSI_SCL_RX_WAKE_HSIOM_REG  \
                                                (*(reg32 *) GPS_UART_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM)
    #define GPS_UART_MOSI_SCL_RX_WAKE_HSIOM_PTR  \
                                                ( (reg32 *) GPS_UART_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM)
    #define GPS_UART_MOSI_SCL_RX_WAKE_HSIOM_MASK \
                                                (GPS_UART_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM_MASK)
    #define GPS_UART_MOSI_SCL_RX_WAKE_HSIOM_POS  \
                                                (GPS_UART_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM_SHIFT)

    #define GPS_UART_MOSI_SCL_RX_WAKE_INTCFG_REG    (*(reg32 *) \
                                                              GPS_UART_spi_mosi_i2c_scl_uart_rx_wake__0__INTCFG)
    #define GPS_UART_MOSI_SCL_RX_WAKE_INTCFG_PTR    ( (reg32 *) \
                                                              GPS_UART_spi_mosi_i2c_scl_uart_rx_wake__0__INTCFG)

    #define GPS_UART_INTCFG_TYPE_MASK                  (0x03u)
    #define GPS_UART_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS  (GPS_UART_spi_mosi_i2c_scl_uart_rx_wake__SHIFT)
    #define GPS_UART_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK ((uint32)                                           \
                                                                    ((uint32) GPS_UART_INTCFG_TYPE_MASK << \
                                                                    GPS_UART_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS))
#endif /* (GPS_UART_MOSI_SCL_RX_WAKE_PIN) */

#if(GPS_UART_MOSI_SCL_RX_PIN)
    #define GPS_UART_MOSI_SCL_RX_HSIOM_REG      (*(reg32 *) GPS_UART_spi_mosi_i2c_scl_uart_rx__0__HSIOM)
    #define GPS_UART_MOSI_SCL_RX_HSIOM_PTR      ( (reg32 *) GPS_UART_spi_mosi_i2c_scl_uart_rx__0__HSIOM)
    #define GPS_UART_MOSI_SCL_RX_HSIOM_MASK     (GPS_UART_spi_mosi_i2c_scl_uart_rx__0__HSIOM_MASK)
    #define GPS_UART_MOSI_SCL_RX_HSIOM_POS      (GPS_UART_spi_mosi_i2c_scl_uart_rx__0__HSIOM_SHIFT)
#endif /* (GPS_UART_MOSI_SCL_RX_PIN) */

#if(GPS_UART_MISO_SDA_TX_PIN)
    #define GPS_UART_MISO_SDA_TX_HSIOM_REG      (*(reg32 *) GPS_UART_spi_miso_i2c_sda_uart_tx__0__HSIOM)
    #define GPS_UART_MISO_SDA_TX_HSIOM_PTR      ( (reg32 *) GPS_UART_spi_miso_i2c_sda_uart_tx__0__HSIOM)
    #define GPS_UART_MISO_SDA_TX_HSIOM_MASK     (GPS_UART_spi_miso_i2c_sda_uart_tx__0__HSIOM_MASK)
    #define GPS_UART_MISO_SDA_TX_HSIOM_POS      (GPS_UART_spi_miso_i2c_sda_uart_tx__0__HSIOM_SHIFT)
#endif /* (GPS_UART_MISO_SDA_TX_PIN_PIN) */

#if(GPS_UART_SCLK_PIN)
    #define GPS_UART_SCLK_HSIOM_REG     (*(reg32 *) GPS_UART_spi_sclk__0__HSIOM)
    #define GPS_UART_SCLK_HSIOM_PTR     ( (reg32 *) GPS_UART_spi_sclk__0__HSIOM)
    #define GPS_UART_SCLK_HSIOM_MASK    (GPS_UART_spi_sclk__0__HSIOM_MASK)
    #define GPS_UART_SCLK_HSIOM_POS     (GPS_UART_spi_sclk__0__HSIOM_SHIFT)
#endif /* (GPS_UART_SCLK_PIN) */

#if(GPS_UART_SS0_PIN)
    #define GPS_UART_SS0_HSIOM_REG      (*(reg32 *) GPS_UART_spi_ss0__0__HSIOM)
    #define GPS_UART_SS0_HSIOM_PTR      ( (reg32 *) GPS_UART_spi_ss0__0__HSIOM)
    #define GPS_UART_SS0_HSIOM_MASK     (GPS_UART_spi_ss0__0__HSIOM_MASK)
    #define GPS_UART_SS0_HSIOM_POS      (GPS_UART_spi_ss0__0__HSIOM_SHIFT)
#endif /* (GPS_UART_SS1_PIN) */

#if(GPS_UART_SS1_PIN)
    #define GPS_UART_SS1_HSIOM_REG      (*(reg32 *) GPS_UART_spi_ss1__0__HSIOM)
    #define GPS_UART_SS1_HSIOM_PTR      ( (reg32 *) GPS_UART_spi_ss1__0__HSIOM)
    #define GPS_UART_SS1_HSIOM_MASK     (GPS_UART_spi_ss1__0__HSIOM_MASK)
    #define GPS_UART_SS1_HSIOM_POS      (GPS_UART_spi_ss1__0__HSIOM_SHIFT)
#endif /* (GPS_UART_SS1_PIN) */

#if(GPS_UART_SS2_PIN)
    #define GPS_UART_SS2_HSIOM_REG     (*(reg32 *) GPS_UART_spi_ss2__0__HSIOM)
    #define GPS_UART_SS2_HSIOM_PTR     ( (reg32 *) GPS_UART_spi_ss2__0__HSIOM)
    #define GPS_UART_SS2_HSIOM_MASK    (GPS_UART_spi_ss2__0__HSIOM_MASK)
    #define GPS_UART_SS2_HSIOM_POS     (GPS_UART_spi_ss2__0__HSIOM_SHIFT)
#endif /* (GPS_UART_SS2_PIN) */

#if(GPS_UART_SS3_PIN)
    #define GPS_UART_SS3_HSIOM_REG     (*(reg32 *) GPS_UART_spi_ss3__0__HSIOM)
    #define GPS_UART_SS3_HSIOM_PTR     ( (reg32 *) GPS_UART_spi_ss3__0__HSIOM)
    #define GPS_UART_SS3_HSIOM_MASK    (GPS_UART_spi_ss3__0__HSIOM_MASK)
    #define GPS_UART_SS3_HSIOM_POS     (GPS_UART_spi_ss3__0__HSIOM_SHIFT)
#endif /* (GPS_UART_SS3_PIN) */

#if(GPS_UART_I2C_PINS)
    #define GPS_UART_SCL_HSIOM_REG     (*(reg32 *) GPS_UART_scl__0__HSIOM)
    #define GPS_UART_SCL_HSIOM_PTR     ( (reg32 *) GPS_UART_scl__0__HSIOM)
    #define GPS_UART_SCL_HSIOM_MASK    (GPS_UART_scl__0__HSIOM_MASK)
    #define GPS_UART_SCL_HSIOM_POS     (GPS_UART_scl__0__HSIOM_SHIFT)

    #define GPS_UART_SDA_HSIOM_REG     (*(reg32 *) GPS_UART_sda__0__HSIOM)
    #define GPS_UART_SDA_HSIOM_PTR     ( (reg32 *) GPS_UART_sda__0__HSIOM)
    #define GPS_UART_SDA_HSIOM_MASK    (GPS_UART_sda__0__HSIOM_MASK)
    #define GPS_UART_SDA_HSIOM_POS     (GPS_UART_sda__0__HSIOM_SHIFT)
#endif /* (GPS_UART_I2C_PINS) */


/***************************************
*        Registers Constants
***************************************/

/* Pins constants */
#define GPS_UART_HSIOM_DEF_SEL      (0x00u)
#define GPS_UART_HSIOM_GPIO_SEL     (0x00u)
#define GPS_UART_HSIOM_UART_SEL     (0x09u)
#define GPS_UART_HSIOM_I2C_SEL      (0x0Eu)
#define GPS_UART_HSIOM_SPI_SEL      (0x0Fu)

#if(!GPS_UART_CY_SCBIP_V1_I2C_ONLY)
    #define GPS_UART_SCB_PINS_NUMBER    (7u)
#else
    #define GPS_UART_SCB_PINS_NUMBER    (2u)
#endif /* (!GPS_UART_CY_SCBIP_V1_I2C_ONLY) */

#define GPS_UART_MOSI_SCL_RX_PIN_INDEX      (0u) /* RX pins without interrupt */
#define GPS_UART_MOSI_SCL_RX_WAKE_PIN_INDEX (0u) /* RX pin with interrupt     */
#define GPS_UART_MISO_SDA_TX_PIN_INDEX      (1u)
#define GPS_UART_SCLK_PIN_INDEX             (2u)
#define GPS_UART_SS0_PIN_INDEX              (3u)
#define GPS_UART_SS1_PIN_INDEX              (4u)
#define GPS_UART_SS2_PIN_INDEX              (5u)
#define GPS_UART_SS3_PIN_INDEX              (6u)

#define GPS_UART_MOSI_SCL_RX_PIN_MASK      ((uint32) 0x01u << GPS_UART_MOSI_SCL_RX_PIN_INDEX)
#define GPS_UART_MOSI_SCL_RX_WAKE_PIN_MASK ((uint32) 0x01u << GPS_UART_MOSI_SCL_RX_WAKE_PIN_INDEX)
#define GPS_UART_MISO_SDA_TX_PIN_MASK      ((uint32) 0x01u << GPS_UART_MISO_SDA_TX_PIN_INDEX)
#define GPS_UART_SCLK_PIN_MASK             ((uint32) 0x01u << GPS_UART_SCLK_PIN_INDEX)
#define GPS_UART_SS0_PIN_MASK              ((uint32) 0x01u << GPS_UART_SS0_PIN_INDEX)
#define GPS_UART_SS1_PIN_MASK              ((uint32) 0x01u << GPS_UART_SS1_PIN_INDEX)
#define GPS_UART_SS2_PIN_MASK              ((uint32) 0x01u << GPS_UART_SS2_PIN_INDEX)
#define GPS_UART_SS3_PIN_MASK              ((uint32) 0x01u << GPS_UART_SS3_PIN_INDEX)

#define GPS_UART_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin DM defines */
#define GPS_UART_PIN_DM_ALG_HIZ  (0u)
#define GPS_UART_PIN_DM_DIG_HIZ  (1u)
#define GPS_UART_PIN_DM_OD_LO    (4u)
#define GPS_UART_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Set bits-mask in register */
#define GPS_UART_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit the in register */
#define GPS_UART_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define GPS_UART_SET_HSIOM_SEL(reg, mask, pos, sel) GPS_UART_SET_REGISTER_BITS(reg, mask, pos, sel)
#define GPS_UART_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        GPS_UART_SET_REGISTER_BITS(reg, mask, pos, intType)
#define GPS_UART_SET_INP_DIS(reg, mask, val) GPS_UART_SET_REGISTER_BIT(reg, mask, val)

/* GPS_UART_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  GPS_UART_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if(GPS_UART_I2C_PINS)
    #define GPS_UART_SET_I2C_SCL_DR(val) GPS_UART_scl_Write(val)

    #define GPS_UART_SET_I2C_SCL_HSIOM_SEL(sel) \
                          GPS_UART_SET_HSIOM_SEL(GPS_UART_SCL_HSIOM_REG,  \
                                                         GPS_UART_SCL_HSIOM_MASK, \
                                                         GPS_UART_SCL_HSIOM_POS,  \
                                                         (sel))
    #define GPS_UART_WAIT_SCL_SET_HIGH  (0u == GPS_UART_scl_Read())

/* Unconfigured SCB: scl signal */
#elif(GPS_UART_MOSI_SCL_RX_WAKE_PIN)
    #define GPS_UART_SET_I2C_SCL_DR(val) \
                            GPS_UART_spi_mosi_i2c_scl_uart_rx_wake_Write(val)

    #define GPS_UART_SET_I2C_SCL_HSIOM_SEL(sel) \
                    GPS_UART_SET_HSIOM_SEL(GPS_UART_MOSI_SCL_RX_WAKE_HSIOM_REG,  \
                                                   GPS_UART_MOSI_SCL_RX_WAKE_HSIOM_MASK, \
                                                   GPS_UART_MOSI_SCL_RX_WAKE_HSIOM_POS,  \
                                                   (sel))

    #define GPS_UART_WAIT_SCL_SET_HIGH  (0u == GPS_UART_spi_mosi_i2c_scl_uart_rx_wake_Read())

#elif(GPS_UART_MOSI_SCL_RX_PIN)
    #define GPS_UART_SET_I2C_SCL_DR(val) \
                            GPS_UART_spi_mosi_i2c_scl_uart_rx_Write(val)


    #define GPS_UART_SET_I2C_SCL_HSIOM_SEL(sel) \
                            GPS_UART_SET_HSIOM_SEL(GPS_UART_MOSI_SCL_RX_HSIOM_REG,  \
                                                           GPS_UART_MOSI_SCL_RX_HSIOM_MASK, \
                                                           GPS_UART_MOSI_SCL_RX_HSIOM_POS,  \
                                                           (sel))

    #define GPS_UART_WAIT_SCL_SET_HIGH  (0u == GPS_UART_spi_mosi_i2c_scl_uart_rx_Read())

#else
    #define GPS_UART_SET_I2C_SCL_DR(val) \
                                                    do{ ; }while(0)
    #define GPS_UART_SET_I2C_SCL_HSIOM_SEL(sel) \
                                                    do{ ; }while(0)

    #define GPS_UART_WAIT_SCL_SET_HIGH  (0u)
#endif /* (GPS_UART_MOSI_SCL_RX_PIN) */

/* SCB I2C: sda signal */
#if(GPS_UART_I2C_PINS)
    #define GPS_UART_WAIT_SDA_SET_HIGH  (0u == GPS_UART_sda_Read())

/* Unconfigured SCB: sda signal */
#elif(GPS_UART_MISO_SDA_TX_PIN)
    #define GPS_UART_WAIT_SDA_SET_HIGH  (0u == GPS_UART_spi_miso_i2c_sda_uart_tx_Read())

#else
    #define GPS_UART_WAIT_SDA_SET_HIGH  (0u)
#endif /* (GPS_UART_MOSI_SCL_RX_PIN) */

#endif /* (CY_SCB_PINS_GPS_UART_H) */


/* [] END OF FILE */
