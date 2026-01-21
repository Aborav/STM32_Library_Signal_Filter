#ifndef __M_FILTER_H__
#define __M_FILTER_H__

#include "main.h"


//Signal Filter mini lib

/*
Ho to use:
////////////////////////////////////////////////////////////////////////
-create filtering buffer
-declare required variable type
*/

//defines
////////////////////////////////////////////////////////////////////////
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
     
     
//typedef     
////////////////////////////////////////////////////////////////////////
typedef uint16_t filter_type;
         

//functions
////////////////////////////////////////////////////////////////////////
/*
 * @brief median filter function  
 * @param[out] *meas -> pointer to a filtering variable (uint16_t)
 * @param[in] buf -> mediana filter buffer
 */
void MedianFilter(filter_type *var, filter_type buf[]) {
  buf[0] = buf[1];
  buf[1] = buf[2];
  buf[2] = *var;
  *var = (max(buf[0], buf[1]) == max(buf[1], buf[2])) ? max(buf[0], buf[2]) : max(buf[1], min(buf[0], buf[2]));
}


////////////////////////////////////////////////////////////////////////
/*
 * @brief running average filter function  
 * @param[in] *new_val -> pointer to a filtering variable
 * @param[in] k -> averaging factor
 */
void ExpRunAverage(filter_type *var, float k) {
  static filter_type filt_val;
  filt_val += (*var - filt_val) * k;
  *var=filt_val;
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
