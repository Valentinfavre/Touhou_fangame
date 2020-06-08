//
// Created by favre.valentin on 31/05/2020.
//

#ifndef TOUHOU_FLANDRE_AUDIO_H
#define TOUHOU_FLANDRE_AUDIO_H

#include <SFML/Audio.hpp>

class sound {
public:
    void firesound();
    void spawnbullet();
    static void playtheme();
    void playmenu();


protected:
    sf::Music theme;
    sf::Music Menutheme;
    sf::Sound fire;
    sf::Sound bullet;
    sf::SoundBuffer firebf;
    sf::SoundBuffer bulletbf;
};

#endif //TOUHOU_FLANDRE_AUDIO_H
