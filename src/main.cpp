#include <iostream>

#include "Image.hpp"
#include "Vector3.hpp"

int main()
{
	/* PPMImage image; */
	/* image.generate_example(); */
	/* std::string file_name = "image.ppm"; */
	/* image.log(); */
	/* image.save(file_name); */

	Vector3 v(1, 2, 3), u(2, 3, 4);

	std::cout << v << ' ' << u << '\n';
	std::cout << v + u << '\n';
	std::cout << v - u << '\n';
	std::cout << v * u << '\n';
	std::cout << v * 3. << '\n';
	std::cout << 3. * v << '\n';
	std::cout << v / 3. << '\n';
	std::cout << v.length() << ' ' << dot_product(v, u) << ' ' << '\n';
	std::cout << cross_product(v, u) << '\n';
	std::cout << unit_vector(v) << '\n';
    std::cout << (v += u) << '\n';

	return 0;
}
