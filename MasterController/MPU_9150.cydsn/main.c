/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *

Notes about the MPU9150:

The slave address of the MPU-9150 is b110100X which is 7 bits long.
The X is the logic on pin AD0, which allows us to use two MPU9150s
on the same I2C bus. We won't be using that feature.

MPU9150 Register Addresses for:
(pg 15 datasheet?)
Accelerometer:
Gyro:
Compass: 0x0C

I2C Communications Protocol (See MPU9150 datasheet pg 32)

We'll mainly be using this function:
    I2CMasterReadBuf(address, pointer to data array, 
    number of bytes to read, mode)
    There are 3 modes:
        SCB_I2C_MODE_COMPLETE_XFER (complete transfer from start to stop)
        SCB_I2C_MODE_REPEAT_START 
        SCB_I2C_MODE_NO_STOP
    We'll be using complete transfer.
 * ========================================
*/
#include <project.h>

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    I2C_1_Start();
    
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
