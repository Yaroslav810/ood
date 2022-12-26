#pragma once
#include "../../Common/CompressItem.h"
#include "../CInputStreamDecorator.h"

class CDecompressInputStream : public CInputStreamDecorator
{
public:
	explicit CDecompressInputStream(IInputDataStreamPtr&& stream);
	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

private:
	CompressItem m_item;
};
