#pragma once
#include "../CAbstractCommand.h"
#include <iostream>

class CReplaceTextCommand : public CAbstractCommand
{
public:
	CReplaceTextCommand(std::string& target, std::string newValue);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::string m_newValue;
	std::string& m_target;
};
