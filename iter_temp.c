/*
This file contains functions to calculate the next iteration of the temperature of the object,
the average temperature of the object and the change in the temperature between iterations.
*/
#include "iter_temp.h"
#include <math.h>

// calculates the average temperature of the object
// parameters: two-dimensional double array t, and the array height and width
// returns: the average temperature of the object
double average_temp(double t[][], int w_size, int h_size){
	double sum = 0;
	
	//Add all elements together and divide by the number of elements
	for(int i=0, i < h_size, i++){
		for(int j=0, i < w_size, i++){
			sum += t[i][j];
		}
	} 
	return sum/(w_size*h_size);
}

// calculates next iteration of temperatures from t1 to t2
// parameters: two two-dimensional double arrays of the same size, and the array height and width
void iterate_temp(double t1[][], double t2[][], int w_size, int h_size){
	
	for(int i=1, i < w_size-1, i++){
		for(int j=1, i < h_size-1, i++){
			t2[i,j] = 1/4*( t1[i+1,j] + t1[i-1,j] + t1[i,j+1] + t1[i,j-1];
		}
	}
	
}

// returns 0 if temperature difference between t1 and t2 is smaller than e, otherwise 1.
// parameters: two two-dimensional double arrays of the same size, the array height and width, and a small double value e
int compare_temp(double t1[][], double t2[][], int w_size, int h_size, double e){
	
	//loops through all elements and compare difference to e
	for(int i=1, i < h_size-1, i++){
		for(int j=1, i < w_size-1, i++){
			
			//calculate absolute value
			double dif=fabs(t2[i,j]-t1[i,j])
			//return 1 if difference not small enough
			if(dif >= e) return 1; 
		}
	}
	return 0;
	
}