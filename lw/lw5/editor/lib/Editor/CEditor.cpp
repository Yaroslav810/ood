#include "CEditor.h"

CEditor::CEditor()
	: m_document(std::make_unique<CDocument>())
{
	m_menu.AddItem("InsertParagraph", "Inserts a paragraph. Args: <pos>|end <text>", [this](std::istream& is) { InsertParagraph(is); });
	m_menu.AddItem("SetTitle", "Changes title. Args: <new title>", [this](std::istream& is) { SetTitle(is); });
	m_menu.AddItem("List", "Show document", [this](std::istream& is) { List(is); });
	m_menu.AddItem("ReplaceText", "Replace a text. Args: <pos> <text>", [this](std::istream& is) { ReplaceText(is); });
	m_menu.AddItem("DeleteItem", "Delete a item. Args: <pos>", [this](std::istream& is) { DeleteItem(is); });
	m_menu.AddItem("Undo", "Undo command", [this](std::istream& is) { Undo(is); });
	m_menu.AddItem("Redo", "Redo undone command", [this](std::istream& is) { Redo(is); });
	m_menu.AddItem("Help", "Help", [this](std::istream&) { m_menu.ShowInstructions(); });
	m_menu.AddItem("Exit", "Exit", [this](std::istream&) { m_menu.Exit(); });
}

void CEditor::Start()
{
	m_menu.Run();
}

void CEditor::InsertParagraph(std::istream& in)
{
	std::string pos;
	std::string text;

	try
	{
		if (in >> pos && in >> text)
		{
			m_document->InsertParagraph(text, pos == "end" ? std::optional<size_t>() : std::stoi(pos));
		}
	}
	catch (std::exception&)
	{
		std::cout << "Invalid pos" << std::endl;
	}
}

void CEditor::SetTitle(std::istream& is)
{
	std::string head;
	std::string tail;

	if (is >> head)
	{
		getline(is, tail);
	}

	auto title = head + tail;
	m_document->SetTitle(title);
}

void CEditor::List(std::istream&)
{
	std::cout << "-------------" << std::endl;
	std::cout << "Title: " << m_document->GetTitle() << std::endl;
	for (size_t i = 0; i < m_document->GetItemsCount(); ++i)
	{
		std::cout << i << ". ";
		if (m_document->GetItem(i).GetParagraph())
		{
			std::shared_ptr<IParagraph> paragraph = m_document->GetItem(i).GetParagraph();
			std::cout << "Paragraph: " << paragraph->GetText() << std::endl;
		}
		else
		{
			std::shared_ptr<IImage> image = m_document->GetItem(i).GetImage();
			std::cout << "Imgae: " << image->GetWidth() << " " << image->GetHeight() << " " << image->GetPath() << std::endl;
		}
	}
	std::cout << "-------------" << std::endl;
}

void CEditor::ReplaceText(std::istream& in)
{
	std::string pos;
	std::string text;

	try
	{
		if (in >> pos && in >> text)
		{
			m_document->ReplaceText(text, std::stoi(pos));
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void CEditor::DeleteItem(std::istream& in)
{
	std::string pos;

	try
	{
		if (in >> pos)
		{
			m_document->DeleteItem(std::stoi(pos));
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
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
