#pragma once

#include "game.hpp"
#include "ECS.hpp"

struct Sprite : public Component {
private:
	sdl::shared_ptr <SDL_Texture> texture;
	SDL_Rect srcRect; // TODO :: make srcRect unmodifiable after creation
	SDL_Rect destRect;
public:
	// defualt
	Sprite() {
		srcRect = { 0, 0, 0, 0 };
		destRect = { 0, 0, 0, 0 };
	};
	Sprite(
		const sdl::shared_ptr <SDL_Texture>& tex,
		const SDL_Rect& srcRect,
		const SDL_Rect& destRect
	);
	
	// spirte copy assignment constructor
	Sprite& operator=(const Sprite& other);
	
	// sprite move assignment constructor
	Sprite& operator=(Sprite&& other) noexcept;

	Sprite(Sprite&& obj) noexcept;
	Sprite(const Sprite& obj);
	
	// render
	void render() override;
	
	//update
	void update() override {};

	// set texture
	void setTexture(const sdl::shared_ptr <SDL_Texture>& tex);

	// change position
	inline void setPosition(int x, int y) {
		destRect.x = x;
		destRect.y = y;
	}
	// keep in mind linker does not respond kindly to inline functions
	// change size
	inline void setSize(int w, int h) {
		destRect.w = w;
		destRect.h = h;
	}
};