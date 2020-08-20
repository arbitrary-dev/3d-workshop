#include "gtest/gtest.h"
#include "matrix.hpp"

TEST(Matrix, Creation) {
  const Matrix *m = new Matrix(4, 4);
  EXPECT_EQ(m->length(), 16);
  // TODO all cells should be 0
}

TEST(Matrix, Identity) {
  const Matrix *m = Matrix::identity(4);
  EXPECT_EQ(m->length(), 16);
  EXPECT_EQ(m->get(0, 0), 1);
  EXPECT_EQ(m->get(1, 1), 1);
  EXPECT_EQ(m->get(2, 2), 1);
  EXPECT_EQ(m->get(3, 3), 1);
}

TEST(Matrix, DISABLED_Equality) {
  // TODO
}

TEST(Matrix, DISABLED_Transpose) {
  /*
   * final m = matrix(4, 4).fill([1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 0, 0, 0, 1]);
   * final transposedM = matrix(4, 4).fill([1, 5, 1, 0, 2, 6, 2, 0, 3, 7, 3, 0, 4, 8, 4, 1, 4, 4]);
   * final result = m.transpose();
   * result.should.equal(transposedM);
   * });
   * it("should transpose identity matrix", {
   * final m = identityMatrix(4, 4);
   * final result = m.transpose();
   * result.should.equal(m);
   *
   */
}

TEST(Matrix, DISABLED_Multiplication) {
  /* it("should multiplay 2 4x4 matrices", {
final a = matrix(4, 4).fill([1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8]);
final b = matrix(4, 4).fill([-1, 2, -3, 4, -5, 6, -7, 8, -1, 2, -3, 4, -5, 6, -7, 8]);
final output = matrix(4, 4).fill([
-34, 44, -54, 64, -82, 108, -134, 160, -34, 44, -54, 64, -82, 108, -134, 160, 4, 4
]);
final result = a * b;
result.should.equal(output);
});
*/
}

TEST(Matrix, DISABLED_MultByIdentity) {
  /* it("should multiplay matrix with identity matrix", {
final m = matrix(4, 4).fill([1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 0, 0, 0, 1]);
final identityMatrix = identityMatrix(4, 4);
final result = m * identityMatrix;
result.should.equal(m);
});
*/
}

TEST(Matrix, DISABLED_MultByVector) {
  /*
it("should multiplay matrix and vector", {
finalm=matrix(4, 4).fill([1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 0, 0, 0, 1]);
finalt=vector(1, 2, 3, 1);
finaloutput=vector(18, 46, 18, 1);
finalresult=m*t;
result.should.equal(output);
 });

it("shoul multiplay identity matrix by vector", {
finalv=vector(1, 2, 3, 4);
finalidentityMatrix=identityMatrix(4, 4);
finalresult=identityMatrix*v;
result.should.equal(v);
 });
*/
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
