
#pragma once
#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include <SDL.h>
#include <SDL_image.h>
#include "SDL_memory.h"

struct point {
    int x;
    int y;
};

struct gameObject {
    sdl::shared_ptr <SDL_Texture> texture;
    point pos;
    SDL_Rect srcRect;
    SDL_Rect destRect;

    gameObject () {
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32;
        destRect.x = destRect.y = 0;
        destRect.w = destRect.h = 32;
    }
};

class game {
private: // all the stuff in the initializer list
    bool isPlaying;
    const int xPos, yPos;
    const int WIDTH, HEIGHT;
private:  // basic UI stuff
    sdl::shared_ptr <SDL_Window> window;
    sdl::shared_ptr <SDL_Renderer> renderer;
    SDL_Event windowEvent;
    bool m_isFullScreen = false;
public: // game assets
    struct assets {
        std::unordered_map < std::string, sdl::shared_ptr <SDL_Texture> > gameTextures; // should be enums ideally
    } assets;
public:
    game (
        const std::string& windowName,
        const std::pair <int, int>& windowPos = {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED},
        const std::pair <int, int>& windowSize = {800, 600},
        bool fullscreen = false
    );
    ~game ( );

    const bool init ( );
    void loadAssets ( );
    void update ( );
    void handleEvents( );
    void render ( );
    void clean ( );

    void fullscreen_toogle ( ) {
        m_isFullScreen = !m_isFullScreen;
    }

    const inline bool isFullScreen ( ) const {
        return m_isFullScreen;
    }

    const inline bool isRunning ( ) const
    {
        return isPlaying;
    };
};

#endif // GAME_HPP_INCLUDED
