#pragma once
#include "./../InputStream/IInputStream.h"

class CInputStreamDecorator : public IInputDataStream
{
public:
	[[nodiscard]] bool IsEOF() const override
	{
		return m_stream->IsEOF();
	}

protected:
	explicit CInputStreamDecorator(IInputDataStreamPtr&& stream)
		: m_stream(move(stream))
	{
	}

	IInputDataStreamPtr m_stream;
};
