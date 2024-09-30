#pragma once

#include "Ray.hpp"
#include "Vector3.hpp"

class HitRecord
{
  public:
	void set_face_normal(const Ray &r, const Vector3 &outward_normal);

  public:
	Point3 p_;
	Vector3 normal_;
	double t_;
	bool front_face_;
};
