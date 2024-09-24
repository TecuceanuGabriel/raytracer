#pragma once

#include "Vector3.hpp"

#include <cstdint>
#include <ostream>

struct RGBPixel {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

using Color = Vector3;

RGBPixel color_to_rgb_pixel(const Color& color);

void write_rgb_pixel(std::ostream &out, const RGBPixel& pixel);
