#include <stdio.h>
#include <stdlib.h>   // для подключения функции malloc
 
int main(void)
{
    int *ptr = malloc(sizeof(int)); // выделяем память для одного int
    if(ptr != NULL)
    {
        *ptr = 24;      // помещаем значение в выделенную память
        printf("%d \n", *ptr);
    }
    free(ptr);
    return 0;
}