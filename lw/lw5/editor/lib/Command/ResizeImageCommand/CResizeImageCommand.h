#pragma once
#include "../../Image/CImage.h"
#include "../CAbstractCommand.h"
#include <iostream>

class CResizeImageCommand : public CAbstractCommand
{
public:
	CResizeImageCommand(int& width, int& height, int newWidth, int newHeight);

private:
	void DoExecute() override;
	void DoUnexecute() override;

	int& m_width;
	int& m_height;
	int m_newWidth;
	int m_newHeight;
};
