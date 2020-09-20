#ifndef H_VECTOR
#define H_VECTOR

#include <ostream>

struct Vector {

  float x, y, z, w;

  Vector(float, float, float, float);
  Vector(float, float, float);
  Vector(const Vector &);

  bool operator==(const Vector &) const;

  Vector operator-() const;

  void operator+=(const Vector &);
  Vector operator+(const Vector &) const;

  void operator-=(const Vector &);
  Vector operator-(const Vector &) const;

  void operator*=(float);
  Vector operator*(float) const;
  void operator*=(const Vector &);
  Vector operator*(const Vector &) const;

  void operator/=(float);
  Vector operator/(float) const;

  float magnitude() const;

  Vector normalize();

  float dot(const Vector &) const;

  Vector cross(const Vector &) const;

  friend std::ostream& operator<<(std::ostream& os, const Vector&);
};

#endif
