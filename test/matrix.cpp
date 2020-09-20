#include "gtest/gtest.h"
#include "matrix.hpp"

TEST(Matrix, Creation) {
  const Matrix *m = new Matrix(2, 3);
  EXPECT_EQ(m->length(), 6);
  EXPECT_EQ(m->get(0, 0), 0);
  EXPECT_EQ(m->get(1, 0), 0);
  EXPECT_EQ(m->get(2, 0), 0);
  EXPECT_EQ(m->get(0, 1), 0);
  EXPECT_EQ(m->get(1, 1), 0);
  EXPECT_EQ(m->get(2, 1), 0);
}

TEST(Matrix, Fill43) {
  const Matrix m = (new Matrix(4, 3))
    ->fill({
      1, 2, 3, 4,
      5, 6, 7, 8,
      1, 2, 3, 4,
    });

  EXPECT_EQ(m.get(0, 0), 1);
  EXPECT_EQ(m.get(1, 0), 2);
  EXPECT_EQ(m.get(2, 0), 3);
  EXPECT_EQ(m.get(3, 0), 4);

  EXPECT_EQ(m.get(0, 1), 5);
  EXPECT_EQ(m.get(1, 1), 6);
  EXPECT_EQ(m.get(2, 1), 7);
  EXPECT_EQ(m.get(3, 1), 8);

  EXPECT_EQ(m.get(0, 2), 1);
  EXPECT_EQ(m.get(1, 2), 2);
  EXPECT_EQ(m.get(2, 2), 3);
  EXPECT_EQ(m.get(3, 2), 4);
}

TEST(Matrix, Fill34) {
  const Matrix m = (new Matrix(3, 4))
    ->fill({
      1, 2, 3,
      4, 5, 6,
      7, 8, 9,
      1, 2, 3,
    });

  EXPECT_EQ(m.get(0, 0), 1);
  EXPECT_EQ(m.get(1, 0), 2);
  EXPECT_EQ(m.get(2, 0), 3);

  EXPECT_EQ(m.get(0, 1), 4);
  EXPECT_EQ(m.get(1, 1), 5);
  EXPECT_EQ(m.get(2, 1), 6);

  EXPECT_EQ(m.get(0, 2), 7);
  EXPECT_EQ(m.get(1, 2), 8);
  EXPECT_EQ(m.get(2, 2), 9);

  EXPECT_EQ(m.get(0, 3), 1);
  EXPECT_EQ(m.get(1, 3), 2);
  EXPECT_EQ(m.get(2, 3), 3);
}

TEST(Matrix, FillUnder) {
  const Matrix m = (new Matrix(3, 3))->fill({
    1, 2, 3,
    4, 5, 6,
    7, 8,
  });
  EXPECT_EQ(m.get(2, 2), 0);
}

TEST(Matrix, FillOver) {
  const Matrix m1 = (new Matrix(3, 3))->fill({
    1, 2, 3,
    4, 5, 6,
    7, 8, 9,
    10,
  });
  const Matrix m2 = (new Matrix(3, 3))->fill({
    1, 2, 3,
    4, 5, 6,
    7, 8, 9,
  });
  EXPECT_EQ(m1, m2);
}

TEST(Matrix, Identity) {
  const Matrix m1 = *Matrix::identity(4);
  const Matrix m2 = (new Matrix(4, 4))->fill({
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1,
  });
  EXPECT_EQ(m1.length(), 16);
  EXPECT_EQ(m1, m2);
}

TEST(Matrix, Equality) {
  Matrix *m1 = new Matrix(4, 4);
  m1->set(3, 1, 3.0);
  m1->set(0, 2, 2.0);
  m1->set(3, 3, 1.5);
  Matrix *m2 = new Matrix(4, 4);
  m2->set(3, 1, 3.0);
  m2->set(0, 2, 2.0);
  m2->set(3, 3, 1.5);
  EXPECT_EQ(*m1, *m2);
}

