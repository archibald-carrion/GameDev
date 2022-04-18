#pragma once

#include <GUI\CanvaElement.hpp>

class Button: public CanvaElement
{
    protected:
        sf::Color clickedColor;

    public:
        Button(sf::Vector2f pos = sf::Vector2f(10.f,10.f), sf::Vector2f scale = sf::Vector2f(1.f,1.f), sf::Color color = sf::Color::Green);
        ~Button();

        virtual void update(sf::Event& event, sf::Clock& deltaTimeclock);
        virtual void fixedUpdate(sf::Event& event, float deltaTime = 0);
};