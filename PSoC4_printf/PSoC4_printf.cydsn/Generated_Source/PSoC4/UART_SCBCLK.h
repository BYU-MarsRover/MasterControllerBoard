/*******************************************************************************
* File Name: UART_SCBCLK.h
* Version 2.0
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_UART_SCBCLK_H)
#define CY_CLOCK_UART_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void UART_SCBCLK_Start(void);
void UART_SCBCLK_Stop(void);

void UART_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 UART_SCBCLK_GetDividerRegister(void);
uint8  UART_SCBCLK_GetFractionalDividerRegister(void);

#define UART_SCBCLK_Enable()                         UART_SCBCLK_Start()
#define UART_SCBCLK_Disable()                        UART_SCBCLK_Stop()
#define UART_SCBCLK_SetDividerRegister(clkDivider, reset)  \
                        UART_SCBCLK_SetFractionalDividerRegister((clkDivider), 0)
#define UART_SCBCLK_SetDivider(clkDivider)           UART_SCBCLK_SetDividerRegister((clkDivider), 1)
#define UART_SCBCLK_SetDividerValue(clkDivider)      UART_SCBCLK_SetDividerRegister((clkDivider) - 1, 1)


/***************************************
*             Registers
***************************************/

#define UART_SCBCLK_DIV_REG    (*(reg32 *)UART_SCBCLK__REGISTER)
#define UART_SCBCLK_ENABLE_REG UART_SCBCLK_DIV_REG

#endif /* !defined(CY_CLOCK_UART_SCBCLK_H) */

/* [] END OF FILE */
