#include <stdio.h>
#include <stdlib.h>
int out_array_n(int *ptr, int n, int i);
int main(void)
{
    // выделяем память для 4-х объектов int
    int n = 4;
    int i = 0;
    int *ptr = calloc(n, sizeof(int));
    if(ptr)
    {
        // устанавливаем значения
        ptr[0] = 1;
        ptr[1] = 2;
        ptr[2] = 3;
        ptr[3] = 5;
        out_array_n(ptr, n, i);
        // получаем значения
    }
 
    free(ptr);
    return 0;
}

int out_array_n(int *ptr, int n, int i) {
    if(i<n){
        printf("%d", ptr[i]);
        i++;
        out_array_n(ptr, n, i);
    }
    return 0;
}