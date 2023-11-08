#include <stdio.h>
#include <stdlib.h>

int array_rows(int **table, int *rows, int n, int m, int i, int j);

int main(void)
{
    int **table;    // указатель для блока памяти для массива указателей
    int *rows;      // указатель для блока памяти для хранения информации по строкам
 
    int n, m = 0; // Последнее число
    int i, j = 0; // Текущее число
    // ввод количества строк
    printf("Rows count=");
    scanf("%d", &n);
    // выделяем память для двухмерного массива
    table = calloc(n, sizeof(int*));
    rows = malloc(sizeof(int)*n);

    matrix(table, rows, n, m, i, j);    
    // освобождение памяти
    free(table);
    free(rows);
 
    return 0;
}

int matrix(int **table, int *rows, int n, int m, int i, int j){
    if(i<n&&!table[i]){
        printf("\nColumns count for row %d=", i);
        scanf("%d", &rows[i]);
        table[i] = calloc(rows[i], sizeof(int));
        int j=0;
        matrix_table(table, rows, n, m, i, j);
        i++;
        matrix(table, rows, n, m, i, j);
    }
    else if(i<n&&table[i]) {
        printf('\n');
        matrix_table(table, rows, n, m, i, j);
    }
    else{
        i=0;
        free(table[i]);
    }
    return 0;
}

int matrix_table(int **table, int *rows, int n, int m, int i, int j) {
    if(j<rows[i]&&!table[i][j]){
        printf("table[%d][%d]=", i, j);
        scanf("%d", &m);
        table[i][j] = m;
    }
    else if(j<rows[i]&&table[i][j]) {
        printf("%d \t", table[i][j]);
    }
    else{
        j=0;
    }
    return 0;
}