/*******************************************************************************
* File Name: Wheels_2.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values for the Wheels_2
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

#if !defined(CY_TCPWM_Wheels_2_H)
#define CY_TCPWM_Wheels_2_H

#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} Wheels_2_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  Wheels_2_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define Wheels_2_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)

/* TCPWM Configuration */
#define Wheels_2_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define Wheels_2_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define Wheels_2_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define Wheels_2_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define Wheels_2_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define Wheels_2_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define Wheels_2_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define Wheels_2_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define Wheels_2_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define Wheels_2_TC_RUN_MODE                    (0lu)
#define Wheels_2_TC_COUNTER_MODE                (0lu)
#define Wheels_2_TC_COMP_CAP_MODE               (2lu)
#define Wheels_2_TC_PRESCALER                   (0lu)

/* Signal modes */
#define Wheels_2_TC_RELOAD_SIGNAL_MODE          (0lu)
#define Wheels_2_TC_COUNT_SIGNAL_MODE           (3lu)
#define Wheels_2_TC_START_SIGNAL_MODE           (0lu)
#define Wheels_2_TC_STOP_SIGNAL_MODE            (0lu)
#define Wheels_2_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define Wheels_2_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define Wheels_2_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define Wheels_2_TC_START_SIGNAL_PRESENT        (0lu)
#define Wheels_2_TC_STOP_SIGNAL_PRESENT         (0lu)
#define Wheels_2_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Wheels_2_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define Wheels_2_PWM_KILL_EVENT                 (0lu)
#define Wheels_2_PWM_STOP_EVENT                 (0lu)
#define Wheels_2_PWM_MODE                       (4lu)
#define Wheels_2_PWM_OUT_N_INVERT               (0lu)
#define Wheels_2_PWM_OUT_INVERT                 (0lu)
#define Wheels_2_PWM_ALIGN                      (0lu)
#define Wheels_2_PWM_RUN_MODE                   (0lu)
#define Wheels_2_PWM_DEAD_TIME_CYCLE            (0lu)
#define Wheels_2_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define Wheels_2_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define Wheels_2_PWM_COUNT_SIGNAL_MODE          (3lu)
#define Wheels_2_PWM_START_SIGNAL_MODE          (0lu)
#define Wheels_2_PWM_STOP_SIGNAL_MODE           (0lu)
#define Wheels_2_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define Wheels_2_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define Wheels_2_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define Wheels_2_PWM_START_SIGNAL_PRESENT       (0lu)
#define Wheels_2_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define Wheels_2_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Wheels_2_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define Wheels_2_TC_PERIOD_VALUE                (65535lu)
#define Wheels_2_TC_COMPARE_VALUE               (65535lu)
#define Wheels_2_TC_COMPARE_BUF_VALUE           (65535lu)
#define Wheels_2_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define Wheels_2_PWM_PERIOD_VALUE               (20000lu)
#define Wheels_2_PWM_PERIOD_BUF_VALUE           (65535lu)
#define Wheels_2_PWM_PERIOD_SWAP                (0lu)
#define Wheels_2_PWM_COMPARE_VALUE              (1500lu)
#define Wheels_2_PWM_COMPARE_BUF_VALUE          (65535lu)
#define Wheels_2_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Wheels_2__LEFT 0
#define Wheels_2__RIGHT 1
#define Wheels_2__CENTER 2
#define Wheels_2__ASYMMETRIC 3

#define Wheels_2__X1 0
#define Wheels_2__X2 1
#define Wheels_2__X4 2

#define Wheels_2__PWM 4
#define Wheels_2__PWM_DT 5
#define Wheels_2__PWM_PR 6

#define Wheels_2__INVERSE 1
#define Wheels_2__DIRECT 0

#define Wheels_2__CAPTURE 2
#define Wheels_2__COMPARE 0

#define Wheels_2__TRIG_LEVEL 3
#define Wheels_2__TRIG_RISING 0
#define Wheels_2__TRIG_FALLING 1
#define Wheels_2__TRIG_BOTH 2

#define Wheels_2__INTR_MASK_TC 1
#define Wheels_2__INTR_MASK_CC_MATCH 2
#define Wheels_2__INTR_MASK_NONE 0
#define Wheels_2__INTR_MASK_TC_CC 3

