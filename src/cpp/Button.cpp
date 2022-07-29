//Headers:
#include <GUI\Button.hpp>

Button::Button(sf::Vector2f position, sf::Vector2f scale, sf::Color color) // Constructor.
{
    this -> setScale(scale);
    this -> setPosition(position);
    this -> clickedColor = color;
}

Button::~Button() // Destructor.
{}

void Button::update(sf::Event &event, sf::Clock &deltaTimeclock)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::RenderWindow* windowOfReference = this -> parentCanva -> getRenderWindow();
        sf::Vector2i mousePixelPos = sf::Mouse::getPosition(*windowOfReference);
        sf::Vector2f mouseFloatPos = windowOfReference -> mapPixelToCoords(mousePixelPos);

        if (this-> getGlobalBounds().contains(mouseFloatPos)) 
        {
            this -> setColor(this-> clickedColor);
        }

        else
        {
            this -> setColor(sf::Color::White);
        }
    }

    else
    {
        this -> setColor(sf::Color::White);
    }
}

void Button::fixedUpdate(sf::Event &event, float deltaTIme)
{}
