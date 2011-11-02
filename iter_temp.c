/*
This file contains functions to calculate the next iteration of the temperature of the object,
the average temperature of the object and the change in the temperature between iterations.
*/
#include "iter_temp.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// initializes temperature array
Temp** initialize_temp(int w, int h, int temp_left, int temp_top, int temp_right, int temp_bottom){
	
	//initialize
	int x,y;
	Temp** array;

	//malloc the 'y' dimension
	array = malloc(sizeof(double*) * h);

	//iterate over 'y' dimension
	for(y=0; y<h; y++){
	  //malloc the 'x' dimension
	  array[y] = malloc(sizeof(double) * w);
	
	  //iterate over the 'x' dimension
	  for(x=0;x<w;x++){

	    //initialize
		if(y == 0)
			array[y][x].t = (double)temp_top;
		else if(y == h-1)
			array[y][x].t = (double)temp_bottom;
		else if(x == 0)
			array[y][x].t = (double)temp_left;
		else if(x == w-1)
			array[y][x].t = (double)temp_right;
		else
			array[y][x].t = 500.0;
	  	}
	}
	return array;
}

// calculates the average temperature of the object
// parameters: two-dimensional double array t, and the array height and width
// returns: the average temperature of the object
double average_temp(Temp** t1, int w, int h){
	double sum = 0;
	//Add all elements together and divide by the number of elements
	
	for(int i=0; i < h; i++){
		for(int j=0; j < w; j++){
			sum += t1[i][j].t;
		}
	} 
	return sum/ (w*h);
}

// calculates next iteration of temperatures from t1 to t2
// parameters: two two-dimensional double arrays of the same size, and the array height and width
void iterate_temp(Temp** t1, Temp** t2, int w, int h){
	
	for(int i=1; i < h-1; i++){
		for(int j=1; j < w-1; j++){
			t2[i][j].t = 0.25*( t1[i+1][j].t + t1[i-1][j].t + t1[i][j+1].t + t1[i][j-1].t);
		}
	}	
}

// returns 0 if temperature difference between t1 and t2 is smaller than e, otherwise 1.
// parameters: two two-dimensional double arrays of the same size, the array height and width, and a small double value e
int compare_temp(Temp** t1, Temp** t2, int w, int h, double e){
	
	//loops through all elements and compare difference to e
	for(int i=1; i < h-1; i++){
		for(int j=1; j < w-1; j++){
			
			//calculate absolute value
			double dif=fabs(t2[i][j].t-t1[i][j].t);
			//return 1 if difference not small enough
			if(dif >= e) return 1; 
		}
	}
	return 0;
	
}