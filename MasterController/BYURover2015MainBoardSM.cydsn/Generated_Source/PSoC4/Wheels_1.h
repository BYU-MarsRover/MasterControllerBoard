/*******************************************************************************
* File Name: Wheels_1.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values for the Wheels_1
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

#if !defined(CY_TCPWM_Wheels_1_H)
#define CY_TCPWM_Wheels_1_H

#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} Wheels_1_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  Wheels_1_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define Wheels_1_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)

/* TCPWM Configuration */
#define Wheels_1_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define Wheels_1_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define Wheels_1_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define Wheels_1_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define Wheels_1_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define Wheels_1_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define Wheels_1_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define Wheels_1_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define Wheels_1_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define Wheels_1_TC_RUN_MODE                    (0lu)
#define Wheels_1_TC_COUNTER_MODE                (0lu)
#define Wheels_1_TC_COMP_CAP_MODE               (2lu)
#define Wheels_1_TC_PRESCALER                   (0lu)

/* Signal modes */
#define Wheels_1_TC_RELOAD_SIGNAL_MODE          (0lu)
#define Wheels_1_TC_COUNT_SIGNAL_MODE           (3lu)
#define Wheels_1_TC_START_SIGNAL_MODE           (0lu)
#define Wheels_1_TC_STOP_SIGNAL_MODE            (0lu)
#define Wheels_1_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define Wheels_1_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define Wheels_1_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define Wheels_1_TC_START_SIGNAL_PRESENT        (0lu)
#define Wheels_1_TC_STOP_SIGNAL_PRESENT         (0lu)
#define Wheels_1_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Wheels_1_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define Wheels_1_PWM_KILL_EVENT                 (0lu)
#define Wheels_1_PWM_STOP_EVENT                 (0lu)
#define Wheels_1_PWM_MODE                       (4lu)
#define Wheels_1_PWM_OUT_N_INVERT               (0lu)
#define Wheels_1_PWM_OUT_INVERT                 (0lu)
#define Wheels_1_PWM_ALIGN                      (0lu)
#define Wheels_1_PWM_RUN_MODE                   (0lu)
#define Wheels_1_PWM_DEAD_TIME_CYCLE            (0lu)
#define Wheels_1_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define Wheels_1_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define Wheels_1_PWM_COUNT_SIGNAL_MODE          (3lu)
#define Wheels_1_PWM_START_SIGNAL_MODE          (0lu)
#define Wheels_1_PWM_STOP_SIGNAL_MODE           (0lu)
#define Wheels_1_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define Wheels_1_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define Wheels_1_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define Wheels_1_PWM_START_SIGNAL_PRESENT       (0lu)
#define Wheels_1_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define Wheels_1_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Wheels_1_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define Wheels_1_TC_PERIOD_VALUE                (65535lu)
#define Wheels_1_TC_COMPARE_VALUE               (65535lu)
#define Wheels_1_TC_COMPARE_BUF_VALUE           (65535lu)
#define Wheels_1_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define Wheels_1_PWM_PERIOD_VALUE               (20000lu)
#define Wheels_1_PWM_PERIOD_BUF_VALUE           (65535lu)
#define Wheels_1_PWM_PERIOD_SWAP                (0lu)
#define Wheels_1_PWM_COMPARE_VALUE              (1500lu)
#define Wheels_1_PWM_COMPARE_BUF_VALUE          (65535lu)
#define Wheels_1_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Wheels_1__LEFT 0
#define Wheels_1__RIGHT 1
#define Wheels_1__CENTER 2
#define Wheels_1__ASYMMETRIC 3

#define Wheels_1__X1 0
#define Wheels_1__X2 1
#define Wheels_1__X4 2

#define Wheels_1__PWM 4
#define Wheels_1__PWM_DT 5
#define Wheels_1__PWM_PR 6

#define Wheels_1__INVERSE 1
#define Wheels_1__DIRECT 0

#define Wheels_1__CAPTURE 2
#define Wheels_1__COMPARE 0

#define Wheels_1__TRIG_LEVEL 3
#define Wheels_1__TRIG_RISING 0
#define Wheels_1__TRIG_FALLING 1
#define Wheels_1__TRIG_BOTH 2

