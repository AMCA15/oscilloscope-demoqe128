/*
 * Oscilloscope.h
 *
 *  Created on: Feb 18, 2019
 *      Author: Anderson Contreras
 */

#ifndef OSCILLOSCOPE_H_
#define OSCILLOSCOPE_H_


#define OSC_FRAME_SIZE         4
#define MASK_DATA_CHAN_LOW     0x003F
#define MASK_DATA_CHAN_HIGH    0x3F00
#define MASK_DATA_ANALOG       0x4040
#define MASK_SYNC_CHANNEL      0x0080
#define MASK_NO_SYNC_CHANNEL   0x8080
#define DATA_ANALOG            0
#define DATA_DIGITAL           1

// Variables
extern int CH_Analog[2];
extern volatile char is_CH_Full;
extern volatile char *BufferSerialCount;

// Functions
void Pack(int *blk, char size, char type);
/*
** ===================================================================
**     Method      :  Pack
*/
/*!
**     @brief
**         Returns the last measured values for all channels. Format
**         and width of the value is a native format of the A/D
**         converter.
**     @param
**         Values          - Pointer to the array that contains
**                           the measured data. Data type is a byte, a
**                           word or an int. It depends on the supported
**                           modes, resolution, etc. of the AD converter.
**                           See the Version specific information for
**                           the current CPU in [General Info].
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_NOTAVAIL - Requested value not
**                           available
**                           ERR_OVERRUN - External trigger overrun flag
**                           was detected after the last value(s) was
**                           obtained (for example by GetValue). This
**                           error may not be supported on some CPUs
**                           (see generated code).
*/
/* ===================================================================*/



#endif /* OSCILLOSCOPE_H_ */
