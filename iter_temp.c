/*
This file contains functions to calculate the next iteration of the temperature of the object,
the average temperature of the object and the change in the temperature between iterations.
*/
#include "iter_temp.h"
#include <math.h>
#include <stdlib.h>

// initializes temperature array
Temp** initialize_temp(int w, int h, int temp_left, int temp_top, int temp_right, int temp_bottom){
	
	//initialize
	int x,y;
	Temp** array;

	//malloc the 'y' dimension
	array = malloc(sizeof(double*) * h);

	//iterate over 'y' dimension
	for(y=0;y<h;y++){
	  //malloc the 'x' dimension
	  array[y] = malloc(sizeof(double) * w);

	  //iterate over the 'x' dimension
	  for(x=0;x<w;x++){

	    //initialize
		if(h == 0)
			array[y][x].t = (double)temp_top;
		else if(h == h-1)
			array[y][x].t = (double)temp_bottom;
		else if(w == 0)
			array[y][x].t = (double)temp_left;
		else if(w == w-1)
			array[y][x].t = (double)temp_right;
		else
			array[y][x].t = 0.0;
	  	}
	}
	
	return array;
}

// calculates the average temperature of the object
// parameters: two-dimensional double array t, and the array height and width
// returns: the average temperature of the object
double average_temp(double** t, int w, int h){
	double sum = 0;
	
	//Add all elements together and divide by the number of elements
	for(int i=0; i < h; i++){
		for(int j=0; i < w; i++){
			sum += t[i][j];
		}
	} 
	return sum/(w*h);
}

// calculates next iteration of temperatures from t1 to t2
// parameters: two two-dimensional double arrays of the same size, and the array height and width
void iterate_temp(double** t1, double** t2, int w, int h){
	
	for(int i=1; i < w-1; i++){
		for(int j=1; i < h-1; i++){
			t2[i][j] = 1/4*( t1[i+1][j] + t1[i-1][j] + t1[i][j+1] + t1[i][j-1]);
		}
	}
	
}

// returns 0 if temperature difference between t1 and t2 is smaller than e, otherwise 1.
// parameters: two two-dimensional double arrays of the same size, the array height and width, and a small double value e
int compare_temp(double** t1, double** t2, int w, int h, double e){
	
	//loops through all elements and compare difference to e
	for(int i=1; i < h-1; i++){
		for(int j=1; i < w-1; i++){
			
			//calculate absolute value
			double dif=fabs(t2[i][j]-t1[i][j]);
			//return 1 if difference not small enough
			if(dif >= e) return 1; 
		}
	}
	return 0;
	
}