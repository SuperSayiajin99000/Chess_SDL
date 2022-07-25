#pragma once

#include "game.hpp"
#include "gameObject.hpp"

class gameObjectsMap {
public:
	static std::vector < std::vector < std::shared_ptr <gameObject> > > background;
	static std::vector < std::shared_ptr <gameObject> > pieces;
public:
	gameObjectsMap();
	static void makeBackground();
	static void makePieces();
	static void generate();
	~gameObjectsMap();
};