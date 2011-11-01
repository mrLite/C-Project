#include "read_data.h"
#include "iter_temp.h"

// global variables
// data from the settings file should be read into these.
double width, height, grid_size;
int temp_left, temp_top, temp_right, temp_bottom;
double EPSILON = 0.0001;

double* initialize_arr(int h_size, int w_size) {
	double* t = malloc(sizeof(double)*h_size*w_size);
	if(t == NULL) return NULL;
	
	for(int h = 0; h < h_size; ++h) {
		for(int w = 0; w < w_size; ++w) {
			if(h == 0)
				t[h][w] = (double)temp_top;
			else if(h == h_size-1)
				t[h][w] = (double)temp_bottom;
			else if(w == 0)
				t[h][w] = (double)temp_left;
			else if(w == w_size-1)
				t[h][w] = (double)temp_right;
			else
				t[h][w] = 0.0;
		}
	}
	return t;
}

int main(int argc, char** argv) {
	FILE* s_fp;
	double* t1;
	double* t2;
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
	
	t1 = initialize_arr(h_size, w_size);
	t2 = initialize_arr(h_size, w_size);
	
	if(t1 == NULL || t2 == NULL) return EXIT_FAILURE;
	
	for(int i = 0; i++) {
		if(i%5 == 0 && compare_temp(t1, t2, w_size, h_size, EPSILON) == 0) break;
		iterate_temp(t1, t2, w_size, h_size);
		iterate_temp(t2, t1, w_size, h_size);
	}
	
	double temp = average_temp(t1, w_size, h_size);
	printf("Average temperature is: %lf\n", temp);
	
	fclose(s_fp);
	
	return EXIT_SUCCESS;
}
