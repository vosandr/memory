#include <stdio.h>
#include <stdlib.h>

int matrix_n(int **table, int *rows,  int i, int j, int n, int m, int tmp);
int matrix_m(int **table, int *rows, int i, int j, int n, int m, int tmp);

int main(void)
{
    int **table;    // указатель для блока памяти для массива указателей
    int *rows;      // указатель для блока памяти для хранения информации по строкам
    int tmp=0; // вводилось ли значение
    int n, m = 0; // Последнее число
    int i, j = 0; // Текущее число
    // ввод количества строк
    printf("Rows count=");
    scanf("%d", &n);
    // выделяем память для двухмерного массива
    table = calloc(n, sizeof(int*));
    rows = malloc(sizeof(int)*n);

    matrix_n(table, rows, i, j, n, m, tmp);
    matrix_n(table, rows, i, j, n, m, tmp);
    // освобождение памяти
    free(table);
    free(rows);
 
    return 0;
}

int matrix_n(int **table, int *rows, int i, int j, int n, int m, int tmp){
    if(i<n&&tmp==0){
        printf("\nColumns count for row %d=", i);
        scanf("%d", &rows[i]);
        table[i] = calloc(rows[i], sizeof(int));
        int j=0;
        matrix_m(table, rows, n, m, i, j, tmp);
        i++;
        matrix_n(table, rows, n, m, i, j, tmp);
    }
    else if(i<n&&tmp==1) {
        printf("\n");
        matrix_m(table, rows, n, m, i, j, tmp);
        i++;
        matrix_n(table, rows, n, m, i, j, tmp);
    }
    else{
        i=0;
        free(table[i]);
    }
    tmp=1;
    return 0;
}

int matrix_m(int **table, int *rows, int i, int j, int n, int m, int tmp) {
    if(j<rows[i]&&tmp==0){
        printf("table[%d][%d]=", i, j);
        scanf("%d", &m);
        table[i][j] = m;
        j++;
        matrix_m(table, rows, i, j, n, m, tmp);
    }
    else if(j<rows[i]&&tmp==1) {
        printf("%d \t", table[i][j]);
        j++;
        matrix_m(table, rows, n, m, i, j, tmp);

    }
    else{
        j=0;
    }
    return 0;
}