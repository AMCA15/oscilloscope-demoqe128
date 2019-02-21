/*
 * Oscilloscope.h
 *
 *  Created on: Feb 18, 2019
 *      Author: Anderson Contreras
 */

#ifndef OSCILLOSCOPE_H_
#define OSCILLOSCOPE_H_

#include "PE_Types.h"


#define CHA 0
#define CHB 1
#define OSC_FRAME_SIZE 4


extern volatile char is_CH_Full;
extern volatile char *BufferSerialCount;


struct Data{
	word Data_Ana_L : 6;
	word Data_Ana_H : 6;
	word Data_Dig   : 1;
};
extern struct Data Channels[2];

struct Frame{
	byte DCHA_Ana_Low  : 6;
	byte DCHA_Dig_Low  : 1;
	byte Sync_CHA_Low  : 1;
	byte DCHA_Ana_High : 6;
	byte DCHA_Dig_High : 1;
	byte Sync_CHA_High : 1;
	byte DCHB_Ana_Low  : 6;
	byte DCHB_Dig_Low  : 1;
	byte Sync_CHB_Low  : 1;
	byte DCHB_Ana_High : 6;
	byte DCHB_Dig_High : 1;
	byte Sync_CHB_High : 1;
};
extern struct Frame Osc_Frame;

// Functions
void Pack(struct Frame *frame, struct Data *channels);


#endif /* OSCILLOSCOPE_H_ */
