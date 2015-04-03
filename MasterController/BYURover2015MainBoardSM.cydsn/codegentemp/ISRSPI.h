/*******************************************************************************
* File Name: ISRSPI.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_ISRSPI_H)
#define CY_ISR_ISRSPI_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void ISRSPI_Start(void);
void ISRSPI_StartEx(cyisraddress address);
void ISRSPI_Stop(void);

CY_ISR_PROTO(ISRSPI_Interrupt);

void ISRSPI_SetVector(cyisraddress address);
cyisraddress ISRSPI_GetVector(void);

void ISRSPI_SetPriority(uint8 priority);
uint8 ISRSPI_GetPriority(void);

void ISRSPI_Enable(void);
uint8 ISRSPI_GetState(void);
void ISRSPI_Disable(void);

void ISRSPI_SetPending(void);
void ISRSPI_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ISRSPI ISR. */
#define ISRSPI_INTC_VECTOR            ((reg32 *) ISRSPI__INTC_VECT)

/* Address of the ISRSPI ISR priority. */
#define ISRSPI_INTC_PRIOR             ((reg32 *) ISRSPI__INTC_PRIOR_REG)

/* Priority of the ISRSPI interrupt. */
#define ISRSPI_INTC_PRIOR_NUMBER      ISRSPI__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ISRSPI interrupt. */
#define ISRSPI_INTC_SET_EN            ((reg32 *) ISRSPI__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ISRSPI interrupt. */
#define ISRSPI_INTC_CLR_EN            ((reg32 *) ISRSPI__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ISRSPI interrupt state to pending. */
#define ISRSPI_INTC_SET_PD            ((reg32 *) ISRSPI__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ISRSPI interrupt. */
#define ISRSPI_INTC_CLR_PD            ((reg32 *) ISRSPI__INTC_CLR_PD_REG)



#endif /* CY_ISR_ISRSPI_H */


/* [] END OF FILE */
