#pragma once
#include "../../Common/CompressItem.h"
#include "../COutputStreamDecorator.h"
#include <iostream>
#include <limits>

class CCompressOutputStream : public COutputStreamDecorator
{
public:
	explicit CCompressOutputStream(IOutputDataStreamPtr&& stream);
	void WriteByte(uint8_t data) override;
	void WriteBlock(const void* srcData, std::streamsize size) override;
	~CCompressOutputStream() override;

private:
	void Flush();

	CompressItem m_item;
};
