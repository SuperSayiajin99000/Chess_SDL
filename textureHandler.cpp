// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "TextureHandler.hpp"
#include "Sprite.hpp"

std::unique_ptr <Sprite> TextureHandler::loadTexture(const char* path) {
    sdl::unique_ptr <SDL_Surface> surface = sdl::make_unique(
        IMG_Load(path)
    );
	if (surface == nullptr) {
		throw std::runtime_error(
			"Failed to load texture: " + std::string(path) +
			": " + std::string(IMG_GetError())
		);
	}
    return std::make_unique <Sprite> (
        Sprite (
            sdl::make_shared <SDL_Texture> (
                SDL_CreateTextureFromSurface(
                    game::renderer.get(),
                    surface.get ()
                )
            ),
            {0, 0, surface->w, surface->h},
            {0, 0, 0, 0}
        )
    );
}