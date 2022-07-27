// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "Sprite.hpp"
#include "TextureHandler.hpp"

// constructor
Sprite::Sprite(
    const sdl::shared_ptr<SDL_Texture>& tex, 
    const SDL_Rect& srcRect, 
    const SDL_Rect& destRect 
) :
    texture(tex),
    srcRect(srcRect),
    destRect(destRect) 
{};


// move constructor
Sprite::Sprite(Sprite&& obj) noexcept :
    texture(obj.texture),
    srcRect(obj.srcRect),
    destRect(obj.destRect)
{};

// copy constructor
Sprite::Sprite(const Sprite& obj) :
	texture(obj.texture),
	srcRect(obj.srcRect),
	destRect(obj.destRect)
{};

// sprite copy assignment constructor
Sprite& Sprite::operator=(const Sprite& obj) {
	texture = obj.texture;
	srcRect = obj.srcRect;
	destRect = obj.destRect;
	return *this;
}

// sprite move assignment constructor
Sprite& Sprite::operator=(Sprite&& obj) noexcept {
	texture = obj.texture;
	srcRect = obj.srcRect;
	destRect = obj.destRect;
	return *this;
}

// render
void Sprite::render() {
	SDL_RenderCopy(
		game::renderer.get ( ),
		texture.get( ),
		&srcRect,
		&destRect
	);
}

// set texture
void Sprite::setTexture(const sdl::shared_ptr<SDL_Texture>& tex) {
	texture = tex;
}
