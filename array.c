#include <stdio.h>
#include <stdlib.h>

int outarr_n (int *ptr, int n, int i);

int main(void)
{
    int n = 4;
    int i = 0;
    int *ptr = malloc(n * sizeof(int)); // выделяем память для 4-х чисел int
    if(ptr)
    {
        // помещаем значения в выделенную память
        ptr[0] = 1;
        ptr[1] = 2;
        ptr[2] = 3;
        ptr[3] = 5;

        // получаем значения
        outarr_n(ptr, n, i);
    }
 
    free(ptr);
    return 0;
}

int outarr_n (int *ptr, int n, int i) {
    if (i<n){
        printf("%d", ptr[i]);
        i++;
        outarr_n(ptr, n, i);
    }
    return 0;
}