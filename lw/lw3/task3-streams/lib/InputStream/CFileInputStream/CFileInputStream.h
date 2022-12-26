#pragma once
#include "./../IInputStream.h"
#include <fstream>

class CFileInputStream : public IInputDataStream
{
public:
	explicit CFileInputStream(const std::string& fileName);
	[[nodiscard]] bool IsEOF() const override;
	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

private:
	mutable std::ifstream m_fstream;
};
