#pragma once

#include "game.hpp"
#include "assetsManager.hpp"

class gameObject {
public:
    //sdl::shared_ptr <SDL_Texture> texture;
    std::unordered_map <int, asset> assetsMap;
    SDL_Rect srcRect;
    SDL_Rect destRect;
public:
    /*std::shared_ptr < std::function < void (const gameObject&)> > render;
    std::shared_ptr < std::function < void (const gameObject&)> > update;*/
private:
    bool active = true;
public:
    gameObject ( );
    
    // copy constructor
    gameObject (
        const sdl::shared_ptr <SDL_Texture>& tex,
        const SDL_Rect& src,
        const SDL_Rect& dst
    );
    
    // object move constructor
    gameObject(
        gameObject&& obj
    ) noexcept;

    bool isActive() const { return active; }
    void deactivate() { active = false; }

    /*template < typename returnT , typename argT >
    returnT update ( const std::function <returnT ( argT )>& func, const argT& arg) {
        return func ( arg );
    };
    */

    void addRender(int typeName) {
        
    }
};

