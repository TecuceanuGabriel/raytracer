#include <iostream>

#include "Image.hpp"

int main()
{
	PPMImage image;
	image.generate_example();
	std::string file_name = "image.ppm";
	image.log();
	image.save(file_name);

	return 0;
}
