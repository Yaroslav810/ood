#include "CEncryptOutputStream.h"

CEncryptOutputStream::CEncryptOutputStream(IOutputDataStreamPtr&& stream, int key)
	: COutputStreamDecorator(std::move(stream))
	, m_encryptTable(CSubstitutionTable::GenerateEncryptionTable(key))
{
}

void CEncryptOutputStream::WriteByte(uint8_t data)
{
	m_stream->WriteByte(m_encryptTable[data]);
}

void CEncryptOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	auto buffer = static_cast<const std::uint8_t*>(srcData);
	for (std::streamsize i = 0; i < size; ++i)
	{
		WriteByte(*(buffer++));
	}
}
