#include "game.hpp"
#include "gameObject.hpp"
#include "textureHandler.hpp"

auto basicUpdate = [](const gameObject& obj) {
	;
};

std::shared_ptr < std::function < void (const gameObject&) > > ptr_to_basicUpdate = 
	std::make_shared < std::function < void( const gameObject& ) > >( basicUpdate );


std::shared_ptr < std::function < void( const gameObject& ) > > ptr_to_pieceUpdate = 
	std::make_shared < std::function < void ( const gameObject& ) > > ( basicUpdate );