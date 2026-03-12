#ifndef __M_FILTER_H__
#define __M_FILTER_H__

#include "main.h"


//Signal Filter mini lib

/*
How to use:
////////////////////////////////////////////////////////////////////////
-create filtering buffer
-declare required variable type (typedef)
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
     
     
//Typedef
////////////////////////////////////////////////////////////////////////
typedef uint16_t filter_type;
         
//Functions
////////////////////////////////////////////////////////////////////////
void FilterMedian(filter_type *var, filter_type buf[]);
void FilterRunAverage(filter_type *var, float k);


#endif

// C++
/* template <typename X> float MedianFilter(X meas) {
    static float buf[3];
    static uint8_t count = 0;
    buf[count] = meas;
    if (++count >= 3) count = 0;
    return (max(buf[0], buf[1]) == max(buf[1], buf[2])) ? max(buf[0], buf[2]) : max(buf[1], min(buf[0], buf[2]));
} */
