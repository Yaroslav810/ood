#pragma once
#include "../ShapeFactory/IShapeFactory.h"
#include "./IDesigner.h"
#include <iostream>

class CDesigner : public IDesigner
{
public:
	CDesigner(IShapeFactory& factory);
	CPictureDraft CreateDraft(std::istream& strm) override;

private:
	static void ExecuteHelpCommand();

	IShapeFactory& m_factory;
};
