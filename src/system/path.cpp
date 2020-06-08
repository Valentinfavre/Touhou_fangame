/*
 * Created By Valentin Favre (1°y in Esqese School in Numerical Sc.)
 * File :path.cpp
 * Description:pour les sauvegardes de paramétres et les gestionnaire non fini des formes de "fire bullet style"
 *
 */
#include "../../include/system/path.h"
#include "../../include/system/data.h"

Vec2 Paths::ThetaMag::loc(int t) {
    return v * (double)t;
}

Vec2 Paths::VelAcc::loc(int t) {
    return vel * (double)t + acc * (double)t*t/2.0;
}
