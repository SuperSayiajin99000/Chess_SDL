#include <iostream>

#include "SDL.h"
#include "SDL_image.h"

#include "game.hpp"
#include "assetsMap.hpp"
#include "SDL_memory.h"
#include "textureManager.h"

constexpr bool IS_ON = true;
constexpr bool IS_OFF = false;
constexpr char SEPERATOR_STR[] = "-------------------------------------\n";
#define DEBUG_MODE IS_ON

extern assetsMap thisAssetsMap;
constexpr int WIN_W = 704, WIN_H = 640;

int main ( int argc, char* argv[] ) {

    using namespace std; // PLEASE DON'T USE OUTSIDE ANYWHERE !!!

    game thisGame = game (
        "CHESS",
        {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED},
        {WIN_W, WIN_H},
        false
    );
    thisAssetsMap.generateAssetsMap ( );

    constexpr int FPS = 60;
    constexpr int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;
    while ( thisGame.isRunning ( ) ) {
        frameStart = SDL_GetTicks();
        
        thisGame.handleEvents ( );
        thisGame.update ( );
        thisGame.render ( );

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < frameDelay) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    thisGame.clean ( );
    cout << "Game ended" << endl;
    return EXIT_SUCCESS;
}
