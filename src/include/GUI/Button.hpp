#pragma once

//Headers:
#include <GUI\CanvaElement.hpp>

// Hereda públicamente de la clase CanvaElement.

class Button: public CanvaElement
{
    protected:
        sf::Color clickedColor;

    public:
        Button(sf::Vector2f position = sf::Vector2f(10.f, 10.f), sf::Vector2f scale = sf::Vector2f(1.f, 1.f), sf::Color color = sf::Color::Green); // Constructor.
        ~Button(); // Destructor.

        virtual void update(sf::Event &event, sf::Clock &deltaTimeclock);
        virtual void fixedUpdate(sf::Event &event, float deltaTime = 0);
};
