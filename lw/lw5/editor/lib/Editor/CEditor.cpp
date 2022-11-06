#include "CEditor.h"

CEditor::CEditor()
	: m_document(std::make_unique<CDocument>())
{
	//	AddMenuItem("setTitle", "Changes title. Args: <new title>", &CEditor::SetTitle);
	//	m_menu.AddItem("list", "Show document", std::bind(&CEditor::List, this, _1));
	//	AddMenuItem("undo", "Undo command", &CEditor::Undo);
	//	AddMenuItem("redo", "Redo undone command", &CEditor::Redo);
	m_menu.AddItem("help", "Help", [this](std::istream&) { m_menu.ShowInstructions(); });
	m_menu.AddItem("exit", "Exit", [this](std::istream&) { m_menu.Exit(); });
}

void CEditor::Start()
{
	m_menu.Run();
}

void CEditor::SetTitle(std::istream& in)
{
	std::string head;
	std::string tail;

	if (in >> head)
	{
		getline(in, tail);
	}
	std::string title = head + tail;

	m_document->SetTitle(title);
}

void CEditor::List(std::istream&)
{
	std::cout << "-------------" << std::endl;
	std::cout << m_document->GetTitle() << std::endl;
	std::cout << "-------------" << std::endl;
}

void CEditor::Undo(std::istream&)
{
	if (m_document->CanUndo())
	{
		m_document->Undo();
	}
	else
	{
		std::cout << "Can't undo" << std::endl;
	}
}

void CEditor::Redo(std::istream&)
{
	if (m_document->CanRedo())
	{
		m_document->Redo();
	}
	else
	{
		std::cout << "Can't redo" << std::endl;
	}
}
