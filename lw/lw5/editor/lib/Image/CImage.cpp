#include "CImage.h"

CImage::CImage(std::string path, int width, int height, CHistory& history)
	: m_path(std::move(path))
	, m_width(width)
	, m_height(height)
	, m_history(history)
{
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
}

void CImage::Destroy()
{
}
