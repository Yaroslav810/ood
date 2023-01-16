#include "CCompressOutputStream.h"

CCompressOutputStream::CCompressOutputStream(IOutputDataStreamPtr&& stream)
	: COutputStreamDecorator(std::move(stream))
	, m_item{ 0, 0 }
{
}

CCompressOutputStream::~CCompressOutputStream()
{
	Flush();
}

void CCompressOutputStream::WriteByte(uint8_t data)
{
	if (m_item.count == 0)
	{
		m_item = { data, 1 };
		return;
	}

	if (m_item.byte == data && m_item.count < std::numeric_limits<std::uint8_t>::max())
	{
		++m_item.count;
		return;
	}

	Flush();
	m_item = { data, 1 };
}

void CCompressOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	auto buffer = static_cast<const uint8_t*>(srcData);
	for (std::streamsize i = 0; i < size; ++i)
	{
		WriteByte(*(buffer++));
	}
}

void CCompressOutputStream::Flush()
{
	m_stream->WriteByte(m_item.byte);
	m_stream->WriteByte(m_item.count);
}
