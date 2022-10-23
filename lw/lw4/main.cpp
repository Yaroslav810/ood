#include "lib/Canvas/CCanvas.h"
#include "lib/Designer/CDesigner.h"
#include "lib/Painter/CPainter.h"
#include "lib/ShapeFactory/CShapeFactory.h"
#include <iostream>

int main()
{
	CShapeFactory shapeFactory;
	CDesigner designer(shapeFactory);
	CPictureDraft pictureDraft = designer.CreateDraft(std::cin);

	CCanvas canvas;
	CPainter::DrawPicture(pictureDraft, canvas);
}
