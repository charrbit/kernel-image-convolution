#include "Matrix.h"

Matrix::Matrix(int r, int c) : row(r), col(c) {
    matrix = new double*[r];
    for (int row = 0; row < r; row++) {
        matrix[row] = new double[c];
        for (int col = 0; col < c; col++) {
            matrix[row][col] = 0;
        }
    }    
}

Matrix::Matrix(std::istream& inp, int r, int c) : row(r), col(c) {
    matrix = new double*[r];
    for (int row = 0; row < r; row++) {
        matrix[row] = new double[c];
        for (int col = 0; col < c; col++) {
            inp >> matrix[row][col];
        }
    }   
}

Matrix::~Matrix() {
    for (int i = 0; i < row; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

std::ostream& operator<<(std::ostream& stream, const Matrix& aMatrix) {
    for (int r = 0; r < aMatrix.row; r++) {
        for (int c = 0; c < aMatrix.col; c++) {
            stream << aMatrix.matrix[r][c];
            if (c <= aMatrix.col - 1) {
                stream << ' ';
            }
        }
        stream << std::endl;
    }

    return stream;
}