add_executable(
        lw5
        main.cpp
        lib/Editor/CEditor.h
        lib/Editor/CEditor.cpp
        lib/Document/IDocument.h
        lib/Document/CDocument.h
        lib/Document/CDocument.cpp
        lib/Document/CConstDocumentItem.h
        lib/Document/CConstDocumentItem.cpp
        lib/Document/CDocumentItem.h
        lib/Document/CDocumentItem.cpp
        lib/History/CHistory.h
        lib/History/CHistory.cpp
        lib/Menu/CMenu.h
        lib/Menu/CMenu.cpp
        lib/Command/ICommand.h
        lib/Command/ICommand_fwd.h
        lib/Command/CAbstractCommand.h
        lib/Command/CAbstractCommand.cpp
        lib/Command/ChangeStringCommand/CChangeStringCommand.h
        lib/Command/ChangeStringCommand/CChangeStringCommand.cpp
        lib/Command/InsertParagraphCommand/CInsertDocumentItemCommand.h
        lib/Command/InsertParagraphCommand/CInsertDocumentItemCommand.cpp
        lib/Command/ReplaceTextCommand/CReplaceTextCommand.h
        lib/Command/ReplaceTextCommand/CReplaceTextCommand.cpp
        lib/Command/DeleteItemCommand/CDeleteItemCommand.h
        lib/Command/DeleteItemCommand/CDeleteItemCommand.cpp
        lib/Command/ResizeImageCommand/CResizeImageCommand.h
        lib/Command/ResizeImageCommand/CResizeImageCommand.cpp
        lib/Image/IImage.h
        lib/Image/CImage.h
        lib/Image/CImage.cpp
        lib/Paragraph/IParagraph.h
        lib/Paragraph/CParagraph.h
        lib/Paragraph/CParagraph.cpp
)

add_executable(
        lw5_test
        tests/lw5_test.cpp
        lib/Editor/CEditor.h
        lib/Editor/CEditor.cpp
        lib/Document/IDocument.h
        lib/Document/CDocument.h
        lib/Document/CDocument.cpp
        lib/Document/CConstDocumentItem.h
        lib/Document/CConstDocumentItem.cpp
        lib/Document/CDocumentItem.h
        lib/Document/CDocumentItem.cpp
        lib/History/CHistory.h
        lib/History/CHistory.cpp
        lib/Menu/CMenu.h
        lib/Menu/CMenu.cpp
        lib/Command/ICommand.h
        lib/Command/ICommand_fwd.h
        lib/Command/CAbstractCommand.h
        lib/Command/CAbstractCommand.cpp
        lib/Command/ChangeStringCommand/CChangeStringCommand.h
        lib/Command/ChangeStringCommand/CChangeStringCommand.cpp
        lib/Command/InsertParagraphCommand/CInsertDocumentItemCommand.h
        lib/Command/InsertParagraphCommand/CInsertDocumentItemCommand.cpp
        lib/Command/ReplaceTextCommand/CReplaceTextCommand.h
        lib/Command/ReplaceTextCommand/CReplaceTextCommand.cpp
        lib/Command/DeleteItemCommand/CDeleteItemCommand.h
        lib/Command/DeleteItemCommand/CDeleteItemCommand.cpp
        lib/Command/ResizeImageCommand/CResizeImageCommand.h
        lib/Command/ResizeImageCommand/CResizeImageCommand.cpp
        lib/Image/IImage.h
        lib/Image/CImage.h
        lib/Image/CImage.cpp
        lib/Paragraph/IParagraph.h
        lib/Paragraph/CParagraph.h
        lib/Paragraph/CParagraph.cpp
)
