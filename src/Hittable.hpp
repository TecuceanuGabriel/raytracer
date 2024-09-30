#pragma once

#include "Ray.hpp"
#include "HitRecord.hpp"

class Hittable
{
  public:
	virtual ~Hittable() = default;
	virtual bool hit(const Ray &r,
					 double ray_tmin,
					 double ray_tmax,
					 HitRecord &record) const = 0;
};
