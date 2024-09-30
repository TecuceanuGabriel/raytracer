#include "Sphere.hpp"

#include "math.h"

Sphere::Sphere(const Point3 &center, const double radius)
	: center_(center), radius_(std::fmax(0, radius))
{
}

bool Sphere::hit(const Ray &r,
				 double ray_tmin,
				 double ray_tmax,
				 HitRecord &rec) const
{
	Vector3 oc = center_ - r.get_origin();
	double a = r.get_direction().length_squared();
	double h = dot_product(r.get_direction(), oc);
	double c = oc.length_squared() - radius_ * radius_;

	double discriminant = h * h - a * c;
	if (discriminant < 0)
		return false;

	double sqrt_d = std::sqrt(discriminant);

	// Find the nearest root that lies in the acceptable range.
	double root = (h - sqrt_d) / a;
	if (root <= ray_tmin || ray_tmax <= root) {
		root = (h + sqrt_d) / a;
		if (root <= ray_tmin || ray_tmax <= root)
			return false;
	}

	rec.t_ = root;
	rec.p_ = r.at(rec.t_);
	Vector3 outward_normal = (rec.p_ - center_) / radius_;
    rec.set_face_normal(r, outward_normal);

	return true;
}
