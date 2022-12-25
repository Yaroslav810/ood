#include "CDecryptInputStream.h"

CDecryptInputStream::CDecryptInputStream(IInputDataStreamPtr&& stream, int key)
	: CInputStreamDecorator(std::move(stream))
	, m_decryptTable(CSubstitutionTable::GenerateDecryptionTable(key))
{
}

uint8_t CDecryptInputStream::ReadByte()
{
	return m_decryptTable[m_stream->ReadByte()];
}

std::streamsize CDecryptInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	auto readCount = m_stream->ReadBlock(dstBuffer, size);
	auto buffer = static_cast<std::uint8_t*>(dstBuffer);
	for (std::streamsize i = 0; i < readCount; ++i)
	{
		*buffer = m_decryptTable[*buffer];
		buffer++;
	}
	return readCount;
}
