#pragma once
#include "./../OutputStream/IOutputStream.h"

class COutputStreamDecorator : public IOutputDataStream
{
protected:
	explicit COutputStreamDecorator(IOutputDataStreamPtr&& stream)
		: m_stream(move(stream))
	{
	}

	IOutputDataStreamPtr m_stream;
};
