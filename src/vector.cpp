#include "vector.hpp"
#include <cmath>

Vector::Vector(float x, float y, float z, float w)
  : x(x), y(y), z(z), w(w) { }

Vector::Vector(float x, float y, float z)
  : x(x), y(y), z(z), w(0) { }

Vector::Vector(const Vector &v)
  : x(v.x), y(v.y), z(v.z), w(v.w) { }

bool Vector::operator==(const Vector &v) const {
  return
    v.x == x &&
    v.y == y &&
    v.z == z &&
    v.w == w;
}

Vector Vector::operator-() const {
  return Vector(-x, -y, -z, -w);
}

void Vector::operator+=(const Vector &v) {
  x += v.x;
  y += v.y;
  z += v.z;
  w += v.w;
}

Vector Vector::operator+(const Vector &v) const {
  Vector res(*this);
  res += v;
  return res;
}

void Vector::operator-=(const Vector &v) {
  x -= v.x;
  y -= v.y;
  z -= v.z;
  w -= v.w;
}

Vector Vector::operator-(const Vector &v) const {
  Vector res(*this);
  res -= v;
  return res;
}

void Vector::operator*=(float scalar) {
  x *= scalar;
  y *= scalar;
  z *= scalar;
  w *= scalar;
}

Vector Vector::operator*(float scalar) const {
  Vector res(*this);
  res *= scalar;
  return res;
}

void Vector::operator*=(const Vector &v) {
  x *= v.x;
  y *= v.y;
  z *= v.z;
  w *= v.w;
}

Vector Vector::operator*(const Vector &v) const {
  Vector res(*this);
  res *= v;
  return res;
}

void Vector::operator/=(float scalar) {
  x /= scalar;
  y /= scalar;
  z /= scalar;
  w /= scalar;
}

Vector Vector::operator/(float scalar) const {
  Vector res(*this);
  res /= scalar;
  return res;
}

float Vector::magnitude() const {
  return std::sqrt(x * x + y * y + z * z + w * w);
}

Vector Vector::normalize() {
  float m = magnitude();
  operator/=(m);
  return *this;
}

float Vector::dot(const Vector &v) const {
  return x * v.x + y * v.y + z * v.z + w * v.w;
}

Vector Vector::cross(const Vector &v) const {
  return Vector(
    y * v.z - z * v.y,
    z * v.x - x * v.z,
    x * v.y - y * v.x,
    0
  );
}