#define Wheels_1__INTR_MASK_TC 1
#define Wheels_1__INTR_MASK_CC_MATCH 2
#define Wheels_1__INTR_MASK_NONE 0
#define Wheels_1__INTR_MASK_TC_CC 3

#define Wheels_1__UNCONFIG 8
#define Wheels_1__TIMER 1
#define Wheels_1__QUAD 3
#define Wheels_1__PWM_SEL 7

#define Wheels_1__COUNT_UP 0
#define Wheels_1__COUNT_DOWN 1
#define Wheels_1__COUNT_UPDOWN0 2
#define Wheels_1__COUNT_UPDOWN1 3


/* Prescaler */
#define Wheels_1_PRESCALE_DIVBY1                ((uint32)(0u << Wheels_1_PRESCALER_SHIFT))
#define Wheels_1_PRESCALE_DIVBY2                ((uint32)(1u << Wheels_1_PRESCALER_SHIFT))
#define Wheels_1_PRESCALE_DIVBY4                ((uint32)(2u << Wheels_1_PRESCALER_SHIFT))
#define Wheels_1_PRESCALE_DIVBY8                ((uint32)(3u << Wheels_1_PRESCALER_SHIFT))
#define Wheels_1_PRESCALE_DIVBY16               ((uint32)(4u << Wheels_1_PRESCALER_SHIFT))
#define Wheels_1_PRESCALE_DIVBY32               ((uint32)(5u << Wheels_1_PRESCALER_SHIFT))
#define Wheels_1_PRESCALE_DIVBY64               ((uint32)(6u << Wheels_1_PRESCALER_SHIFT))
#define Wheels_1_PRESCALE_DIVBY128              ((uint32)(7u << Wheels_1_PRESCALER_SHIFT))

/* TCPWM set modes */
#define Wheels_1_MODE_TIMER_COMPARE             ((uint32)(Wheels_1__COMPARE         <<  \
                                                                  Wheels_1_MODE_SHIFT))
#define Wheels_1_MODE_TIMER_CAPTURE             ((uint32)(Wheels_1__CAPTURE         <<  \
                                                                  Wheels_1_MODE_SHIFT))
#define Wheels_1_MODE_QUAD                      ((uint32)(Wheels_1__QUAD            <<  \
                                                                  Wheels_1_MODE_SHIFT))
#define Wheels_1_MODE_PWM                       ((uint32)(Wheels_1__PWM             <<  \
                                                                  Wheels_1_MODE_SHIFT))
#define Wheels_1_MODE_PWM_DT                    ((uint32)(Wheels_1__PWM_DT          <<  \
                                                                  Wheels_1_MODE_SHIFT))
#define Wheels_1_MODE_PWM_PR                    ((uint32)(Wheels_1__PWM_PR          <<  \
                                                                  Wheels_1_MODE_SHIFT))

/* Quad Modes */
#define Wheels_1_MODE_X1                        ((uint32)(Wheels_1__X1              <<  \
                                                                  Wheels_1_QUAD_MODE_SHIFT))
#define Wheels_1_MODE_X2                        ((uint32)(Wheels_1__X2              <<  \
                                                                  Wheels_1_QUAD_MODE_SHIFT))
#define Wheels_1_MODE_X4                        ((uint32)(Wheels_1__X4              <<  \
                                                                  Wheels_1_QUAD_MODE_SHIFT))

/* Counter modes */
#define Wheels_1_COUNT_UP                       ((uint32)(Wheels_1__COUNT_UP        <<  \
                                                                  Wheels_1_UPDOWN_SHIFT))
#define Wheels_1_COUNT_DOWN                     ((uint32)(Wheels_1__COUNT_DOWN      <<  \
                                                                  Wheels_1_UPDOWN_SHIFT))
#define Wheels_1_COUNT_UPDOWN0                  ((uint32)(Wheels_1__COUNT_UPDOWN0   <<  \
                                                                  Wheels_1_UPDOWN_SHIFT))
#define Wheels_1_COUNT_UPDOWN1                  ((uint32)(Wheels_1__COUNT_UPDOWN1   <<  \
                                                                  Wheels_1_UPDOWN_SHIFT))

/* PWM output invert */
#define Wheels_1_INVERT_LINE                    ((uint32)(Wheels_1__INVERSE         <<  \
                                                                  Wheels_1_INV_OUT_SHIFT))