#define Wheels_2__UNCONFIG 8
#define Wheels_2__TIMER 1
#define Wheels_2__QUAD 3
#define Wheels_2__PWM_SEL 7

#define Wheels_2__COUNT_UP 0
#define Wheels_2__COUNT_DOWN 1
#define Wheels_2__COUNT_UPDOWN0 2
#define Wheels_2__COUNT_UPDOWN1 3


/* Prescaler */
#define Wheels_2_PRESCALE_DIVBY1                ((uint32)(0u << Wheels_2_PRESCALER_SHIFT))
#define Wheels_2_PRESCALE_DIVBY2                ((uint32)(1u << Wheels_2_PRESCALER_SHIFT))
#define Wheels_2_PRESCALE_DIVBY4                ((uint32)(2u << Wheels_2_PRESCALER_SHIFT))
#define Wheels_2_PRESCALE_DIVBY8                ((uint32)(3u << Wheels_2_PRESCALER_SHIFT))
#define Wheels_2_PRESCALE_DIVBY16               ((uint32)(4u << Wheels_2_PRESCALER_SHIFT))
#define Wheels_2_PRESCALE_DIVBY32               ((uint32)(5u << Wheels_2_PRESCALER_SHIFT))
#define Wheels_2_PRESCALE_DIVBY64               ((uint32)(6u << Wheels_2_PRESCALER_SHIFT))
#define Wheels_2_PRESCALE_DIVBY128              ((uint32)(7u << Wheels_2_PRESCALER_SHIFT))

/* TCPWM set modes */
#define Wheels_2_MODE_TIMER_COMPARE             ((uint32)(Wheels_2__COMPARE         <<  \
                                                                  Wheels_2_MODE_SHIFT))
#define Wheels_2_MODE_TIMER_CAPTURE             ((uint32)(Wheels_2__CAPTURE         <<  \
                                                                  Wheels_2_MODE_SHIFT))
#define Wheels_2_MODE_QUAD                      ((uint32)(Wheels_2__QUAD            <<  \
                                                                  Wheels_2_MODE_SHIFT))
#define Wheels_2_MODE_PWM                       ((uint32)(Wheels_2__PWM             <<  \
                                                                  Wheels_2_MODE_SHIFT))
#define Wheels_2_MODE_PWM_DT                    ((uint32)(Wheels_2__PWM_DT          <<  \
                                                                  Wheels_2_MODE_SHIFT))
#define Wheels_2_MODE_PWM_PR                    ((uint32)(Wheels_2__PWM_PR          <<  \
                                                                  Wheels_2_MODE_SHIFT))

/* Quad Modes */
#define Wheels_2_MODE_X1                        ((uint32)(Wheels_2__X1              <<  \
                                                                  Wheels_2_QUAD_MODE_SHIFT))
#define Wheels_2_MODE_X2                        ((uint32)(Wheels_2__X2              <<  \
                                                                  Wheels_2_QUAD_MODE_SHIFT))
#define Wheels_2_MODE_X4                        ((uint32)(Wheels_2__X4              <<  \
                                                                  Wheels_2_QUAD_MODE_SHIFT))

/* Counter modes */
#define Wheels_2_COUNT_UP                       ((uint32)(Wheels_2__COUNT_UP        <<  \
                                                                  Wheels_2_UPDOWN_SHIFT))
#define Wheels_2_COUNT_DOWN                     ((uint32)(Wheels_2__COUNT_DOWN      <<  \
                                                                  Wheels_2_UPDOWN_SHIFT))
#define Wheels_2_COUNT_UPDOWN0                  ((uint32)(Wheels_2__COUNT_UPDOWN0   <<  \
                                                                  Wheels_2_UPDOWN_SHIFT))
#define Wheels_2_COUNT_UPDOWN1                  ((uint32)(Wheels_2__COUNT_UPDOWN1   <<  \
                                                                  Wheels_2_UPDOWN_SHIFT))

/* PWM output invert */
#define Wheels_2_INVERT_LINE                    ((uint32)(Wheels_2__INVERSE         <<  \
                                                                  Wheels_2_INV_OUT_SHIFT))
