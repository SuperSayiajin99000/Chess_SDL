// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "gameObject.hpp"


GameObject::GameObject(
    const sdl::shared_ptr <SDL_Texture>& tex,
    const SDL_Rect& srcRect,
    const SDL_Rect& destRect
) :
    texture(tex),
    srcRect(srcRect),
    destRect(destRect)
{};

// move constructor
GameObject::GameObject(GameObject&& obj) noexcept :
    texture(obj.texture),
    srcRect(obj.srcRect),
    destRect(obj.destRect)
{};

// copy constructor
GameObject::GameObject(const GameObject& obj) :
	texture(obj.texture),
	srcRect(obj.srcRect),
	destRect(obj.destRect)
{};