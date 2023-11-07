#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int *ptr=malloc(sizeof(int));
    *ptr=24;
    printf("%d \n", *ptr);
    free(ptr);
    return 0;
}