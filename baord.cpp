#include "board.hpp"
#include "assetsMap.hpp"
#include "textureManager.h"

point board::start = { 
	board::sqLen * 3, // x
	board::sqLen * 2  // y
};

void board::renderBackgound ( ) {
    const auto& background = assetsMap::background;
    for (const auto& row : background) {
        for (const auto& obj : row) {
            textureManager(game::renderer).draw(*obj);
        }
    }
}

void board::renderPeices() {
    const auto& peices = assetsMap::peices;
    for (const auto& peice : peices) {
        textureManager(game::renderer).draw(*peice);       
    }
}