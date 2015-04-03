/*******************************************************************************
* File Name: Wheels.h  
* Version 3.0
*
* Description:
*  Contains the prototypes and constants for the functions available to the 
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_Wheels_H)
#define CY_PWM_Wheels_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Wheels_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define Wheels_Resolution 16u
#define Wheels_UsingFixedFunction 0u
#define Wheels_DeadBandMode 0u
#define Wheels_KillModeMinTime 0u
#define Wheels_KillMode 0u
#define Wheels_PWMMode 1u
#define Wheels_PWMModeIsCenterAligned 0u
#define Wheels_DeadBandUsed 0u
#define Wheels_DeadBand2_4 0u

#if !defined(Wheels_PWMUDB_genblk8_stsreg__REMOVED)
    #define Wheels_UseStatus 1u
#else
    #define Wheels_UseStatus 0u
#endif /* !defined(Wheels_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(Wheels_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define Wheels_UseControl 1u
#else
    #define Wheels_UseControl 0u
#endif /* !defined(Wheels_PWMUDB_genblk1_ctrlreg__REMOVED) */
#define Wheels_UseOneCompareMode 0u
#define Wheels_MinimumKillTime 1u
#define Wheels_EnableMode 0u

#define Wheels_CompareMode1SW 0u
#define Wheels_CompareMode2SW 0u

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define Wheels__B_PWM__DISABLED 0
#define Wheels__B_PWM__ASYNCHRONOUS 1
#define Wheels__B_PWM__SINGLECYCLE 2
#define Wheels__B_PWM__LATCHED 3
#define Wheels__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define Wheels__B_PWM__DBMDISABLED 0
#define Wheels__B_PWM__DBM_2_4_CLOCKS 1
#define Wheels__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define Wheels__B_PWM__ONE_OUTPUT 0
#define Wheels__B_PWM__TWO_OUTPUTS 1
#define Wheels__B_PWM__DUAL_EDGE 2
#define Wheels__B_PWM__CENTER_ALIGN 3
#define Wheels__B_PWM__DITHER 5
#define Wheels__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define Wheels__B_PWM__LESS_THAN 1
#define Wheels__B_PWM__LESS_THAN_OR_EQUAL 2
#define Wheels__B_PWM__GREATER_THAN 3
#define Wheels__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define Wheels__B_PWM__EQUAL 0
#define Wheels__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{
    
    uint8 PWMEnableState;
       
    #if(!Wheels_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!Wheels_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!Wheels_PWMModeIsCenterAligned) */
        #if (Wheels_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (Wheels_UseStatus) */
        
        /* Backup for Deadband parameters */
        #if(Wheels_DeadBandMode == Wheels__B_PWM__DBM_256_CLOCKS || \
            Wheels_DeadBandMode == Wheels__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */
        
        /* Backup Kill Mode Counter*/
        #if(Wheels_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (Wheels_KillModeMinTime) */
       
        /* Backup control register */
        #if(Wheels_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (Wheels_UseControl) */
        
    #endif /* (!Wheels_UsingFixedFunction) */
   
}Wheels_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/
 
void    Wheels_Start(void) ;
void    Wheels_Stop(void) ;

#if (Wheels_UseStatus || Wheels_UsingFixedFunction)
    void  Wheels_SetInterruptMode(uint8 interruptMode) ;
    uint8 Wheels_ReadStatusRegister(void) ;
#endif /* (Wheels_UseStatus || Wheels_UsingFixedFunction) */

#define Wheels_GetInterruptSource() Wheels_ReadStatusRegister()

#if (Wheels_UseControl)
    uint8 Wheels_ReadControlRegister(void) ; 
    void  Wheels_WriteControlRegister(uint8 control) ;
#endif /* (Wheels_UseControl) */

#if (Wheels_UseOneCompareMode)
   #if (Wheels_CompareMode1SW)
       void    Wheels_SetCompareMode(uint8 comparemode) ;
   #endif /* (Wheels_CompareMode1SW) */
