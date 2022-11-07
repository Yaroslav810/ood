#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../lib/Command/CAbstractCommand.h"
#include "../lib/Command/ChangeStringCommand/CChangeStringCommand.h"
#include "../lib/Command/DeleteItemCommand/CDeleteItemCommand.h"
#include "../lib/Command/InsertParagraphCommand/CInsertDocumentItemCommand.h"
#include "../lib/Command/ReplaceTextCommand/CReplaceTextCommand.h"
#include "../lib/Document/CDocument.h"
#include "../lib/Image/CImage.h"
#include "../lib/Paragraph/CParagraph.h"

class MockCommand : public CAbstractCommand
{
public:
	MockCommand() = default;

protected:
	void DoExecute() override{};
	void DoUnexecute() override{};
};

TEST_CASE("Paragraph")
{
	CHistory history;
	CParagraph paragraph("Paragraph", history);
	THEN("Created CParagraph")
	{
		REQUIRE(paragraph.GetText() == "Paragraph");
	}
}

TEST_CASE("Image")
{
	CHistory history;
	CImage image("image.png", 150, 100, history);
	THEN("Created CImage")
	{
		REQUIRE(image.GetPath() == "image.png");
		REQUIRE(image.GetWidth() == 150);
		REQUIRE(image.GetHeight() == 100);
	}
}

TEST_CASE("History")
{
	CHistory history;

	SECTION("Empty")
	{
		REQUIRE(history.CanUndo() == false);
		REQUIRE(history.CanRedo() == false);
	}

	SECTION("MockCommand")
	{
		history.AddAndExecuteCommand(std::make_unique<MockCommand>());

		THEN("Has undo")
		{
			REQUIRE(history.CanUndo() == true);
			REQUIRE(history.CanRedo() == false);
		}
	}

	SECTION("MockCommand and Undo")
	{
		history.AddAndExecuteCommand(std::make_unique<MockCommand>());
		history.Undo();

		THEN("Has redo")
		{
			REQUIRE(history.CanUndo() == false);
			REQUIRE(history.CanRedo() == true);
		}
	}

	SECTION("MockCommand, Undo and Redo")
	{
		history.AddAndExecuteCommand(std::make_unique<MockCommand>());
		history.Undo();
		history.Redo();

		THEN("Has undo")
		{
			REQUIRE(history.CanUndo() == true);
			REQUIRE(history.CanRedo() == false);
		}
	}

	SECTION("MockCommand, Undo and MockCommand")
	{
		history.AddAndExecuteCommand(std::make_unique<MockCommand>());
		history.Undo();
		history.AddAndExecuteCommand(std::make_unique<MockCommand>());

		THEN("Has undo")
		{
			REQUIRE(history.CanUndo() == true);
			REQUIRE(history.CanRedo() == false);
		}
	}

	SECTION("2 MockCommand, Undo, MockCommand and Undo")
	{
		history.AddAndExecuteCommand(std::make_unique<MockCommand>());
		history.AddAndExecuteCommand(std::make_unique<MockCommand>());
		history.Undo();

		THEN("Has undo, has Redo")
		{
			REQUIRE(history.CanUndo() == true);
			REQUIRE(history.CanRedo() == true);
		}
	}

	SECTION("10 command in History")
	{
		for (auto i = 0; i < 12; i++)
		{
			history.AddAndExecuteCommand(std::make_unique<MockCommand>());
		}

		THEN("10 command")
		{
			int count = 0;
			while (history.CanUndo())
			{
				history.Undo();
				count++;
			}
			REQUIRE(count == 10);
		}
	}
}

TEST_CASE("ChangeStringCommand")
{
	std::string oldTitle = "Old Title";
	std::string newTitle = "New Title";
	CChangeStringCommand changeStringCommand(oldTitle, newTitle);

	SECTION("Execute")
	{
		changeStringCommand.Execute();
		THEN("oldTitle === newTitle`")
		{
			REQUIRE(oldTitle == "New Title");
		}
	}

	SECTION("Execute and Unexecute")
	{
		changeStringCommand.Execute();
		changeStringCommand.Unexecute();

		THEN("oldTitle === oldTitle")
		{
			REQUIRE(oldTitle == "Old Title");
		}
	}
}

