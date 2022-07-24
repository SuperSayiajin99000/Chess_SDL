#include "assetsMap.hpp"
#include "board.hpp"
#include "textureManager.h"

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

std::vector <std::vector < std::shared_ptr <gameObject> > > assetsMap::background;
std::vector <std::shared_ptr <gameObject>> assetsMap::peices;
assetsMap::texturesMap assetsMap::textures;
assetsMap::soundsMap assetsMap::sounds;

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
		( "./assets/PNGs/No shadow/128h/square gray dark _png_128px.png" );

	textures.map [sq_light_gray] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/square gray light _png_128px.png" );

	textures.map [b_bishop] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/b_bishop_png_128px.png" );
	
	textures.map [b_king] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/b_king_png_128px.png" );
	
	textures.map [b_knight] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/b_knight_png_128px.png" );
	
	textures.map [b_pawn] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/b_pawn_png_128px.png" );
	
	textures.map [b_queen] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/b_queen_png_128px.png" );
	
	textures.map [b_rook] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/b_rook_png_128px.png" );
	textures.map [w_bishop] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/w_bishop_png_128px.png" );
	
	textures.map [w_king] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/w_king_png_128px.png" );
	
	textures.map [w_knight] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/w_knight_png_128px.png" );
	
	textures.map [w_pawn] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/w_pawn_png_128px.png" );
	
	textures.map [w_queen] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/w_queen_png_128px.png" );
	
	textures.map [w_rook] =
		txmgr.loadTexture
		( "./assets/PNGs/No shadow/128h/w_rook_png_128px.png" );

	int fail = 0, success = 0;
	for (const auto& [name, tex] : textures.map) {
		if (tex.get() == nullptr) {
			fail++;
		}
		else success++;
	}
	std::cout << textures.map.size() << " textures initiallized to load" << std::endl;
	std::cout << fail << " textures failed to load " << std::endl;
	std::cout << success << " textures successfully loaded" << std::endl;
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

			obj->srcRect = { 0, 0, sqLen*2, sqLen*2 };
			obj->destRect = { xpos, ypos, sqLen, sqLen}; // [X, Y, W, H]
			isBlack = !isBlack;
			xpos += sqLen;
		}
		isBlack = !isBlack;
		xpos = board::start.x;
		ypos += sqLen;
	}
}

inline void addPeice (enum TEXTURE_NAMES textureName, int xPos, int yPos) {
	assetsMap::peices.push_back(
		std::make_shared <gameObject>(
			gameObject(
				assetsMap::textures.map[textureName],
				{ 0, 0, board::sqLen*3, board::sqLen*3 },
				{   
					board::start.x + xPos + board::sqLen/8,
					board::start.y + yPos + board::sqLen/8,
					3*board::sqLen/4,
					3*board::sqLen/4
				}
			)
		)
	);
}

void assetsMap::makePeices() {
	int xPos = 0, yPos = 0;
	
	addPeice(b_rook, xPos, yPos);
	xPos += board::sqLen;
	
	addPeice(b_knight, xPos, yPos);
	xPos += board::sqLen;
	
	addPeice(b_bishop, xPos, yPos);
	xPos += board::sqLen;
	
	addPeice(b_queen, xPos, yPos);
	xPos += board::sqLen;
	
	addPeice(b_king, xPos, yPos);
	xPos += board::sqLen;
	
	addPeice(b_bishop, xPos, yPos);
	xPos += board::sqLen;
	
	addPeice(b_knight, xPos, yPos);
	xPos += board::sqLen;
	
	addPeice(b_rook, xPos, yPos);
	xPos += board::sqLen;

	xPos = 0;
	yPos += board::sqLen;
	
	for (int i = 0; i < 8; ++i) {
		addPeice(b_pawn, xPos, yPos);
		xPos += board::sqLen;
	}

	xPos = 0;
	yPos = board::sqLen * 6;

	for (int i = 0; i < 8; ++i) {
		addPeice(w_pawn, xPos, yPos);
		xPos += board::sqLen;
	}
	
	xPos = 0;
	yPos += board::sqLen;

	addPeice(w_rook, xPos, yPos);
	xPos += board::sqLen;

	addPeice(w_knight, xPos, yPos);
	xPos += board::sqLen;
	
	addPeice(w_bishop, xPos, yPos);
	xPos += board::sqLen;
	
	addPeice(w_queen, xPos, yPos);
	xPos += board::sqLen;
	
	addPeice(w_king, xPos, yPos);
	xPos += board::sqLen;
	
	addPeice(w_bishop, xPos, yPos);
	xPos += board::sqLen;
	
	addPeice(w_knight, xPos, yPos);
	xPos += board::sqLen;
	
	addPeice(w_rook, xPos, yPos);
	xPos += board::sqLen;
}

void assetsMap::generateAssetsMap ( ) {
	loadAssets ( );
	makeBackground ( );
	makePeices ( );
}

assetsMap::~assetsMap ( ) {
	textures.map.clear ( );
	sounds.map.clear ( );
	background.clear ( );
}
