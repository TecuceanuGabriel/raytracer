#include "HitRecord.hpp"

void HitRecord::set_face_normal(const Ray &r, const Vector3 &outward_normal)
{
	front_face_ = dot_product(r.get_direction(), outward_normal) < 0;
	normal_ = front_face_ ? outward_normal : -outward_normal;
}
