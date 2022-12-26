#include "CDecompressInputStream.h"

CDecompressInputStream::CDecompressInputStream(IInputDataStreamPtr&& stream)
	: CInputStreamDecorator(std::move(stream))
	, m_item{ 0, 0 }
{
}

uint8_t CDecompressInputStream::ReadByte()
{
	if (m_item.count == 0 && !m_stream->IsEOF())
	{
		m_item.byte = m_stream->ReadByte();
		m_item.count = !m_stream->IsEOF()
			? m_stream->ReadByte()
			: 0;
	}

	--m_item.count;
	return m_item.byte;
}

std::streamsize CDecompressInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	auto buffer = static_cast<unsigned char*>(dstBuffer);
	for (std::streamsize i = 0; i < size; ++i)
	{
		*(buffer++) = ReadByte();
	}
	return size;
}
