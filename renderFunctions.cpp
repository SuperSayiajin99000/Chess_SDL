#include "game.hpp"
#include "gameObject.hpp"
#include "textureManager.h"

//typedef void(*renderFunction)(const gameObject&);

auto basicObjRender = [](const gameObject& obj) {
	textureManager::draw(obj);
};

auto ptr_to_basicObjRender = std::make_shared <std::function <void(const gameObject&)>>(basicObjRender);

auto pieceRender = [](const gameObject& obj) {
	textureManager::draw(obj);
};

auto ptr_to_pieceRender = std::make_shared <std::function <void(const gameObject&)>>(pieceRender);
