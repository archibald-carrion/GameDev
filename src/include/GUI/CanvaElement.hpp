#pragma once

#include <SFML\Graphics.hpp>
#include <GUI\Canva.hpp>

#include <memory>

class Canva;

class CanvaElement: public sf::Sprite
{
    protected:
        std::shared_ptr<Canva> parentCanva;

    public:
        CanvaElement();
        ~CanvaElement();

        bool linkToParent(std::shared_ptr<Canva> parentToLink);
        bool unlinkFromParent();

        std::shared_ptr<Canva> getParent() const;

        virtual void update(sf::Event& event, sf::Clock& deltaTimeclock) = 0;
        virtual void fixedUpdate(sf::Event& event, float deltaTime = 0) = 0;

        friend class Canva;
};