TEST_CASE("DeleteItemCommand")
{
	CHistory history;
	CDocumentItem paragraph1(std::make_unique<CParagraph>("paragraph #1", history));
	CDocumentItem paragraph2(std::make_unique<CParagraph>("paragraph #2", history));
	CDocumentItem image1(std::make_unique<CImage>("image1.png", 150, 100, history));
	CDocumentItem image2(std::make_unique<CImage>("image2.png", 150, 100, history));

	SECTION("Deleting a single paragraph")
	{
		std::vector<CDocumentItem> items = { paragraph1 };
		CDeleteItemCommand(items, 0).Execute();

		THEN("throw exception")
		{
			REQUIRE(items.empty());
		}
	}

	SECTION("Deleting a single image")
	{
		std::vector<CDocumentItem> items = { image1 };
		CDeleteItemCommand(items, 0).Execute();

		THEN("throw exception")
		{
			REQUIRE(items.empty());
		}
	}

	SECTION("Few deleting")
	{
		std::vector<CDocumentItem> items = { paragraph1, image1 };

		CDeleteItemCommand(items, 0).Execute();
		THEN("Items size = 1")
		{
			REQUIRE(items.size() == 1);
			REQUIRE(items[0].GetImage()->GetPath() == "image1.png");
			REQUIRE(items[0].GetImage()->GetWidth() == 150);
			REQUIRE(items[0].GetImage()->GetHeight() == 100);
		}

		CDeleteItemCommand(items, 0).Execute();
		THEN("Items size = 0")
		{
			REQUIRE(items.empty());
		}
	}

	SECTION("Execute and Unexecute paragraph")
	{
		std::vector<CDocumentItem> items = { paragraph1, image1 };
		auto command = CDeleteItemCommand(items, 0);

		command.Execute();
		THEN("Items size = 1")
		{
			REQUIRE(items.size() == 1);
			REQUIRE(items[0].GetImage()->GetPath() == "image1.png");
			REQUIRE(items[0].GetImage()->GetWidth() == 150);
			REQUIRE(items[0].GetImage()->GetHeight() == 100);
		}

		command.Unexecute();
		THEN("Items size = 2")
		{
			REQUIRE(items.size() == 2);
			REQUIRE(items[0].GetParagraph()->GetText() == "paragraph #1");
			REQUIRE(items[1].GetImage()->GetPath() == "image1.png");
			REQUIRE(items[1].GetImage()->GetWidth() == 150);
			REQUIRE(items[1].GetImage()->GetHeight() == 100);
		}
	}

	SECTION("Execute and Unexecute image")
	{
		std::vector<CDocumentItem> items = { paragraph1, image1 };
		auto command = CDeleteItemCommand(items, 1);

		command.Execute();
		THEN("Items size = 1")
		{
			REQUIRE(items.size() == 1);
			REQUIRE(items[0].GetParagraph()->GetText() == "paragraph #1");
		}

		command.Unexecute();
		THEN("Items size = 2")
		{
			REQUIRE(items.size() == 2);
			REQUIRE(items[0].GetParagraph()->GetText() == "paragraph #1");
			REQUIRE(items[1].GetImage()->GetPath() == "image1.png");
			REQUIRE(items[1].GetImage()->GetWidth() == 150);
			REQUIRE(items[1].GetImage()->GetHeight() == 100);
		}
	}
}

