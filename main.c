#include <stdio.h>
#include <stdlib.h>
#include "read_data.h"

// global variables
// data from the settings file should be read into these.
double width, height, grid_size;
int temp_left, temp_top, temp_right, temp_bottom;

int main(int argc, char** argv) {
	FILE* s_fp;
	
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
	
	// this is where the magic happens
		
	fclose(s_fp);
	
	return EXIT_SUCCESS
}