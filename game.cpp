#include "game.hpp"
#include "gameObject.hpp"
#include "textureManager.h"
#include "assetsMap.hpp"
#include "board.hpp"


constexpr bool IS_ON = true;
constexpr bool IS_OFF = false;

#define DEBUG_MODE IS_ON

constexpr char SEPERATOR_STR [] = 
"-------------------------------------\n";

sdl::shared_ptr <SDL_Window> game::window = nullptr;
sdl::shared_ptr <SDL_Renderer> game::renderer = nullptr;

extern enum TEXTURE_NAMES textureNames;
auto thisAssetsMap = assetsMap ();
auto thisBoard = board();


const bool game::init() {

    using namespace std;

    // SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {

#if DEBUG_MODE == IS_ON
        cout << "SDL initialization ERROR ::" << ' ' << SDL_GetError() << endl;
#endif // DEBUG_MODE
        return false;
    }

    // SDL_image
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {

#if DEBUG_MODE == IS_ON
        cout << "Failed to initialize SDL_image for PNG, ERROR :: " << IMG_GetError() << endl;
#endif // DEBUG_MODE
        return false;
    }

    cout << "All Initializations successfull" << endl;
    cout << SEPERATOR_STR;

    return true;
}

game::game (
    const std::string& windowName,
    const std::pair <int, int>& windowPos,
    const std::pair <int, int>& windowSize,
    bool fullscreen
) :

isPlaying (true),
xPos(windowPos.first),
yPos(windowPos.second),
WIDTH (windowSize.first),
HEIGHT(windowSize.second) {
    
    using namespace std;

    if ( init () == false )
    {

        cout << "INITILIZATIONS FAILED!" << endl;

        isPlaying = false;

        return;
    }

    auto flags = ((fullscreen) ? SDL_WINDOW_FULLSCREEN : 0);

    // ---------- create window -------------
    this->window =
        sdl::make_shared (SDL_CreateWindow (
            windowName.c_str( ),         // name of the application window
            xPos, yPos,                  // x, y COORDs of the window on screen
            WIDTH, HEIGHT,               // size of the window
            flags
        ));

    if ( this->window == nullptr )
    {

        std::cout << "SDL could not create window, ERROR :: " << SDL_GetError ( ) << std::endl;

        isPlaying = false;

        return;
    }

    this->renderer = sdl::make_shared (SDL_CreateRenderer ( this->window.get (), -1, 0 ));

    if ( renderer == nullptr )
    {

        std::cout << "SDL could not create renderer, ERROR :: " << SDL_GetError ( ) << std::endl;

        isPlaying = false;

        return;
    }

    SDL_SetRenderDrawColor(renderer.get ( ), 255, 255, 255, 255);

    thisAssetsMap.generateAssetsMap();
    thisBoard.makeBoardRenderMatrix();
};


game::~game () {
    #if DEBUG_MODE == IS_ON
    std::cout << "Destroying the game. Please wait while we free your memory." << std::endl;
    #endif // DEBUG_MODE
    SDL_Quit ();
    return;
}

void game::handleEvents ( ) {
    if ( SDL_PollEvent ( &windowEvent ) ) {
        switch (windowEvent.type) {
        case SDL_QUIT:
            isPlaying = false;
            return;
        default:
            return;
        }
    }
}

void game::update ( ) {
    
}

void game::render ( ) {  
    static const auto& background = thisAssetsMap.background;
    SDL_RenderClear( game::renderer.get ( ) );
    
    // empty space
    SDL_RenderCopy(renderer.get ( ),
        thisAssetsMap.textures.map[sq_light_gray].get( ),
        NULL, NULL);
    // game board
    board::renderTheMatrix();

    SDL_RenderPresent( game::renderer.get ( ) );
}

void game::clean ( ) {  }