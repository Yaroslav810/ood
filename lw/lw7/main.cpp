#include "lib/Canvas/CCanvas/CCanvas.h"
#include "lib/GroupShape/CGroupShape/CGroupShape.h"
#include "lib/Shape/CEllipse/CEllipse.h"
#include "lib/Shape/CRectangle/CRectangle.h"
#include "lib/Shape/CTriangle/CTriangle.h"
#include "lib/Slide/CSlide.h"
#include <SFML/Graphics.hpp>
#include <memory>

const int SLIDE_WIDTH = 1200;
const int SLIDE_HEIGHT = 800;

std::shared_ptr<IShape> CreateBackground()
{
	auto sky = std::make_shared<CRectangle>(PointD{ 0, 0 }, SLIDE_WIDTH, SLIDE_HEIGHT);
	sky->GetFillStyle()->SetColor(0x0000ffff);

	auto grass = std::make_shared<CRectangle>(PointD{ 0, 500 }, SLIDE_WIDTH, SLIDE_HEIGHT - 500);
	grass->GetFillStyle()->SetColor(0x00ff00ff);

	auto background = std::make_shared<CGroupShape>();
	background->InsertShape(sky, 0);
	background->InsertShape(grass, 1);

	return background;
}

std::shared_ptr<IShape> CreateSun()
{
	auto sun = std::make_shared<CEllipse>(PointD{ 1100, 700 }, 50, 50);
	sun->GetFillStyle()->SetColor(0xffff00ff);
	return sun;
}

std::shared_ptr<IShape> CreateHouse()
{
	auto main = std::make_shared<CRectangle>(PointD{ 200, 400 }, 200, 200);
	main->GetFillStyle()->SetColor(0x964b00ff);
	main->GetOutlineStyle()->SetColor(0xff3867ff);
	main->GetOutlineStyle()->SetThickness(3);

	auto roof = std::make_shared<CTriangle>(PointD{ 150, 400 }, PointD{ 300, 250 }, PointD{ 450, 400 });
	roof->GetFillStyle()->SetColor(0x4b4d4bff);
	roof->GetOutlineStyle()->SetColor(0x000000ff);
	roof->GetOutlineStyle()->SetThickness(3);

	auto flue = std::make_shared<CRectangle>(PointD{ 350, 250 }, 40, 100);
	flue->GetFillStyle()->SetColor(0xff0000ff);
	flue->GetOutlineStyle()->SetColor(0x000000ff);
	flue->GetOutlineStyle()->SetThickness(5);

	auto result = std::make_shared<CGroupShape>();
	result->InsertShape(main, 0);
	result->InsertShape(flue, 1);
	result->InsertShape(roof, 2);

	return result;
}

std::shared_ptr<IShape> CreatePond()
{
	auto pond = std::make_shared<CEllipse>(PointD{ 800, 150 }, 150, 50);
	pond->GetFillStyle()->SetColor(0x0000ffff);
	return pond;
}

std::shared_ptr<ISlide> CreateSlide()
{
	auto slide = std::make_shared<CSlide>(SLIDE_WIDTH, SLIDE_HEIGHT);
	slide->InsertShape(CreateBackground(), 0);
	slide->InsertShape(CreateSun(), 1);
	slide->InsertShape(CreateHouse(), 2);
	slide->InsertShape(CreatePond(), 3);

	return slide;
}

int main()
{
	auto slide = CreateSlide();
	auto width = slide->GetWidth();
	auto height = slide->GetHeight();

	sf::RenderWindow window(sf::VideoMode(width, height), "Slide");
	CCanvas canvas(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		slide->Draw(canvas);
		window.display();
	}

	return 0;
}
