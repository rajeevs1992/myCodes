/**
    Note: The arrays are implemented as Ragged Arrays
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DIMENSION 64     // Dimension for the matrix to be defined

int determinant(int **matrix, int dimension);
int getAt(int **m, int i, int j);
void putAt(int **m, int i, int j, int value);
int **randomMatrix(int dimension);
int **copyMatrix(int **matrix, int dimension);
void deleteMatrix(int **matrix, int dimension);
void swapRows(int **m, int a, int b);

int main(){
    int **matrix;     // matrix is a pointer to pointer
    int det;
    int dim;
    scanf("%d",&dim);
    
    matrix = randomMatrix(dim);
    det = determinant(matrix, dim);
    
    printf("%d\n", det);   
    return 0;
}

int determinant(int **matrix, int dimension){
    int i, j, k, p, swapCount=0, determinantFactor=1;
    int a, ajj, result, value;
	int swapee = 0;		// used to indicate row to swap
    int **m = NULL;

    // Let us copy the matrix first
    m = copyMatrix(matrix, dimension);

    // First step: perform LU Decomposition using Doolittle's Method
    // This algorithm will return, in the same matrix, a lower unit triangular matrix
    // (i.e. diagonals one)
    // and an upper trangular matrix
    // https://vismor.com/documents/network_analysis/matrix_algorithms/S4.SS2.php

    for (i = 0; i < dimension; i++){
        for (j = 0; j < i; j++){
            ajj = getAt(m,j,j);

            // a number we are dividing by is zero.
            // we thus have to do a partial pivot
            if (ajj == 0){
                if (swapCount == dimension){
                    // Seems like we have exhaused all swaps
                    return NAN;
                }

                // Let's find a swap row to swap
                result = -INFINITY;
                for (k = 0; k < dimension; k++){
                    value = getAt(m, k, j);
                    if (value > result){
                        result = value;
                        swapee = k;
                    }
                }
				// Swap rows
				swapRows(m, j, swapee);              
                swapCount++;
                determinantFactor *= -1;

                ajj = getAt(m,j,j);
            }

            a = getAt(m, i, j);
            for (p = 0; p < j; p++){
                a -= getAt(m, i, p) * getAt(m, p, j);
            }
            putAt(m, i, j, a/ajj);
        }
        for (j = i; j < dimension; j++){
            a = getAt(m, i, j);
            for (p = 0; p < i; p++){
                a -= getAt(m, i, p) * getAt(m, p, j);
            }
            putAt(m, i, j, a);
        }
    }

    // Second step is to find the determinant.
    // Because the lower triangle is a unit triangular matrix
    // the determinant is simply a product of all the upper triangle diagonal
    // which in this case is exactly the diagonal of m
    result = determinantFactor;
    for (i = 0; i < dimension; i++)
        result *= getAt(m, i, i);

    deleteMatrix(m, dimension);
	
    return result;
}

// Based on i and j, and a int pointer, get the value at row i column j
int getAt(int **m, int i, int j){
    return *(*(m + i) + j);
}

// Based on i and j, and a int pointer, put the value at row i column j
void putAt(int **m, int i, int j, int value){
    *( (*(m+i)) + j ) = value;
} 

// Generate a n by n matrix consisting of numbers between -1 and 1.
// Outputs in a Matlab format, good for checking in Matlab
int **randomMatrix(int dimension){
    int i, j;
    int **matrix;
    int *row;
    int no;

    // let's first initialise the ragged array
    // initialise Ragged Array
    matrix = (int **) malloc(dimension*sizeof(int *));


    for (i = 0; i < dimension; i++){
        // Initialise this row
        row = (int *) malloc(dimension*sizeof(int));
        *(matrix + i) = row;

        // random no between -1 and 1
        for (j = 0; j < dimension; j++){
            scanf("%d",&no);
             *(row + j) = no;
        }
    }

    return matrix;
}

// copy matrix (ragged array)
int **copyMatrix(int **matrix, int dimension){
    int i;
    int **copy = (int **) malloc(dimension*sizeof(int *));

    for (i = 0; i < dimension; i++){
        // allocate memory for row
        *(copy + i) = (int *) malloc(dimension*sizeof(int));
        // copy row
        memcpy( *(copy +i), *(matrix + i), sizeof(int)*dimension );
    }

    return copy;
}

// delete matrix (ragged array)
void deleteMatrix(int **matrix, int dimension){
    int i;
    for (i = 0; i <dimension; i++){
        free( *(matrix+i));
    }
	free(matrix);
}

// swap rows -- ragged array. swap rows a and b
void swapRows(int **matrix, int a, int b){
	 int *swapRowTemp = *( matrix + a );
	 *( matrix + a ) = *( matrix + b );
	 *( matrix + b ) = swapRowTemp;
}
