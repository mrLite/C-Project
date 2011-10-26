#ifndef __ITER_TEMP_H__
#define __ITER_TEMP_H__

// calculates the average temperature of the object
double average_temp(double* t, int w_size, int h_size);

// calculates next iteration of temperatures from t1 to t2
void iterate_temp(double* t1, double* t2, int w_size, int h_size);

// returns 0 if temperature difference between t1 and t2 is smaller than e, otherwise 1.
int compare_temp(double* t1, double* t2, int w_size, int h_size, double e);

#endif