#define Wheels_2_INVERT_LINE_N                  ((uint32)(Wheels_2__INVERSE         <<  \
                                                                  Wheels_2_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define Wheels_2_TRIG_RISING                    ((uint32)Wheels_2__TRIG_RISING)
#define Wheels_2_TRIG_FALLING                   ((uint32)Wheels_2__TRIG_FALLING)
#define Wheels_2_TRIG_BOTH                      ((uint32)Wheels_2__TRIG_BOTH)
#define Wheels_2_TRIG_LEVEL                     ((uint32)Wheels_2__TRIG_LEVEL)

/* Interrupt mask */
#define Wheels_2_INTR_MASK_TC                   ((uint32)Wheels_2__INTR_MASK_TC)
#define Wheels_2_INTR_MASK_CC_MATCH             ((uint32)Wheels_2__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define Wheels_2_CC_MATCH_SET                   (0x00u)
#define Wheels_2_CC_MATCH_CLEAR                 (0x01u)
#define Wheels_2_CC_MATCH_INVERT                (0x02u)
#define Wheels_2_CC_MATCH_NO_CHANGE             (0x03u)
#define Wheels_2_OVERLOW_SET                    (0x00u)
#define Wheels_2_OVERLOW_CLEAR                  (0x04u)
#define Wheels_2_OVERLOW_INVERT                 (0x08u)
#define Wheels_2_OVERLOW_NO_CHANGE              (0x0Cu)
#define Wheels_2_UNDERFLOW_SET                  (0x00u)
#define Wheels_2_UNDERFLOW_CLEAR                (0x10u)
#define Wheels_2_UNDERFLOW_INVERT               (0x20u)
#define Wheels_2_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define Wheels_2_PWM_MODE_LEFT                  (Wheels_2_CC_MATCH_CLEAR        |   \
                                                         Wheels_2_OVERLOW_SET           |   \
                                                         Wheels_2_UNDERFLOW_NO_CHANGE)
#define Wheels_2_PWM_MODE_RIGHT                 (Wheels_2_CC_MATCH_SET          |   \
                                                         Wheels_2_OVERLOW_NO_CHANGE     |   \
                                                         Wheels_2_UNDERFLOW_CLEAR)
#define Wheels_2_PWM_MODE_CENTER                (Wheels_2_CC_MATCH_INVERT       |   \
                                                         Wheels_2_OVERLOW_NO_CHANGE     |   \
                                                         Wheels_2_UNDERFLOW_CLEAR)
#define Wheels_2_PWM_MODE_ASYM                  (Wheels_2_CC_MATCH_NO_CHANGE    |   \
                                                         Wheels_2_OVERLOW_SET           |   \
                                                         Wheels_2_UNDERFLOW_CLEAR )

/* Command operations without condition */
#define Wheels_2_CMD_CAPTURE                    (0u)
#define Wheels_2_CMD_RELOAD                     (8u)
#define Wheels_2_CMD_STOP                       (16u)
#define Wheels_2_CMD_START                      (24u)

/* Status */
#define Wheels_2_STATUS_DOWN                    (1u)
#define Wheels_2_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   Wheels_2_Init(void);
void   Wheels_2_Enable(void);
void   Wheels_2_Start(void);
void   Wheels_2_Stop(void);

void   Wheels_2_SetMode(uint32 mode);
void   Wheels_2_SetCounterMode(uint32 counterMode);
void   Wheels_2_SetPWMMode(uint32 modeMask);
void   Wheels_2_SetQDMode(uint32 qdMode);

void   Wheels_2_SetPrescaler(uint32 prescaler);
void   Wheels_2_TriggerCommand(uint32 mask, uint32 command);
void   Wheels_2_SetOneShot(uint32 oneShotEnable);
uint32 Wheels_2_ReadStatus(void);

void   Wheels_2_SetPWMSyncKill(uint32 syncKillEnable);
void   Wheels_2_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   Wheels_2_SetPWMDeadTime(uint32 deadTime);
void   Wheels_2_SetPWMInvert(uint32 mask);

void   Wheels_2_SetInterruptMode(uint32 interruptMask);
uint32 Wheels_2_GetInterruptSourceMasked(void);
uint32 Wheels_2_GetInterruptSource(void);
void   Wheels_2_ClearInterrupt(uint32 interruptMask);
void   Wheels_2_SetInterrupt(uint32 interruptMask);