TEST_CASE("InsertParagraphCommand")
{
	CHistory history;
	CDocumentItem paragraph = CDocumentItem(std::make_unique<CParagraph>("paragraph", history));
	CDocumentItem image = CDocumentItem(std::make_unique<CImage>("image.png", 150, 100, history));

	SECTION("1 item paragraph")
	{
		std::vector<CDocumentItem> items = {};
		CInsertDocumentItemCommand(items, paragraph, 0).Execute();

		THEN("1 item - paragraph")
		{
			REQUIRE(items.size() == 1);
			REQUIRE(items[0].GetParagraph()->GetText() == "paragraph");
		}
	}

	SECTION("1 item image")
	{
		std::vector<CDocumentItem> items = {};
		CInsertDocumentItemCommand(items, image, 0).Execute();

		THEN("1 item - image")
		{
			REQUIRE(items.size() == 1);
			REQUIRE(items[0].GetImage()->GetPath() == "image.png");
			REQUIRE(items[0].GetImage()->GetWidth() == 150);
			REQUIRE(items[0].GetImage()->GetHeight() == 100);
		}
	}

	SECTION("Few item with add to start")
	{
		std::vector<CDocumentItem> items = {};
		CInsertDocumentItemCommand(items, image, 0).Execute();
		CInsertDocumentItemCommand(items, paragraph, 0).Execute();

		THEN("Paragraph and Item")
		{
			REQUIRE(items.size() == 2);
			REQUIRE(items[0].GetParagraph()->GetText() == "paragraph");
			REQUIRE(items[1].GetImage()->GetPath() == "image.png");
			REQUIRE(items[1].GetImage()->GetWidth() == 150);
			REQUIRE(items[1].GetImage()->GetHeight() == 100);
		}
	}

	SECTION("Few item with add to end")
	{
		std::vector<CDocumentItem> items = {};
		CInsertDocumentItemCommand(items, image, 0).Execute();
		CInsertDocumentItemCommand(items, paragraph, 1).Execute();

		THEN("Paragraph and Item")
		{
			REQUIRE(items.size() == 2);
			REQUIRE(items[0].GetImage()->GetPath() == "image.png");
			REQUIRE(items[0].GetImage()->GetWidth() == 150);
			REQUIRE(items[0].GetImage()->GetHeight() == 100);
			REQUIRE(items[1].GetParagraph()->GetText() == "paragraph");
		}
	}

	SECTION("Execute and Unexecute paragraph")
	{
		std::vector<CDocumentItem> items = {};
		auto command = CInsertDocumentItemCommand(items, paragraph, 0);
		command.Execute();
		command.Unexecute();

		THEN("Empty")
		{
			REQUIRE(items.empty());
		}
	}

	SECTION("Execute and Unexecute image")
	{
		std::vector<CDocumentItem> items = {};
		auto command = CInsertDocumentItemCommand(items, image, 0);
		command.Execute();
		command.Unexecute();

		THEN("Empty")
		{
			REQUIRE(items.empty());
		}
	}
}

TEST_CASE("ReplaceTextCommand")
{
	std::string oldText = "Old Text";
	std::string newText = "New Text";
	CReplaceTextCommand replaceTextCommand(oldText, newText);

	SECTION("Execute")
	{
		replaceTextCommand.Execute();
		THEN("oldTitle === newTitle`")
		{
			REQUIRE(oldText == "New Text");
		}
	}

	SECTION("Execute and Unexecute")
	{
		replaceTextCommand.Execute();
		replaceTextCommand.Unexecute();

		THEN("oldText === oldText")
		{
			REQUIRE(oldText == "Old Text");
		}
	}
}

