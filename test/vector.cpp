#include "gtest/gtest.h"
#include "vector.hpp"

TEST(Vector, Creation) {
  const Vector v1 = Vector(1, 2, 3, 4);
  EXPECT_EQ(v1.x, 1);
  EXPECT_EQ(v1.y, 2);
  EXPECT_EQ(v1.z, 3);
  EXPECT_EQ(v1.w, 4);

  const Vector v2 = Vector(3, 2, 1);
  EXPECT_EQ(v2.x, 3);
  EXPECT_EQ(v2.y, 2);
  EXPECT_EQ(v2.z, 1);
  EXPECT_EQ(v2.w, 0);
}

TEST(Vector, Equality) {
  const Vector v1 = Vector(1, 2, 3, 4);
  const Vector v2 = Vector(1, 2, 3, 4);
  EXPECT_EQ(v1, v2);
}

TEST(Vector, Negation) {
  const Vector v1 = -Vector(-1,  2, -3,  4);
  const Vector v2 =  Vector( 1, -2,  3, -4);
  EXPECT_EQ(v1, v2);
}

TEST(Vector, Addition) {
  const Vector v1 = Vector(1, 2, 3, 4);
  const Vector v2 = Vector(4, 3, 2, 1);
  const Vector vSum = Vector(5, 5, 5, 5);
  EXPECT_EQ(v1 + v2, vSum);

  Vector v = v1;
  v += v2;
  EXPECT_EQ(v, vSum);
}

TEST(Vector, Subtraction) {
  const Vector v1 = Vector(1, 2, 3, 4);
  const Vector v2 = Vector(4, 3, 2, 1);
  const Vector vDiff = Vector(-3, -1, 1, 3);
  EXPECT_EQ(v1 - v2, vDiff);

  Vector v = v1;
  v -= v2;
  EXPECT_EQ(v, vDiff);
}

TEST(Vector, MultiplicationByScalar) {
  const Vector v1 = Vector(1, 2, 3, 4);
  const Vector v2 = Vector(2, 4, 6, 8);
  EXPECT_EQ(v1 * 2, v2);

  Vector v(v1);
  v *= 2;
  EXPECT_EQ(v, v2);
}

TEST(Vector, MultiplicationByVector) {
  const Vector v1 = Vector(1, 2, 3, 4);
  const Vector v2 = Vector(4, 3, 2, 1);
  const Vector vMult = Vector(4, 6, 6, 4);
  EXPECT_EQ(v1 * v2, vMult);

  Vector v(v1);
  v *= v2;
  EXPECT_EQ(v, vMult);
}

TEST(Vector, DivizionByScalar) {
  const Vector v1 = Vector(2, 4, 6, 8);
  const Vector v2 = Vector(1, 2, 3, 4);
  EXPECT_EQ(v1 / 2, v2);

  Vector v(v1);
  v /= 2;
  EXPECT_EQ(v, v2);
}

TEST(Vector, Magnitude) {
  EXPECT_EQ(Vector(1, 0, 0, 0).magnitude(), 1);
  EXPECT_EQ(Vector(0, 1, 0, 0).magnitude(), 1);
  EXPECT_EQ(Vector(0, 0, 1, 0).magnitude(), 1);
  EXPECT_EQ(Vector(0, 0, 0, 1).magnitude(), 1);

  EXPECT_FLOAT_EQ(Vector(1, 2, 3, 5).magnitude(),     6.245);
  EXPECT_FLOAT_EQ(Vector(-1, -2, -3, -5).magnitude(), 6.245);
}

TEST(Vector, Normalization) {
  EXPECT_EQ(Vector(2, 0, 0, 0).normalize(), Vector(1, 0, 0, 0));
  EXPECT_EQ(Vector(0, 2, 0, 0).normalize(), Vector(0, 1, 0, 0));
  EXPECT_EQ(Vector(0, 0, 2, 0).normalize(), Vector(0, 0, 1, 0));
  EXPECT_EQ(Vector(0, 0, 0, 2).normalize(), Vector(0, 0, 0, 1));

  EXPECT_EQ(Vector(1, 2, 3, 5).normalize().magnitude(), 1);
}

TEST(Vector, DotProduct) {
  const Vector vp1 = Vector(1, 2, 3);
  const Vector vp2 = Vector(2, 4, 6);
  EXPECT_EQ(vp1.dot(vp2), 28);

  const Vector vn1 = Vector(1, 2,  3);
  const Vector vn2 = Vector(1, 2, -3);
  EXPECT_EQ(vn1.dot(vn2), -4);

  const Vector vz1 = Vector(1, 0, 0);
  const Vector vz2 = Vector(0, 1, 0);
  EXPECT_EQ(vz1.dot(vz2), 0);
}

TEST(Vector, CrossProduct) {
  const Vector v1 = Vector(1, -5,  3);
  const Vector v2 = Vector(0,  4, -4);
  const Vector vCross = Vector(8, 4, 4);
  EXPECT_EQ(v1.cross(v2), vCross);
}
