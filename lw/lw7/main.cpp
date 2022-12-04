#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::VertexArray rect(sf::Quads, 4);
	double thickness = 20;
	sf::Vector2f start(10, 10);
	sf::Vector2f end(150, 150);

	sf::Vector2f difference = start - end;
	sf::Vector2f perpendicular(-difference.y / difference.x, 1);
	sf::Vector2f offset = float(thickness / 2) * perpendicular;
	rect[0].position = start + offset;
	rect[1].position = end + offset;
	rect[2].position = end - offset;
	rect[3].position = start - offset;
	rect[0].color = sf::Color::Red;
	rect[1].color = sf::Color::Red;
	rect[2].color = sf::Color::Red;
	rect[3].color = sf::Color::Red;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);

		sf::Vertex line[] = {
			sf::Vertex(sf::Vector2f(10, 10)),
			sf::Vertex(sf::Vector2f(150, 150))
		};

		window.draw(rect);
		window.draw(line, 2, sf::Lines);

		window.display();
	}

	return 0;
}
