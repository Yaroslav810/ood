#include "CResizeImageCommand.h"

CResizeImageCommand::CResizeImageCommand(int& width, int& height, int newWidth, int newHeight)
	: m_width(width)
	, m_height(height)
	, m_newWidth(newWidth)
	, m_newHeight(newHeight)
{
	if (m_newWidth >= CImage::MAX_SIZE || m_newWidth <= CImage::MIN_SIZE || m_newHeight >= CImage::MAX_SIZE || m_newHeight <= CImage::MIN_SIZE)
	{
		throw std::invalid_argument("Unavailable file sizes");
	}
}

void CResizeImageCommand::DoExecute()
{
	std::swap(m_width, m_newWidth);
	std::swap(m_height, m_newHeight);
}

void CResizeImageCommand::DoUnexecute()
{
	std::swap(m_width, m_newWidth);
	std::swap(m_height, m_newHeight);
}