void   Wheels_2_WriteCounter(uint32 count);
uint32 Wheels_2_ReadCounter(void);

uint32 Wheels_2_ReadCapture(void);
uint32 Wheels_2_ReadCaptureBuf(void);

void   Wheels_2_WritePeriod(uint32 period);
uint32 Wheels_2_ReadPeriod(void);
void   Wheels_2_WritePeriodBuf(uint32 periodBuf);
uint32 Wheels_2_ReadPeriodBuf(void);

void   Wheels_2_WriteCompare(uint32 compare);
uint32 Wheels_2_ReadCompare(void);
void   Wheels_2_WriteCompareBuf(uint32 compareBuf);
uint32 Wheels_2_ReadCompareBuf(void);

void   Wheels_2_SetPeriodSwap(uint32 swapEnable);
void   Wheels_2_SetCompareSwap(uint32 swapEnable);

void   Wheels_2_SetCaptureMode(uint32 triggerMode);
void   Wheels_2_SetReloadMode(uint32 triggerMode);
void   Wheels_2_SetStartMode(uint32 triggerMode);
void   Wheels_2_SetStopMode(uint32 triggerMode);
void   Wheels_2_SetCountMode(uint32 triggerMode);

void   Wheels_2_SaveConfig(void);
void   Wheels_2_RestoreConfig(void);
void   Wheels_2_Sleep(void);
void   Wheels_2_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define Wheels_2_BLOCK_CONTROL_REG              (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Wheels_2_BLOCK_CONTROL_PTR              ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Wheels_2_COMMAND_REG                    (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Wheels_2_COMMAND_PTR                    ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Wheels_2_INTRRUPT_CAUSE_REG             (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Wheels_2_INTRRUPT_CAUSE_PTR             ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Wheels_2_CONTROL_REG                    (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__CTRL )
#define Wheels_2_CONTROL_PTR                    ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__CTRL )
#define Wheels_2_STATUS_REG                     (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__STATUS )
#define Wheels_2_STATUS_PTR                     ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__STATUS )
#define Wheels_2_COUNTER_REG                    (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__COUNTER )
#define Wheels_2_COUNTER_PTR                    ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__COUNTER )
#define Wheels_2_COMP_CAP_REG                   (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__CC )
#define Wheels_2_COMP_CAP_PTR                   ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__CC )
#define Wheels_2_COMP_CAP_BUF_REG               (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__CC_BUFF )
#define Wheels_2_COMP_CAP_BUF_PTR               ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__CC_BUFF )
#define Wheels_2_PERIOD_REG                     (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__PERIOD )
#define Wheels_2_PERIOD_PTR                     ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__PERIOD )
#define Wheels_2_PERIOD_BUF_REG                 (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Wheels_2_PERIOD_BUF_PTR                 ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Wheels_2_TRIG_CONTROL0_REG              (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Wheels_2_TRIG_CONTROL0_PTR              ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Wheels_2_TRIG_CONTROL1_REG              (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Wheels_2_TRIG_CONTROL1_PTR              ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Wheels_2_TRIG_CONTROL2_REG              (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Wheels_2_TRIG_CONTROL2_PTR              ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Wheels_2_INTERRUPT_REQ_REG              (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__INTR )
#define Wheels_2_INTERRUPT_REQ_PTR              ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__INTR )
#define Wheels_2_INTERRUPT_SET_REG              (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__INTR_SET )
#define Wheels_2_INTERRUPT_SET_PTR              ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__INTR_SET )
#define Wheels_2_INTERRUPT_MASK_REG             (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__INTR_MASK )
#define Wheels_2_INTERRUPT_MASK_PTR             ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__INTR_MASK )
#define Wheels_2_INTERRUPT_MASKED_REG           (*(reg32 *) Wheels_2_cy_m0s8_tcpwm_1__INTR_MASKED )
#define Wheels_2_INTERRUPT_MASKED_PTR           ( (reg32 *) Wheels_2_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define Wheels_2_MASK                           ((uint32)Wheels_2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define Wheels_2_RELOAD_CC_SHIFT                (0u)
#define Wheels_2_RELOAD_PERIOD_SHIFT            (1u)
#define Wheels_2_PWM_SYNC_KILL_SHIFT            (2u)
#define Wheels_2_PWM_STOP_KILL_SHIFT            (3u)
#define Wheels_2_PRESCALER_SHIFT                (8u)
#define Wheels_2_UPDOWN_SHIFT                   (16u)
#define Wheels_2_ONESHOT_SHIFT                  (18u)
#define Wheels_2_QUAD_MODE_SHIFT                (20u)
#define Wheels_2_INV_OUT_SHIFT                  (20u)
#define Wheels_2_INV_COMPL_OUT_SHIFT            (21u)
#define Wheels_2_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define Wheels_2_RELOAD_CC_MASK                 ((uint32)(Wheels_2_1BIT_MASK        <<  \
                                                                            Wheels_2_RELOAD_CC_SHIFT))
#define Wheels_2_RELOAD_PERIOD_MASK             ((uint32)(Wheels_2_1BIT_MASK        <<  \
                                                                            Wheels_2_RELOAD_PERIOD_SHIFT))
