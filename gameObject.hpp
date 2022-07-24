#pragma once

#include "game.hpp"
#include <functional>

struct gameObject {
public:
    sdl::shared_ptr <SDL_Texture> texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
public:
    gameObject ( );
    gameObject (
        sdl::shared_ptr <SDL_Texture> tex,
        const SDL_Rect& src,
        const SDL_Rect& dst
    ) : 
        texture (tex),
        srcRect (src),
        destRect (dst) 
    {};
    template < typename returnT , typename argT >
    returnT update ( const std::function <returnT ( argT )>& func, const argT& arg) {
        return func ( arg );
    };

    template < typename returnT, typename argT >
    returnT render ( const std::function <returnT ( argT )>& func, const argT& arg ) {
        return func ( arg );
    };
};

