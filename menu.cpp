//
// Created by favre.valentin on 29/04/2020.
//

#include "menu.hpp"
#include "main.hpp"


Menu::Menu(float width, float height) {


    if (!back.loadFromFile("../../Graphics/menu.png")) {
        // error...
    }
    back.setSmooth(true);
    bgi.setTexture(back);

    if (!font.loadFromFile("../../Graphics/Arcade.ttf")) {
        // Handle Error
    }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Green);
    menu[0].setString("Play");
    menu[0].setCharacterSize(70);
    menu[0].setPosition(sf::Vector2f(width / 5, height / (MAX_ITEMS + 1) * 1 + 200));

    menu[1].setColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setCharacterSize(70);
    menu[1].setPosition(sf::Vector2f(width / 5, height / (MAX_ITEMS + 1) * 2 + 100));
    menu[1].setFont(font);

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Quitter");
    menu[2].setCharacterSize(70);
    menu[2].setPosition(sf::Vector2f(width / 5, height / (MAX_ITEMS + 1) * 3));

    selectedItemIndex = 0;


}


void Menu::draw(sf::RenderWindow &window) {
    window.draw(bgi);
    for (int i = 0; i < MAX_ITEMS; ++i) {
        window.draw(menu[i]);

    }

}

void Menu::MoveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        std::cout << "up pressed" << std::endl;
        menu[selectedItemIndex].setColor(sf::Color::Green);
    }
}

void Menu::MoveDown() {
    if (selectedItemIndex + 1 < MAX_ITEMS) {

        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        std::cout << "donwpressed" << std::endl;
        menu[selectedItemIndex].setColor(sf::Color::Green);
    }
}