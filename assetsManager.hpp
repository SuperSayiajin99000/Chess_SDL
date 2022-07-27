#pragma once

#include "game.hpp"
#include "Sprite.hpp"

enum TEXTURE_NAMES {
	sq_dark_brown,
	sq_light_brown,
	sq_dark_gray,
	sq_light_gray,

	b_pawn,
	b_bishop,
	b_king,
	b_knight,
	b_queen,
	b_rook,

	w_pawn,
	w_bishop,
	w_king,
	w_knight,
	w_queen,
	w_rook,
};

using sound = int; // ! CHANGE WHEN ADDING SOUNDS

class AssetsManager {
public:
	typedef struct SpritesMap {
		std::unordered_map < int, sdl::shared_ptr <Sprite> > map;
	} SpritesMap;
	typedef struct soundsMap {
		std::unordered_map < int, sdl::shared_ptr <sound> > map;
	} soundsMap;
	static SpritesMap Sprites;
	static soundsMap sounds;
public:
	static void init ( );
	static std::shared_ptr<Sprite> getSprite ( int name );
};
