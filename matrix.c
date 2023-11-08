#include <stdio.h>
#include <stdlib.h>

int array_rows(int **table, int *rows, int rowscount, int i);

int main(void)
{
    int **table;    // указатель для блока памяти для массива указателей
    int *rows;      // указатель для блока памяти для хранения информации по строкам
 
    int rowscount;  // количество строк
    int d;      // вводимое число
    int i, j=0;
    // ввод количества строк
    printf("Rows count=");
    scanf("%d", &rowscount);
 
    // выделяем память для двухмерного массива
    table = calloc(rowscount, sizeof(int*));
    rows = malloc(sizeof(int)*rowscount);

    matrix(table, rows, d, rowscount, i);    
    // освобождение памяти
    free(table);
    free(rows);
 
    return 0;
}

int matrix(int **table, int *rows, int d, int rowscount, int i){
    if(i<rowscount&&!table[i]){
        printf("\nColumns count for row %d=", i);
        scanf("%d", &rows[i]);
        table[i] = calloc(rows[i], sizeof(int));
        int j=0;
        matrix_table(table, rows, d, i, j);
        i++;
        matrix(table, rows, d, i, j);
    }
    else if(i<rowscount&&table[i]) {
        printf('\n');
        matrix_table(table, rows, d, i, j);
    }
    else{
        i=0;
        free(table[i]);
    }
    return 0;
}

int matrix_table(int **table, int *rows, int d, int i, int j) {
    if(j<rows[i]&&!table[i][j]){
        printf("table[%d][%d]=", i, j);
        scanf("%d", &d);
        table[i][j] = d;
    }
    else if(j<rows[i]&&table[i][j]) {
        printf("%d \t", table[i][j]);
    }
    else{
        j=0;
    }
    return 0;
}