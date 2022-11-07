#pragma once
#include "../History/CHistory.h"
#include "IParagraph.h"

class CParagraph : public IParagraph
{
public:
	explicit CParagraph(std::string text, CHistory& history);

	[[nodiscard]] std::string GetText() const override;
	void SetText(const std::string& text) override;

private:
	std::string m_text;
	CHistory& m_history;
};
