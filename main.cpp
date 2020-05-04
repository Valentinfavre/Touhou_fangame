//
// Created by favre.valentin on 17/04/2020.
//

#include "main.hpp"
#include "menu.hpp"

int main() {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Touhou XVI, Revenge of Flandre Scarlet ",
                            sf::Style::Fullscreen);

    Menu menu(window.getSize().x, window.getSize().y);

    // Fais Tourner le programme
    while (window.isOpen()) {
        // Check les events du jeu
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {

                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.Getpresseditem()) {
                                case 0:
                                    std::cout << "play button was selected" << std::endl;
                                    break;
                                case 1:
                                    std::cout << "option Button was selected" << std::endl;
                                    break;
                                case 2:
                                    std::cout << "Quit Game was Selected" << std::endl;
                                    window.close();
                                    break;


                            }
                    }

            }
            // Requéte de fermeture de fenétre et de fin de programme
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        window.clear();

        menu.draw(window);


        window.display();
    }

    return 0;

}