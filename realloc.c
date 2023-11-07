#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    // выделяем память для 1-го объекта int
    int size = sizeof(int);
    int *ptr = malloc(size);
    if(ptr)
    {
        // отображаем адрес и размер памяти
        printf("Addresss: %p \t Size: %d\n", (void*)ptr, size);
    }
    // расширяем память до размера 4-х объектов int
    size = 4 * sizeof(int);
    int *ptr_new = realloc(ptr, size);
    // если выделение памяти прошло успещно
    if(ptr_new)
    {
        printf("Reallocation\n");
        // заново отображаем адрес и размер памяти
        printf("Addresss: %p \t Size: %d\n", (void*)ptr_new, size);
        free(ptr_new);  // освобождаем новый указатель
    }
    else
    {
        free(ptr);  // освобождаем старый указатель
    }
    return 0;
}