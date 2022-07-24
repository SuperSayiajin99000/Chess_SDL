#include "gameObject.hpp"

gameObject::gameObject ( ) {
    srcRect = {0, 0, 128, 128};
    destRect.x = destRect.y = 0;
    destRect.w = destRect.h = 32;
};
