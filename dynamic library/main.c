#include <stdio.h>
#include <stdlib.h>

#include "file.h"

#define SIZE 20

int main()
{
    int *m1 = NULL, *m2 = NULL, *m3 = NULL;
    fill_array(&m1, SIZE, 0, 10);
    fill_array(&m2, SIZE, 0, 10);
    fill_array(&m3, SIZE, 0, 10);
    save_to_file("duom1.bin", m1, SIZE);
    save_to_file("duom1.bin", m3, SIZE);
    int n;
    load_from_file("duom1.bin", &m1, &n);
    save_to_file("duom2.bin", m2, SIZE);
    load_from_file("duom2.bin", &m3, &n);
    load_from_file("duom1.bin", &m2, &n);
    int a = save_count, b = load_count;
    if (save_count == 3 && load_count == 3){
        printf("all good\n");
    } else {
        printf("something is wrong\n");
    }
    return 0;
}
