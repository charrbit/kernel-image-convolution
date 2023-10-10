#ifndef _MATRIX
#define _MATRIX

#include <iostream>


class Matrix
{
    int n_rows;
    int n_cols;

    double** matrix_data;

public:
    /* Constructors */
    // Default Empty Matrix
    Matrix() : n_rows(0), n_cols(0), matrix_data(nullptr) {}

    // Non-Square Matrix with all element values defaulted to 0
    Matrix(int numRows, int numCols);

    // Square Matrix with all element values defaulted to 0
    Matrix(int numRowsCols) : Matrix(numRowsCols, numRowsCols) {};

    // Non-Square matrix with element values read from input stream
    Matrix(int numRows, int numCols, std::istream& inputMatrix);

    // Square matrix with element values read from input stream
    Matrix(int numRowsCols, std::istream& inputMatrix) : Matrix(numRowsCols, numRowsCols, inputMatrix) {};

    /* Destructor */
    ~Matrix();

    /* Getter Methods */
    int getRowCount() { return n_rows; }
    int getColCount() { return n_cols; }
    // Get an individual element value
    int get(int row, int col) { return matrix_data[row][col]; }

    /* Setter Method */
    // Set an individual element value
    void set(int row, int col, int val) { matrix_data[row][col] = val; }

    /* Overloaded Output Operator */
    friend std::ostream& operator<<(std::ostream& outputStream, const Matrix& Matrix);
};
#endif