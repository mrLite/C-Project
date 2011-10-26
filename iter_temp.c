#include "iter_temp.h"

// calculates the average temperature of the object
double average_temp(double* t, int w_size, int h_size){
	double sum=0;
	for(int i=0, i < h_size, i++){
		for(int j=0, i < w_size, i++){
			sum+=t(i,j);
		}
	} 
	return sum/(w_size*h_size);
	
}

// calculates next iteration of temperatures from t1 to t2
void iterate_temp(double* t1, double* t2);

// returns 0 if temperature difference between t1 and t2 is smaller than e, otherwise 1.
int compare_temp(double* t1, double* t2, double e);