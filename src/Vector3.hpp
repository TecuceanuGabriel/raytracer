#pragma once

#include <ostream>

class Vector3
{
  public:
	Vector3();
	Vector3(const double x, const double y, const double z);

	double get_x() const;
	double get_y() const;
	double get_z() const;

	void set_x(const double x);
	void set_y(const double y);
	void set_z(const double z);

	Vector3 operator-() const;
	Vector3 &operator+=(const Vector3 &);
	Vector3 &operator*=(const double);
	Vector3 &operator/=(const double);

	double length() const;
	double length_squared() const;

  private:
  private:
	double x_;
	double y_;
	double z_;
};

Vector3 operator+(const Vector3 &, const Vector3 &);
Vector3 operator-(const Vector3 &, const Vector3 &);
Vector3 operator*(const Vector3 &, const Vector3 &);
Vector3 operator*(const Vector3 &, const double);
Vector3 operator*(const double, const Vector3 &);
Vector3 operator/(const Vector3 &, const double);
std::ostream &operator<<(std::ostream &, const Vector3 &);

double dot_product(const Vector3 &, const Vector3 &);
Vector3 cross_product(const Vector3 &, const Vector3 &);
Vector3 unit_vector(const Vector3 &);

using Point3 = Vector3;
