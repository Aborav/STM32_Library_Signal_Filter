#ifndef __M_FILTER_H__
#define __M_FILTER_H__

#include "stm32f0xx.h"


//Signal Filter mini lib

/*
Ho to use:
-create filtering buffer

*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////



         

/*
 * @brief median filter function  
 * @param[out] *meas -> pointer to a filtering variable (uint16_t)
 * @param[in] buf -> mediana filter buffer
 */
void MedianFilter(uint16_t *meas, uint16_t buf[]) {
  buf[0] = buf[1];
  buf[1] = buf[2];
  buf[2] = *meas;
  *meas = (max(buf[0], buf[1]) == max(buf[1], buf[2])) ? max(buf[0], buf[2]) : max(buf[1], min(buf[0], buf[2]));
}

/*
 * @brief running average filter function  
 * @param[in] *new_val -> pointer to a filtering variable
 * @param[in] k -> averaging factor
 */
uint16_t ExpRunAverage(uint16_t *new_val, float k) {
  static float filt_val = 0;
  filt_val += (*new_val - filt_val) * k;
  return filt_val;
}


#endif

// C++
/* template <typename X> float MedianFilter(X meas) {
    static float buf[3];
    static uint8_t count = 0;
    buf[count] = meas;
    if (++count >= 3) count = 0;
    return (max(buf[0], buf[1]) == max(buf[1], buf[2])) ? max(buf[0], buf[2]) : max(buf[1], min(buf[0], buf[2]));
} */
