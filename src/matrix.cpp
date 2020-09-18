#include "matrix.hpp"
#include "vector.hpp"
#include <cstdlib>
//#include "glog/logging.h"

Matrix::Matrix(int cols, int rows)
  : cols(cols)
  , rows(rows)
{
  m = (float *) calloc(cols * rows, sizeof(float));
}

Matrix* Matrix::identity(int size) {
  Matrix *m = new Matrix(size, size);
  for (int i = 0; i < size; ++i)
    m->set(i, i, 1);
  return m;
}

int Matrix::length() const {
  return cols * rows;
}

float Matrix::get(int col, int row) const {
  return m[row * cols + col];
}

void Matrix::set(int col, int row, float value) {
  m[row * cols + col] = value;
}

Matrix Matrix::fill(std::vector<float> v) {
  int i = 0;
  for (float f : v) {
    m[i++] = f;
    if (i == rows * cols)
      break;
  }
  return *this;
}

bool Matrix::operator==(const Matrix &that) const {
  if (rows != that.rows || cols != that.cols)
    return false;
  for (int i = 0; i < rows * cols; ++i) {
    // LOG(INFO) << m[i] << "?" << that.m[i];
    if (m[i] != that.m[i])
      return false;
  }
  return true;
}

bool Matrix::operator!=(const Matrix &that) const {
  return !(*this == that);
}

Matrix Matrix::operator*(const Matrix that) const {
  if (cols != that.rows)
    throw;
  Matrix *neu = new Matrix(that.cols, rows);
  for (int j = 0; j < rows; j++)
    for (int i = 0; i < that.cols; ++i) {
      float v = 0;
      for (int k = 0; k < cols; k++)
        v += get(k, j) * that.get(i, k);
      neu->set(i, j, v);
    }
  return *neu;
}

Vector Matrix::operator*(Vector) const {
  // TODO
  return *(new Vector(1, 2, 3, 4));
}

Matrix Matrix::transpose() {
  int L = length();
  float *neu = (float *) malloc(L * sizeof(float));

  for (int i = 0; i < L; ++i) {
    int col = i % cols;
    int row = i / cols;
    neu[col * rows + row] = m[i];
  }
  free(m);
  m = neu;

  int temp = cols;
  cols = rows;
  rows = temp;

  return *this;
}

/*
function determinant(m:Matrix): Float {
var det:Float = 0;
if (m.length == 4) {
det = m.get(0, 0) * m.get(1, 1) - m.get(0, 1) * m.get(1, 0);
} else {
for (column in 0...m.columns) {
det += m.get(0, column) * cofactor(m, 0, column);
}
}
return det;
}

function cofactor(m:Matrix, row:UInt, column:UInt):Float {
final minorValue = minor(m, row, column);
return (row + column) % 2 == 0 ? minorValue : minorValue * -1;
}

function minor(m:Matrix, row:UInt, column:UInt):Float {
return determinant(submatrix(m, row, column));
}

function inverse(m:Matrix):Matrix {
final out = new Matrix(m.rows, m.columns);
final det = determinant(m);
for (row in 0...m.rows) {
for (column in 0...m.columns) {
out.set(column, row, cofactor(m, row, column) / det);
}
}
return out;
}
￼
*/

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
  for (int j = 0; j < m.rows; ++j)
    for (int i = 0; i < m.cols; ++i) {
      if (i == 0)
        os << "\n";
      os << " " << m.get(i, j);
    }
  return os;
}
