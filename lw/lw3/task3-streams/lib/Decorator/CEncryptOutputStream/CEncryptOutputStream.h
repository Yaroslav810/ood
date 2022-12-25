#pragma once
#include "../COutputStreamDecorator.h"
#include "./../../SubstitutionTable/CSubstitutionTable.h"
#include <vector>

class CEncryptOutputStream : public COutputStreamDecorator
{
public:
	CEncryptOutputStream(IOutputDataStreamPtr&& stream, int key);

	void WriteByte(uint8_t data) override;
	void WriteBlock(const void* srcData, std::streamsize size) override;

private:
	std::vector<uint8_t> m_encryptTable;
};
