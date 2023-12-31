#include "Matrix.h"

// Constructor definition for square and non-square user-populated Matrix
Matrix::Matrix(int numRows, int numCols) : n_rows(numRows), n_cols(numCols) {
    matrix_data = new double*[numRows];
    for (int row = 0; row < numRows; row++) {
        matrix_data[row] = new double[numCols];
        for (int col = 0; col < numCols; col++) {
            // Assign the current matrix element a default value of 0
            matrix_data[row][col] = 0;
        }
    }    
}

// Constructor definition for square and non-square file-populated Matrix
Matrix::Matrix(int numRows, int numCols, std::istream& inputMatrix) : n_rows(numRows), n_cols(numCols) {
    matrix_data = new double*[numRows];
    for (int row = 0; row < numRows; row++) {
        matrix_data[row] = new double[numCols];
        for (int col = 0; col < numCols; col++) {
            // Read the next input value into the current matrix element
            inputMatrix >> matrix_data[row][col];
        }
    }   
}

Matrix::~Matrix() {
    for (int i = 0; i < n_rows; i++) {
        delete [] matrix_data[i];
    }
    delete [] matrix_data;
}

std::ostream& operator<<(std::ostream& outputStream, const Matrix& Matrix) {
    for (int row = 0; row < Matrix.n_rows; row++) {
        for (int col = 0; col < Matrix.n_cols; col++) {
            outputStream << Matrix.matrix_data[row][col] << " ";
        }
    }

    return outputStream;
}