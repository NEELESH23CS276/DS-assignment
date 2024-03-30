#include <stdio.h>

#define MAX_TERMS 100

// Structure to represent a sparse matrix element
typedef struct {
    int row;
    int col;
    int value;
} Element;

// Structure to represent a sparse matrix
typedef struct {
    int rows;
    int cols;
    int terms; // Number of non-zero terms
    Element data[MAX_TERMS];
} SparseMatrix;

// Function to display the sparse matrix
void display(SparseMatrix matrix) {
    printf("Sparse Matrix:\n");
    printf("Rows: %d, Cols: %d, Non-Zero Terms: %d\n", matrix.rows, matrix.cols, matrix.terms);
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < matrix.terms; i++) {
        printf("%d\t%d\t%d\n", matrix.data[i].row, matrix.data[i].col, matrix.data[i].value);
    }
}

// Function to add two sparse matrices
SparseMatrix add(SparseMatrix a, SparseMatrix b) {
    SparseMatrix result;
    int aPos = 0, bPos = 0, resultPos = 0;

    // Initialize the result matrix
    result.rows = a.rows;
    result.cols = a.cols;
    result.terms = 0;

    while (aPos < a.terms && bPos < b.terms) {
        if (a.data[aPos].row < b.data[bPos].row ||
            (a.data[aPos].row == b.data[bPos].row && a.data[aPos].col < b.data[bPos].col)) {
            result.data[resultPos++] = a.data[aPos++];
        } else if (a.data[aPos].row > b.data[bPos].row ||
                   (a.data[aPos].row == b.data[bPos].row && a.data[aPos].col > b.data[bPos].col)) {
            result.data[resultPos++] = b.data[bPos++];
        } else {
            result.data[resultPos].row = a.data[aPos].row;
            result.data[resultPos].col = a.data[aPos].col;
            result.data[resultPos++].value = a.data[aPos++].value + b.data[bPos++].value;
            result.terms++;
        }
    }

    // Add remaining elements of a, if any
    while (aPos < a.terms) {
        result.data[resultPos++] = a.data[aPos++];
    }

    // Add remaining elements of b, if any
    while (bPos < b.terms) {
        result.data[resultPos++] = b.data[bPos++];
    }

    result.terms = resultPos;
    return result;
}

// Function to multiply two sparse matrices
SparseMatrix multiply(SparseMatrix a, SparseMatrix b) {
    SparseMatrix result;
    int aRow, bCol, sum, cIndex;

    // Initialize the result matrix
    result.rows = a.rows;
    result.cols = b.cols;
    result.terms = 0;

    // Multiply matrices
    for (aRow = 0; aRow < a.terms; aRow += a.cols) {
        for (bCol = 0; bCol < b.terms; bCol += b.rows) {
            sum = 0;
            for (int i = 0; i < a.cols; i++) {
                sum += (a.data[aRow + i].value * b.data[bCol + i].value);
}
            if (sum != 0) {
                result.data[result.terms].row = a.data[aRow].row;
                result.data[result.terms].col = b.data[bCol].col;
                result.data[result.terms].value = sum;
                result.terms++;
}
}
}

    return result;
}

// Function to transpose a sparse matrix
SparseMatrix transpose(SparseMatrix matrix) {
    SparseMatrix result;
    int i, j, k;

    // Initialize the result matrix
    result.rows = matrix.cols;
    result.cols = matrix.rows;
    result.terms = matrix.terms;

    // Transpose the matrix
    if (matrix.terms > 0) {
        k = 0;
        for (i = 0; i < matrix.cols; i++) {
            for (j = 0; j < matrix.terms; j++) {
                if (matrix.data[j].col == i) {
                    result.data[k].row = matrix.data[j].col;
                    result.data[k].col = matrix.data[j].row;
                    result.data[k].value = matrix.data[j].value;
                    k++;
 }
 }
}
}

    return result;
}

// Main function
int main() {
    SparseMatrix matrix1 = {3, 3, 4, {{0, 0, 1}, {1, 1, 2}, {2, 0, 3}, {2, 2, 4}}};
    SparseMatrix matrix2 = {3, 3, 4, {{0, 1, 5}, {0, 2, 6}, {1, 0, 7}, {2, 1, 8}}};

    // Display original matrices
    printf("Matrix 1:\n");
    display(matrix1);
    printf("\nMatrix 2:\n");
    display(matrix2);

    // Perform addition
    SparseMatrix resultAdd = add(matrix1, matrix2);
    printf("\nAddition Result:\n");
    display(resultAdd);

    // Perform multiplication
    SparseMatrix resultMul = multiply(matrix1, matrix2);
    printf("\nMultiplication Result:\n");
    display(resultMul);

    // Perform transpose
    SparseMatrix resultTrans = transpose(matrix1);
    printf("\nTranspose Result:\n");
    display(resultTrans);

    return 0;
}
