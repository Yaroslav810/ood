#include "CImage.h"

CImage::CImage(std::string path, int width, int height, CHistory& history)
	: m_path(std::move(path))
	, m_width(width)
	, m_height(height)
	, m_history(history)
{
	if (!std::filesystem::exists(m_path))
	{
		throw std::invalid_argument("The file does not exist");
	}

	if (!CheckExtension())
	{
		throw std::invalid_argument("File extension unavailable");
	}

	if (!CheckSize())
	{
		throw std::invalid_argument("Unavailable file sizes");
	}

	if (!std::filesystem::is_directory(DIRECTORY))
	{
		std::filesystem::create_directory(DIRECTORY);
	}

	std::string newImagePath = DIRECTORY + '/' + GenerateName() + GetExtension();
	std::filesystem::copy(m_path, newImagePath);
	m_path = newImagePath;
}

std::string CImage::GetPath() const
{
	return m_path;
}

int CImage::GetWidth() const
{
	return m_width;
}

int CImage::GetHeight() const
{
	return m_height;
}

void CImage::Resize(int width, int height)
{
	m_history.AddAndExecuteCommand(std::make_unique<CResizeImageCommand>(m_width, m_height, width, height));
}

void CImage::Destroy()
{
	std::filesystem::remove(m_path);
}

bool CImage::CheckExtension()
{
	return std::find(AVAILABLE_EXTENSIONS.begin(), AVAILABLE_EXTENSIONS.end(), GetExtension()) != AVAILABLE_EXTENSIONS.end();
}

bool CImage::CheckSize() const
{
	return m_width >= MIN_SIZE && m_width <= MAX_SIZE && m_height >= MIN_SIZE && m_height <= MAX_SIZE;
}

std::string CImage::GetExtension()
{
	return std::filesystem::path(m_path).extension().string();
}

std::string CImage::GenerateName()
{
	auto& chars = "0123456789"
				  "abcdefghijklmnopqrstuvwxyz"
				  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	std::mt19937 rg{ std::random_device{}() };
	std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chars) - 2);
	std::string result;
	for (size_t i = 0; i < 10; ++i)
	{
		result += chars[pick(rg)];
	}

	return result;
}
