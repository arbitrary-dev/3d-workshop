#include "matrix.hpp"
#include <cstdlib>

Matrix::Matrix(int rows, int cols)
  : rows(rows)
  , cols(cols)
{
  m = (float *) malloc((rows * cols) * (sizeof(float)));
}

Matrix* Matrix::identity(int size) {
  Matrix *m = new Matrix(size, size);
  for (int i = 0; i < size; ++i)
    m->set(i, i, 1);
  return m;
}

int Matrix::length() const {
  return rows * cols;
}

float Matrix::get(int row, int col) const {
  return m[row * cols + col];
}

void Matrix::set(int row, int col, float value) {
  m[row * cols + col] = value;
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
