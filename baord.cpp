#include "board.hpp"
#include "assetsMap.hpp"
#include "textureManager.h"
#include "gameObjectsMap.hpp"

const auto& pieces = gameObjectsMap::pieces;

std::unordered_map <int, std::shared_ptr <gameObject> > board::piecesMap;

std::array < std::array <std::vector < std::shared_ptr <gameObject> >, 8 >, 8 > board::boardRenderMatrix;

void board::makeBoardRenderMatrix() {

	piecesMap = std::unordered_map <int, std::shared_ptr <gameObject> >({
		{ b_rook1, pieces[0] },

		{ b_knight1, pieces[1] },

		{ b_bishop1, pieces[2] },

		{ b_king1, pieces[3] },
		{ b_queen1, pieces[4] },

		{ b_bishop2, pieces[5] },

		{ b_knight2, pieces[6] },

		{ b_rook2, pieces[7] },

		{ b_pawn1, pieces[8] },
		{ b_pawn2, pieces[9] },
		{ b_pawn3, pieces[10] },
		{ b_pawn4, pieces[11] },
		{ b_pawn5, pieces[12] },
		{ b_pawn6, pieces[13] },
		{ b_pawn7, pieces[14] },
		{ b_pawn8, pieces[15] },

		{ w_rook1, pieces[16] },

		{ w_knight1, pieces[17]},

		{ w_bishop1, pieces[18] },

		{ w_king1, pieces[19] },
		{ w_queen1, pieces[20] },

		{ w_bishop2, pieces[21] },

		{ w_knight2, pieces[22] },

		{ w_rook2, pieces[23] },

		{ w_pawn1, pieces[24] },
		{ w_pawn2, pieces[25] },
		{ w_pawn3, pieces[26] },
		{ w_pawn4, pieces[27] },
		{ w_pawn5, pieces[28] },
		{ w_pawn6, pieces[29] },
		{ w_pawn7, pieces[30] },
		{ w_pawn8, pieces[31] },

	});

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			boardRenderMatrix[i][j].push_back(gameObjectsMap::background[i][j]);
		}
	}
	for (int i = 0; i < ROWS; ++i) {
		boardRenderMatrix[0][i].push_back(pieces[i]);
	}
	for (int i = 0; i < ROWS; ++i) {
		boardRenderMatrix[1][i].push_back(pieces[i + 8]);
	}
	for (int i = 0; i < ROWS; ++i) {
		boardRenderMatrix[6][i].push_back(pieces[i + 16]);
	}
	for (int i = 0; i < ROWS; ++i) {
		boardRenderMatrix[7][i].push_back(pieces[i + 24]);
	}
	
}

void board::renderMatrix() {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			for (auto& thisObj : boardRenderMatrix[i][j]) {
				// thisObj->render <void, gameObject> (drawGameObj, *thisObj);
				const auto& render = *thisObj->render;
				render(*thisObj);
			}
		}
	}
}

void board::updateMatrix() {

}