#pragma once
#include "../Canvas/ICanvas.h"
#include "../PictureDraft/CPictureDraft.h"

class CPainter
{
public:
	static void DrawPicture(const CPictureDraft& pictureDraft, ICanvas& canvas);
};
