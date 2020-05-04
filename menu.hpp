//
// Created by favre.valentin on 29/04/2020.
//

#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


#define MAX_ITEMS 3

class Menu {
public:
    Menu(float width, float height);


    void draw(sf::RenderWindow &window);

    void MoveUp();

    void MoveDown();

    int Getpresseditem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_ITEMS];
    sf::Texture back;
    sf::Sprite bgi;


};



