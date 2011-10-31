#include "read_data.h"
#include <stdio.h>
#include <stdlib.h>

void read_data(FILE* fp, double* width, double* height, double* grid_size, int* temp_left, int* temp_top, int* temp_right, int* temp_bottom){
  char string[30];
  char id[15];
  double num;
  int len;
  
  fseek(fp, 0, SEEK_SET); //Set to stream start

  while(fgets(string, sizeof(string), fp) != NULL){
    if(string[0] != '#'){
      sscanf(string, "%[^0-9] %lf", id, &num);

      //Parse setting identifier
      len = (int)(strlen(id));
     
      if(parse_id(id, len, "width ") == 1)
	
      if(parse_id(id, len, "height ") == 1)
	
      if(parse_id(id, len, "grid_size ") == 1)
	
      if(parse_id(id, len, "temp_left ") == 1)
	
      if(parse_id(id, len, "temp_right ") == 1)
	
      if(parse_id(id, len, "temp_bottom ") == 1)
	
      if(parse_id(id, len, "temp_top ") == 1)
	
    }
  }
}

int parse_id(char* string, int len, char* comp){
  int ret = 1;
  
  for(int i = 0; i < len; i++){
    if(string[i] != comp[i])
      ret = 0;
  }

  return ret;
}
