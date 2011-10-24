#ifndef __ITER_TEMP_H__
#define __ITER_TEMP_H__

// calculates next iteration of temperatures from t1 to t2
void iterate_temp(double* t1, double* t2);

// returns 0 if temperature difference between t1 and t2 is smaller than e, otherwise 1.
int compare_temp(double* t1, double* t2, double e);

#endif