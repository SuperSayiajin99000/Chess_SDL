#include <iostream>
constexpr bool IS_ON = true;
constexpr bool IS_OFF = false;
constexpr char SEPERATOR_STR[] = "-------------------------------------\n";
#define DEBUG_MODE IS_ON
#include "game.hpp"
#include "textureManager.h"

game thisGame = game ( "CHESS" );
constexpr int ROWS = 8;
constexpr int COLS = 8;

std::vector < std::vector < std::shared_ptr <gameObject> > >
background (
    ROWS, std::vector <std::shared_ptr<gameObject>> (COLS)
);

void make_background () {
    bool isOdd = true;
    std::unordered_map <std::string, sdl::shared_ptr<SDL_Texture>>& gameTextures
        = thisGame.assets.gameTextures;

    for (auto& row: background) {
        for (auto& obj: row) {
            std::shared_ptr <gameObject> temp;
            if (isOdd) {
                temp->texture = gameTextures["square dark brown"];
            } else {
                temp->texture = gameTextures["square light brown"];
            }
            obj = std::move (temp);
            isOdd = !isOdd;
        }
    }
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
        HEIGHT(windowSize.second)
    {

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

        loadAssets ( );
    };


game::~game () {
    #if DEBUG_MODE == IS_ON
    std::cout << "Destroying the game. Please wait while we free your memory." << std::endl;
    #endif // DEBUG_MODE
    assets.gameTextures.clear ();
    SDL_Quit ();
    return;
}

const bool game::init ( ) {

    using namespace std;
#if DEBUG_MODE == IS_ON
    cout << "Starting initializations... " << endl;
#endif // DEBUG_MODE

    // SDL
    if ( SDL_Init (SDL_INIT_EVERYTHING) < 0 ) {

        #if DEBUG_MODE == IS_ON
            cout << "SDL initialization ERROR ::" << ' ' << SDL_GetError ( ) << endl;
        #endif // DEBUG_MODE
        return false;
    }
    #if DEBUG_MODE == IS_ON
    else cout << "SDL initialized successfully" << endl;
    #endif // DEBUG_MODE

    // SDL_image
    if ( !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) ) {

    #if DEBUG_MODE == IS_ON
        cout << "Failed to initialize SDL_image for PNG, ERROR :: " << IMG_GetError ( ) << endl;
    #endif // DEBUG_MODE
        return false;
    }

    #if DEBUG_MODE == IS_ON
    else cout << "SDL_image initialized successfully" << endl;

    cout << "All Initializations successfull" << endl;
    cout << SEPERATOR_STR;

    #endif // DEBUG_MODE

    return true;
}

void game::loadAssets ( ) {
    using namespace std;
    cout << "Loading Assets... " << endl;

    textureManager txmgr (renderer);

    assets.gameTextures ["square dark brown"] =
            txmgr.loadTexture
            ("./assets/PNGs/No shadow/128h/square brown dark_png_128px.png");

    assets.gameTextures ["square light brown"] =
            txmgr.loadTexture
            ("./assets/PNGs/No shadow/128h/square brown light_png_128px.png");

    assets.gameTextures ["square dark gray"] =
            txmgr.loadTexture
            ("./assets/PNGs/No shadow/128h/square gray dark_png_128px.png");

    assets.gameTextures ["square light gray"] =
            txmgr.loadTexture
            ("./assets/PNGs/No shadow/128h/square gray light_png_128px.png");

    make_background ();

    cout <<  assets.gameTextures.size() << " assets loaded." << endl;
//    assets.gameTextures.erase (assets.gameTextures.find ("square dark brown"));
    cout << "Assets successfully loaded " << endl;
    cout << SEPERATOR_STR;
}

void game::handleEvents () {
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
    for (const auto& row: background) {
        for (const auto& obj: row) {
            textureManager(renderer).draw (*obj);
        }
    }
}

void game::render ( ) { }

void game::clean ( ) { }

