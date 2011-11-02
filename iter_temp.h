#ifndef __ITER_TEMP_H__
#define __ITER_TEMP_H__

typedef struct{
	double t;
}Temp;

Temp** initialize_temp(int w, int h, int temp_left, int temp_top, int temp_right, int temp_bottom);

double average_temp(Temp** t, int w_size, int h_size);

void iterate_temp(Temp** t1, Temp** t2, int w_size, int h_size);

int compare_temp(Temp** t1, Temp** t2, int w_size, int h_size, double e);

#endif