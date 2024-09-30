#pragma once

#include "Color.hpp"

#include <cstdint>
#include <string>
#include <vector>

class PPMImage
{
  public:
	PPMImage();
	PPMImage(uint32_t width, uint32_t height);

	void load(std::string file_name);
	void save(std::string file_name);

	const RGBPixel &get_pixel(uint32_t x, uint32_t y) const;
	void set_pixel(uint32_t x, uint32_t y, RGBPixel &pixel);

	uint16_t get_max_value() const;
	void set_max_value(uint16_t max_value);

	void generate_example();
	void log();

  private:
  private:
	std::string header_;
	uint32_t width_;
	uint32_t height_;
	uint16_t max_value_;

	std::vector<RGBPixel> pixels_;
};
