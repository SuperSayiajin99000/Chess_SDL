#include "gameObject.hpp"

gameObject::gameObject() = default;

gameObject::gameObject(
    const sdl::shared_ptr <SDL_Texture>& tex,
    const SDL_Rect& src,
    const SDL_Rect& dst
) :
    texture(tex),
    srcRect(src),
    destRect(dst)
{};

gameObject::gameObject(gameObject&& obj) noexcept :
    texture(obj.texture),
    srcRect(obj.srcRect),
    destRect(obj.destRect),
    render (obj.render),
    update (obj.update)
{};
