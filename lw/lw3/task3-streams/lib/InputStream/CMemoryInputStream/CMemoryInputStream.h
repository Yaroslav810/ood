#pragma once
#include "./../IInputStream.h"
#include <vector>

class CMemoryInputStream : public IInputDataStream
{
public:
	explicit CMemoryInputStream(const std::vector<std::uint8_t>& data);
	[[nodiscard]] bool IsEOF() const override;
	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

private:
	const std::vector<std::uint8_t>& m_stream;
	size_t m_currentPos;
};
