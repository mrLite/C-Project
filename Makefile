# makefile

CC = gcc -std=c99 -pedantic -Wall -Wextra -Werror

all: AVG_TEMP
AVG_TEMP: main.o iter_temp.o read_data.o
	$(CC) main.o iter_temp.o read_data.o -o AVG_TEMP
iter_temp.o: iter_temp.c
	$(CC) -c iter_temp.c -o iter_temp.o
main.o: main.c
	$(CC) -c main.c -o main.o
read_data.o: read_data.c
	$(CC) -c read_data.c -o read_data.o

clean:
	rm *.o
	rm AVG_TEMP