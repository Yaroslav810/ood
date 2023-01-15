#include "lib/Canvas/CCanvas.h"
#include "lib/Designer/CDesigner.h"
#include "lib/Painter/CPainter.h"
#include "lib/ShapeFactory/CShapeFactory.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

int main()
{
	CShapeFactory shapeFactory;
	CDesigner designer(shapeFactory);
	CPictureDraft pictureDraft = designer.CreateDraft(std::cin);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Slide");
	CCanvas canvas(window);
	while (window.isOpen())
	{
		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		CPainter::DrawPicture(pictureDraft, canvas);
		window.display();
	}
}
