//C++:
#include <iostream> //Para la entrada y salida de datos por consola.
#include <time.h> //Header que contiene definiciones y funciones para trabajar con la fecha y hora de la máquina.

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

//Método que genera un número pseudoalteatoriamente de acuerdo a un rango determinado.
unsigned int generar_numero(unsigned int min, unsigned int max) // [min, max].
{
    srand(time(NULL));

    return min + (rand() % max);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "GameDev");
    
    Canva myCanva(window);

    // La dirección de la textura debe estar al mismo nivel o más profundo de la carpeta del ejecutable
    // Se podrá resolver? Para que aloje imagenes directamente de src\res ? Ni idea
    sf::Texture myButtonTexture; 
    myButtonTexture.loadFromFile("undertale_button.jpg");

    //-------------------------------------------------------------------------------------------------
    // Botones de opciones del menú principal:
    sf::Texture main_menu_start_button_texture; 
    main_menu_start_button_texture.loadFromFile("main_menu_start_button.jpg");

    std::shared_ptr<Button> boton_menu_principal_1(new Button(sf::Vector2f(300.f, 100.f), sf::Vector2f(0.1f, 0.1f), sf::Color::Black));
    boton_menu_principal_1 -> setTexture(main_menu_start_button_texture);
    myCanva.linkElement(boton_menu_principal_1);

    sf::Texture main_menu_settings_button_texture; 
    main_menu_settings_button_texture.loadFromFile("main_menu_settings_button.jpg");

    std::shared_ptr<Button> boton_menu_principal_2(new Button(sf::Vector2f(300.f, 200.f), sf::Vector2f(0.1f, 0.1f), sf::Color::Black));
    boton_menu_principal_2 -> setTexture(main_menu_settings_button_texture);
    myCanva.linkElement(boton_menu_principal_2);

    sf::Texture main_menu_exit_button_texture; 
    main_menu_exit_button_texture.loadFromFile("main_menu_exit_button.jpg");

    std::shared_ptr<Button> boton_menu_principal_3(new Button(sf::Vector2f(300.f, 300.f), sf::Vector2f(0.1f, 0.1f), sf::Color::Black));
    boton_menu_principal_3 -> setTexture(main_menu_exit_button_texture);
    myCanva.linkElement(boton_menu_principal_3);

    //-------------------------------------------------------------------------------------------------
    sf::Clock deltaClock;

    //------------------------------------------
    //---AUDIO TEST---
    sf::Music music;
    music.openFromFile("Order_v1.ogg");
    music.play();
    //------------------------------------------

    std::cout << "Num generado: " << generar_numero(1, 3) << "\n\n"; //Pruebas.

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
