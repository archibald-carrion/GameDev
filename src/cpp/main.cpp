//C++:
#include <iostream>

//SFML:
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//Headers:
#include <GUI\Button.hpp>

void check_key_pressed()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        std::cout << "UP\n\n";
    }
 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        std::cout << "DOWN\n\n";
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        std::cout << "LEFT\n\n";
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        std::cout << "RIGHT\n\n";
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        std::cout << "Z\n\n";
    }
}

//Este método funciona con cualquier joystick USB genérico.
//Detecta a un solo joystick.
//Es importante aclarar que para SFML el número de los botones empieza en 0 y no 1.
void check_joystick_button_pressed()
{
    if (sf::Joystick::isButtonPressed(0, 0))
    {
        std::cout << "0\n\n";
    }

    else if (sf::Joystick::isButtonPressed(0, 1))
    {
        std::cout << "1\n\n";
    }

    else if (sf::Joystick::isButtonPressed(0, 2))
    {
        std::cout << "2\n\n";
    }

    else if (sf::Joystick::isButtonPressed(0, 3))
    {
        std::cout << "3\n\n";
    }

    else if (sf::Joystick::isButtonPressed(0, 4))
    {
        std::cout << "4\n\n";
    }

    else if (sf::Joystick::isButtonPressed(0, 5))
    {
        std::cout << "5\n\n";
    }

    else if (sf::Joystick::isButtonPressed(0, 6))
    {
        std::cout << "6\n\n";
    }

    else if (sf::Joystick::isButtonPressed(0, 7))
    {
        std::cout << "7\n\n";
    }

    else if (sf::Joystick::isButtonPressed(0, 8))
    {
        std::cout << "8\n\n";
    }

    else if (sf::Joystick::isButtonPressed(0, 9))
    {
        std::cout << "9\n\n";
    }

    else if (sf::Joystick::isButtonPressed(0, 10))
    {
        std::cout << "10\n\n";
    }
}

void check_mouse_position(sf::Window &window) //Check the mouse position relative to the window.
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mouse_local_position = sf::Mouse::getPosition(window);

        std::cout << "Mouse X position: " << mouse_local_position.x << "\n\n";
        std::cout << "Mouse Y position: " << mouse_local_position.y << "\n\n\n\n";
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "GameDev");
    
    Canva myCanva(window);

    // La dirección de la textura debe estar al mismo nivel o más profundo de la carpeta del ejecutable
    // Se podrá resolver? Para que aloje imagenes directamente de src\res ? Ni idea
    sf::Texture myButtonTexture; 
    myButtonTexture.loadFromFile("undertale_button.jpg");

    std::shared_ptr<Button> boton_1(new Button(sf::Vector2f(100.f,100.f), sf::Vector2f(0.1f,0.1f), sf::Color::Green));
    boton_1 -> setTexture(myButtonTexture);
    myCanva.linkElement(boton_1);

    std::shared_ptr<Button> boton_2(new Button(sf::Vector2f(200.f,100.f), sf::Vector2f(0.1f,0.1f), sf::Color::Red));
    boton_2 -> setTexture(myButtonTexture);
    myCanva.linkElement(boton_2);

    sf::Clock deltaClock;

    //------------------------------------------
    //---AUDIO TEST---
    sf::Music music;
    music.openFromFile("Order_v1.ogg");
    music.play();
    //------------------------------------------

    while (window.isOpen())
    {
        deltaClock.restart();
        
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
                
            else
            {
                myCanva.update(event, deltaClock);
            }
        }

        //------------------------------------------
        window.clear();

        window.draw(myCanva);

        //User input check routines:
        check_key_pressed();
        check_joystick_button_pressed();
        check_mouse_position(window);

        window.display();
        //------------------------------------------
    }

    return 0;
}
