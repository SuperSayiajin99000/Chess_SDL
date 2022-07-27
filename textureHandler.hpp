#pragma once
#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED

#include "game.hpp"
#include "gameObject.hpp"

class textureHandler {
public:
    static sdl::unique_ptr <SDL_Texture> loadTexture(const char* path);

    static void draw(const GameObject& obj);
};

#endif // TEXTUREMANAGER_H_INCLUDED
