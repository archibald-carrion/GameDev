#pragma once

//C++:
#include <memory>
#include <vector>

//SFML:
#include <SFML\Graphics.hpp>

//Headers:
#include <GUI\CanvaElement.hpp>

class CanvaElement;

class Canva: public sf::Drawable
{
    protected:
        sf::RenderWindow *renderWindowRef;
        std::vector<std::shared_ptr<CanvaElement>> elements; // Vector para almacenar punteros a CanvaElements.

    public:
        Canva(sf::RenderWindow &windowRef); // Constructor.
        ~Canva(); // Destructor.

        bool linkElement(std::shared_ptr<CanvaElement> elementToAdd);
        bool unlinkElement(std::shared_ptr<CanvaElement> elementToAdd);
        bool hasElement(std::shared_ptr<CanvaElement> elementToSearch) const;

        std::shared_ptr<CanvaElement> getElement(unsigned int index) const;
        sf::RenderWindow *getRenderWindow() const;

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        virtual void update(sf::Event &event, sf::Clock &deltaTimeclock);
        virtual void fixedUpdate(sf::Event &event, float deltaTime = 0);

        friend class CanvaElement;
};
