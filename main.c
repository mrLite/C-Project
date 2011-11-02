/*
This is the main function of the program. It does the job of opening the settings file, and calling functions from the other files.
It also contains the main loop for iterating each step of the temperature of the object.

Function usage from the other files:
read_data.c
	read_data();
iter_temp.c
	iterate_temp();
	compare_temp();
	average_temp();
*/
#include "read_data.h"
#include "iter_temp.h"

// global variables
// data from the settings file should be read into these.
double width, height, grid_size;
int temp_left, temp_top, temp_right, temp_bottom;
double EPSILON = 0.0001;

int main(int argc, char** argv) {
	FILE* s_fp;
	int w_size;
	int h_size;
	
	if(argc <= 1) {
		// should print the usage message here, if no parameters are given.
		printf("Give me a setting file!\n");
		return EXIT_FAILURE;
	}
	
	s_fp = fopen(argv[1], "r");
	if(s_fp == NULL) {
		printf("Failed to open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	
	read_data(s_fp);
	
	w_size = (int)width/grid_size;
	h_size = (int)height/grid_size;
	
	Temp** ptp_temp1; 
	Temp** ptp_temp2; 
	
	ptp_temp1=initialize_temp(w_size, h_size, temp_left, temp_top, temp_right, temp_bottom);
	ptp_temp2=initialize_temp(w_size, h_size, temp_left, temp_top, temp_right, temp_bottom);
	
	
	if(ptp_temp1 == NULL || ptp_temp2 == NULL)
		return EXIT_FAILURE;
		
	ptp_temp1 = initialize_temp(w_size, h_size, temp_left, temp_top, temp_right, temp_bottom);
	ptp_temp2 = initialize_temp(w_size, h_size, temp_left, temp_top, temp_right, temp_bottom);

	
	// Iterates the temperature of the object until it reaches balance, that is, it doesn't change anymore.
	// Compares the temperature once every five iterations.
	for(int i = 0; i++;) {
		if((i%5 == 0) && (compare_temp(ptp_temp1, ptp_temp2, w_size, h_size, EPSILON) == 0))
			break;
		iterate_temp(ptp_temp1, ptp_temp2, w_size, h_size);
		iterate_temp(ptp_temp1, ptp_temp2, w_size, h_size);
	}
	
	double temp = average_temp(ptp_temp1, w_size, h_size);
	printf("Average temperature is: %lf\n", temp);
	
	fclose(s_fp);
	
	return EXIT_SUCCESS;
}
