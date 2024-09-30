#include "Image.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>

PPMImage::PPMImage()
	: header_("P6"), width_(0), height_(0), max_value_(0), pixels_(0)
{
}

PPMImage::PPMImage(uint32_t width, uint32_t height)
	: header_("P6"), width_(width), height_(height), max_value_(0),
	  pixels_(width * height)
{
	pixels_.resize(width_ * height_);
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
	file << max_value_ << '\n';

	file.write(reinterpret_cast<char *>(pixels_.data()),
			   pixels_.size() * sizeof(RGBPixel));

	file.close();
}

const RGBPixel &PPMImage::get_pixel(uint32_t x, uint32_t y) const
{
	return pixels_[x * height_ + y];
}

void PPMImage::set_pixel(uint32_t x, uint32_t y, RGBPixel &pixel)
{
	pixels_[x * width_ + y] = pixel;
}

uint16_t PPMImage::get_max_value() const { return max_value_; }

void PPMImage::set_max_value(uint16_t max_value) { max_value_ = max_value; }

void PPMImage::generate_example()
{
	width_ = 10;
	height_ = 10;

	pixels_.resize(width_ * height_);

	for (uint8_t i = 0; i < height_; ++i) {
		for (uint8_t j = 0; j < width_; ++j) {
			RGBPixel pixel =
				color_to_rgb_pixel(Color(static_cast<double>(j) / (width_ - 1),
										 static_cast<double>(i) / (height_ - 1),
										 0.0));

			max_value_ = std::max({static_cast<uint8_t>(max_value_),
								   pixel.red,
								   pixel.green,
								   pixel.blue});

			pixels_[i * width_ + j] = pixel;
		}
	}
}

void PPMImage::log()
{
	std::cout << header_ << '\n';
	std::cout << width_ << ' ' << height_ << '\n';
	std::cout << max_value_ << '\n';
	for (uint32_t i = 0; i < height_; ++i) {
		for (uint32_t j = 0; j < width_; ++j) {
			write_rgb_pixel(std::cout, pixels_[i * width_ + j]);
			std::cout << ' ';
		}
		std::cout << '\n';
	}
}
