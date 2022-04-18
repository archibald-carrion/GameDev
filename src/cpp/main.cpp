#include <SFML/Graphics.hpp>

#include <GUI\Button.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Pruebita Boton :D");
    
    Canva myCanva(window);

    // La dirección de la textura debe estar al mismo nivel o más profundo de la carpeta del ejecutable
    // Se podrá resolver? Para que aloje imagenes directamente de src\res ? Ni idea
    sf::Texture myButtonTexture; myButtonTexture.loadFromFile("undertale_button.jpg");

    std::shared_ptr<Button> boton_1(new Button(sf::Vector2f(100.f,100.f), sf::Vector2f(0.1f,0.1f), sf::Color::Green) );
    boton_1->setTexture(myButtonTexture); myCanva.linkElement(boton_1);

    std::shared_ptr<Button> boton_2(new Button( sf::Vector2f(200.f,100.f), sf::Vector2f(0.1f,0.1f), sf::Color::Red) );
    boton_2->setTexture(myButtonTexture); myCanva.linkElement(boton_2);

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        deltaClock.restart();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else
                myCanva.update(event, deltaClock);
        }

        window.clear();
        window.draw(myCanva);
        window.display();
    }

    return 0;
}