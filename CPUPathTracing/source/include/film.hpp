#pragma once

#include <glm/glm.hpp>
#include <filesystem>
#include <vector>

class Film
{
public:
	Film(size_t width, size_t height);
	void Save(const std::filesystem::path& filename);

	size_t GetWidth() const { return width; }
	size_t GetHeight() const { return height; }
	glm::vec3 GetPixel(size_t x, size_t y) { return pixels[y * width + x]; }
	void SetPixel(size_t x, size_t y, glm::vec3 col) { pixels[y * width + x] = col; }

private:
	size_t width, height;
	std::vector<glm::vec3> pixels;
};