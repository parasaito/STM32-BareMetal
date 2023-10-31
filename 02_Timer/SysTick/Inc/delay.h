#ifndef _DELAY_H_
#define _DELAY_H_

#include <stdint.h>

/* Blocking call to generate a delay in milli-seconds */
void delayms(uint32_t time);

/* Blocking call to generate a delay in micro-seconds */
void delayus(uint32_t time);



#endif //_DELAY_H_