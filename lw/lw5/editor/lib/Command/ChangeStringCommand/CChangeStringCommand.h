#pragma once
#include "../CAbstractCommand.h"
#include <iostream>

class CChangeStringCommand : public CAbstractCommand
{
public:
	CChangeStringCommand(std::string& target, std::string newValue);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::string m_newValue;
	std::string& m_target;
};
