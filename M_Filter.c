/*
 * M_Filter.c
 *
 *  Created on: Mar 8, 2026
 *      Author: aborav
 */
#include "SignalFilter/M_Filter.h"

//functions
////////////////////////////////////////////////////////////////////////
/*
 * @brief median filter function
 * @param[in/out] *var -> pointer to a filtering variable (uint16_t)
 * @param[in] buf -> mediana filter buffer
 */
void FilterMedian(filter_type *var, filter_type buf[]) {
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
void FilterRunAverage(filter_type *var, float k) {
  static filter_type filt_val;
  filt_val += (*var - filt_val) * k;
  *var=filt_val;
}
