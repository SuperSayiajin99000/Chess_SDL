#include "gameObject.hpp"
#include "assetsManager.hpp"
#include "objectsManager.hpp"
#include "board.hpp"

std::vector <std::vector < std::shared_ptr <gameObject> > > objectsManager::background;
std::vector <std::shared_ptr <gameObject>> objectsManager::pieces;
auto& textures = assetsManager::textures;


void objectsManager::makeBackground() {
	bool isBlack = false; // index start form 0

	const auto& tileSize = board::tileSize;
	int xpos = board::start.x, ypos = board::start.y;

	background.reserve(board::ROWS);
	for (int i = 0; i < board::ROWS; ++i) {
		std::shared_ptr <gameObject> obj;
		background.back().reserve(board::COLS);
		for (int j = 0; j < board::COLS; ++j) {
			sdl::shared_ptr <SDL_Texture> tempTex;
			if (isBlack)
				tempTex = textures.map[sq_dark_brown];

			else
				tempTex = textures.map[sq_light_brown];

			obj = std::make_shared <gameObject>(
				gameObject(
					std::move(tempTex),
					{ 0, 0, tileSize * 2, tileSize * 2 },
					{ xpos, ypos, tileSize, tileSize }
				)
				);

			obj->render = ptr_to_basicObjRender;
			obj->update = ptr_to_basicUpdate;

			isBlack = !isBlack;
			xpos += tileSize;
		}
		background.emplace_back(std::move (obj));
		isBlack = !isBlack;
		xpos = board::start.x;
		ypos += tileSize;
	}
}

inline void objectsManager::addPiece(enum TEXTURE_NAMES textureName, int xPos, int yPos) {
	sdl::shared_ptr <SDL_Texture> tempTex = textures.map[textureName];
	pieces.push_back(
		std::make_shared <gameObject>(
			gameObject(
				std::move(tempTex),
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
	pieces.back()->render = ptr_to_pieceRender;
	pieces.back()->update = ptr_to_pieceUpdate;
}

void objectsManager::makePieces() {
	int xPos = 0, yPos = 0;


	addPiece(b_rook, xPos, yPos);
	xPos += board::tileSize;

	addPiece(b_knight, xPos, yPos);
	xPos += board::tileSize;

	addPiece(b_bishop, xPos, yPos);
	xPos += board::tileSize;

	addPiece(b_queen, xPos, yPos);
	xPos += board::tileSize;

	addPiece(b_king, xPos, yPos);
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

	addPiece(w_queen, xPos, yPos);
	xPos += board::tileSize;

	addPiece(w_king, xPos, yPos);
	xPos += board::tileSize;

	addPiece(w_bishop, xPos, yPos);
	xPos += board::tileSize;

	addPiece(w_knight, xPos, yPos);
	xPos += board::tileSize;

	addPiece(w_rook, xPos, yPos);
	xPos += board::tileSize;
}

void objectsManager::generate() {
	makeBackground();
	makePieces();
}