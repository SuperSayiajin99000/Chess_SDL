
#include "game.hpp"
#include "assetsMap.hpp"
#include "gameObjectsMap.hpp"
#include "board.hpp"

constexpr int WIN_W = 704, WIN_H = 640;

assetsMap       thisAssetsMap     ;
gameObjectsMap  thisGameObjectsMap;
board           thisBoard         ;

int main ( int argc, char* argv[] ) {

    using namespace std; // PLEASE DON'T USE OUTSIDE ANYWHERE !!!

    game thisGame = game (
        "CHESS",
        {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED},
        {WIN_W, WIN_H},
        false
    );
    
    thisAssetsMap = assetsMap();
    thisAssetsMap.generate();

    thisGameObjectsMap = gameObjectsMap();
    thisGameObjectsMap.generate();

    thisBoard = board();
    thisBoard.makeBoardRenderMatrix();

    constexpr int FPS = 10;
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
    
    if (!std::string(SDL_GetError()).empty()) {
        return EXIT_FAILURE;
    }
    
    cout << "Game ended" << endl;

    return EXIT_SUCCESS;
}