#else
    #if (Wheels_CompareMode1SW)
        void    Wheels_SetCompareMode1(uint8 comparemode) ;
    #endif /* (Wheels_CompareMode1SW) */
    #if (Wheels_CompareMode2SW)
        void    Wheels_SetCompareMode2(uint8 comparemode) ;
    #endif /* (Wheels_CompareMode2SW) */
#endif /* (Wheels_UseOneCompareMode) */

#if (!Wheels_UsingFixedFunction)
    uint16   Wheels_ReadCounter(void) ;
    uint16 Wheels_ReadCapture(void) ;
    
	#if (Wheels_UseStatus)
	        void Wheels_ClearFIFO(void) ;
	#endif /* (Wheels_UseStatus) */

    void    Wheels_WriteCounter(uint16 counter) ;
#endif /* (!Wheels_UsingFixedFunction) */

void    Wheels_WritePeriod(uint16 period) ;
uint16 Wheels_ReadPeriod(void) ;

#if (Wheels_UseOneCompareMode)
    void    Wheels_WriteCompare(uint16 compare) ;
    uint16 Wheels_ReadCompare(void) ; 
#else
    void    Wheels_WriteCompare1(uint16 compare) ;
    uint16 Wheels_ReadCompare1(void) ; 
    void    Wheels_WriteCompare2(uint16 compare) ;
    uint16 Wheels_ReadCompare2(void) ; 
#endif /* (Wheels_UseOneCompareMode) */


#if (Wheels_DeadBandUsed)
    void    Wheels_WriteDeadTime(uint8 deadtime) ;
    uint8   Wheels_ReadDeadTime(void) ;
#endif /* (Wheels_DeadBandUsed) */

#if ( Wheels_KillModeMinTime)
    void Wheels_WriteKillTime(uint8 killtime) ;
    uint8 Wheels_ReadKillTime(void) ; 
#endif /* ( Wheels_KillModeMinTime) */

void Wheels_Init(void) ;
void Wheels_Enable(void) ;
void Wheels_Sleep(void) ;
void Wheels_Wakeup(void) ;
void Wheels_SaveConfig(void) ;
void Wheels_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define Wheels_INIT_PERIOD_VALUE        20000u
#define Wheels_INIT_COMPARE_VALUE1      1500u
#define Wheels_INIT_COMPARE_VALUE2      1500u
#define Wheels_INIT_INTERRUPTS_MODE     (uint8)(((uint8)(0u << Wheels_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                  (uint8)((uint8)(0u << Wheels_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                  (uint8)((uint8)(0u << Wheels_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                  (uint8)((uint8)(0u << Wheels_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define Wheels_DEFAULT_COMPARE2_MODE    (uint8)((uint8)1u << Wheels_CTRL_CMPMODE2_SHIFT)
#define Wheels_DEFAULT_COMPARE1_MODE    (uint8)((uint8)1u << Wheels_CTRL_CMPMODE1_SHIFT)
#define Wheels_INIT_DEAD_TIME           1u


/********************************
*         Registers
******************************** */

#if (Wheels_UsingFixedFunction)
   #define Wheels_PERIOD_LSB          (*(reg16 *) Wheels_PWMHW__PER0)
   #define Wheels_PERIOD_LSB_PTR      ( (reg16 *) Wheels_PWMHW__PER0)
   #define Wheels_COMPARE1_LSB        (*(reg16 *) Wheels_PWMHW__CNT_CMP0)
   #define Wheels_COMPARE1_LSB_PTR    ( (reg16 *) Wheels_PWMHW__CNT_CMP0)
   #define Wheels_COMPARE2_LSB        0x00u
   #define Wheels_COMPARE2_LSB_PTR    0x00u
   #define Wheels_COUNTER_LSB         (*(reg16 *) Wheels_PWMHW__CNT_CMP0)
   #define Wheels_COUNTER_LSB_PTR     ( (reg16 *) Wheels_PWMHW__CNT_CMP0)
   #define Wheels_CAPTURE_LSB         (*(reg16 *) Wheels_PWMHW__CAP0)
   #define Wheels_CAPTURE_LSB_PTR     ( (reg16 *) Wheels_PWMHW__CAP0)
   #define Wheels_RT1                 (*(reg8 *)  Wheels_PWMHW__RT1)
   #define Wheels_RT1_PTR             ( (reg8 *)  Wheels_PWMHW__RT1)
      
