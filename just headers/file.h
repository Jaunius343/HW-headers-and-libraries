#ifndef fileh
#define fileh

void fill_array(int data[], int size, int low, int high);
void save_to_file(char *file_name, int array[], int array_size);
void load_from_file(char *file_name, int *array, int *array_size);

extern int save_count, load_count;

#endif