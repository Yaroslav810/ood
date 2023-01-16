#include "CFileOutputStream.h"

CFileOutputStream::CFileOutputStream(const std::string& fileName)
{
	m_fstream.open(fileName, std::ios::binary);
	if (!m_fstream.is_open())
	{
		throw std::ios_base::failure("Error opening the file!\nIt is possible that the file is corrupted or there are no permissions to write it\n");
	}
}

void CFileOutputStream::WriteByte(uint8_t data)
{
	WriteBlock(&data, 1);
}

void CFileOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	m_fstream.write(static_cast<const char*>(srcData), size);
	if (m_fstream.bad())
	{
		throw std::ios_base::failure("An error occurred while writing the block");
	}
	m_fstream.flush();
}
