#pragma once
#ifndef SDL_MEMORY_H_INCLUDED
#define SDL_MEMORY_H_INCLUDED

struct sdl_delete
{
    void operator () (SDL_Window* p)
    {
    #if DEBUG_MODE == IS_ON
        std::cout << p << " Window destroyed" << std::endl;
    #endif // SDL_MEMORY_H_INCLUDED
        SDL_DestroyWindow(p);
    }
    void operator () (SDL_Renderer* p)
    {
    #if DEBUG_MODE == IS_ON
        std::cout << p << " Renderer destroyed" << std::endl;
    #endif // SDL_MEMORY_H_INCLUDED
        SDL_DestroyRenderer(p);
    }
    void operator () (SDL_Texture* p)
    {
    #if DEBUG_MODE == IS_ON
        std::cout << p << " Texture destroyed " << std::endl;
    #endif // SDL_MEMORY_H_INCLUDED
        SDL_DestroyTexture(p);
    }
    void operator () (SDL_Surface* p)
    {
    #if DEBUG_MODE == IS_ON
        std::cout << p << " Surface freed " << std::endl;
    #endif // SDL_MEMORY_H_INCLUDED
        SDL_FreeSurface(p);
    }
};

namespace sdl {
    template <typename T>
    using unique_ptr = std::unique_ptr <T, sdl_delete>;

    template <typename T>
    using shared_ptr = std::shared_ptr <T>;

    template <typename T>
    sdl::unique_ptr <T> make_unique (T* ptr) {
        return std::unique_ptr <T, sdl_delete> (ptr, sdl_delete ());
    }

    template <typename T>
    sdl::shared_ptr <T> make_shared (T* ptr) {
        return std::shared_ptr <T> (ptr, sdl_delete ());
    }
};
#endif // SDL_MEMORY_H_INCLUDED
