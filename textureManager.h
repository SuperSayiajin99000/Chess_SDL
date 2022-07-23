#pragma once
#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED

#include "game.hpp"
#include "sdl_image.h"

class textureManager {
private:
    sdl::shared_ptr <SDL_Renderer> ren;
public:
    textureManager (sdl::shared_ptr <SDL_Renderer> ren) : ren (ren) {};

    sdl::unique_ptr <SDL_Texture> loadTexture (const char* path) {
        return
        sdl::make_unique (
             SDL_CreateTextureFromSurface (
                ren.get (),
                sdl::make_unique <SDL_Surface> ( IMG_Load (path) ).get()
            )
        );
    }

    inline void draw (const gameObject& obj) {
        SDL_RenderCopy (
            ren.get(),
            obj.texture.get(),
            &obj.srcRect,
            &obj.destRect
        );
    }
};


#endif // TEXTUREMANAGER_H_INCLUDED
