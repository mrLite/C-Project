#ifndef __ITER_TEMP_H__
#define __ITER_TEMP_H__

typedef struct{
	double t;
}Temp;

Temp** initialize_temp(int w, int h, int temp_left, int temp_top, int temp_right, int temp_bottom);

double average_temp(Temp** t1, int w, int h);

void iterate_temp(Temp** t1, Temp** t2, int w, int h);

int compare_temp(Temp** t1, Temp** t2, int w, int h, double e);

#endif