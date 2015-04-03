/*******************************************************************************
* File Name: P.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values for the P
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_P_H)
#define CY_TCPWM_P_H

#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} P_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  P_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define P_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)

/* TCPWM Configuration */
#define P_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define P_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define P_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define P_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define P_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define P_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define P_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define P_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define P_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define P_TC_RUN_MODE                    (0lu)
#define P_TC_COUNTER_MODE                (0lu)
#define P_TC_COMP_CAP_MODE               (2lu)
#define P_TC_PRESCALER                   (0lu)

/* Signal modes */
#define P_TC_RELOAD_SIGNAL_MODE          (0lu)
#define P_TC_COUNT_SIGNAL_MODE           (3lu)
#define P_TC_START_SIGNAL_MODE           (0lu)
#define P_TC_STOP_SIGNAL_MODE            (0lu)
#define P_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define P_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define P_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define P_TC_START_SIGNAL_PRESENT        (0lu)
#define P_TC_STOP_SIGNAL_PRESENT         (0lu)
#define P_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define P_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define P_PWM_KILL_EVENT                 (0lu)
#define P_PWM_STOP_EVENT                 (0lu)
#define P_PWM_MODE                       (4lu)
#define P_PWM_OUT_N_INVERT               (0lu)
#define P_PWM_OUT_INVERT                 (0lu)
#define P_PWM_ALIGN                      (0lu)
#define P_PWM_RUN_MODE                   (0lu)
#define P_PWM_DEAD_TIME_CYCLE            (0lu)
#define P_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define P_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define P_PWM_COUNT_SIGNAL_MODE          (3lu)
#define P_PWM_START_SIGNAL_MODE          (0lu)
#define P_PWM_STOP_SIGNAL_MODE           (0lu)
#define P_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define P_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define P_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define P_PWM_START_SIGNAL_PRESENT       (0lu)
#define P_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define P_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define P_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define P_TC_PERIOD_VALUE                (65535lu)
#define P_TC_COMPARE_VALUE               (65535lu)
#define P_TC_COMPARE_BUF_VALUE           (65535lu)
#define P_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define P_PWM_PERIOD_VALUE               (20000lu)
#define P_PWM_PERIOD_BUF_VALUE           (65535lu)
#define P_PWM_PERIOD_SWAP                (0lu)
#define P_PWM_COMPARE_VALUE              (1000lu)
#define P_PWM_COMPARE_BUF_VALUE          (65535lu)
#define P_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define P__LEFT 0
#define P__RIGHT 1
#define P__CENTER 2
#define P__ASYMMETRIC 3

#define P__X1 0
#define P__X2 1
#define P__X4 2

#define P__PWM 4
#define P__PWM_DT 5
#define P__PWM_PR 6

#define P__INVERSE 1
#define P__DIRECT 0

#define P__CAPTURE 2
#define P__COMPARE 0

#define P__TRIG_LEVEL 3
#define P__TRIG_RISING 0
#define P__TRIG_FALLING 1
#define P__TRIG_BOTH 2

#define P__INTR_MASK_TC 1
#define P__INTR_MASK_CC_MATCH 2
#define P__INTR_MASK_NONE 0
#define P__INTR_MASK_TC_CC 3

#define P__UNCONFIG 8
#define P__TIMER 1
#define P__QUAD 3
#define P__PWM_SEL 7

#define P__COUNT_UP 0
#define P__COUNT_DOWN 1
#define P__COUNT_UPDOWN0 2
#define P__COUNT_UPDOWN1 3


/* Prescaler */
#define P_PRESCALE_DIVBY1                ((uint32)(0u << P_PRESCALER_SHIFT))
#define P_PRESCALE_DIVBY2                ((uint32)(1u << P_PRESCALER_SHIFT))
#define P_PRESCALE_DIVBY4                ((uint32)(2u << P_PRESCALER_SHIFT))
#define P_PRESCALE_DIVBY8                ((uint32)(3u << P_PRESCALER_SHIFT))
#define P_PRESCALE_DIVBY16               ((uint32)(4u << P_PRESCALER_SHIFT))
#define P_PRESCALE_DIVBY32               ((uint32)(5u << P_PRESCALER_SHIFT))
#define P_PRESCALE_DIVBY64               ((uint32)(6u << P_PRESCALER_SHIFT))
#define P_PRESCALE_DIVBY128              ((uint32)(7u << P_PRESCALER_SHIFT))

/* TCPWM set modes */
#define P_MODE_TIMER_COMPARE             ((uint32)(P__COMPARE         <<  \
                                                                  P_MODE_SHIFT))
