/*
 * Created By Valentin Favre (1°y in Esqese School in Numerical Sc.)
 * File :game.cpp
 * Description: Gestonnaire du geu entre les différentes étapes (menu, options et jeu "World")
 *
 */
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../../include/game/game.h"
#include "../../include/system/data.h"
#include "../../include/game/world.h"
#include "../../include/menu/pause.h"
#include "../../include/menu/main_options_menu.h"
#include "../../include/menu/main_menu.h"
#include "../../include/system/input.h"
#include "../../include/game/player.h"

Game::Game(std::string options_file) : options{loadOptionsFromFile(options_file)}, window{sf::VideoMode(1920, 1080), "Touhou XVI VallenStriker game's"}, finished{false} {
    pushState(GameStateType::MainMenu);
    window.setFramerateLimit(options.FRAME_LIMIT);
}

Game::~Game() {
    window.close();
    popState(0);
}

void Game::reloadOptions(std::string filename) {
    options = loadOptionsFromFile(filename);
}

void Game::handleInput() {
    while (!new_states.empty()) {
        auto p = new_states.front();
        new_states.pop();
        if (p.second != nullptr) {
            state.push_back(p.second);
        } else if (p.first == -1) {
            state.pop_back();
        } else {
            while ((int)state.size() > p.first) {
                state.pop_back();
            }
        }
    }
    if (state.empty()) finished = true;
    else state.back()->handleInput();
}

void Game::update() {
    if (state.empty()) finished = true;
    else state.back()->update();
}

void Game::draw() {
    if (state.empty()) finished = true;
    else state.back()->draw();
}

void Game::pushState(GameStateType gst) {
    switch (gst) {
        case GameStateType::MainMenu:
            new_states.push(std::make_pair(0, std::make_shared<MainMenu>(*this)));
            break;
        case GameStateType::PauseMenu:
            new_states.push(std::make_pair(0, std::make_shared<Pause>(*this)));
            break;
        case GameStateType::MainOptionsMenu:
            new_states.push(std::make_pair(0, std::make_shared<MainOptionsMenu>(*this)));
            break;
        case GameStateType::World:
            new_states.push(std::make_pair(0, std::make_shared<World>(*this)));
            break;
    }
}

void Game::popState(int to_size) {
    new_states.push(std::make_pair(to_size, nullptr));
}

GameState::GameState(Game &g) : parent{g}, window{g.getWindow()}, ih{std::make_unique<InputHandler>(g)} {}

void GameState::setKeymap(Keymap keymap) {
    ih->setKeymap(keymap);
}

void GameState::handleInput() {
    std::vector< std::shared_ptr<Command> > input = ih->handleInput(window);
    for (std::shared_ptr<Command> c : input) {
        c->execute();
    }
}
