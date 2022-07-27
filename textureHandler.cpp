// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "textureHandler.hpp"

sdl::unique_ptr <SDL_Texture> textureHandler::loadTexture(const char* path) {
    return
    sdl::make_unique(
        SDL_CreateTextureFromSurface(
            game::renderer.get(),
            sdl::make_unique <SDL_Surface>(IMG_Load(path)).get()
        )
    );
}

void textureHandler::draw( const GameObject& obj ) {
    SDL_RenderCopy(
        game::renderer.get(),
        obj.texture.get(),
        &obj.srcRect,
        &obj.destRect
    );
}