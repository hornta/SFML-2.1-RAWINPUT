#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Mithrandir");
	/*
	*	false(default): (no events are fired)
	*	true: Register raw input for mice(events are fired)
	*/
	window.setRelativeMouseMode(true);
	window.setMouseCursorVisible(false);

	// Apply the mouse velocity to this shape
	sf::CircleShape shape;
	shape.setFillColor(sf::Color::Yellow);
	shape.setRadius(10);
	shape.setOrigin(10, 10);

	// A vector to hold the changes given from sf::Event::MouseMotion
	sf::Vector2f changes;

    while (window.isOpen())
    {
		// Offset to the shapes position
		changes = shape.getPosition();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed))
            {
                window.close();
                break;
            }

			if (event.type == sf::Event::MouseMotion)
			{
				// Apply the change from the mouse to variable
				changes.x += event.mouseMotion.x;
				changes.y += event.mouseMotion.y;
			}
		}

		// When the mouse is moved, the shapes behaves(moves) like a system cursor would do. Perfect for FPS.
		shape.setPosition(changes);

        window.clear();
		window.draw(shape);
        window.display();
    }
    return 0;
}
