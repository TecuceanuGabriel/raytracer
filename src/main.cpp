#include <algorithm>
#include <iostream>

#include "HitRecord.hpp"
#include "Hittable.hpp"
#include "HittableList.hpp"
#include "Image.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "utility.hpp"

Color get_color(const Ray &r, const Hittable &world)
{
	HitRecord record;
	if (world.hit(r, 0, INFINITE, record)) {
		return 0.5 * (record.normal_ + Color(1, 1, 1));
	}

	Vector3 unit_direction = unit_vector(r.get_direction());
	double a = 0.5 * (unit_direction.get_y() + 1.0);
	return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}

int main()
{
	// Image
	//
	double aspect_ratio = 16.0 / 9.0;

	int image_width = 400;
	int image_height = int(image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;

	// Camera
	double focal_length = 1.0;

	double viewport_height = 2.0;
	double viewport_width =
		viewport_height * (double(image_width) / image_height);

	Point3 camera_center = Point3(0, 0, 0);

	Vector3 viewport_u = Vector3(viewport_width, 0, 0);
	Vector3 viewport_v = Vector3(0, -viewport_height, 0);

	auto pixel_delta_u = viewport_u / image_width;
	auto pixel_delta_v = viewport_v / image_height;

	Vector3 viewport_upper_left = camera_center - Vector3(0, 0, focal_length) -
								  viewport_u / 2 - viewport_v / 2;
	Vector3 pixel00_loc =
		viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

	// World
	HittableList world;

	world.add(make_shared<Sphere>(Point3(0, 0, -1), 0.5));
	world.add(make_shared<Sphere>(Point3(0, -100.5, -1), 100));

	PPMImage image(image_width, image_height);

	for (int i = 0; i < image_height; i++) {
		std::clog << "\rScanlines remaining: " << (image_height - i) << ' '
				  << std::flush;
		for (int j = 0; j < image_width; j++) {
			Vector3 pixel_center =
				pixel00_loc + (j * pixel_delta_u) + (i * pixel_delta_v);
			Vector3 ray_direction = pixel_center - camera_center;
			Ray ray(camera_center, ray_direction);

			RGBPixel pixel_color = color_to_rgb_pixel(get_color(ray, world));

			image.set_max_value(
				std::max({static_cast<uint8_t>(image.get_max_value()),
						  pixel_color.red,
						  pixel_color.green,
						  pixel_color.blue}));
			image.set_pixel(i, j, pixel_color);
		}
	}
	std::clog << "\rDone.                 \n";

	image.save("image.ppm");

	return 0;
}
