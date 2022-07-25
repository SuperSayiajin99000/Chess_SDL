
#pragma once
#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

// IO
#include <iostream>

// DS
#include <string>
#include <vector>
#include <array>
#include <unordered_map>

// mem & func
#include <memory>
#include <functional>

// SDL
#include "SDL.h"
#include "SDL_image.h"

// CUSTOM
#include "SDL_memory.h"

class game {
private: // all the stuff in the initializer list
    bool isPlaying;
    const int xPos, yPos;
    const int WIDTH, HEIGHT;
private:  // basic UI stuff
    SDL_Event windowEvent;
    bool m_isFullScreen = false;
public:
    static sdl::shared_ptr <SDL_Window> window;
    static sdl::shared_ptr <SDL_Renderer> renderer;
public:
    game (
        const std::string& windowName,
        const std::pair <int, int>& windowPos = {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED},
        const std::pair <int, int>& windowSize = {800, 600},
        bool fullscreen = false
    );
    ~game ( );

    const bool init ( );
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

    const inline bool isRunning ( ) const {
        return isPlaying;
    };
};

#endif // GAME_HPP_INCLUDED
