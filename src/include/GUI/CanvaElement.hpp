#pragma once

//C++:
#include <memory>

//SFML:
#include <SFML\Graphics.hpp>

//Headers:
#include <GUI\Canva.hpp>

//Clase base.

class Canva;

// Hereda públicamente de la clase sf::Sprite.
class CanvaElement: public sf::Sprite
{
    protected:
        std::shared_ptr<Canva> parentCanva; //Puntero al Canva al cuál pertenece.

    public:
        CanvaElement(); // Constructor.
        ~CanvaElement(); // Destructor.

        bool linkToParent(std::shared_ptr<Canva> parentToLink);
        bool unlinkFromParent();

        std::shared_ptr<Canva> getParent() const;

        virtual void update(sf::Event &event, sf::Clock &deltaTimeclock) = 0;
        virtual void fixedUpdate(sf::Event &event, float deltaTime = 0) = 0;

        friend class Canva;
};
