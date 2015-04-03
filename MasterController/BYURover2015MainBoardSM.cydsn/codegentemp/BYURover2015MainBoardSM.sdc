# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Jared\Documents\PSoC Creator\MasterControllerBoard\MasterController\BYURover2015MainBoardSM.cydsn\BYURover2015MainBoardSM.cyprj
# Date: Fri, 03 Apr 2015 03:06:05 GMT
#set_units -time ns
create_clock -name {UART_1_SCBCLK(FFB)} -period 708.33333333333326 -waveform {0 354.166666666667} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {Clock_2(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_8}] [get_pins {ClockBlock/ff_div_9}] [get_pins {ClockBlock/ff_div_10}]]
create_clock -name {GPS_UART_SCBCLK(FFB)} -period 17375 -waveform {0 8687.5} [list [get_pins {ClockBlock/ff_div_3}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_generated_clock -name {UART_1_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 17 35} -nominal_period 708.33333333333326 [list]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list [get_pins {ClockBlock/udb_div_3}]]
create_generated_clock -name {SPIM_IntClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 13 25} [list [get_pins {ClockBlock/udb_div_1}]]
create_generated_clock -name {GPS_UART_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 417 835} [list]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]


# Component constraints for C:\Users\Jared\Documents\PSoC Creator\MasterControllerBoard\MasterController\BYURover2015MainBoardSM.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Jared\Documents\PSoC Creator\MasterControllerBoard\MasterController\BYURover2015MainBoardSM.cydsn\BYURover2015MainBoardSM.cyprj
# Date: Fri, 03 Apr 2015 03:05:36 GMT
