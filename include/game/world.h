#ifndef __WORLD_H_
#define __WORLD_H_

#include <vector>
#include <memory>
#include <SFML/Audio.hpp>
#include "game.h"
#include "../objects/background.h"
#include "../system/clock.h"


class Bullet;
class Spawner;
class Player;

class World : public GameState {
    std::unique_ptr<Player> player;
    std::vector< std::shared_ptr<Bullet> > bullet;
    std::vector< std::shared_ptr<Bullet> > player_bullet;
    std::vector< std::shared_ptr<Spawner> > spawner;
    sf::View view;

    Background b;

    void moveBullets(double);
    void spawnBullets();
    void spawnPlayerBullets();
    void checkCollisions();
    int getFrame();
    //int playmusic();

public:
    World(Game&);
    ~World();
    void registerBullet(std::shared_ptr<Bullet>);
    void registerPlayerBullet(std::shared_ptr<Bullet>);
    void registerSpawner(std::shared_ptr<Spawner>);

    void update() override;
    void draw() override;

private:

};


#endif
