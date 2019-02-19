/*
 * Oscilloscope.c
 *
 *  Created on: Feb 18, 2019
 *      Author: Anderson Contreras
 */

#include "Oscilloscope.h"


int CH_Analog[2];
volatile char is_CH_Full;
volatile char *BufferSerialCount;


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
void Pack(int *blk, char size, char type){
	int i = 0;
	
	for(i; i < size*2; i++){
		blk[i] = (((blk[i] << 6) & MASK_DATA_CHAN_HIGH) | (blk[i] & MASK_DATA_CHAN_LOW));
		if(type == DATA_ANALOG){
			blk[i] = blk[i] | MASK_DATA_ANALOG;
		}
		if(i == 0){
			blk[i] = blk[i] | MASK_SYNC_CHANNEL;
		}
		else{
			blk[i] = blk[i] | MASK_NO_SYNC_CHANNEL;
		}
	}
}
