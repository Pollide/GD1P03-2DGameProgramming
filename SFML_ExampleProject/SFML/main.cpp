#include "SFML/Graphics.hpp"

void InputChecking(sf::RectangleShape* rect, sf::Vector2f* moveVec)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        moveVec->x = -5.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        moveVec->x = +5.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        moveVec->y = -5.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        moveVec->y = +5.0f;
    }

    rect->move(*moveVec);
}

int main()
{
    std::vector <sf::Shape*> shapes;

    // Player Input Move Vector
    sf::Vector2f moveVector;

    // Window Properties
    sf::RenderWindow window(sf::VideoMode(1024, 720), "SFML works!");

    // Circle Properties
    sf::CircleShape shape(50.0f);
    sf::Vector2f shapePos = sf::Vector2f(400, 300);
    shape.setPosition(shapePos);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setFillColor(sf::Color::Magenta);
    shape.setOutlineThickness(5.0f);
    shape.setOutlineColor(sf::Color::Red);

    shapes.push_back(&shape);

    // Rectangle Properties
    sf::RectangleShape rectShape;
    sf::Vector2f rectSize = sf::Vector2f(100, 50);
    rectShape.setSize(rectSize);
    rectShape.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
    rectShape.setOrigin(rectShape.getSize() / 2.0f);
    rectShape.setFillColor(sf::Color::Blue);

    shapes.push_back(&rectShape);

    while (window.isOpen())
    {
        moveVector.x = 0.0f;
        moveVector.y = 0.0f;
        sf::Event event; // Avoid putting game related stuff in the event section. All events require user input
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // Command to allow the window to be closed
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::A)
                {
                    shape.setRadius(shape.getRadius() + 1);
                    shape.setOutlineThickness(shape.getOutlineThickness() + 0.5);
                    shape.setOrigin(shape.getRadius(), shape.getRadius());
                }
                if (event.key.code == sf::Keyboard::D)
                {
                    shape.setRadius(shape.getRadius() - 1);
                    shape.setOutlineThickness(shape.getOutlineThickness() - 0.5);
                    shape.setOrigin(shape.getRadius(), shape.getRadius());
                }
            }
        }

        InputChecking(&rectShape, &moveVector);

        window.clear();
        for (int i = 0; i < shapes.size(); i++)
        {
            window.draw(*shapes[i]);
        }
        window.display();
    }

    return 0;
}