#define Wheels_1_INVERT_LINE_N                  ((uint32)(Wheels_1__INVERSE         <<  \
                                                                  Wheels_1_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define Wheels_1_TRIG_RISING                    ((uint32)Wheels_1__TRIG_RISING)
#define Wheels_1_TRIG_FALLING                   ((uint32)Wheels_1__TRIG_FALLING)
#define Wheels_1_TRIG_BOTH                      ((uint32)Wheels_1__TRIG_BOTH)
#define Wheels_1_TRIG_LEVEL                     ((uint32)Wheels_1__TRIG_LEVEL)

/* Interrupt mask */
#define Wheels_1_INTR_MASK_TC                   ((uint32)Wheels_1__INTR_MASK_TC)
#define Wheels_1_INTR_MASK_CC_MATCH             ((uint32)Wheels_1__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define Wheels_1_CC_MATCH_SET                   (0x00u)
#define Wheels_1_CC_MATCH_CLEAR                 (0x01u)
#define Wheels_1_CC_MATCH_INVERT                (0x02u)
#define Wheels_1_CC_MATCH_NO_CHANGE             (0x03u)
#define Wheels_1_OVERLOW_SET                    (0x00u)
#define Wheels_1_OVERLOW_CLEAR                  (0x04u)
#define Wheels_1_OVERLOW_INVERT                 (0x08u)
#define Wheels_1_OVERLOW_NO_CHANGE              (0x0Cu)
#define Wheels_1_UNDERFLOW_SET                  (0x00u)
#define Wheels_1_UNDERFLOW_CLEAR                (0x10u)
#define Wheels_1_UNDERFLOW_INVERT               (0x20u)
#define Wheels_1_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define Wheels_1_PWM_MODE_LEFT                  (Wheels_1_CC_MATCH_CLEAR        |   \
                                                         Wheels_1_OVERLOW_SET           |   \
                                                         Wheels_1_UNDERFLOW_NO_CHANGE)
#define Wheels_1_PWM_MODE_RIGHT                 (Wheels_1_CC_MATCH_SET          |   \
                                                         Wheels_1_OVERLOW_NO_CHANGE     |   \
                                                         Wheels_1_UNDERFLOW_CLEAR)
#define Wheels_1_PWM_MODE_CENTER                (Wheels_1_CC_MATCH_INVERT       |   \
                                                         Wheels_1_OVERLOW_NO_CHANGE     |   \
                                                         Wheels_1_UNDERFLOW_CLEAR)
#define Wheels_1_PWM_MODE_ASYM                  (Wheels_1_CC_MATCH_NO_CHANGE    |   \
                                                         Wheels_1_OVERLOW_SET           |   \
                                                         Wheels_1_UNDERFLOW_CLEAR )

/* Command operations without condition */
#define Wheels_1_CMD_CAPTURE                    (0u)
#define Wheels_1_CMD_RELOAD                     (8u)
#define Wheels_1_CMD_STOP                       (16u)
#define Wheels_1_CMD_START                      (24u)

/* Status */
#define Wheels_1_STATUS_DOWN                    (1u)
#define Wheels_1_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   Wheels_1_Init(void);
void   Wheels_1_Enable(void);
void   Wheels_1_Start(void);
void   Wheels_1_Stop(void);

void   Wheels_1_SetMode(uint32 mode);
void   Wheels_1_SetCounterMode(uint32 counterMode);
void   Wheels_1_SetPWMMode(uint32 modeMask);
void   Wheels_1_SetQDMode(uint32 qdMode);

void   Wheels_1_SetPrescaler(uint32 prescaler);
void   Wheels_1_TriggerCommand(uint32 mask, uint32 command);
void   Wheels_1_SetOneShot(uint32 oneShotEnable);
uint32 Wheels_1_ReadStatus(void);

void   Wheels_1_SetPWMSyncKill(uint32 syncKillEnable);
void   Wheels_1_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   Wheels_1_SetPWMDeadTime(uint32 deadTime);
void   Wheels_1_SetPWMInvert(uint32 mask);

void   Wheels_1_SetInterruptMode(uint32 interruptMask);
uint32 Wheels_1_GetInterruptSourceMasked(void);
uint32 Wheels_1_GetInterruptSource(void);
void   Wheels_1_ClearInterrupt(uint32 interruptMask);
void   Wheels_1_SetInterrupt(uint32 interruptMask);