#define P_MODE_TIMER_CAPTURE             ((uint32)(P__CAPTURE         <<  \
                                                                  P_MODE_SHIFT))
#define P_MODE_QUAD                      ((uint32)(P__QUAD            <<  \
                                                                  P_MODE_SHIFT))
#define P_MODE_PWM                       ((uint32)(P__PWM             <<  \
                                                                  P_MODE_SHIFT))
#define P_MODE_PWM_DT                    ((uint32)(P__PWM_DT          <<  \
                                                                  P_MODE_SHIFT))
#define P_MODE_PWM_PR                    ((uint32)(P__PWM_PR          <<  \
                                                                  P_MODE_SHIFT))

/* Quad Modes */
#define P_MODE_X1                        ((uint32)(P__X1              <<  \
                                                                  P_QUAD_MODE_SHIFT))
#define P_MODE_X2                        ((uint32)(P__X2              <<  \
                                                                  P_QUAD_MODE_SHIFT))
#define P_MODE_X4                        ((uint32)(P__X4              <<  \
                                                                  P_QUAD_MODE_SHIFT))

/* Counter modes */
#define P_COUNT_UP                       ((uint32)(P__COUNT_UP        <<  \
                                                                  P_UPDOWN_SHIFT))
#define P_COUNT_DOWN                     ((uint32)(P__COUNT_DOWN      <<  \
                                                                  P_UPDOWN_SHIFT))
#define P_COUNT_UPDOWN0                  ((uint32)(P__COUNT_UPDOWN0   <<  \
                                                                  P_UPDOWN_SHIFT))
#define P_COUNT_UPDOWN1                  ((uint32)(P__COUNT_UPDOWN1   <<  \
                                                                  P_UPDOWN_SHIFT))

/* PWM output invert */
#define P_INVERT_LINE                    ((uint32)(P__INVERSE         <<  \
                                                                  P_INV_OUT_SHIFT))
#define P_INVERT_LINE_N                  ((uint32)(P__INVERSE         <<  \
                                                                  P_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define P_TRIG_RISING                    ((uint32)P__TRIG_RISING)
#define P_TRIG_FALLING                   ((uint32)P__TRIG_FALLING)
#define P_TRIG_BOTH                      ((uint32)P__TRIG_BOTH)
#define P_TRIG_LEVEL                     ((uint32)P__TRIG_LEVEL)

/* Interrupt mask */
#define P_INTR_MASK_TC                   ((uint32)P__INTR_MASK_TC)
#define P_INTR_MASK_CC_MATCH             ((uint32)P__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define P_CC_MATCH_SET                   (0x00u)
#define P_CC_MATCH_CLEAR                 (0x01u)
#define P_CC_MATCH_INVERT                (0x02u)
#define P_CC_MATCH_NO_CHANGE             (0x03u)
#define P_OVERLOW_SET                    (0x00u)
#define P_OVERLOW_CLEAR                  (0x04u)
#define P_OVERLOW_INVERT                 (0x08u)
#define P_OVERLOW_NO_CHANGE              (0x0Cu)
#define P_UNDERFLOW_SET                  (0x00u)
#define P_UNDERFLOW_CLEAR                (0x10u)
#define P_UNDERFLOW_INVERT               (0x20u)
#define P_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define P_PWM_MODE_LEFT                  (P_CC_MATCH_CLEAR        |   \
                                                         P_OVERLOW_SET           |   \
                                                         P_UNDERFLOW_NO_CHANGE)
#define P_PWM_MODE_RIGHT                 (P_CC_MATCH_SET          |   \
                                                         P_OVERLOW_NO_CHANGE     |   \
                                                         P_UNDERFLOW_CLEAR)
#define P_PWM_MODE_CENTER                (P_CC_MATCH_INVERT       |   \
                                                         P_OVERLOW_NO_CHANGE     |   \
                                                         P_UNDERFLOW_CLEAR)
#define P_PWM_MODE_ASYM                  (P_CC_MATCH_NO_CHANGE    |   \
                                                         P_OVERLOW_SET           |   \
                                                         P_UNDERFLOW_CLEAR )

/* Command operations without condition */
#define P_CMD_CAPTURE                    (0u)
#define P_CMD_RELOAD                     (8u)
#define P_CMD_STOP                       (16u)
#define P_CMD_START                      (24u)

/* Status */
#define P_STATUS_DOWN                    (1u)
#define P_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   P_Init(void);
void   P_Enable(void);
void   P_Start(void);
void   P_Stop(void);

