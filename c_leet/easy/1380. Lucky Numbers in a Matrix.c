#include <stdlib.h>
#include <stdio.h>

/**
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers (int** matrix, int matrixSize, int matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = *matrixColSize;

    int* result = (int*) malloc(m*sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < m; i++){
        int min = matrix[i][0];
        int minColIdx = 0;

        for (int j = 1; j < n; j++){
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                minColIdx = j;
            }
        }

        int isLucky = 1;
        for (int j = 0; j < m; j++){
            if (matrix[j][minColIdx] > min){
                isLucky = 0;
                break;
            }
        }

        if (isLucky){
            result[*returnSize] = min;
            (*returnSize)++;
        }
    }
    return result;
}


int main() {
    const int n=3, m=3;
    int** matrix = (int**) malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++){
        matrix[i] = (int*)malloc(n*sizeof(int));
    }
    matrix[0][0] = 3; matrix[0][1] = 7; matrix[0][2] = 8;
    matrix[1][0] = 9; matrix[1][1] = 11; matrix[1][2] = 13;
    matrix[2][0] = 15; matrix[2][1] = 16; matrix[2][2] = 17;
    printf("\nn: %d; m: %d\n", n, m);
    printf("Matrix: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int returnSize;
    int* result = luckyNumbers(matrix, n, m, &returnSize);
    for (int i = 0; i < n; i++){
        free( matrix[i] );
    }
    free( matrix );
    printf("Return size: %d\n", returnSize);
    printf("Result:");
    for (int i = 0; i < returnSize; i++){
        printf("%d ", result[i]);
    }
    printf("\n\n");
    free( result );
    return 0;
}