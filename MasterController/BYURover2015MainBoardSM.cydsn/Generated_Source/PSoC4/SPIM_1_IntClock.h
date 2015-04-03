/*******************************************************************************
* File Name: SPIM_1_IntClock.h
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

#if !defined(CY_CLOCK_SPIM_1_IntClock_H)
#define CY_CLOCK_SPIM_1_IntClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void SPIM_1_IntClock_StartEx(uint32 alignClkDiv);
#define SPIM_1_IntClock_Start() \
    SPIM_1_IntClock_StartEx(SPIM_1_IntClock__PA_DIV_ID)

#else

void SPIM_1_IntClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void SPIM_1_IntClock_Stop(void);

void SPIM_1_IntClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 SPIM_1_IntClock_GetDividerRegister(void);
uint8  SPIM_1_IntClock_GetFractionalDividerRegister(void);

#define SPIM_1_IntClock_Enable()                         SPIM_1_IntClock_Start()
#define SPIM_1_IntClock_Disable()                        SPIM_1_IntClock_Stop()
#define SPIM_1_IntClock_SetDividerRegister(clkDivider, reset)  \
    SPIM_1_IntClock_SetFractionalDividerRegister((clkDivider), 0u)
#define SPIM_1_IntClock_SetDivider(clkDivider)           SPIM_1_IntClock_SetDividerRegister((clkDivider), 1u)
#define SPIM_1_IntClock_SetDividerValue(clkDivider)      SPIM_1_IntClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define SPIM_1_IntClock_DIV_ID     SPIM_1_IntClock__DIV_ID

#define SPIM_1_IntClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define SPIM_1_IntClock_CTRL_REG   (*(reg32 *)SPIM_1_IntClock__CTRL_REGISTER)
#define SPIM_1_IntClock_DIV_REG    (*(reg32 *)SPIM_1_IntClock__DIV_REGISTER)

#define SPIM_1_IntClock_CMD_DIV_SHIFT          (0u)
#define SPIM_1_IntClock_CMD_PA_DIV_SHIFT       (8u)
#define SPIM_1_IntClock_CMD_DISABLE_SHIFT      (30u)
#define SPIM_1_IntClock_CMD_ENABLE_SHIFT       (31u)

#define SPIM_1_IntClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << SPIM_1_IntClock_CMD_DISABLE_SHIFT))
#define SPIM_1_IntClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << SPIM_1_IntClock_CMD_ENABLE_SHIFT))

#define SPIM_1_IntClock_DIV_FRAC_MASK  (0x000000F8u)
#define SPIM_1_IntClock_DIV_FRAC_SHIFT (3u)
#define SPIM_1_IntClock_DIV_INT_MASK   (0xFFFFFF00u)
#define SPIM_1_IntClock_DIV_INT_SHIFT  (8u)

#else 

#define SPIM_1_IntClock_DIV_REG        (*(reg32 *)SPIM_1_IntClock__REGISTER)
#define SPIM_1_IntClock_ENABLE_REG     SPIM_1_IntClock_DIV_REG
#define SPIM_1_IntClock_DIV_FRAC_MASK  SPIM_1_IntClock__FRAC_MASK
#define SPIM_1_IntClock_DIV_FRAC_SHIFT (16u)
#define SPIM_1_IntClock_DIV_INT_MASK   SPIM_1_IntClock__DIVIDER_MASK
#define SPIM_1_IntClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_SPIM_1_IntClock_H) */

/* [] END OF FILE */
