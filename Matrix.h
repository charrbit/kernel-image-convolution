#ifndef _MATRIX
#define _MATRIX

#include <iostream>


class Matrix
{
    int row;
    int col;

    double** matrix;

public:
    Matrix() : row(0), col(0), matrix(nullptr) {}

    Matrix(int r, int c);

    Matrix(int n) : Matrix(n, n) {};

    Matrix(std::istream& inp, int r, int c);

    Matrix(std::istream& inp, int n) : Matrix(inp, n, n) {};

    ~Matrix();

    int getRow() { return row; }
    int getCol() { return col; }
    
    int get(int r, int c) { return matrix[r][c]; }
    void set(int r, int c, int val) { matrix[r][c] = val; }

    friend std::ostream& operator<<(std::ostream& stream, const Matrix& aMatrix);
};
#endif