void   P_SetMode(uint32 mode);
void   P_SetCounterMode(uint32 counterMode);
void   P_SetPWMMode(uint32 modeMask);
void   P_SetQDMode(uint32 qdMode);

void   P_SetPrescaler(uint32 prescaler);
void   P_TriggerCommand(uint32 mask, uint32 command);
void   P_SetOneShot(uint32 oneShotEnable);
uint32 P_ReadStatus(void);

void   P_SetPWMSyncKill(uint32 syncKillEnable);
void   P_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   P_SetPWMDeadTime(uint32 deadTime);
void   P_SetPWMInvert(uint32 mask);

void   P_SetInterruptMode(uint32 interruptMask);
uint32 P_GetInterruptSourceMasked(void);
uint32 P_GetInterruptSource(void);
void   P_ClearInterrupt(uint32 interruptMask);
void   P_SetInterrupt(uint32 interruptMask);

void   P_WriteCounter(uint32 count);
uint32 P_ReadCounter(void);

uint32 P_ReadCapture(void);
uint32 P_ReadCaptureBuf(void);

void   P_WritePeriod(uint32 period);
uint32 P_ReadPeriod(void);
void   P_WritePeriodBuf(uint32 periodBuf);
uint32 P_ReadPeriodBuf(void);

void   P_WriteCompare(uint32 compare);
uint32 P_ReadCompare(void);
void   P_WriteCompareBuf(uint32 compareBuf);
uint32 P_ReadCompareBuf(void);

void   P_SetPeriodSwap(uint32 swapEnable);
void   P_SetCompareSwap(uint32 swapEnable);

void   P_SetCaptureMode(uint32 triggerMode);
void   P_SetReloadMode(uint32 triggerMode);
void   P_SetStartMode(uint32 triggerMode);
void   P_SetStopMode(uint32 triggerMode);
void   P_SetCountMode(uint32 triggerMode);

void   P_SaveConfig(void);
void   P_RestoreConfig(void);
void   P_Sleep(void);
void   P_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define P_BLOCK_CONTROL_REG              (*(reg32 *) P_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define P_BLOCK_CONTROL_PTR              ( (reg32 *) P_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define P_COMMAND_REG                    (*(reg32 *) P_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define P_COMMAND_PTR                    ( (reg32 *) P_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define P_INTRRUPT_CAUSE_REG             (*(reg32 *) P_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define P_INTRRUPT_CAUSE_PTR             ( (reg32 *) P_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define P_CONTROL_REG                    (*(reg32 *) P_cy_m0s8_tcpwm_1__CTRL )
#define P_CONTROL_PTR                    ( (reg32 *) P_cy_m0s8_tcpwm_1__CTRL )
#define P_STATUS_REG                     (*(reg32 *) P_cy_m0s8_tcpwm_1__STATUS )
#define P_STATUS_PTR                     ( (reg32 *) P_cy_m0s8_tcpwm_1__STATUS )
#define P_COUNTER_REG                    (*(reg32 *) P_cy_m0s8_tcpwm_1__COUNTER )
#define P_COUNTER_PTR                    ( (reg32 *) P_cy_m0s8_tcpwm_1__COUNTER )
#define P_COMP_CAP_REG                   (*(reg32 *) P_cy_m0s8_tcpwm_1__CC )
#define P_COMP_CAP_PTR                   ( (reg32 *) P_cy_m0s8_tcpwm_1__CC )
#define P_COMP_CAP_BUF_REG               (*(reg32 *) P_cy_m0s8_tcpwm_1__CC_BUFF )
#define P_COMP_CAP_BUF_PTR               ( (reg32 *) P_cy_m0s8_tcpwm_1__CC_BUFF )
#define P_PERIOD_REG                     (*(reg32 *) P_cy_m0s8_tcpwm_1__PERIOD )
#define P_PERIOD_PTR                     ( (reg32 *) P_cy_m0s8_tcpwm_1__PERIOD )
#define P_PERIOD_BUF_REG                 (*(reg32 *) P_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define P_PERIOD_BUF_PTR                 ( (reg32 *) P_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define P_TRIG_CONTROL0_REG              (*(reg32 *) P_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define P_TRIG_CONTROL0_PTR              ( (reg32 *) P_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define P_TRIG_CONTROL1_REG              (*(reg32 *) P_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define P_TRIG_CONTROL1_PTR              ( (reg32 *) P_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define P_TRIG_CONTROL2_REG              (*(reg32 *) P_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define P_TRIG_CONTROL2_PTR              ( (reg32 *) P_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define P_INTERRUPT_REQ_REG              (*(reg32 *) P_cy_m0s8_tcpwm_1__INTR )
#define P_INTERRUPT_REQ_PTR              ( (reg32 *) P_cy_m0s8_tcpwm_1__INTR )
#define P_INTERRUPT_SET_REG              (*(reg32 *) P_cy_m0s8_tcpwm_1__INTR_SET )
#define P_INTERRUPT_SET_PTR              ( (reg32 *) P_cy_m0s8_tcpwm_1__INTR_SET )
#define P_INTERRUPT_MASK_REG             (*(reg32 *) P_cy_m0s8_tcpwm_1__INTR_MASK )
#define P_INTERRUPT_MASK_PTR             ( (reg32 *) P_cy_m0s8_tcpwm_1__INTR_MASK )
#define P_INTERRUPT_MASKED_REG           (*(reg32 *) P_cy_m0s8_tcpwm_1__INTR_MASKED )
#define P_INTERRUPT_MASKED_PTR           ( (reg32 *) P_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define P_MASK                           ((uint32)P_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define P_RELOAD_CC_SHIFT                (0u)
#define P_RELOAD_PERIOD_SHIFT            (1u)
#define P_PWM_SYNC_KILL_SHIFT            (2u)
#define P_PWM_STOP_KILL_SHIFT            (3u)
#define P_PRESCALER_SHIFT                (8u)
#define P_UPDOWN_SHIFT                   (16u)
#define P_ONESHOT_SHIFT                  (18u)
#define P_QUAD_MODE_SHIFT                (20u)
#define P_INV_OUT_SHIFT                  (20u)
#define P_INV_COMPL_OUT_SHIFT            (21u)
#define P_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define P_RELOAD_CC_MASK                 ((uint32)(P_1BIT_MASK        <<  \
                                                                            P_RELOAD_CC_SHIFT))
#define P_RELOAD_PERIOD_MASK             ((uint32)(P_1BIT_MASK        <<  \
                                                                            P_RELOAD_PERIOD_SHIFT))
#define P_PWM_SYNC_KILL_MASK             ((uint32)(P_1BIT_MASK        <<  \
                                                                            P_PWM_SYNC_KILL_SHIFT))
