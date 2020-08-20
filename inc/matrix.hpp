#ifndef H_MATRIX
#define H_MATRIX

#include "vector.hpp"

class Matrix {

  int rows, cols;
  float *m;

public:

  Matrix(int rows, int cols);
  static Matrix* identity(int size);

  int length() const;

  float get(int row, int col) const;
  void set(int row, int col, float value);

  bool operator==(Matrix) const;
  Matrix operator*(Matrix) const;
  Vector operator*(Vector) const;

  Matrix transpose();
  Matrix inverse();
  float determinant() const;
  float minor(int row, int col) const;
  Matrix submatrix(int row2remove, int col2remove) const;
};

#endif
