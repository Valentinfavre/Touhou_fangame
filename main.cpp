/*
 * Created By Valentin Favre (1°y in Esqese School in Numerical Sc.)
 * File :main.cpp
 * Description:Coeur du system (la boucle est réduite car son utilisation est comme
 * la SFML mais gérer par le moteur de jeu mis en place par moi méme et inspirée du systéme unity3D mis en place par
 * alexander Zohov sur unity 3d
 *
 *
 */
#include "./include/game/game.h"



int main() {
    sf::Music Music1;
    if (!Music1.openFromFile("../ressources/audio/gamethme.wav"))
    {
        // Erreur...
    }
    Music1.play();
    Game G;

    while (!G.isFinished()) {
        G.handleInput();
        G.update();
        G.draw();
    }
}
