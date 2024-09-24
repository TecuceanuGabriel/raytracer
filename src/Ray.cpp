#include "Ray.hpp"

Ray::Ray() : origin_(Point3(0, 0, 0)), direction_(Vector3(0, 0, 0)) {}

Ray::Ray(const Point3 &origin, const Vector3 &direction)
	: origin_(origin), direction_(direction)
{
}

const Point3 &Ray::get_origin() const { return origin_; }

const Vector3 &Ray::get_direction() const { return direction_; }

Point3 Ray::at(double t) const { return origin_ + direction_ * t; }
