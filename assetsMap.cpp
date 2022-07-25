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
std::vector <std::shared_ptr <gameObject>> assetsMap::pieces;
assetsMap::texturesMap assetsMap::textures;
assetsMap::soundsMap assetsMap::sounds;

assetsMap::assetsMap () {

	background.reserve(board::ROWS);
	for (int i = 0; i < board::ROWS; ++i) {

		background.push_back( std::vector < std::shared_ptr < gameObject> > () );
		background.back().reserve(board::COLS);
		for (int j = 0; j < board::COLS; ++j) {

			background.back().push_back ( std::make_shared < gameObject >() );
		
		}
	}
}

void assetsMap::loadAssets ( ) {
	using namespace std;
	cout << "Loading Assets... " << endl;

	textureManager txmgr;

	textures.map [sq_dark_brown] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/square brown dark_png_shadow_128px.png" );

	textures.map [sq_light_brown] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/square brown light_png_shadow_128px.png" );

	textures.map [sq_dark_gray] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/square gray dark _png_shadow_128px.png" );

	textures.map [sq_light_gray] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/square gray light _png_shadow_128px.png" );

	textures.map [b_bishop] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/b_bishop_png_shadow_128px.png" );
	
	textures.map [b_king] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/b_king_png_shadow_128px.png" );
	
	textures.map [b_knight] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/b_knight_png_shadow_128px.png" );
	
	textures.map [b_pawn] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/b_pawn_png_shadow_128px.png" );
	
	textures.map [b_queen] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/b_queen_png_shadow_128px.png" );
	
	textures.map [b_rook] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/b_rook_png_shadow_128px.png" );
	textures.map [w_bishop] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/w_bishop_png_shadow_128px.png" );
	
	textures.map [w_king] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/w_king_png_shadow_128px.png" );
	
	textures.map [w_knight] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/w_knight_png_shadow_128px.png" );
	
	textures.map [w_pawn] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/w_pawn_png_shadow_128px.png" );
	
	textures.map [w_queen] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/w_queen_png_shadow_128px.png" );
	
	textures.map [w_rook] =
		txmgr.loadTexture
		( "./assets/PNGs/With Shadow/128h/w_rook_png_shadow_128px.png" );

	// debug
	{
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
}

extern std::shared_ptr <std::function <void (const gameObject&)>> ptr_to_basicObjRender;

extern std::shared_ptr <std::function <void (const gameObject&)>> ptr_to_pieceRender;

void assetsMap::makeBackground ( ) {
	bool isBlack = false; // index start form 0

	const auto& tileSize = board::tileSize;
	int xpos = board::start.x, ypos = board::start.y;

	for (auto& row : background) {
		for (auto& obj : row) {

			if (isBlack)
				obj->texture = textures.map[sq_dark_brown];

			else
				obj->texture = textures.map[sq_light_brown];

			obj->srcRect = { 0, 0, tileSize*2, tileSize*2 };
			obj->destRect = { xpos, ypos, tileSize, tileSize}; // [X, Y, W, H]
			obj->render = ptr_to_basicObjRender;

			isBlack = !isBlack;
			xpos += tileSize;
		}
		isBlack = !isBlack;
		xpos = board::start.x;
		ypos += tileSize;
	}
}

inline void addPiece (enum TEXTURE_NAMES textureName, int xPos, int yPos) {
	assetsMap::pieces.push_back(
		std::make_shared <gameObject>(
			gameObject(
				assetsMap::textures.map[textureName],
				{ 0, 0, board::tileSize*3, board::tileSize*3 },
				{   
					board::start.x + xPos + board::piece_shift_origin,
					board::start.y + yPos + board::piece_shift_origin,
					board::piece_size,
					board::piece_size
				}
			)
		)
	);
	assetsMap::pieces.back()->render = ptr_to_pieceRender;
}

void assetsMap::makePieces() {
	int xPos = 0, yPos = 0;
	

	addPiece(b_rook, xPos, yPos);
	xPos += board::tileSize;
	
	addPiece(b_knight, xPos, yPos);
	xPos += board::tileSize;
	
	addPiece(b_bishop, xPos, yPos);
	xPos += board::tileSize;
	
	addPiece(TEXTURE_NAMES::b_queen, xPos, yPos);
	xPos += board::tileSize;
	
	addPiece(TEXTURE_NAMES::b_king, xPos, yPos);
	xPos += board::tileSize;
	
	addPiece(b_bishop, xPos, yPos);
	xPos += board::tileSize;
	
	addPiece(b_knight, xPos, yPos);
	xPos += board::tileSize;
	
	addPiece(b_rook, xPos, yPos);
	xPos += board::tileSize;

	xPos = 0;
	yPos += board::tileSize;
	
	for (int i = 0; i < 8; ++i) {
		addPiece(b_pawn, xPos, yPos);
		xPos += board::tileSize;
	}

	xPos = 0;
	yPos = board::tileSize * 6;

	for (int i = 0; i < 8; ++i) {
		addPiece(w_pawn, xPos, yPos);
		xPos += board::tileSize;
	}
	
	xPos = 0;
	yPos += board::tileSize;

	addPiece(w_rook, xPos, yPos);
	xPos += board::tileSize;

	addPiece(w_knight, xPos, yPos);
	xPos += board::tileSize;
	
	addPiece(w_bishop, xPos, yPos);
	xPos += board::tileSize;
	
	addPiece(TEXTURE_NAMES::w_queen, xPos, yPos);
	xPos += board::tileSize;
	
	addPiece(TEXTURE_NAMES::w_king, xPos, yPos);
	xPos += board::tileSize;
	
	addPiece(w_bishop, xPos, yPos);
	xPos += board::tileSize;
	
	addPiece(w_knight, xPos, yPos);
	xPos += board::tileSize;
	
	addPiece(w_rook, xPos, yPos);
	xPos += board::tileSize;
}

void assetsMap::generateAssetsMap ( ) {
	loadAssets ( );
	makeBackground ( );
	makePieces ( );
	board::makeBoardRenderMatrix();
}

assetsMap::~assetsMap ( ) {
	textures.map.clear ( );
	sounds.map.clear ( );
	background.clear ( );
}
