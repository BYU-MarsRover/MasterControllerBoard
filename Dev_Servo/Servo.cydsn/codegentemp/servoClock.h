/*******************************************************************************
* File Name: servoClock.h
* Version 2.20
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

#if !defined(CY_CLOCK_servoClock_H)
#define CY_CLOCK_servoClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void servoClock_StartEx(uint32 alignClkDiv);
#define servoClock_Start() \
    servoClock_StartEx(servoClock__PA_DIV_ID)

#else

void servoClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void servoClock_Stop(void);

void servoClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 servoClock_GetDividerRegister(void);
uint8  servoClock_GetFractionalDividerRegister(void);

#define servoClock_Enable()                         servoClock_Start()
#define servoClock_Disable()                        servoClock_Stop()
#define servoClock_SetDividerRegister(clkDivider, reset)  \
    servoClock_SetFractionalDividerRegister((clkDivider), 0u)
#define servoClock_SetDivider(clkDivider)           servoClock_SetDividerRegister((clkDivider), 1u)
#define servoClock_SetDividerValue(clkDivider)      servoClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define servoClock_DIV_ID     servoClock__DIV_ID

#define servoClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define servoClock_CTRL_REG   (*(reg32 *)servoClock__CTRL_REGISTER)
#define servoClock_DIV_REG    (*(reg32 *)servoClock__DIV_REGISTER)

#define servoClock_CMD_DIV_SHIFT          (0u)
#define servoClock_CMD_PA_DIV_SHIFT       (8u)
#define servoClock_CMD_DISABLE_SHIFT      (30u)
#define servoClock_CMD_ENABLE_SHIFT       (31u)

#define servoClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << servoClock_CMD_DISABLE_SHIFT))
#define servoClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << servoClock_CMD_ENABLE_SHIFT))

#define servoClock_DIV_FRAC_MASK  (0x000000F8u)
#define servoClock_DIV_FRAC_SHIFT (3u)
#define servoClock_DIV_INT_MASK   (0xFFFFFF00u)
#define servoClock_DIV_INT_SHIFT  (8u)

#else 

#define servoClock_DIV_REG        (*(reg32 *)servoClock__REGISTER)
#define servoClock_ENABLE_REG     servoClock_DIV_REG
#define servoClock_DIV_FRAC_MASK  servoClock__FRAC_MASK
#define servoClock_DIV_FRAC_SHIFT (16u)
#define servoClock_DIV_INT_MASK   servoClock__DIVIDER_MASK
#define servoClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_servoClock_H) */

/* [] END OF FILE */
