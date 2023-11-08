#include <stdio.h>
#include <stdlib.h>

int matrix_n(int **table, int *rows,  int i, int j, int n, int m);
int matrix_m(int **table, int *rows, int i, int j, int n, int m);

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

    matrix_n(table, rows, i, j, n, m);    
    // освобождение памяти
    free(table);
    free(rows);
 
    return 0;
}

int matrix_n(int **table, int *rows, int i, int j, int n, int m){
    if(i<n&&table[i]==NULL){
        printf("\nColumns count for row %d=", i);
        scanf("%d", &rows[i]);
        table[i] = calloc(rows[i], sizeof(int));
        int j=0;
        matrix_m(table, rows, n, m, i, j);
        i++;
        matrix_n(table, rows, n, m, i, j);
    }
    else if(i<n&&table[i]!=NULL) {
        printf("\n");
        matrix_m(table, rows, n, m, i, j);
    }
    else{
        i=0;
        free(table[i]);
    }
    return 0;
}
int matrix_n_out(){
    if (i<n){
        printf("\n");
        matrix_m_out();
        matrix_n_out();
        i++;
    }
}

int matrix_m(int **table, int *rows, int i, int j, int n, int m) {
    if(j<rows[i]&&!table[i][j]==NULL){
        printf("table[%d][%d]=", i, j);
        scanf("%d", &m);
        table[i][j] = m;
    }
    else if(j<rows[i]&&table[i][j]!=NULL) {
        printf("%d \t", table[i][j]);
    }
    else{
        j=0;
    }
    return 0;
}
int matrix_m_out(){
    if (i<m){
        printf("%d \t", table[i][j]);
    }
};