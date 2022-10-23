#include "CDesigner.h"

CDesigner::CDesigner(IShapeFactory& factory)
	: m_factory(factory)
{
}

CPictureDraft CDesigner::CreateDraft(std::istream& strm)
{
	CPictureDraft pictureDraft;
	std::string command;
	while (std::getline(strm, command))
	{
		if (command == "exit")
		{
			break;
		}
		if (command == "help")
		{
			ExecuteHelpCommand();
			continue;
		}
		try
		{
			pictureDraft.AddShape(m_factory.CreateShape(command));
		}
		catch (const std::exception& exception)
		{
			std::cout << "Error: " << exception.what() << std::endl;
		}
	}

	return pictureDraft;
}

void CDesigner::ExecuteHelpCommand()
{
	auto indent = std::string(5, ' ');
	std::cout << "The following commands are available: " << std::endl;
	std::cout << indent << "- help - show available commands" << std::endl;
	std::cout << indent << "- rectangle <color> <left top x> <left top y> <right bottom x> <right bottom y> - creating a rectangle" << std::endl;
	std::cout << indent << "- triangle <color> <x1> <y1> <x2> <y2> <x3> <y3> - creating a triangle" << std::endl;
	std::cout << indent << "- ellipse <color> <x> <y> <horizontal radius> <vertical radius> - creating an ellipse" << std::endl;
	std::cout << indent << "- regular-polygon <color> <count> <x> <y> <radius> - creating a regular polygon" << std::endl;
	std::cout << indent << "- exit - exiting the program" << std::endl;
	std::cout << std::endl;
}
