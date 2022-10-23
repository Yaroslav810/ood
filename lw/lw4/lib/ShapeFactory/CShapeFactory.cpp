#include "CShapeFactory.h"

CShape::ShapePtr CShapeFactory::CreateShape(const std::string& description)
{
	auto command = ParseDescription(description);
	return GetShape(command);
}

CShapeFactory::Command CShapeFactory::ParseDescription(const std::string& description)
{
	std::istringstream line(description);
	std::string type;
	std::string argument;
	std::vector<std::string> arguments;

	line >> type;
	while (line >> argument)
	{
		arguments.push_back(argument);
	}

	return {
		type,
		arguments,
	};
}

CShape::ShapePtr CShapeFactory::GetShape(const CShapeFactory::Command& command)
{
	if (command.type == "rectangle")
	{
		return CreateRectangle(command.arguments);
	}
	if (command.type == "triangle")
	{
		return CreateTriangle(command.arguments);
	}
	if (command.type == "ellipse")
	{
		return CreateEllipse(command.arguments);
	}
	if (command.type == "regular-polygon")
	{
		return CreateRegularPolygon(command.arguments);
	}

	throw std::invalid_argument("Undefined state when executing a command");
}

Color CShapeFactory::GetColor(const std::string& color)
{
	if (color == "green")
	{
		return Color::Green;
	}
	if (color == "red")
	{
		return Color::Red;
	}
	if (color == "blue")
	{
		return Color::Blue;
	}
	if (color == "yellow")
	{
		return Color::Yellow;
	}
	if (color == "pink")
	{
		return Color::Pink;
	}
	if (color == "black")
	{
		return Color::Black;
	}

	throw std::invalid_argument("Undefined state when executing a color");
}

CShape::ShapePtr CShapeFactory::CreateRectangle(const std::vector<std::string>& arguments)
{
	if (arguments.size() != 5)
	{
		throw std::invalid_argument("The rectangle is expected to have 5 arguments. Received: " + std::to_string(arguments.size()));
	}

	Color color = GetColor(arguments[0]);
	CPoint leftTop(std::stod(arguments[1]), std::stod(arguments[2]));
	CPoint rightBottom(std::stod(arguments[3]), std::stod(arguments[4]));
	return std::make_unique<CRectangle>(color, leftTop, rightBottom);
}

CShape::ShapePtr CShapeFactory::CreateTriangle(const std::vector<std::string>& arguments)
{
	if (arguments.size() != 7)
	{
		throw std::invalid_argument("The triangle is expected to have 7 arguments. Received: " + std::to_string(arguments.size()));
	}

	Color color = GetColor(arguments[0]);
	CPoint firstVertex = { std::stod(arguments[1]), std::stod(arguments[2]) };
	CPoint secondVertex = { std::stod(arguments[3]), std::stod(arguments[4]) };
	CPoint thirdVertex = { std::stod(arguments[5]), std::stod(arguments[6]) };
	return std::make_unique<CTriangle>(color, firstVertex, secondVertex, thirdVertex);
}

CShape::ShapePtr CShapeFactory::CreateEllipse(const std::vector<std::string>& arguments)
{
	if (arguments.size() != 5)
	{
		throw std::invalid_argument("The ellipse is expected to have 5 arguments. Received: " + std::to_string(arguments.size()));
	}

	Color color = GetColor(arguments[0]);
	CPoint center = { std::stod(arguments[1]), std::stod(arguments[2]) };
	auto horizontalRadius = std::stod(arguments[3]);
	auto verticalRadius = std::stod(arguments[4]);
	return std::make_unique<CEllipse>(color, center, horizontalRadius, verticalRadius);
}

CShape::ShapePtr CShapeFactory::CreateRegularPolygon(const std::vector<std::string>& arguments)
{
	if (arguments.size() != 5)
	{
		throw std::invalid_argument("The regular polygon is expected to have 5 arguments. Received: " + std::to_string(arguments.size()));
	}

	Color color = GetColor(arguments[0]);
	int vertexCount = std::stoi(arguments[1]);
	CPoint center = { std::stod(arguments[2]), std::stod(arguments[3]) };
	auto radius = std::stod(arguments[4]);
	return std::make_unique<CRegularPolygon>(color, vertexCount, center, radius);
}
