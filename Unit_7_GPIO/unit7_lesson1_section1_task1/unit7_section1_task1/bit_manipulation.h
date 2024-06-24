/*
 * bit_manipulation.h
 *
 * Created: 1/30/2024 2:50:03 PM
 *  Author: hassa
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#define SetBit(reg,bit)	(reg|= (1<<bit))
#define ResetBit(reg,bit)	(reg &= ~(1<<bit))
#define ToggleBit(reg,bit)	(reg ^= (1<<bit))
#define ReadBit(reg,bit)	((reg>>bit) & 1)



#endif /* BIT_MANIPULATION_H_ */