#pragma once

#include "Hittable.hpp"

#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;

class HittableList : public Hittable
{
  public:
	HittableList();
	HittableList(shared_ptr<Hittable> object);

	void clear();

	void add(shared_ptr<Hittable> object);

	bool hit(const Ray &r,
			 double ray_tmin,
			 double ray_tmax,
			 HitRecord &rec) const override;

  public:
	std::vector<shared_ptr<Hittable>> objects_;
};
