#include "Vector3.hpp"

#include <math.h>

Vector3::Vector3() : x_(0), y_(0), z_(0) {}

Vector3::Vector3(double x, double y, double z) : x_(x), y_(y), z_(z) {}

double Vector3::get_x() const { return x_; }

double Vector3::get_y() const { return y_; }

double Vector3::get_z() const { return z_; }

void Vector3::set_x(double x) { x_ = x; }

void Vector3::set_y(double y) { y_ = y; }

void Vector3::set_z(double z) { z_ = z; }

Vector3 Vector3::operator-() const { return Vector3(-x_, -y_, -z_); }

Vector3 &Vector3::operator+=(const Vector3 &v)
{
	this->x_ += v.x_;
	this->y_ += v.y_;
	this->z_ += v.z_;
	return *this;
}

Vector3 &Vector3::operator*=(const double c)
{
	this->x_ *= c;
	this->y_ *= c;
	this->z_ *= c;
	return *this;
}

Vector3 &Vector3::operator/=(const double c) { return *this *= (1 / c); }

double Vector3::length() const { return sqrt(length_squared()); }

double Vector3::length_squared() const { return x_ * x_ + y_ * y_ + z_ * z_; }

Vector3 operator+(const Vector3 &v, const Vector3 &u)
{
	return Vector3(v.get_x() + u.get_x(),
				   v.get_y() + u.get_y(),
				   v.get_z() + u.get_z());
}

Vector3 operator-(const Vector3 &v, const Vector3 &u)
{
	return Vector3(v.get_x() - u.get_x(),
				   v.get_y() - u.get_y(),
				   v.get_z() - u.get_z());
}

Vector3 operator*(const Vector3 &v, const Vector3 &u)
{
	return Vector3(v.get_x() * u.get_x(),
				   v.get_y() * u.get_y(),
				   v.get_z() * u.get_z());
}

Vector3 operator*(const double c, const Vector3 &v)
{
	return Vector3(c * v.get_x(), c * v.get_y(), c * v.get_z());
}

Vector3 operator*(const Vector3 &v, const double c) { return c * v; }

Vector3 operator/(const Vector3 &v, const double c) { return (1 / c) * v; }

std::ostream &operator<<(std::ostream &out, const Vector3 &v)
{
	return out << v.get_x() << ' ' << v.get_y() << ' ' << v.get_z();
}

double dot_product(const Vector3 &v, const Vector3 &u)
{
	return v.get_x() * u.get_x() + v.get_y() * u.get_y() +
		   v.get_z() * u.get_z();
}

Vector3 cross_product(const Vector3 &v, const Vector3 &u)
{
	return Vector3(v.get_y() * u.get_z() - v.get_z() * u.get_y(),
				   v.get_z() * u.get_x() - v.get_x() * u.get_z(),
				   v.get_x() * u.get_y() - v.get_y() * u.get_x());
}

Vector3 unit_vector(const Vector3 &v) { return v / v.length(); }
