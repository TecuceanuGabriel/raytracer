#include "Color.hpp"

RGBPixel color_to_rgb_pixel(const Color &color)
{
	return RGBPixel({static_cast<uint8_t>(color.get_x() * 255.999),
					 static_cast<uint8_t>(color.get_y() * 255.999),
					 static_cast<uint8_t>(color.get_z() * 255.999)});
}

void write_rgb_pixel(std::ostream &out, const RGBPixel &pixel)
{
	out << static_cast<int>(pixel.red) << ' ' << static_cast<int>(pixel.green)
		<< ' ' << static_cast<int>(pixel.green);
}
