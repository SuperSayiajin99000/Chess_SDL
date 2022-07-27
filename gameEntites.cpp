// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "gameEntities.hpp"
#include "TextureHandler.hpp"

extern int typeIdGen();

template <typename T> 
extern int typeId();

// Tile
// Tile consturctor
void Tile::
init (int x, int y, int w, int h, std::shared_ptr <Sprite> uSprite) {
	Sprite iSprite = *uSprite;
	iSprite.init <Sprite> (std::make_shared<Tile> (*this));
	iSprite.setPosition(x, y);
	iSprite.setSize(w, h);
	this->addComponent <Sprite>(std::make_shared <Sprite> (iSprite));
	// debug 
	{
		std::cout << "Sprite with ID " << iSprite.getComponentId() << " has dimentions " << w << ' ' << h << std::endl;
	}
}
// Piece

void Piece::init(
	std::shared_ptr <Sprite> uSprite,
	int x,
	int y,
	int w,
	int h,
	int name,
	int color
) {
	Sprite iSprite = *uSprite;
	iSprite.init <Sprite>(std::make_shared<Piece> (*this));
	iSprite.setPosition(x, y);
	iSprite.setSize(w, h);
	this->addComponent<Sprite>(std::make_shared <Sprite> (iSprite));
	this->color = color;
	this->name = name;
	std::cout << "Sprite with id " << iSprite.getComponentId() << " had dimentions " << w << ' ' << h << std::endl;
}
