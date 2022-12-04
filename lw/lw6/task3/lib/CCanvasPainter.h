#pragma once
#include "CModernGraphicsLibAdapter.h"
#include "modern_graphics_lib/modern_graphics_lib.h"
#include "shape_drawing_lib/shape_drawing_lib.h"

// Пространство имен приложения (доступно для модификации)
namespace app
{
void PaintPicture(shape_drawing_lib::CCanvasPainter& painter)
{
	using namespace shape_drawing_lib;

	CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 }, 0xff00ff);
	CRectangle rectangle({ 30, 40 }, 18, 24, 0x00ff00);

	// TODO: нарисовать прямоугольник и треугольник при помощи painter
	painter.Draw(triangle);
	painter.Draw(rectangle);
}

void PaintPictureOnCanvas()
{
	graphics_lib::CCanvas simpleCanvas;
	shape_drawing_lib::CCanvasPainter painter(simpleCanvas);
	PaintPicture(painter);
}

void PaintPictureOnModernGraphicsRenderer()
{
	modern_graphics_lib::CModernGraphicsRenderer renderer(std::cout);
	CModernGraphicsLibAdapter adapterModernGraphicsRenderer(renderer);
	shape_drawing_lib::CCanvasPainter painter(adapterModernGraphicsRenderer);

	renderer.BeginDraw();
	PaintPicture(painter);
	renderer.EndDraw();
}
} // namespace app