#else
   #if (Wheels_Resolution == 8u) /* 8bit - PWM */
	   
	   #if(Wheels_PWMModeIsCenterAligned)
	       #define Wheels_PERIOD_LSB      (*(reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__D1_REG)
	       #define Wheels_PERIOD_LSB_PTR   ((reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__D1_REG)
	   #else
	       #define Wheels_PERIOD_LSB      (*(reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__F0_REG)
	       #define Wheels_PERIOD_LSB_PTR   ((reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__F0_REG)
	   #endif /* (Wheels_PWMModeIsCenterAligned) */
	   
	   #define Wheels_COMPARE1_LSB    (*(reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__D0_REG)
	   #define Wheels_COMPARE1_LSB_PTR ((reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__D0_REG)
	   #define Wheels_COMPARE2_LSB    (*(reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__D1_REG)
	   #define Wheels_COMPARE2_LSB_PTR ((reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__D1_REG)
	   #define Wheels_COUNTERCAP_LSB   (*(reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__A1_REG)
	   #define Wheels_COUNTERCAP_LSB_PTR ((reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__A1_REG)
	   #define Wheels_COUNTER_LSB     (*(reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__A0_REG)
	   #define Wheels_COUNTER_LSB_PTR  ((reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__A0_REG)
	   #define Wheels_CAPTURE_LSB     (*(reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__F1_REG)
	   #define Wheels_CAPTURE_LSB_PTR  ((reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__F1_REG)
   
   #else
   		#if(CY_PSOC3) /* 8-bit address space */	
			#if(Wheels_PWMModeIsCenterAligned)
		       #define Wheels_PERIOD_LSB      (*(reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__D1_REG)
		       #define Wheels_PERIOD_LSB_PTR   ((reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__D1_REG)
		    #else
		       #define Wheels_PERIOD_LSB      (*(reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__F0_REG)
		       #define Wheels_PERIOD_LSB_PTR   ((reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__F0_REG)
		    #endif /* (Wheels_PWMModeIsCenterAligned) */
		   
		    #define Wheels_COMPARE1_LSB    (*(reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__D0_REG)
		    #define Wheels_COMPARE1_LSB_PTR ((reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__D0_REG)
		    #define Wheels_COMPARE2_LSB    (*(reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__D1_REG)
		    #define Wheels_COMPARE2_LSB_PTR ((reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__D1_REG)
		    #define Wheels_COUNTERCAP_LSB   (*(reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__A1_REG)
		    #define Wheels_COUNTERCAP_LSB_PTR ((reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__A1_REG)
		    #define Wheels_COUNTER_LSB     (*(reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__A0_REG)
		    #define Wheels_COUNTER_LSB_PTR  ((reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__A0_REG)
		    #define Wheels_CAPTURE_LSB     (*(reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__F1_REG)
		    #define Wheels_CAPTURE_LSB_PTR  ((reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__F1_REG)
		#else
			#if(Wheels_PWMModeIsCenterAligned)
		       #define Wheels_PERIOD_LSB      (*(reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
		       #define Wheels_PERIOD_LSB_PTR   ((reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
		    #else
		       #define Wheels_PERIOD_LSB      (*(reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
		       #define Wheels_PERIOD_LSB_PTR   ((reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
		    #endif /* (Wheels_PWMModeIsCenterAligned) */
		   
		    #define Wheels_COMPARE1_LSB    (*(reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
		    #define Wheels_COMPARE1_LSB_PTR ((reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
		    #define Wheels_COMPARE2_LSB    (*(reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
		    #define Wheels_COMPARE2_LSB_PTR ((reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
		    #define Wheels_COUNTERCAP_LSB   (*(reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
		    #define Wheels_COUNTERCAP_LSB_PTR ((reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
		    #define Wheels_COUNTER_LSB     (*(reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
		    #define Wheels_COUNTER_LSB_PTR  ((reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
		    #define Wheels_CAPTURE_LSB     (*(reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
		    #define Wheels_CAPTURE_LSB_PTR  ((reg16 *) Wheels_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
		#endif
		
	   #define Wheels_AUX_CONTROLDP1    (*(reg8 *) Wheels_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define Wheels_AUX_CONTROLDP1_PTR  ((reg8 *) Wheels_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (Wheels_Resolution == 8) */
   
   #define Wheels_AUX_CONTROLDP0      (*(reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define Wheels_AUX_CONTROLDP0_PTR  ((reg8 *) Wheels_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (Wheels_UsingFixedFunction) */
   
