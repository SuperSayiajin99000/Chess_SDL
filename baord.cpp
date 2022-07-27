// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "board.hpp"
#include "assetsManager.hpp"
#include "textureHandler.hpp"

std::unordered_map <int, std::shared_ptr <Piece> > board::piecesMap;
std::array < std::array < std::shared_ptr <Tile>, board::COLS >, board::ROWS > board::background;

static std::shared_ptr <Piece> generatePeice (int textureName, int xPos, int yPos, int color) {
	std::shared_ptr <Piece> tempPiece = std::make_shared <Piece>(
		Piece(
			{ 0, 0, board::tileSize * 3, board::tileSize * 3 },
			{
				board::start.x + xPos + board::piece_shift_origin,
				board::start.y + yPos + board::piece_shift_origin,
				board::piece_size,
				board::piece_size
			},
			assetsManager::getTexture(textureName),
			color
		)
	);
	return tempPiece;
}

static std::shared_ptr <Tile> generateTile (int textureName, int x, int y) {
	return std::make_shared <Tile>(
		Tile(
			board::start.x + x,
			board::start.y + y,
			board::tileSize,
			board::tileSize,
			assetsManager::getTexture(textureName)
		)
	);
}

void board::makeBackground() {
	bool isWhite = true;
	for (int i = 0; i < board::ROWS; i++) {
		for (int j = 0; j < board::COLS; j++) {
			int textureName = sq_dark_brown;
			if (isWhite) 
				textureName = sq_light_brown;
			background[i][j] = generateTile (textureName, j * tileSize, i * tileSize);
			isWhite = !isWhite;
		}
		isWhite = !isWhite;
	}
};

void board::makeMap() {
	piecesMap = std::unordered_map <int, std::shared_ptr <Piece> >({
		{ b_rook1, generatePeice( b_rook, 0, 0, Piece::COLOR::BLACK ) },
		{ b_rook2, generatePeice( b_rook, board::tileSize * 7, 0, Piece::COLOR::BLACK ) },
		
		{ b_knight1, generatePeice( b_knight, board::tileSize * 1, 0, Piece::COLOR::BLACK ) },
		{ b_knight2, generatePeice( b_knight, board::tileSize * 6, 0, Piece::COLOR::BLACK ) },
																										    
		{ b_bishop1, generatePeice( b_bishop, board::tileSize * 2, 0, Piece::COLOR::BLACK ) },
		{ b_bishop2, generatePeice( b_bishop, board::tileSize * 5, 0, Piece::COLOR::BLACK ) },
		
		{ b_queen, generatePeice( b_queen, board::tileSize * 3, 0, Piece::COLOR::BLACK ) },
		{ b_king, generatePeice( b_king, board::tileSize * 4, 0, Piece::COLOR::BLACK ) },
		
		{ b_pawn1, generatePeice( b_pawn, 0, board::tileSize * 1, Piece::COLOR::BLACK ) },
		{ b_pawn2, generatePeice( b_pawn, board::tileSize * 1, board::tileSize * 1, Piece::COLOR::BLACK ) },
		{ b_pawn3, generatePeice( b_pawn, board::tileSize * 2, board::tileSize * 1, Piece::COLOR::BLACK ) },
		{ b_pawn4, generatePeice( b_pawn, board::tileSize * 3, board::tileSize * 1, Piece::COLOR::BLACK ) },
		{ b_pawn5, generatePeice( b_pawn, board::tileSize * 4, board::tileSize * 1, Piece::COLOR::BLACK ) },
		{ b_pawn6, generatePeice( b_pawn, board::tileSize * 5, board::tileSize * 1, Piece::COLOR::BLACK ) },
		{ b_pawn7, generatePeice( b_pawn, board::tileSize * 6, board::tileSize * 1, Piece::COLOR::BLACK ) },
		{ b_pawn8, generatePeice( b_pawn, board::tileSize * 7, board::tileSize * 1, Piece::COLOR::BLACK ) },
		
		{ w_rook1, generatePeice( w_rook, 0, board::tileSize * 7, Piece::COLOR::WHITE ) },
		{ w_rook2, generatePeice( w_rook, board::tileSize * 7, board::tileSize * 7, Piece::COLOR::WHITE ) },
		
		{ w_knight1, generatePeice( w_knight, board::tileSize * 1, board::tileSize * 7, Piece::COLOR::WHITE ) },
		{ w_knight2, generatePeice( w_knight, board::tileSize * 6, board::tileSize * 7, Piece::COLOR::WHITE ) },
		
		{ w_bishop1, generatePeice( w_bishop, board::tileSize * 2, board::tileSize * 7, Piece::COLOR::WHITE ) },
		{ w_bishop2, generatePeice( w_bishop, board::tileSize * 5, board::tileSize * 7, Piece::COLOR::WHITE ) },
		
		{ w_queen, generatePeice( w_queen, board::tileSize * 3, board::tileSize * 7, Piece::COLOR::WHITE ) },
		{ w_king, generatePeice( w_king, board::tileSize * 4, board::tileSize * 7, Piece::COLOR::WHITE ) },
		
		{ w_pawn1, generatePeice( w_pawn, 0, board::tileSize * 6, Piece::COLOR::WHITE) },
		{ w_pawn2, generatePeice( w_pawn, board::tileSize * 1, board::tileSize * 6, Piece::COLOR::WHITE ) },
		{ w_pawn3, generatePeice( w_pawn, board::tileSize * 2, board::tileSize * 6, Piece::COLOR::WHITE ) },
		{ w_pawn4, generatePeice( w_pawn, board::tileSize * 3, board::tileSize * 6, Piece::COLOR::WHITE ) },
		{ w_pawn5, generatePeice( w_pawn, board::tileSize * 4, board::tileSize * 6, Piece::COLOR::WHITE ) },
		{ w_pawn6, generatePeice( w_pawn, board::tileSize * 5, board::tileSize * 6, Piece::COLOR::WHITE ) },
		{ w_pawn7, generatePeice( w_pawn, board::tileSize * 6, board::tileSize * 6, Piece::COLOR::WHITE ) },
		{ w_pawn8, generatePeice( w_pawn, board::tileSize * 7, board::tileSize * 6, Piece::COLOR::WHITE ) }
	});
};

void board::init() {
	piecesMap.reserve(total_pieces);
	makeBackground();
	makeMap();
}