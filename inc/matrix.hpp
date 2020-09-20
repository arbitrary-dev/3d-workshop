#ifndef H_MATRIX
#define H_MATRIX

#include "vector.hpp"
#include <vector>
#include <ostream>

class Matrix {

  int cols, rows;
  float *m;

public:

  Matrix(int cols, int rows);
  static Matrix* identity(int size);

  int length() const;

  float get(int col, int row) const;
  void set(int col, int row, float value);
  Matrix fill(std::vector<float>);

  bool operator==(const Matrix &) const;
  bool operator!=(const Matrix &) const;
  Matrix operator*(Matrix) const;
  Vector operator*(Vector) const;

  Matrix transpose() const;
  Matrix submatrix(int col2remove, int row2remove) const;
  float cofactor(int col, int row) const;
  float minor(int col, int row) const;
  float determinant() const;
  Matrix inverse() const;

  friend std::ostream& operator<<(std::ostream& os, const Matrix&);
};

#endif
