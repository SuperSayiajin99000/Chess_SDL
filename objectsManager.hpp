#pragma once

#include "game.hpp"
#include "gameObject.hpp"

class objectsManager {
public:
	static std::vector < std::vector < std::shared_ptr <GameObject> > > background;
	static std::vector < std::shared_ptr <GameObject> > pieces;
private:
	void makeBackground();
	inline void addPiece(enum TEXTURE_NAMES textureName, int xPos, int yPos);
	inline void makePieces();
public:
	void generate();
};