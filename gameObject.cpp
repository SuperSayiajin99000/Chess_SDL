#include "gameObject.hpp"

// copy constructor
gameObject::gameObject(
    sdl::shared_ptr <SDL_Texture> tex,
    const SDL_Rect& src,
    const SDL_Rect& dst
) :
    texture(tex),
    srcRect(src),
    destRect(dst)
{};

// move construtor
gameObject::gameObject(
    sdl::shared_ptr <SDL_Texture>&& tex,
    SDL_Rect&& src,
    SDL_Rect&& dst
) :
    texture(tex),
    srcRect(src),
    destRect(dst)
{};

// object move consturctor
gameObject::gameObject(gameObject&& obj) :
    texture(obj.texture),
    srcRect(obj.srcRect),
    destRect(obj.destRect),
    update(obj.update),
    render(obj.render)
{}

// object copy constructor
gameObject::gameObject(const gameObject& obj) :
    texture(obj.texture),
    srcRect(obj.srcRect),
    destRect(obj.destRect),
    update(obj.update),
    render(obj.render)
{}