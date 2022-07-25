#pragma once
#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED

#include "game.hpp"
#include "gameObject.hpp"

class textureManager {
public:
    static inline sdl::unique_ptr <SDL_Texture> loadTexture (const char* path) {
        return
        sdl::make_unique (
             SDL_CreateTextureFromSurface (
                game::renderer.get ( ),
                sdl::make_unique <SDL_Surface> ( IMG_Load (path) ).get( )
            )
        );
    }

    static inline void draw ( const gameObject& obj ) {
        SDL_RenderCopy (
            game::renderer.get ( ),
            obj.texture.get ( ),
            &obj.srcRect,
            &obj.destRect
        );
    }
};


#endif // TEXTUREMANAGER_H_INCLUDED
