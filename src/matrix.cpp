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

Vector Matrix::operator*(Vector v) const {
  if (cols != rows || cols != 4)
    throw;
  return *(new Vector(
    v.x * get(0, 0) + v.y * get(1, 0) + v.z * get(2, 0) + v.w * get(3, 0),
    v.x * get(0, 1) + v.y * get(1, 1) + v.z * get(2, 1) + v.w * get(3, 1),
    v.x * get(0, 2) + v.y * get(1, 2) + v.z * get(2, 2) + v.w * get(3, 2),
    v.x * get(0, 3) + v.y * get(1, 3) + v.z * get(2, 3) + v.w * get(3, 3)
  ));
}

Matrix Matrix::transpose() const {
  Matrix neu = *(new Matrix(rows, cols));
  for (int j = 0; j < rows; j++)
    for (int i = 0; i < cols; ++i)
      neu.set(j, i, get(i, j));
  return neu;
}

Matrix Matrix::submatrix(int col2remove, int row2remove) const {
  Matrix neu = *(new Matrix(cols - 1, rows - 1));
  for (int j = 0; j < rows; j++) {
    if (j == row2remove)
      continue;
    for (int i = 0; i < cols; ++i) {
      if (i == col2remove)
        continue;
      neu.set(
        i < col2remove ? i : i - 1,
        j < row2remove ? j : j - 1,
        get(i, j)
      );
    }
  }
  return neu;
}

float Matrix::minor(int col, int row) const {
  return submatrix(col, row).determinant();
}

float Matrix::cofactor(int col, int row) const {
  float m = minor(col, row);
  return (col + row) % 2 == 0 ? m : -m;
}

float Matrix::determinant() const {
  if (cols != rows)
    throw;
  float result = 0;
  if (cols == 2)
    result = get(0, 0) * get(1, 1) - get(1, 0) * get(0, 1);
  else for (int i = 0; i < cols; ++i)
    result += get(i, 0) * cofactor(i, 0);
  return result;
}

Matrix Matrix::inverse() const {
  Matrix neu = *(new Matrix(cols, rows));
  float det = determinant();
  for (int j = 0; j < rows; j++)
    for (int i = 0; i < cols; ++i)
      neu.set(i, j, cofactor(j, i) / det);
  return neu;
}

/*
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