void   Wheels_1_WriteCounter(uint32 count);
uint32 Wheels_1_ReadCounter(void);

uint32 Wheels_1_ReadCapture(void);
uint32 Wheels_1_ReadCaptureBuf(void);

void   Wheels_1_WritePeriod(uint32 period);
uint32 Wheels_1_ReadPeriod(void);
void   Wheels_1_WritePeriodBuf(uint32 periodBuf);
uint32 Wheels_1_ReadPeriodBuf(void);

void   Wheels_1_WriteCompare(uint32 compare);
uint32 Wheels_1_ReadCompare(void);
void   Wheels_1_WriteCompareBuf(uint32 compareBuf);
uint32 Wheels_1_ReadCompareBuf(void);

void   Wheels_1_SetPeriodSwap(uint32 swapEnable);
void   Wheels_1_SetCompareSwap(uint32 swapEnable);

void   Wheels_1_SetCaptureMode(uint32 triggerMode);
void   Wheels_1_SetReloadMode(uint32 triggerMode);
void   Wheels_1_SetStartMode(uint32 triggerMode);
void   Wheels_1_SetStopMode(uint32 triggerMode);
void   Wheels_1_SetCountMode(uint32 triggerMode);

void   Wheels_1_SaveConfig(void);
void   Wheels_1_RestoreConfig(void);
void   Wheels_1_Sleep(void);
void   Wheels_1_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define Wheels_1_BLOCK_CONTROL_REG              (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Wheels_1_BLOCK_CONTROL_PTR              ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Wheels_1_COMMAND_REG                    (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Wheels_1_COMMAND_PTR                    ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Wheels_1_INTRRUPT_CAUSE_REG             (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Wheels_1_INTRRUPT_CAUSE_PTR             ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Wheels_1_CONTROL_REG                    (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__CTRL )
#define Wheels_1_CONTROL_PTR                    ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__CTRL )
#define Wheels_1_STATUS_REG                     (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__STATUS )
#define Wheels_1_STATUS_PTR                     ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__STATUS )
#define Wheels_1_COUNTER_REG                    (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__COUNTER )
#define Wheels_1_COUNTER_PTR                    ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__COUNTER )
#define Wheels_1_COMP_CAP_REG                   (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__CC )
#define Wheels_1_COMP_CAP_PTR                   ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__CC )
#define Wheels_1_COMP_CAP_BUF_REG               (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__CC_BUFF )
#define Wheels_1_COMP_CAP_BUF_PTR               ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__CC_BUFF )
#define Wheels_1_PERIOD_REG                     (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__PERIOD )
#define Wheels_1_PERIOD_PTR                     ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__PERIOD )
#define Wheels_1_PERIOD_BUF_REG                 (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Wheels_1_PERIOD_BUF_PTR                 ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Wheels_1_TRIG_CONTROL0_REG              (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Wheels_1_TRIG_CONTROL0_PTR              ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Wheels_1_TRIG_CONTROL1_REG              (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Wheels_1_TRIG_CONTROL1_PTR              ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Wheels_1_TRIG_CONTROL2_REG              (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Wheels_1_TRIG_CONTROL2_PTR              ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Wheels_1_INTERRUPT_REQ_REG              (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__INTR )
#define Wheels_1_INTERRUPT_REQ_PTR              ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__INTR )
#define Wheels_1_INTERRUPT_SET_REG              (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__INTR_SET )
#define Wheels_1_INTERRUPT_SET_PTR              ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__INTR_SET )
#define Wheels_1_INTERRUPT_MASK_REG             (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__INTR_MASK )
#define Wheels_1_INTERRUPT_MASK_PTR             ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__INTR_MASK )
#define Wheels_1_INTERRUPT_MASKED_REG           (*(reg32 *) Wheels_1_cy_m0s8_tcpwm_1__INTR_MASKED )
#define Wheels_1_INTERRUPT_MASKED_PTR           ( (reg32 *) Wheels_1_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define Wheels_1_MASK                           ((uint32)Wheels_1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define Wheels_1_RELOAD_CC_SHIFT                (0u)
#define Wheels_1_RELOAD_PERIOD_SHIFT            (1u)
#define Wheels_1_PWM_SYNC_KILL_SHIFT            (2u)
#define Wheels_1_PWM_STOP_KILL_SHIFT            (3u)
#define Wheels_1_PRESCALER_SHIFT                (8u)
#define Wheels_1_UPDOWN_SHIFT                   (16u)
#define Wheels_1_ONESHOT_SHIFT                  (18u)
#define Wheels_1_QUAD_MODE_SHIFT                (20u)
#define Wheels_1_INV_OUT_SHIFT                  (20u)
#define Wheels_1_INV_COMPL_OUT_SHIFT            (21u)
#define Wheels_1_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define Wheels_1_RELOAD_CC_MASK                 ((uint32)(Wheels_1_1BIT_MASK        <<  \
                                                                            Wheels_1_RELOAD_CC_SHIFT))
#define Wheels_1_RELOAD_PERIOD_MASK             ((uint32)(Wheels_1_1BIT_MASK        <<  \
                                                                            Wheels_1_RELOAD_PERIOD_SHIFT))
