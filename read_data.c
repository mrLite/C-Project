#include "read_data.h"

extern double width, height, grid_size;
extern int temp_left, temp_top, temp_right, temp_bottom;

void read_data(FILE* fp){
  char string[30];
  char id[15];
  double num, doub;
  int len, integ;
  
  fseek(fp, 0, SEEK_SET); //Set to stream start

  while(fgets(string, sizeof(string), fp) != NULL){
    if(string[0] != '#'){
      sscanf(string, "%[^0-9] %lf", id, &num);

      //Parse setting identifier
      len = (int)(strlen(id));
     
	 integ = (int)num;
	 doub = (double)num;
	 
      if(parse_id(id, len, "width ") == 1){
		width = doub;
		printf("%s%f\n", id, width);
		}
      if(parse_id(id, len, "height ") == 1){
		height = doub;
		printf("%s%f\n", id, height);
		}
      if(parse_id(id, len, "grid_size ") == 1){
		grid_size = doub;
		printf("%s%f\n", id, grid_size);
		}
      if(parse_id(id, len, "temp_left ") == 1){
		temp_left = integ;
		printf("%s%d\n", id, temp_left);
		}
      if(parse_id(id, len, "temp_right ") == 1){
		temp_right = integ;
		printf("%s%d\n", id, temp_right);
		}
      if(parse_id(id, len, "temp_bottom ") == 1){
		temp_bottom = integ;
		printf("%s%d\n", id, temp_bottom);
		}
      if(parse_id(id, len, "temp_top ") == 1){
		temp_top = integ;
		printf("%s%d\n", id, temp_top);
		}
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
