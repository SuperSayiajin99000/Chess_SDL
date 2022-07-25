#pragma once

#include "game.hpp"

class gameObject {
public:
    sdl::shared_ptr <SDL_Texture> texture;
    SDL_Rect srcRect{};
    SDL_Rect destRect{};
public:
    std::shared_ptr < std::function < void(gameObject&)> > update {};
    std::shared_ptr < std::function < void(const gameObject&)> > render{};
public:
    gameObject () = default;

    // copy constructor
    gameObject (
        sdl::shared_ptr <SDL_Texture> tex,
        const SDL_Rect& src,
        const SDL_Rect& dst
    );

    // move construtor
    gameObject(
        sdl::shared_ptr <SDL_Texture>&& tex,
        SDL_Rect&& src,
        SDL_Rect&& dst
    );

    // object move consturctor
    gameObject(gameObject&& obj);

    // object copy constructor
    gameObject(const gameObject& obj);


    /*template < typename returnT , typename argT >
    returnT update ( const std::function <returnT ( argT )>& func, const argT& arg) {
        return func ( arg );
    };
    */
};

