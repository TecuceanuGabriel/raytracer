#pragma once

#include "Hittable.hpp"
#include "Vector3.hpp"

class Sphere : public Hittable
{
  public:
	Sphere(const Point3 &center, const double radius);
	bool hit(const Ray &r,
			 double ray_tmin,
			 double ray_tmax,
			 HitRecord &record) const override;

  private:
	Point3 center_;
	double radius_;
};
