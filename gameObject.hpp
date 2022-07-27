#pragma once

#include "game.hpp"
#include "ECS.hpp"
#include "assetsManager.hpp"

struct GameObject {
public:
	sdl::shared_ptr <SDL_Texture> texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
public:
	// defualt
	GameObject() {
		srcRect = { 0, 0, 0, 0 };
		destRect = { 0, 0, 0, 0 };
	};
	GameObject(
		const sdl::shared_ptr <SDL_Texture>& tex,
		const SDL_Rect& srcRect,
		const SDL_Rect& destRect
	);
	GameObject(GameObject&& obj) noexcept;
	GameObject(const GameObject& obj);
};