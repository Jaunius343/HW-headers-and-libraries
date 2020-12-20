#ifndef filec
#define filec

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "file.h"

load_count = 0;
save_count = 0;

void fill_array(int *data, int size, int low, int high)
{
    srand(time(0));

	int *temp = (int *)malloc(size * sizeof(int));
    if(high < low)
        printf("\nincorrect interval\n");
    else{
        for(int i = 0; i < size; ++i){
            temp[i] = low + rand()% (high - low + 1);
        }
    }
	*data = temp;
}

void load_from_file(char *file_name, int *array, int *array_size)
{
    int *temp = NULL;
    FILE *my_file;
    my_file = fopen(file_name, "rb");
    int n;
    fread(&n, sizeof(int), 1, my_file);
    *array_size = n;
    temp = (int *)malloc(n * sizeof(int));
    fread(temp, sizeof(int), n, my_file);
    *array = temp;
    fclose(my_file);
	++load_count;
}

void save_to_file(char *file_name, int array[], int array_size)
{
    FILE *my_file;
    my_file = fopen(file_name, "wb");
    fwrite(&array_size, sizeof(int), 1, my_file);
    fwrite(array, sizeof(int), array_size, my_file);
    fclose(my_file);
	++save_count;
}


#endif
