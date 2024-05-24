#include <iostream>
#include <limits>

#include "game.h"

int main() {
    Game* game = new Game();
    game->game_loop(); 
    delete game;

    LOG("\nPress enter to exit.");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
