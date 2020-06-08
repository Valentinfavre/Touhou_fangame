/*
 * Created By Valentin Favre (1°y in Esqese School in Numerical Sc.)
 * File :clock.cpp
 * Description:gestionnaire d'horloges
 *
 */
#include "../../include/system/clock.h"

sf::Time Clock::getElapsedTime() {
    return clock.getElapsedTime() - pause_time;
}

sf::Time Clock::lap() {
    sf::Time ret = clock.getElapsedTime() - lap_time;
    lap_time = clock.getElapsedTime();
    return ret;
}

int Clock::getTicker() {
    return ticker;
}

void Clock::restart() {
    pause_time = sf::Time{};
    lap_time = sf::Time{};
    clock = sf::Clock{};
    pause_clock = sf::Clock{};
}

void Clock::pause() {
    pause_clock.restart();
}

void Clock::resume() {
    sf::Time t = pause_clock.getElapsedTime();
    pause_time += t;
    lap_time += t;
}

void Clock::tick() {
    ticker++;
}
