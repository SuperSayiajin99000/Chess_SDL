#pragma once

#include "game.hpp"
#include "gameObject.hpp"
#include "SDL_memory.h"
#include <unordered_map>
#include <vector>

using sound = int; // ! CHANGE WHEN ADDING SOUNDS

enum textureNames {
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


class assetsMap {
public:
	struct textures {
		std::unordered_map < int, sdl::shared_ptr <SDL_Texture> > map;
	} textures;
	struct sounds {
		std::unordered_map < int, sdl::shared_ptr <sound> > map;
	} sounds;
public:
	static constexpr int ROWS = 8;
	static constexpr int COLS = 8;
	static std::vector < std::vector < std::shared_ptr <gameObject> > > background;
public:
	assetsMap ( );
	void loadAssets ( );
	void makeBackground ( );
	void generateAssetsMap();
	~assetsMap ( );
};