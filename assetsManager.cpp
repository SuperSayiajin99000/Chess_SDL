// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "TextureHandler.hpp"
#include "AssetsManager.hpp"
#include "board.hpp"

//
//enum TEXTURE_NAMES {
//	sq_dark_brown,
//	sq_light_brown,
//	sq_dark_gray,
//	sq_light_gray,
//
//	b_pawn,
//	b_bishop,
//	b_king,
//	b_knight,
//	b_queen,
//	b_rook,
//
//	w_pawn,
//	w_bishop,
//	w_king,
//	w_knight,
//	w_queen,
//	w_rook,
//};

AssetsManager::SpritesMap AssetsManager::Sprites;
AssetsManager::soundsMap AssetsManager::sounds;

void AssetsManager::init ( ) {
	using namespace std;
	cout << "Loading Assets... " << endl;

	Sprites.map.reserve(board::total_pieces);
	
	// This map contians unitialized Sprite Components
	// It is used to initialize the sprites in the game
	// Unitialized sprites are not drawn in the game by the componentsMap
	// but can be drawn if called explicitly
	
	Sprites.map [sq_dark_brown] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/square brown dark_png_shadow_128px.png" );

	Sprites.map [sq_light_brown] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/square brown light_png_shadow_128px.png" );

	Sprites.map [sq_dark_gray] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/square gray dark _png_shadow_128px.png" );

	Sprites.map [sq_light_gray] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/square gray light _png_shadow_128px.png" );

	Sprites.map [b_bishop] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/b_bishop_png_shadow_128px.png" );
	
	Sprites.map [b_king] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/b_king_png_shadow_128px.png" );
	
	Sprites.map [b_knight] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/b_knight_png_shadow_128px.png" );
	
	Sprites.map [b_pawn] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/b_pawn_png_shadow_128px.png" );
	
	Sprites.map [b_queen] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/b_queen_png_shadow_128px.png" );
	
	Sprites.map [b_rook] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/b_rook_png_shadow_128px.png" );
	Sprites.map [w_bishop] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/w_bishop_png_shadow_128px.png" );
	
	Sprites.map [w_king] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/w_king_png_shadow_128px.png" );
	
	Sprites.map [w_knight] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/w_knight_png_shadow_128px.png" );
	
	Sprites.map [w_pawn] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/w_pawn_png_shadow_128px.png" );
	
	Sprites.map [w_queen] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/w_queen_png_shadow_128px.png" );
	
	Sprites.map [w_rook] =
		TextureHandler::loadTexture
		( "./assets/PNGs/With Shadow/128h/w_rook_png_shadow_128px.png" );

	// debug
	{
		int fail = 0, success = 0;
		for (const auto& [name, tex] : Sprites.map) {
			if (tex.get() == nullptr) {
				fail++;
			}
			else success++;
		}
		std::cout << Sprites.map.size() << " Sprites initiallized to load" << std::endl;
		std::cout << fail << " Sprites failed to load " << std::endl;
		std::cout << success << " Sprites successfully loaded" << std::endl;
	}
}

// get texture
std::shared_ptr <Sprite> AssetsManager::getSprite (int name) {
	return Sprites.map[name];
}
