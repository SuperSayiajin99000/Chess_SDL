#pragma once

#include "game.hpp"
#include "gameObject.hpp"

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

class assetsMap {
public:
	typedef struct texturesMap {
		std::unordered_map < int, sdl::shared_ptr <SDL_Texture> > map;
	} texturesMap;
	typedef struct soundsMap {
		std::unordered_map < int, sdl::shared_ptr <sound> > map;
	} soundsMap;
	static texturesMap textures;
	static soundsMap sounds;
public:
	static std::vector < std::vector < std::shared_ptr <gameObject> > > background;
	static std::vector < std::shared_ptr <gameObject> > pieces;
private:
	void loadAssets ( );
	void makeBackground ( );
	inline void makePieces( );
public:
	assetsMap ( );
	void generateAssetsMap ( );
	~assetsMap ( );
};
