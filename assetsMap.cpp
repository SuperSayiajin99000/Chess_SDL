#include "assetsMap.hpp"
#include "board.hpp"
#include "textureManager.h"

std::vector <std::vector < std::shared_ptr <gameObject> > > assetsMap::background;

assetsMap::assetsMap ( ) {
	for (int i = 0; i < ROWS; ++i) {
		background.push_back(std::vector < std::shared_ptr < gameObject> > ());
		for (int j = 0; j < COLS; ++j) {
			background.back().push_back (std::make_shared <gameObject>());
		}
	}
}

void assetsMap::loadAssets ( ) {
	using namespace std;
	cout << "Loading Assets... " << endl;

	textureManager txmgr ( game::renderer );

	textures.map [sq_dark_brown] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/square brown dark_png_128px.png" );

	textures.map [sq_light_brown] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/square brown light_png_128px.png" );

	textures.map [sq_dark_gray] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/square gray dark_png_128px.png" );

	textures.map [sq_light_gray] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/square gray light_png_128px.png" );


}

void assetsMap::makeBackground ( ) {
	bool isBlack = false; // index start form 0

	const auto& sqLen = board::sqLen;
	int xpos = board::start.x, ypos = board::start.y;

	for (auto& row : background) {
		for (auto& obj : row) {

			if (isBlack)
				obj->texture = textures.map[sq_dark_brown];

			else
				obj->texture = textures.map[sq_light_brown];

			obj->srcRect = { 0, 0, sqLen, sqLen };
			obj->destRect = { xpos, ypos, sqLen, sqLen }; // [X, Y, W, H]
			isBlack = !isBlack;
			xpos += sqLen;
		}
		isBlack = !isBlack;
		xpos = board::start.x;
		ypos += sqLen;
	}
}

void assetsMap::generateAssetsMap ( ) {
	loadAssets ( );
	makeBackground ( );
}

assetsMap::~assetsMap ( ) {
	textures.map.clear ( );
	sounds.map.clear ( );
	background.clear ( );
}
