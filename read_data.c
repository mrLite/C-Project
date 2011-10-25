#include "read_data.h"
#include <stdio.h>
#include <stdlib.h>

void read_data(FILE* fp, double* width, double* height, double* grid_size, int* temp_left, int* temp_top, int* temp_right, int* temp_bottom){
  char string[30];
  char id[15];
  
  fseek(fp, 0, SEEK_SET); //Set to stream start

  while(fgets(string, sizeof(string), fp) != NULL){
    if(string[0] != '#'){
      sscanf(string, "%[^0-9]", id);
      printf("%s\n", id);
    }
  }
  
}