TEST(Matrix, NonEquality1) {
  Matrix *m1 = new Matrix(4, 4);
  m1->set(3, 1, 3.0);
  m1->set(0, 2, 2.0);
  m1->set(3, 3, 1.5);
  Matrix *m2 = new Matrix(4, 4);
  m2->set(3, 1, 3.0);
  m2->set(0, 2, 2.0);
  m2->set(3, 3, 4.5);
  EXPECT_NE(*m1, *m2);
}

TEST(Matrix, NonEquality2) {
  Matrix *m1 = new Matrix(4, 3);
  Matrix *m2 = new Matrix(2, 2);
  EXPECT_NE(*m1, *m2);
  EXPECT_NE(*m2, *m1); // Why isn't it failing?
}

TEST(Matrix, NonEquality3) {
  Matrix *m1 = new Matrix(3, 2);
  Matrix *m2 = new Matrix(2, 3);
  EXPECT_NE(*m1, *m2);
}

TEST(Matrix, Multiplication) {
  const Matrix m1 = (new Matrix(4, 4))
    ->fill({
      1, 2, 3, 4,
      5, 6, 7, 8,
      1, 2, 3, 4,
      5, 6, 7, 8,
    });
  const Matrix m2 = (new Matrix(4, 4))
    ->fill({
      -1, 2, -3, 4,
      -5, 6, -7, 8,
      -1, 2, -3, 4,
      -5, 6, -7, 8,
    });
  const Matrix expected = (new Matrix(4, 4))
    ->fill({
      -34, 44,  -54,  64,
      -82, 108, -134, 160,
      -34, 44,  -54,  64,
      -82, 108, -134, 160,
    });
  EXPECT_EQ(m1 * m2, expected);
}

TEST(Matrix, MultByIdentity) {
  const Matrix m = (new Matrix(4, 4))
    ->fill({
      1, 2, 3, 4,
      5, 6, 7, 8,
      1, 2, 3, 4,
      0, 0, 0, 1,
    });
  const Matrix id = *Matrix::identity(4);
  EXPECT_EQ(m * id, m);
}

TEST(Matrix, MultByVector) {
  const Matrix m = (new Matrix(4, 4))
    ->fill({
      1, 2, 3, 4,
      5, 6, 7, 8,
      1, 2, 3, 4,
      0, 0, 0, 1,
    });
  const Vector v = *(new Vector(1, 2, 3, 1));
  const Vector expected = *(new Vector(18, 46, 18, 1));
  EXPECT_EQ(m * v, expected);
}

TEST(Matrix, MultIdByVector) {
  const Matrix id = *(Matrix::identity(4));
  const Vector v = *(new Vector(1, 2, 3, 1));
  EXPECT_EQ(id * v, v);
}

TEST(Matrix, Transpose43) {
  const Matrix transposed = (new Matrix(4, 3))
    ->fill({
      1, 2, 3, 4,
      5, 6, 7, 8,
      1, 2, 3, 4,
    })
    .transpose();
  const Matrix expected = (new Matrix(3, 4))
    ->fill({
      1, 5, 1,
      2, 6, 2,
      3, 7, 3,
      4, 8, 4,
    });
  EXPECT_EQ(transposed, expected);
}

TEST(Matrix, Transpose34) {
  const Matrix transposed = (new Matrix(3, 4))
    ->fill({
      1, 2, 3,
      4, 5, 6,
      7, 8, 9,
      1, 2, 3,
    })
    .transpose();
  const Matrix expected = (new Matrix(4, 3))
    ->fill({
      1, 4, 7, 1,
      2, 5, 8, 2,
      3, 6, 9, 3,
    });
  EXPECT_EQ(transposed, expected);
}

TEST(Matrix, TransposeIdentity) {
  const Matrix transposed = Matrix::identity(4)->transpose();
  const Matrix expected = *Matrix::identity(4);
  EXPECT_EQ(transposed, expected);
}

TEST(Matrix, DISABLED_Inverse) {
  // TODO
}

TEST(Matrix, DISABLED_Determinant) {
  /*
it("should calculate determinant for 2x2", {
final m = matrix(2, 2).fill([1, 2, 3, 4]);
final result = m.determinant();
result.should.be(-2);
});
*/
}
