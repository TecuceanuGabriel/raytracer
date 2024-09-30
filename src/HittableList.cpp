#include "HittableList.hpp"

HittableList::HittableList() {}
HittableList::HittableList(shared_ptr<Hittable> object) { add(object); }

void HittableList::clear() { objects_.clear(); }

void HittableList::add(shared_ptr<Hittable> object)
{
	objects_.push_back(object);
}

bool HittableList::hit(const Ray &r,
					   double ray_tmin,
					   double ray_tmax,
					   HitRecord &rec) const
{
	HitRecord temp_rec;
	bool hit_anything = false;
	auto closest_so_far = ray_tmax;

	for (const auto &object : objects_) {
		if (object->hit(r, ray_tmin, closest_so_far, temp_rec)) {
			hit_anything = true;
			closest_so_far = temp_rec.t_;
			rec = temp_rec;
		}
	}

	return hit_anything;
}
