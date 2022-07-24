#pragma once

#include "game.hpp"

struct point{
	int x, y;
};
class board {
public:
	const static int sqLen = 64;
	static point start;
public:
	static void renderBackgound( );
	static void renderPeices( );
};