#define Wheels_1_PWM_SYNC_KILL_MASK             ((uint32)(Wheels_1_1BIT_MASK        <<  \
                                                                            Wheels_1_PWM_SYNC_KILL_SHIFT))
#define Wheels_1_PWM_STOP_KILL_MASK             ((uint32)(Wheels_1_1BIT_MASK        <<  \
                                                                            Wheels_1_PWM_STOP_KILL_SHIFT))
#define Wheels_1_PRESCALER_MASK                 ((uint32)(Wheels_1_8BIT_MASK        <<  \
                                                                            Wheels_1_PRESCALER_SHIFT))
#define Wheels_1_UPDOWN_MASK                    ((uint32)(Wheels_1_2BIT_MASK        <<  \
                                                                            Wheels_1_UPDOWN_SHIFT))
#define Wheels_1_ONESHOT_MASK                   ((uint32)(Wheels_1_1BIT_MASK        <<  \
                                                                            Wheels_1_ONESHOT_SHIFT))
#define Wheels_1_QUAD_MODE_MASK                 ((uint32)(Wheels_1_3BIT_MASK        <<  \
                                                                            Wheels_1_QUAD_MODE_SHIFT))
#define Wheels_1_INV_OUT_MASK                   ((uint32)(Wheels_1_2BIT_MASK        <<  \
                                                                            Wheels_1_INV_OUT_SHIFT))
#define Wheels_1_MODE_MASK                      ((uint32)(Wheels_1_3BIT_MASK        <<  \
                                                                            Wheels_1_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define Wheels_1_CAPTURE_SHIFT                  (0u)
#define Wheels_1_COUNT_SHIFT                    (2u)
#define Wheels_1_RELOAD_SHIFT                   (4u)
#define Wheels_1_STOP_SHIFT                     (6u)
#define Wheels_1_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define Wheels_1_CAPTURE_MASK                   ((uint32)(Wheels_1_2BIT_MASK        <<  \
                                                                  Wheels_1_CAPTURE_SHIFT))
#define Wheels_1_COUNT_MASK                     ((uint32)(Wheels_1_2BIT_MASK        <<  \
                                                                  Wheels_1_COUNT_SHIFT))
#define Wheels_1_RELOAD_MASK                    ((uint32)(Wheels_1_2BIT_MASK        <<  \
                                                                  Wheels_1_RELOAD_SHIFT))
#define Wheels_1_STOP_MASK                      ((uint32)(Wheels_1_2BIT_MASK        <<  \
                                                                  Wheels_1_STOP_SHIFT))
#define Wheels_1_START_MASK                     ((uint32)(Wheels_1_2BIT_MASK        <<  \
                                                                  Wheels_1_START_SHIFT))

/* MASK */
#define Wheels_1_1BIT_MASK                      ((uint32)0x01u)
#define Wheels_1_2BIT_MASK                      ((uint32)0x03u)
#define Wheels_1_3BIT_MASK                      ((uint32)0x07u)
#define Wheels_1_6BIT_MASK                      ((uint32)0x3Fu)
#define Wheels_1_8BIT_MASK                      ((uint32)0xFFu)
#define Wheels_1_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define Wheels_1_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define Wheels_1_PWM_PR_INIT_VALUE              (1u)

#endif /* End CY_TCPWM_Wheels_1_H */

/* [] END OF FILE */
