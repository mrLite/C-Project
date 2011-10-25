#include "read_data.h"
#include <stdio.h>
#include <stdlib.h>

void read_data(FILE* fp, double* width, double* height, double* grid_size, int* temp_left, int* temp_top, int* temp_right, int* temp_bottom){
  char string[30];
  char id[15];
  double num;
  
  fseek(fp, 0, SEEK_SET); //Set to stream start

  while(fgets(string, sizeof(string), fp) != NULL){
    if(string[0] != '#'){
      sscanf(string, "%[^0-9] %lf", id, &num);
      
      
      if(id == "width")
	*width = num;
      if(id == "height")
	*height = num;
      if(id == "grid_size")
	*grid_size = num;
      if(id == "temp_left")
	*temp_left = num;

    }
  }
  
}
