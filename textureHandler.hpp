#pragma once
#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED

#include "game.hpp"
#include "Sprite.hpp"

class TextureHandler {
public:
    static std::unique_ptr <Sprite> loadTexture(const char* path);
};

#endif // TEXTUREMANAGER_H_INCLUDED
