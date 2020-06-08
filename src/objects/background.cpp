/*
 * Created By Valentin Favre (1°y in Esqese School in Numerical Sc.)
 * File :background
 * Description:Dessine le Bg du world
 *
 */
#include "../../include/objects/background.h"
#include "../../include/system/data.h"
#include "../../include/objects/resources.h"

Background::Background(std::string filename, Options &options) : t{getResource<sf::Texture>(filename)}, s{t}, options{options} {
}

void Background::draw(sf::RenderWindow &w) {
    w.draw(s);
}