#define Wheels_2_PWM_SYNC_KILL_MASK             ((uint32)(Wheels_2_1BIT_MASK        <<  \
                                                                            Wheels_2_PWM_SYNC_KILL_SHIFT))
#define Wheels_2_PWM_STOP_KILL_MASK             ((uint32)(Wheels_2_1BIT_MASK        <<  \
                                                                            Wheels_2_PWM_STOP_KILL_SHIFT))
#define Wheels_2_PRESCALER_MASK                 ((uint32)(Wheels_2_8BIT_MASK        <<  \
                                                                            Wheels_2_PRESCALER_SHIFT))
#define Wheels_2_UPDOWN_MASK                    ((uint32)(Wheels_2_2BIT_MASK        <<  \
                                                                            Wheels_2_UPDOWN_SHIFT))
#define Wheels_2_ONESHOT_MASK                   ((uint32)(Wheels_2_1BIT_MASK        <<  \
                                                                            Wheels_2_ONESHOT_SHIFT))
#define Wheels_2_QUAD_MODE_MASK                 ((uint32)(Wheels_2_3BIT_MASK        <<  \
                                                                            Wheels_2_QUAD_MODE_SHIFT))
#define Wheels_2_INV_OUT_MASK                   ((uint32)(Wheels_2_2BIT_MASK        <<  \
                                                                            Wheels_2_INV_OUT_SHIFT))
#define Wheels_2_MODE_MASK                      ((uint32)(Wheels_2_3BIT_MASK        <<  \
                                                                            Wheels_2_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define Wheels_2_CAPTURE_SHIFT                  (0u)
#define Wheels_2_COUNT_SHIFT                    (2u)
#define Wheels_2_RELOAD_SHIFT                   (4u)
#define Wheels_2_STOP_SHIFT                     (6u)
#define Wheels_2_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define Wheels_2_CAPTURE_MASK                   ((uint32)(Wheels_2_2BIT_MASK        <<  \
                                                                  Wheels_2_CAPTURE_SHIFT))
#define Wheels_2_COUNT_MASK                     ((uint32)(Wheels_2_2BIT_MASK        <<  \
                                                                  Wheels_2_COUNT_SHIFT))
#define Wheels_2_RELOAD_MASK                    ((uint32)(Wheels_2_2BIT_MASK        <<  \
                                                                  Wheels_2_RELOAD_SHIFT))
#define Wheels_2_STOP_MASK                      ((uint32)(Wheels_2_2BIT_MASK        <<  \
                                                                  Wheels_2_STOP_SHIFT))
#define Wheels_2_START_MASK                     ((uint32)(Wheels_2_2BIT_MASK        <<  \
                                                                  Wheels_2_START_SHIFT))

/* MASK */
#define Wheels_2_1BIT_MASK                      ((uint32)0x01u)
#define Wheels_2_2BIT_MASK                      ((uint32)0x03u)
#define Wheels_2_3BIT_MASK                      ((uint32)0x07u)
#define Wheels_2_6BIT_MASK                      ((uint32)0x3Fu)
#define Wheels_2_8BIT_MASK                      ((uint32)0xFFu)
#define Wheels_2_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define Wheels_2_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define Wheels_2_PWM_PR_INIT_VALUE              (1u)

#endif /* End CY_TCPWM_Wheels_2_H */

/* [] END OF FILE */
