#ifndef _MATRIX
#define _MATRIX

#include <iostream>


class Matrix
{
    int n_rows;
    int n_cols;

    double** matrix_data;

public:
    Matrix() : n_rows(0), n_cols(0), matrix_data(nullptr) {}

    Matrix(int numRows, int numCols);

    Matrix(int numRowsCols) : Matrix(numRowsCols, numRowsCols) {};

    Matrix(int numRows, int numCols, std::istream& inputMatrix);

    Matrix(int numRowsCols, std::istream& inputMatrix) : Matrix(numRowsCols, numRowsCols, inputMatrix) {};

    ~Matrix();

    int getRowCount() { return n_rows; }
    int getColCount() { return n_cols; }
    
    int get(int row, int col) { return matrix_data[row][col]; }
    void set(int row, int col, int val) { matrix_data[row][col] = val; }

    friend std::ostream& operator<<(std::ostream& outputStream, const Matrix& Matrix);
};
#endif