#if(Wheels_KillModeMinTime )
    #define Wheels_KILLMODEMINTIME      (*(reg8 *) Wheels_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define Wheels_KILLMODEMINTIME_PTR   ((reg8 *) Wheels_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (Wheels_KillModeMinTime ) */

#if(Wheels_DeadBandMode == Wheels__B_PWM__DBM_256_CLOCKS)
    #define Wheels_DEADBAND_COUNT      (*(reg8 *) Wheels_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Wheels_DEADBAND_COUNT_PTR  ((reg8 *) Wheels_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Wheels_DEADBAND_LSB_PTR    ((reg8 *) Wheels_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define Wheels_DEADBAND_LSB        (*(reg8 *) Wheels_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(Wheels_DeadBandMode == Wheels__B_PWM__DBM_2_4_CLOCKS)
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (Wheels_UsingFixedFunction)
        #define Wheels_DEADBAND_COUNT        (*(reg8 *) Wheels_PWMHW__CFG0) 
        #define Wheels_DEADBAND_COUNT_PTR     ((reg8 *) Wheels_PWMHW__CFG0)
        #define Wheels_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Wheels_DEADBAND_COUNT_SHIFT)
        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define Wheels_DEADBAND_COUNT_SHIFT   0x06u  
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define Wheels_DEADBAND_COUNT        (*(reg8 *) Wheels_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define Wheels_DEADBAND_COUNT_PTR     ((reg8 *) Wheels_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define Wheels_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Wheels_DEADBAND_COUNT_SHIFT) 
        /* As defined by the verilog implementation of the Control Register */
        #define Wheels_DEADBAND_COUNT_SHIFT   0x00u 
    #endif /* (Wheels_UsingFixedFunction) */
#endif /* (Wheels_DeadBandMode == Wheels__B_PWM__DBM_256_CLOCKS) */



#if (Wheels_UsingFixedFunction)
    #define Wheels_STATUS                (*(reg8 *) Wheels_PWMHW__SR0)
    #define Wheels_STATUS_PTR            ((reg8 *) Wheels_PWMHW__SR0)
    #define Wheels_STATUS_MASK           (*(reg8 *) Wheels_PWMHW__SR0)
    #define Wheels_STATUS_MASK_PTR       ((reg8 *) Wheels_PWMHW__SR0)
    #define Wheels_CONTROL               (*(reg8 *) Wheels_PWMHW__CFG0)
    #define Wheels_CONTROL_PTR           ((reg8 *) Wheels_PWMHW__CFG0)    
    #define Wheels_CONTROL2              (*(reg8 *) Wheels_PWMHW__CFG1)    
    #define Wheels_CONTROL3              (*(reg8 *) Wheels_PWMHW__CFG2)
    #define Wheels_GLOBAL_ENABLE         (*(reg8 *) Wheels_PWMHW__PM_ACT_CFG)
    #define Wheels_GLOBAL_ENABLE_PTR       ( (reg8 *) Wheels_PWMHW__PM_ACT_CFG)
    #define Wheels_GLOBAL_STBY_ENABLE      (*(reg8 *) Wheels_PWMHW__PM_STBY_CFG)
    #define Wheels_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) Wheels_PWMHW__PM_STBY_CFG)
  
  
    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define Wheels_BLOCK_EN_MASK          Wheels_PWMHW__PM_ACT_MSK
    #define Wheels_BLOCK_STBY_EN_MASK     Wheels_PWMHW__PM_STBY_MSK 
    /* Control Register definitions */
    #define Wheels_CTRL_ENABLE_SHIFT      0x00u
    
    #define Wheels_CTRL_CMPMODE1_SHIFT    0x04u  /* As defined by Register map as MODE_CFG bits in CFG2*/
    
    #define Wheels_CTRL_DEAD_TIME_SHIFT   0x06u   /* As defined by Register map */

    /* Fixed Function Block Only CFG register bit definitions */
    #define Wheels_CFG0_MODE              0x02u   /*  Set to compare mode */
    
    /* #define Wheels_CFG0_ENABLE            0x01u */  /* Enable the block to run */
    #define Wheels_CFG0_DB                0x20u   /* As defined by Register map as DB bit in CFG0 */

    /* Control Register Bit Masks */
    #define Wheels_CTRL_ENABLE            (uint8)((uint8)0x01u << Wheels_CTRL_ENABLE_SHIFT)
    #define Wheels_CTRL_RESET             (uint8)((uint8)0x01u << Wheels_CTRL_RESET_SHIFT)
    #define Wheels_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Wheels_CTRL_CMPMODE2_SHIFT)
    #define Wheels_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Wheels_CTRL_CMPMODE1_SHIFT)
    
    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Wheels_CTRL2_IRQ_SEL_SHIFT    0x00u       
    #define Wheels_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << Wheels_CTRL2_IRQ_SEL_SHIFT)  
    
    /* Status Register Bit Locations */
    #define Wheels_STATUS_TC_SHIFT            0x07u   /* As defined by Register map as TC in SR0 */
    #define Wheels_STATUS_CMP1_SHIFT          0x06u   /* As defined by the Register map as CAP_CMP in SR0 */
    
    /* Status Register Interrupt Enable Bit Locations */
    #define Wheels_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)    
    #define Wheels_STATUS_TC_INT_EN_MASK_SHIFT            (Wheels_STATUS_TC_SHIFT - 4u)
    #define Wheels_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)  
    #define Wheels_STATUS_CMP1_INT_EN_MASK_SHIFT          (Wheels_STATUS_CMP1_SHIFT - 4u)
    
    /* Status Register Bit Masks */
    #define Wheels_STATUS_TC              (uint8)((uint8)0x01u << Wheels_STATUS_TC_SHIFT)
    #define Wheels_STATUS_CMP1            (uint8)((uint8)0x01u << Wheels_STATUS_CMP1_SHIFT)
    
    /* Status Register Interrupt Bit Masks */
    #define Wheels_STATUS_TC_INT_EN_MASK              (uint8)((uint8)Wheels_STATUS_TC >> 4u)
    #define Wheels_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)Wheels_STATUS_CMP1 >> 4u)
    
    /*RT1 Synch Constants */
    #define Wheels_RT1_SHIFT             0x04u
    #define Wheels_RT1_MASK              (uint8)((uint8)0x03u << Wheels_RT1_SHIFT)/* Sync TC and CMP bit masks */
    #define Wheels_SYNC                  (uint8)((uint8)0x03u << Wheels_RT1_SHIFT)
    #define Wheels_SYNCDSI_SHIFT         0x00u
    #define Wheels_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << Wheels_SYNCDSI_SHIFT) /* Sync all DSI inputs */
    #define Wheels_SYNCDSI_EN            (uint8)((uint8)0x0Fu << Wheels_SYNCDSI_SHIFT) /* Sync all DSI inputs */
    

#else
    #define Wheels_STATUS                (*(reg8 *) Wheels_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define Wheels_STATUS_PTR            ((reg8 *) Wheels_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define Wheels_STATUS_MASK           (*(reg8 *) Wheels_PWMUDB_genblk8_stsreg__MASK_REG)
    #define Wheels_STATUS_MASK_PTR       ((reg8 *) Wheels_PWMUDB_genblk8_stsreg__MASK_REG)
    #define Wheels_STATUS_AUX_CTRL       (*(reg8 *) Wheels_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define Wheels_CONTROL               (*(reg8 *) Wheels_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define Wheels_CONTROL_PTR           ((reg8 *) Wheels_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    
    
    /***********************************
    *          Constants
    ***********************************/

    /* Control Register definitions */
    #define Wheels_CTRL_ENABLE_SHIFT      0x07u
    #define Wheels_CTRL_RESET_SHIFT       0x06u
    #define Wheels_CTRL_CMPMODE2_SHIFT    0x03u
    #define Wheels_CTRL_CMPMODE1_SHIFT    0x00u
    #define Wheels_CTRL_DEAD_TIME_SHIFT   0x00u   /* No Shift Needed for UDB block */
    /* Control Register Bit Masks */
    #define Wheels_CTRL_ENABLE            (uint8)((uint8)0x01u << Wheels_CTRL_ENABLE_SHIFT)
    #define Wheels_CTRL_RESET             (uint8)((uint8)0x01u << Wheels_CTRL_RESET_SHIFT)
    #define Wheels_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Wheels_CTRL_CMPMODE2_SHIFT)
    #define Wheels_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Wheels_CTRL_CMPMODE1_SHIFT) 
    
    /* Status Register Bit Locations */
    #define Wheels_STATUS_KILL_SHIFT          0x05u
    #define Wheels_STATUS_FIFONEMPTY_SHIFT    0x04u
    #define Wheels_STATUS_FIFOFULL_SHIFT      0x03u  
    #define Wheels_STATUS_TC_SHIFT            0x02u
    #define Wheels_STATUS_CMP2_SHIFT          0x01u
    #define Wheels_STATUS_CMP1_SHIFT          0x00u
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define Wheels_STATUS_KILL_INT_EN_MASK_SHIFT          Wheels_STATUS_KILL_SHIFT          
    #define Wheels_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    Wheels_STATUS_FIFONEMPTY_SHIFT    
    #define Wheels_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      Wheels_STATUS_FIFOFULL_SHIFT        
    #define Wheels_STATUS_TC_INT_EN_MASK_SHIFT            Wheels_STATUS_TC_SHIFT            
    #define Wheels_STATUS_CMP2_INT_EN_MASK_SHIFT          Wheels_STATUS_CMP2_SHIFT          
    #define Wheels_STATUS_CMP1_INT_EN_MASK_SHIFT          Wheels_STATUS_CMP1_SHIFT   
    /* Status Register Bit Masks */
    #define Wheels_STATUS_KILL            (uint8)((uint8)0x00u << Wheels_STATUS_KILL_SHIFT )
    #define Wheels_STATUS_FIFOFULL        (uint8)((uint8)0x01u << Wheels_STATUS_FIFOFULL_SHIFT)
    #define Wheels_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << Wheels_STATUS_FIFONEMPTY_SHIFT)
    #define Wheels_STATUS_TC              (uint8)((uint8)0x01u << Wheels_STATUS_TC_SHIFT)
    #define Wheels_STATUS_CMP2            (uint8)((uint8)0x01u << Wheels_STATUS_CMP2_SHIFT) 
    #define Wheels_STATUS_CMP1            (uint8)((uint8)0x01u << Wheels_STATUS_CMP1_SHIFT)
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define Wheels_STATUS_KILL_INT_EN_MASK            Wheels_STATUS_KILL
    #define Wheels_STATUS_FIFOFULL_INT_EN_MASK        Wheels_STATUS_FIFOFULL
    #define Wheels_STATUS_FIFONEMPTY_INT_EN_MASK      Wheels_STATUS_FIFONEMPTY
    #define Wheels_STATUS_TC_INT_EN_MASK              Wheels_STATUS_TC
    #define Wheels_STATUS_CMP2_INT_EN_MASK            Wheels_STATUS_CMP2
    #define Wheels_STATUS_CMP1_INT_EN_MASK            Wheels_STATUS_CMP1
                                                          
    /* Datapath Auxillary Control Register definitions */
    #define Wheels_AUX_CTRL_FIFO0_CLR     0x01u
    #define Wheels_AUX_CTRL_FIFO1_CLR     0x02u
    #define Wheels_AUX_CTRL_FIFO0_LVL     0x04u
    #define Wheels_AUX_CTRL_FIFO1_LVL     0x08u
    #define Wheels_STATUS_ACTL_INT_EN_MASK  0x10u /* As defined for the ACTL Register */
#endif /* Wheels_UsingFixedFunction */

#endif  /* CY_PWM_Wheels_H */


/* [] END OF FILE */
