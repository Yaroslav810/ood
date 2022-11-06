#pragma once
#include "../Document/CDocument.h"
#include "../Menu/CMenu.h"
#include <iostream>
#include <memory>
#include <string>

class CEditor
{
public:
	CEditor();
	void Start();

private:
	void SetTitle(std::istream& in);

	void List(std::istream&);

	void Undo(std::istream&);

	void Redo(std::istream&);

	CMenu m_menu;
	std::unique_ptr<IDocument> m_document;
};
