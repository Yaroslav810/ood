#include "CFileInputStream.h"

CFileInputStream::CFileInputStream(const std::string& fileName)
{
	m_fstream.open(fileName);
	if (!m_fstream.is_open())
	{
		throw std::ios_base::failure("Error opening the file!\nIt is possible that the file is corrupted or there are no permissions to read it\n");
	}
}

bool CFileInputStream::IsEOF() const
{
	m_fstream.peek();
	return m_fstream.eof();
}

uint8_t CFileInputStream::ReadByte()
{
	if (IsEOF())
	{
		throw std::ios_base::failure("Attempt to read outside the file boundaries");
	}
	return m_fstream.get();
}

std::streamsize CFileInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	m_fstream.read(static_cast<char*>(dstBuffer), size);
	if (m_fstream.bad())
	{
		throw std::ios_base::failure("An error occurred while reading the block");
	}

	return m_fstream.gcount();
}
