/*
 * Created By Valentin Favre (1°y in Esqese School in Numerical Sc.)
 * File :bullet.cpp
 * Description:gestionnaire des "bullet" ainsi que leurs durée de vie pour eviter un overload de mémoire
 * (saturation graphique)
 *
 */
#include "../../include/objects/bullet.h"
#include "../../include/system/data.h"
#include "../../include/system/path.h"
#include <string>

Bullet::Bullet(Vec2 initial_loc, std::shared_ptr<Path> p, double radius) : Drawable{
    { {"../ressources/bullets/red.png"},
      {"../ressources/bullets/blue.png"},
      {"../ressources/bullets/green.png"},
      {"../ressources/bullets/Orange.png"},
      {"../ressources/bullets/purple.png"},
      {"../ressources/bullets/yellow.png"} } },
    initial_loc{initial_loc},
    p{p}, lifetime{0}, cache_time{-1}, hitbox_radius{radius} {}

Vec2 &Bullet::getLocation() {
    if (cache_time == lifetime) return loc_cache;
    cache_time = lifetime;
    loc_cache = initial_loc + p->loc(lifetime);
    return loc_cache;
}
