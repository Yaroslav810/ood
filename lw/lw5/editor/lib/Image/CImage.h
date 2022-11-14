#pragma once
#include "../History/CHistory.h"
#include "IImage.h"
#include <utility>
#include <filesystem>
#include <vector>
#include <random>

class CImage : public IImage
{
public:
	CImage(std::string path, int width, int height, CHistory& history);
	[[nodiscard]] std::string GetPath() const override;
	[[nodiscard]] int GetWidth() const override;
	[[nodiscard]] int GetHeight() const override;
	void Resize(int width, int height) override;
	void Destroy() override;

private:
	bool CheckExtension();
	[[nodiscard]] bool CheckSize() const;
	std::string GetExtension();
	static std::string GenerateName();

	std::string const DIRECTORY = "temp";
	std::vector<std::string> AVAILABLE_EXTENSIONS = { ".jpg", ".png" };
	int const MIN_SIZE = 1;
	int const MAX_SIZE = 10000;

	std::string m_path;
	int m_width;
	int m_height;
	CHistory& m_history;
};
