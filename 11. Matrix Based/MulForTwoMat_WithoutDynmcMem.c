#include <stdio.h>

#define MAX_ROW_A 100
#define MAX_COL_A 100
#define MAX_ROW_B 100
#define MAX_COL_B 100

void matrix_multiply(int A[][MAX_COL_A], int B[][MAX_COL_B], int C[][MAX_COL_B], int row_A, int col_A, int row_B, int col_B) {
    if (col_A != row_B) {
        printf("Error: Number of columns in A is not equal to the number of rows in B.\n");
        return;
    }

    for (int i = 0; i < row_A; i++) {
        for (int j = 0; j < col_B; j++) {
            C[i][j] = 0;
            for (int k = 0; k < col_A; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX_ROW_A][MAX_COL_A] = {
        {1, 2},
        {3, 4}
    };

    int B[MAX_ROW_B][MAX_COL_B] = {
        {2, 0},
        {1, 3}
    };

    int C[MAX_ROW_A][MAX_COL_B];

    int row_A = 2; // Number of rows in matrix A
    int col_A = 2; // Number of columns in matrix A
    int row_B = 2; // Number of rows in matrix B
    int col_B = 2; // Number of columns in matrix B

    matrix_multiply(A, B, C, row_A, col_A, row_B, col_B);

    printf("Result:\n");
    for (int i = 0; i < row_A; i++) {
        for (int j = 0; j < col_B; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
