#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef __READ_DATA_H__
#define __READ_DATA_H__

void read_data(FILE* fp);

int parse_id(char* string, int len, char* comp);

#endif
