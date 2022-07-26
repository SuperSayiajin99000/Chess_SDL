#include "assetsManager.hpp"
#include "board.hpp"
#include "textureHandler.hpp"

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


assetsManager::texturesMap assetsManager::textures;
assetsManager::soundsMap assetsManager::sounds;

assetsManager::assetsManager () {

	background.reserve(board::ROWS);
	for (int i = 0; i < board::ROWS; ++i) {

		background.push_back( std::vector < std::shared_ptr < gameObject> > () );
		background.back().reserve(board::COLS);
		for (int j = 0; j < board::COLS; ++j) {

			background.back().push_back ( std::make_shared < gameObject >() );
		
		}
	}
}

void assetsManager::loadAssets ( ) {
	using namespace std;
	cout << "Loading Assets... " << endl;

	textureHandler txmgr;

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
// render functions
extern std::shared_ptr < std::function < void ( const gameObject& ) > > ptr_to_basicObjRender;
extern std::shared_ptr < std::function < void ( const gameObject& ) > > ptr_to_pieceRender;
// update fucntions 
extern std::shared_ptr < std::function < void ( const gameObject& ) > > ptr_to_basicUpdate;
extern std::shared_ptr < std::function < void ( const gameObject& ) > > ptr_to_pieceUpdate;



void assetsManager::generate ( ) {
	loadAssets ( );
	board::makeobjMatrix ( );
}

assetsManager::~assetsManager ( ) {
	textures.map.clear ( );
	sounds.map.clear ( );
	background.clear ( );
}
