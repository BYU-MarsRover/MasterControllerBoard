#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include <cydevice_trm.h>

/* PWM_1_cy_m0s8_tcpwm_1 */
#define PWM_1_cy_m0s8_tcpwm_1__CC CYREG_TCPWM_CNT0_CC
#define PWM_1_cy_m0s8_tcpwm_1__CC_BUFF CYREG_TCPWM_CNT0_CC_BUFF
#define PWM_1_cy_m0s8_tcpwm_1__COUNTER CYREG_TCPWM_CNT0_COUNTER
#define PWM_1_cy_m0s8_tcpwm_1__CTRL CYREG_TCPWM_CNT0_CTRL
#define PWM_1_cy_m0s8_tcpwm_1__INTR CYREG_TCPWM_CNT0_INTR
#define PWM_1_cy_m0s8_tcpwm_1__INTR_MASK CYREG_TCPWM_CNT0_INTR_MASK
#define PWM_1_cy_m0s8_tcpwm_1__INTR_MASKED CYREG_TCPWM_CNT0_INTR_MASKED
#define PWM_1_cy_m0s8_tcpwm_1__INTR_SET CYREG_TCPWM_CNT0_INTR_SET
#define PWM_1_cy_m0s8_tcpwm_1__PERIOD CYREG_TCPWM_CNT0_PERIOD
#define PWM_1_cy_m0s8_tcpwm_1__PERIOD_BUFF CYREG_TCPWM_CNT0_PERIOD_BUFF
#define PWM_1_cy_m0s8_tcpwm_1__STATUS CYREG_TCPWM_CNT0_STATUS
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMD CYREG_TCPWM_CMD
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK 0x01u
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT 0
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK 0x100u
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT 8
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK 0x1000000u
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT 24
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK 0x10000u
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT 16
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_CTRL CYREG_TCPWM_CTRL
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK 0x01u
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT 0
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE CYREG_TCPWM_INTR_CAUSE
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK 0x01u
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT 0
#define PWM_1_cy_m0s8_tcpwm_1__TCPWM_NUMBER 0u
#define PWM_1_cy_m0s8_tcpwm_1__TR_CTRL0 CYREG_TCPWM_CNT0_TR_CTRL0
#define PWM_1_cy_m0s8_tcpwm_1__TR_CTRL1 CYREG_TCPWM_CNT0_TR_CTRL1
#define PWM_1_cy_m0s8_tcpwm_1__TR_CTRL2 CYREG_TCPWM_CNT0_TR_CTRL2

/* Servo */
#define Servo__0__DM__MASK 0x07u
#define Servo__0__DM__SHIFT 0
#define Servo__0__DR CYREG_PRT2_DR
#define Servo__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define Servo__0__HSIOM_MASK 0x0000000Fu
#define Servo__0__HSIOM_SHIFT 0u
#define Servo__0__INTCFG CYREG_PRT2_INTCFG
#define Servo__0__INTSTAT CYREG_PRT2_INTSTAT
#define Servo__0__MASK 0x01u
#define Servo__0__OUT_SEL CYREG_UDB_PA2_CFG10
#define Servo__0__OUT_SEL_SHIFT 0u
#define Servo__0__OUT_SEL_VAL 0u
#define Servo__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define Servo__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define Servo__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define Servo__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define Servo__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define Servo__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define Servo__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define Servo__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define Servo__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define Servo__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define Servo__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define Servo__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define Servo__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define Servo__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define Servo__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define Servo__0__PC CYREG_PRT2_PC
#define Servo__0__PC2 CYREG_PRT2_PC2
#define Servo__0__PORT 2u
#define Servo__0__PS CYREG_PRT2_PS
#define Servo__0__SHIFT 0
#define Servo__DR CYREG_PRT2_DR
#define Servo__INTCFG CYREG_PRT2_INTCFG
#define Servo__INTSTAT CYREG_PRT2_INTSTAT
#define Servo__MASK 0x01u
#define Servo__PA__CFG0 CYREG_UDB_PA2_CFG0
#define Servo__PA__CFG1 CYREG_UDB_PA2_CFG1
#define Servo__PA__CFG10 CYREG_UDB_PA2_CFG10
#define Servo__PA__CFG11 CYREG_UDB_PA2_CFG11
#define Servo__PA__CFG12 CYREG_UDB_PA2_CFG12
#define Servo__PA__CFG13 CYREG_UDB_PA2_CFG13
#define Servo__PA__CFG14 CYREG_UDB_PA2_CFG14
#define Servo__PA__CFG2 CYREG_UDB_PA2_CFG2
#define Servo__PA__CFG3 CYREG_UDB_PA2_CFG3
#define Servo__PA__CFG4 CYREG_UDB_PA2_CFG4
#define Servo__PA__CFG5 CYREG_UDB_PA2_CFG5
#define Servo__PA__CFG6 CYREG_UDB_PA2_CFG6
#define Servo__PA__CFG7 CYREG_UDB_PA2_CFG7
#define Servo__PA__CFG8 CYREG_UDB_PA2_CFG8
#define Servo__PA__CFG9 CYREG_UDB_PA2_CFG9
#define Servo__PC CYREG_PRT2_PC
#define Servo__PC2 CYREG_PRT2_PC2
#define Servo__PORT 2u
#define Servo__PS CYREG_PRT2_PS
#define Servo__SHIFT 0

