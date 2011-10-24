#include <stdio.h>
#include <stdlib.h>
#include "read_data.h"

int main(int argc, char** argv) {
	FILE* s_fp;
	
	if(argc <= 1) {
		printf("Give me a setting file!\n");
	}
	else {
		s_fp = fopen(argv[1], "r");
		if(s_fp == NULL) {
			printf("Failed to open file %s\n", argv[1]);
			return EXIT_FAILURE;
		}
		fclose(s_fp);
	}
	
	return EXIT_SUCCESS
}