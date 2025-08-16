#ifndef __M_FILTER_H__
#define __M_FILTER_H__

#include "stm32f0xx.h"


//Signal Filter mini lib
////////////////////////////////////////////////////////////////


#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
         
/* template <typename X> float MedianFilter(X meas) {
    static float buf[3];
    static uint8_t count = 0;
    buf[count] = meas;
    if (++count >= 3) count = 0;
    return (max(buf[0], buf[1]) == max(buf[1], buf[2])) ? max(buf[0], buf[2]) : max(buf[1], min(buf[0], buf[2]));
} */

void MedianFilter(uint16_t *meas, uint16_t buf[]) {
  buf[0] = buf[1];
  buf[1] = buf[2];
  buf[2] = *meas;
  *meas = (max(buf[0], buf[1]) == max(buf[1], buf[2])) ? max(buf[0], buf[2]) : max(buf[1], min(buf[0], buf[2]));
}

uint16_t ExpRunAverage(uint16_t *new_val, float k) {
  static float filt_val = 0;
  filt_val += (*new_val - filt_val) * k;
  return filt_val;
}


#endif