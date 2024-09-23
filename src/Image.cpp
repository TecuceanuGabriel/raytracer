#include "Image.hpp"

#include <algorithm>
#include <fstream>
#include <initializer_list>
#include <iostream>

PPMImage::PPMImage()
	: header_("P6"), width_(0), height_(0), max_value_(0), pixels_(0)
{
}

PPMImage::PPMImage(uint32_t width, uint32_t height)
	: header_("P6"), width_(width), height_(height), max_value_(0),
	  pixels_(width * height)
{
}

void PPMImage::load(std::string file_name)
{
	std::ifstream file(file_name, std::ios::binary | std::ios::in);

	if (!file) {
		std::cerr << "load_image() - cannot open file " << file_name
				  << std::endl;
		exit(EXIT_FAILURE);
	}

	file >> header_ >> width_ >> height_ >> max_value_;
	file.ignore();

	pixels_.resize(width_ * height_);

	file.read(reinterpret_cast<char *>(pixels_.data()),
			  pixels_.size() * sizeof(RGBPixel));

	file.close();
}

void PPMImage::save(std::string file_name)
{
	std::ofstream file(file_name, std::ios::binary | std::ios::out);

	file << header_ << '\n';
	file << width_ << ' ' << height_ << '\n';
	file << static_cast<int>(max_value_) << '\n';

	file.write(reinterpret_cast<char *>(pixels_.data()),
			   pixels_.size() * sizeof(RGBPixel));

	file.close();
}

void PPMImage::generate_example()
{
	width_ = 20;
	height_ = 20;

	pixels_.resize(width_ * height_);

	for (uint8_t i = 0; i < height_; ++i) {
		for (uint8_t j = 0; j < width_; ++j) {
			auto r = double(j) / (width_ - 1);
			auto g = double(i) / (height_ - 1);
			auto b = 0.0;

			uint8_t ir = uint8_t(255.999 * r);
			uint8_t ig = uint8_t(255.999 * g);
			uint8_t ib = uint8_t(255.999 * b);

			max_value_ = std::max({max_value_, ir, ig, ib});

			pixels_[i * height_ + j] = RGBPixel{ir, ig, ib};
		}
	}
}

static void log_pixel(RGBPixel pixel)
{
	std::cout << (int)pixel.red << ' ' << (int)pixel.green << ' '
			  << (int)pixel.blue;
}

void PPMImage::log()
{
	for (uint32_t i = 0; i < height_; ++i) {
		for (uint32_t j = 0; j < width_; ++j) {
			log_pixel(pixels_[i * height_ + j]);
			std::cout << ' ';
		}
		std::cout << '\n';
	}
}