TEST_CASE("Document")
{
	SECTION("Empty")
	{
		CDocument document;
		THEN("Empty title and items")
		{
			REQUIRE(document.GetTitle().empty());
			REQUIRE(document.GetItemsCount() == 0);
		}
	}

	SECTION("SetTitle")
	{
		CDocument document;
		document.SetTitle("Title");

		THEN("Title = Title")
		{
			REQUIRE(document.GetTitle() == "Title");
		}
	}

	SECTION("Adding a paragraph")
	{
		CDocument document;
		document.InsertParagraph("paragraph", 0);

		THEN("The first element is a paragraph")
		{
			REQUIRE(document.GetItemsCount() == 1);
			REQUIRE(document.GetItem(0).GetParagraph()->GetText() == "paragraph");
		}
	}

	SECTION("Adding an image")
	{
		CDocument document;
		document.InsertImage("image.png", 150, 100, 0);

		THEN("The first element is a paragraph")
		{
			REQUIRE(document.GetItemsCount() == 1);
			REQUIRE(document.GetItem(0).GetImage()->GetPath() == "image.png");
			REQUIRE(document.GetItem(0).GetImage()->GetWidth() == 150);
			REQUIRE(document.GetItem(0).GetImage()->GetHeight() == 100);
		}
	}

	SECTION("GetItemsCount")
	{
		CDocument document;
		THEN("Size = 0")
		{
			REQUIRE(document.GetItemsCount() == 0);
		}

		document.InsertImage("image.png", 150, 100, 0);
		THEN("Size = 1")
		{
			REQUIRE(document.GetItemsCount() == 1);
		}

		document.InsertParagraph("paragraph", 0);
		THEN("Size = 2")
		{
			REQUIRE(document.GetItemsCount() == 2);
		}
	}

	SECTION("GetItem")
	{
		CDocument document;

		document.InsertImage("image.png", 150, 100, 0);
		THEN("Size = 1")
		{
			REQUIRE(document.GetItemsCount() == 1);
			REQUIRE(document.GetItem(0).GetImage()->GetPath() == "image.png");
			REQUIRE(document.GetItem(0).GetImage()->GetWidth() == 150);
			REQUIRE(document.GetItem(0).GetImage()->GetHeight() == 100);
		}

		document.InsertParagraph("paragraph", 0);
		THEN("Size = 2")
		{
			REQUIRE(document.GetItemsCount() == 2);
			REQUIRE(document.GetItem(0).GetParagraph()->GetText() == "paragraph");
			REQUIRE(document.GetItem(1).GetImage()->GetPath() == "image.png");
			REQUIRE(document.GetItem(1).GetImage()->GetWidth() == 150);
			REQUIRE(document.GetItem(1).GetImage()->GetHeight() == 100);
		}
	}

	SECTION("DeleteItem with start")
	{
		CDocument document;
		document.InsertParagraph("paragraph", 0);
		document.InsertImage("image.png", 150, 100, 1);

		document.DeleteItem(0);
		THEN("Image")
		{
			REQUIRE(document.GetItemsCount() == 1);
			REQUIRE(document.GetItem(0).GetImage()->GetPath() == "image.png");
			REQUIRE(document.GetItem(0).GetImage()->GetWidth() == 150);
			REQUIRE(document.GetItem(0).GetImage()->GetHeight() == 100);
		}

		document.DeleteItem(0);
		THEN("Size = 0")
		{
			REQUIRE(document.GetItemsCount() == 0);
		}
	}

	SECTION("DeleteItem with end")
	{
		CDocument document;
		document.InsertParagraph("paragraph", 0);
		document.InsertImage("image.png", 150, 100, 1);

		document.DeleteItem(1);
		THEN("Paragraph")
		{
			REQUIRE(document.GetItemsCount() == 1);
			REQUIRE(document.GetItem(0).GetParagraph()->GetText() == "paragraph");
		}

		document.DeleteItem(0);
		THEN("Size = 0")
		{
			REQUIRE(document.GetItemsCount() == 0);
		}
	}

	SECTION("ReplaceText")
	{
		CDocument document;
		document.InsertParagraph("paragraph #1", 0);
		document.InsertParagraph("paragraph #2", 0);

		document.ReplaceText("New paragraph #1", 0);
		THEN("New paragraph #1")
		{
			REQUIRE(document.GetItem(0).GetParagraph()->GetText() == "New paragraph #1");
		}

		document.ReplaceText("New paragraph #2", 1);
		THEN("New paragraph #2")
		{
			REQUIRE(document.GetItem(1).GetParagraph()->GetText() == "New paragraph #2");
		}
	}
}
