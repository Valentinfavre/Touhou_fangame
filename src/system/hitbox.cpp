/*
 * Created By Valentin Favre (1°y in Esqese School in Numerical Sc.)
 * File :htbox.cpp
 * Description:hitbox x) en 1 mot pour 1 ligne XD
 *
 */
#include "../../include/system/hitbox.h"
#include "../../include/system/data.h"

bool intersect(Hitbox hitbox_1, Hitbox hitbox_2) {
    return magnitude(hitbox_1.first - hitbox_2.first) < hitbox_1.second + hitbox_2.second;
}
