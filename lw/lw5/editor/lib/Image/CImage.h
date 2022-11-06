#pragma once
#include "IImage.h"
#include <vector>

class CImage : public IImage
{
public:
	CImage(const std::string& path, int width, int height);
	[[nodiscard]] std::string GetPath() const override;
	[[nodiscard]] int GetWidth() const override;
	[[nodiscard]] int GetHeight() const override;
	void Resize(int width, int height) override;
	void Destroy() override;

private:
	std::string const DIRECTORY = "images";
	std::vector<std::string> AVAILABLE_EXTENSIONS = { "jpg", "png", "svg" };

	std::string m_path;
	int m_width;
	int m_height;
};
