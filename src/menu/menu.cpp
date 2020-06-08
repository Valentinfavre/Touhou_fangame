/*
 * Created By Valentin Favre (1°y in Esqese School in Numerical Sc.)
 * File :menu.cpp
 * Description:Coeur du menu du jeu avec affichage de text et du bg
 * (j'ai déssiner une petite forme rouge mais je m'en suis juste servi pour dire que je sais mettre une boule rouge)
 *
 */
#include <memory>
#include "../../include/menu/menu.h"
#include "../../include/objects/resources.h"

#define clip(x,a,b) (x < a ? a : (x > b ? b : x))

Menu::Menu(Game &g) : GameState{g}, cursor{0} {
    setKeymap({
        { {}, {sf::Keyboard::Up}, std::make_shared<Commands::Menu::CursorUp>(*this)},
        { {}, {sf::Keyboard::Down}, std::make_shared<Commands::Menu::CursorDown>(*this)},
        { {}, {sf::Keyboard::Return}, std::make_shared<Commands::Menu::Select>(*this)}
    });
};
sf::CircleShape selector(10);

void Menu::moveCursor(int delta) {
    cursor = clip(cursor + delta, 0, (int)menu_option.size()-1);
}

void Menu::update() {}

void Menu::draw() {
    window.clear();

    sf::Font f = getResource<sf::Font>("../ressources/fonts/Arcade.ttf");
    Menu::texbg;
    sf::CircleShape selector(10);
    selector.setFillColor(sf::Color(250, 0,0));

    if (!texbg.loadFromFile("../ressources/bg/menu.png"))
    {
        std::cout<<"Erreur au chargement"<< std::endl;
    }
    Menu::sprbg;
    sprbg.setTexture(texbg);
    window.draw(sprbg);
    window.draw(selector);

    int i = 0;
    for (std::string option : menu_option) {
        sf::Text t(option, f);
        t.setCharacterSize(48);
        t.setPosition({400, 600 + 75.f * i});
        if (cursor == i) {
            t.setFillColor(sf::Color::Green);
        }
        window.draw(t);
        i++;
    }
    window.display();
}

