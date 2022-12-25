#pragma once
#include "./../IOutputStream.h"
#include <fstream>

class CFileOutputStream : public IOutputDataStream
{
public:
	explicit CFileOutputStream(const std::string& fileName);
	void WriteByte(uint8_t data) override;
	void WriteBlock(const void* srcData, std::streamsize size) override;

private:
	std::ofstream m_fstream;
};
