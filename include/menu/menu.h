#ifndef __MENU_H_
#define __MENU_H_

#include <vector>
#include <iostream>
#include <SFML/Audio.hpp>
#include "../system/input.h"
#include "../game/game.h"

class Menu : public GameState {
protected:
    int cursor;
    std::vector<std::string> menu_option;
    sf::Texture texbg;
    sf::Sprite sprbg;

public:
    Menu(Game&);
    virtual ~Menu() = default;


    void moveCursor(int delta);
    virtual void select() = 0;

    virtual void update();
    virtual void draw();
};

#endif
