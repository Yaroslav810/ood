#pragma once
#include "../CInputStreamDecorator.h"
#include "./../../SubstitutionTable/CSubstitutionTable.h"
#include <vector>

class CDecryptInputStream : public CInputStreamDecorator
{
public:
	CDecryptInputStream(IInputDataStreamPtr&& stream, int key);

	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

private:
	std::vector<uint8_t> m_decryptTable;
};