#define P_PWM_STOP_KILL_MASK             ((uint32)(P_1BIT_MASK        <<  \
                                                                            P_PWM_STOP_KILL_SHIFT))
#define P_PRESCALER_MASK                 ((uint32)(P_8BIT_MASK        <<  \
                                                                            P_PRESCALER_SHIFT))
#define P_UPDOWN_MASK                    ((uint32)(P_2BIT_MASK        <<  \
                                                                            P_UPDOWN_SHIFT))
#define P_ONESHOT_MASK                   ((uint32)(P_1BIT_MASK        <<  \
                                                                            P_ONESHOT_SHIFT))
#define P_QUAD_MODE_MASK                 ((uint32)(P_3BIT_MASK        <<  \
                                                                            P_QUAD_MODE_SHIFT))
#define P_INV_OUT_MASK                   ((uint32)(P_2BIT_MASK        <<  \
                                                                            P_INV_OUT_SHIFT))
#define P_MODE_MASK                      ((uint32)(P_3BIT_MASK        <<  \
                                                                            P_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define P_CAPTURE_SHIFT                  (0u)
#define P_COUNT_SHIFT                    (2u)
#define P_RELOAD_SHIFT                   (4u)
#define P_STOP_SHIFT                     (6u)
#define P_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define P_CAPTURE_MASK                   ((uint32)(P_2BIT_MASK        <<  \
                                                                  P_CAPTURE_SHIFT))
#define P_COUNT_MASK                     ((uint32)(P_2BIT_MASK        <<  \
                                                                  P_COUNT_SHIFT))
#define P_RELOAD_MASK                    ((uint32)(P_2BIT_MASK        <<  \
                                                                  P_RELOAD_SHIFT))
#define P_STOP_MASK                      ((uint32)(P_2BIT_MASK        <<  \
                                                                  P_STOP_SHIFT))
#define P_START_MASK                     ((uint32)(P_2BIT_MASK        <<  \
                                                                  P_START_SHIFT))

/* MASK */
#define P_1BIT_MASK                      ((uint32)0x01u)
#define P_2BIT_MASK                      ((uint32)0x03u)
#define P_3BIT_MASK                      ((uint32)0x07u)
#define P_6BIT_MASK                      ((uint32)0x3Fu)
#define P_8BIT_MASK                      ((uint32)0xFFu)
#define P_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define P_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define P_PWM_PR_INIT_VALUE              (1u)

#endif /* End CY_TCPWM_P_H */

/* [] END OF FILE */
