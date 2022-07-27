#pragma once

#include "game.hpp"
#include "Sprite.hpp"
#include "ECS.hpp"

class Tile;

class Tile : public Entity {
public:
	// tile consturctor
	void init (
		int x, 
		int y, 
		int w, 
		int h, 
		std::shared_ptr <Sprite> uSprite
	);
};

class Piece : public Entity {
public:
	enum COLOR {
		BLACK,
		WHITE
	};
private:
	int color;
	int name;
public:
	void init(
		std::shared_ptr <Sprite> uSprite,
		int x,
		int y,
		int w,
		int h,
		int name,
		int color
	);

	// get sprite
	std::shared_ptr <Sprite> getSprite() {
		return std::make_shared <Sprite>(this->getComponent <Sprite>());
	}
};
