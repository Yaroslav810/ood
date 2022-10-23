#pragma once
#include "../Color/Color.h"
#include "../Point/CPoint.h"
#include "../Shape/Ellipse/CEllipse.h"
#include "../Shape/Rectangle/CRectangle.h"
#include "../Shape/RegularPolygon/CRegularPolygon.h"
#include "../Shape/Triangle/CTriangle.h"
#include "./IShapeFactory.h"
#include <functional>
#include <map>
#include <sstream>
#include <vector>

class CShapeFactory : public IShapeFactory
{
public:
	CShape::ShapePtr CreateShape(const std::string& description) override;

private:
	struct Command
	{
		std::string type;
		std::vector<std::string> arguments;
	};
	Command ParseDescription(const std::string& description);
	CShape::ShapePtr GetShape(const Command& command);
	Color GetColor(const std::string& color);
	CShape::ShapePtr CreateRectangle(const std::vector<std::string>& arguments);
	CShape::ShapePtr CreateTriangle(const std::vector<std::string>& arguments);
	CShape::ShapePtr CreateEllipse(const std::vector<std::string>& arguments);
	CShape::ShapePtr CreateRegularPolygon(const std::vector<std::string>& arguments);
};
