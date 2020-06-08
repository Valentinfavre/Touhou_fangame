/*
 * Created By Valentin Favre (1°y in Esqese School in Numerical Sc.)
 * File :player.cpp
 * Description:utilitaire du joueur ainsi que le gestionaires de tir.
 *
 */
#include "../../include/objects/bullet.h"
#include "../../include/game/player.h"
#include "../../include/system/path.h"

Player::Player() : Drawable{ { { "../ressources/img/reimu.png" } } } {
    hitbox_radius = PLAYER_HITBOX_RADIUS;
    p = std::make_shared<Paths::ThetaMag>(-PI/2.0, 10);
}

std::vector< std::shared_ptr<Bullet> > Player::getBullets() {
    std::vector< std::shared_ptr<Bullet> > bullets;
    bullets.push_back(std::make_shared<Bullet>(getLocation(),p));;
    return bullets;
}
