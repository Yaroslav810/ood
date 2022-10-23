#include "CPainter.h"

void CPainter::DrawPicture(const CPictureDraft& pictureDraft, ICanvas& canvas)
{
	auto shapeCount = pictureDraft.GetShapesCount();
	for (int i = 0; i < shapeCount; ++i)
	{
		pictureDraft.GetShape(i).Draw(canvas);
	}
}
