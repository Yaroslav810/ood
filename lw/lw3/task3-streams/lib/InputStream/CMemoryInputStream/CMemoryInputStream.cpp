#include "CMemoryInputStream.h"

CMemoryInputStream::CMemoryInputStream(const std::vector<std::uint8_t>& data)
	: m_stream(data)
	, m_currentPos(0)
{
}

bool CMemoryInputStream::IsEOF() const
{
	return m_stream.size() == m_currentPos;
}

uint8_t CMemoryInputStream::ReadByte()
{
	if (IsEOF())
	{
		throw std::ios_base::failure("Attempt to read outside the vector boundaries");
	}

	return m_stream[m_currentPos++];
}

std::streamsize CMemoryInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	auto buffer = static_cast<std::uint8_t*>(dstBuffer);
	auto readCount = size;
	if (readCount > m_stream.size() - m_currentPos)
	{
		readCount = static_cast<std::streamsize>(m_stream.size() - m_currentPos);
	}
	for (std::streamsize i = 0; i < readCount; ++i)
	{
		*(buffer++) = m_stream[m_currentPos++];
	}
}
