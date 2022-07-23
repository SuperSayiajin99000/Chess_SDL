#include <iostream>
constexpr bool IS_ON = true;
constexpr bool IS_OFF = false;
constexpr char SEPERATOR_STR[] = "-------------------------------------\n";
#define DEBUG_MODE IS_ON

#include "SDL.h"
#include "SDL_image.h"
#include "game.hpp"
#include "SDL_memory.h"
#include "textureManager.h"

extern game thisGame;

int main ( int argc, char* argv[] ) {

    using namespace std; // PLEASE DON'T USE OUTSIDE ANYWHERE !!!

    while ( thisGame.isRunning ( ) ) {
        thisGame.handleEvents();
        thisGame.update ();
        thisGame.clean ();
    }

    cout << "Game ended" << endl;
    return EXIT_SUCCESS;
}