/* servoClock */
#define servoClock__DIVIDER_MASK 0x0000FFFFu
#define servoClock__ENABLE CYREG_CLK_DIVIDER_A00
#define servoClock__ENABLE_MASK 0x80000000u
#define servoClock__MASK 0x80000000u
#define servoClock__REGISTER CYREG_CLK_DIVIDER_A00

/* Miscellaneous */
#define CYDEV_BCLK__HFCLK__HZ 24000000U
#define CYDEV_BCLK__HFCLK__KHZ 24000U
#define CYDEV_BCLK__HFCLK__MHZ 24U
#define CYDEV_BCLK__SYSCLK__HZ 24000000U
#define CYDEV_BCLK__SYSCLK__KHZ 24000U
#define CYDEV_BCLK__SYSCLK__MHZ 24U
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PANTHER 4u
#define CYDEV_CHIP_DIE_PSOC4A 2u
#define CYDEV_CHIP_DIE_PSOC5LP 5u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC4
#define CYDEV_CHIP_JTAG_ID 0x04C81193u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 2u
#define CYDEV_CHIP_MEMBER_4D 3u
#define CYDEV_CHIP_MEMBER_5A 4u
#define CYDEV_CHIP_MEMBER_5B 5u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_4A
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PANTHER_ES0 0u
#define CYDEV_CHIP_REV_PANTHER_ES1 1u
#define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_ES0 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_4A_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_PROTECT_KILL 4
#define CYDEV_DEBUG_PROTECT_OPEN 1
#define CYDEV_DEBUG_PROTECT CYDEV_DEBUG_PROTECT_OPEN
#define CYDEV_DEBUG_PROTECT_PROTECTED 2
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_HEAP_SIZE 0x0100
#define CYDEV_PROJ_TYPE 2
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_STACK_SIZE 0x0400
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 1
#define CYDEV_VDDA 3.3
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.3
#define CYDEV_VDDD_MV 3300
#define CYIPBLOCK_M0S8_CTBM_VERSION 0
#define CYIPBLOCK_m0s8cpuss_VERSION 0
#define CYIPBLOCK_m0s8csd_VERSION 0
#define CYIPBLOCK_m0s8gpio2_VERSION 0
#define CYIPBLOCK_m0s8hsiom4a_VERSION 0
#define CYIPBLOCK_m0s8lcd_VERSION 0
#define CYIPBLOCK_m0s8lpcomp_VERSION 0
#define CYIPBLOCK_m0s8pclk_VERSION 0
#define CYIPBLOCK_m0s8sar_VERSION 0
#define CYIPBLOCK_m0s8scb_VERSION 0
#define CYIPBLOCK_m0s8srssv2_VERSION 1
#define CYIPBLOCK_m0s8tcpwm_VERSION 0
#define CYIPBLOCK_m0s8udbif_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 2
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
