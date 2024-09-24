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

	void generate_example();
	void log();

  private:
  private:
	std::string header_;
	uint32_t width_;
	uint32_t height_;
	uint8_t max_value_;

	std::vector<RGBPixel> pixels_;
};
