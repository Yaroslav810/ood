#pragma once
#include <string>

class IParagraph
{
public:
	[[nodiscard]] virtual std::string GetText() const = 0;
	virtual void SetText(const std::string& text) = 0;
	virtual ~IParagraph() = default;
};
