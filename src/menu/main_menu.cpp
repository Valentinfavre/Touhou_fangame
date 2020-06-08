/*
 * Created By Valentin Favre (1°y in Esqese School in Numerical Sc.)
 * File :main.menu_cpp
 * Description:Menu de selection
 *
 */
#include "../../include/menu/main_menu.h"
#include "../../include/objects/resources.h"
#include "../../include/game/world.h"
#include "../../include/menu/main_options_menu.h"

MainMenu::MainMenu(Game &g) : Menu{g} {
    menu_option = {"Play", "Options", "Quitter"};
}

void MainMenu::select() {
    switch (cursor) {
        case 0:
            parent.pushState(GameStateType::World);
            break;
        case 1:
            parent.pushState(GameStateType::MainOptionsMenu);
            break;
        case 2:
            parent.popState();
            break;
    }
}
