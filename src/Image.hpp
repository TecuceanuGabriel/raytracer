#pragma once

#include <cstdint>
#include <string>
#include <vector>

struct RGBPixel {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

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
