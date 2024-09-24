#pragma once

#include "Vector3.hpp"

class Ray
{
  public:
	Ray();
	Ray(const Point3 &origin, const Vector3 &direction);

	const Point3 &get_origin() const;
	const Vector3 &get_direction() const;

    Point3 at(double t) const;

  private:
	Point3 origin_;
	Vector3 direction_;
};
