#include "gameObjectsMap.hpp"
#include "assetsMap.hpp"
#include "board.hpp"


std::vector <std::vector < std::shared_ptr <gameObject> > > gameObjectsMap::background;
std::vector <std::shared_ptr <gameObject>> gameObjectsMap::pieces;

extern std::shared_ptr <std::function <void(const gameObject&)>> ptr_to_basicObjRender;
extern std::shared_ptr <std::function <void(const gameObject&)>> ptr_to_pieceRender;

gameObjectsMap::gameObjectsMap() {
	background.reserve(board::ROWS);
	for (int i = 0; i < board::ROWS; ++i) {

		background.push_back(std::vector < std::shared_ptr < gameObject> >());
		background.back().reserve(board::COLS);
		for (int j = 0; j < board::COLS; ++j) {

			background.back().push_back(std::make_shared < gameObject >());

		}
	}
}

void gameObjectsMap::makeBackground() {

	const auto& tileSize = board::tileSize;
	
	int xpos = board::start.x, ypos = board::start.y;
	bool isBlack = false; // index start form 0

	for (auto& row : background) {
		for (auto& obj : row) {
			sdl::shared_ptr <SDL_Texture> tempTex;
			std::shared_ptr <gameObject> tempObj;
			if (isBlack)
				tempTex = assetsMap::textures.map[sq_dark_brown];
			else
				tempTex = assetsMap::textures.map[sq_light_brown];

			tempObj = std::make_shared <gameObject>(
				gameObject(
					std::move(tempTex),
					{ 0, 0, tileSize * 2, tileSize * 2 },
					{ xpos, ypos, tileSize, tileSize }
				)
			);
			tempObj->render = ptr_to_basicObjRender;
			obj = std::move(tempObj);

			isBlack = !isBlack;
			xpos += tileSize;
		}
		isBlack = !isBlack;
		xpos = board::start.x;
		ypos += tileSize;
	}
}

inline void addPiece(enum TEXTURE_NAMES textureName, int xPos, int yPos) {
	auto tempTex = assetsMap::textures.map[textureName];
	gameObjectsMap::pieces.push_back(
		std::make_shared <gameObject>(
			gameObject(
				std::move (tempTex),
				{ 0, 0, board::tileSize * 3, board::tileSize * 3 },
				{
					board::start.x + xPos + board::piece_shift_origin,
					board::start.y + yPos + board::piece_shift_origin,
					board::piece_size,
					board::piece_size
				}
			)
		)
	);
	gameObjectsMap::pieces.back()->render = ptr_to_pieceRender;
}

void gameObjectsMap::makePieces() {
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

void gameObjectsMap::generate() {
	makeBackground();
	makePieces();
}

gameObjectsMap::~gameObjectsMap() {
	background.clear();
	pieces.clear();
}