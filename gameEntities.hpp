#pragma once

#ifndef GAME_ENTITIES_HPP_INCLUDED
#define GAME_ENTITIES_HPP_INCLUDED

#include "game.hpp"
#include "gameObject.hpp"
#include "ECS.hpp"


class Picture;
class Tile;

class Picture : public Component {
private:
	std::shared_ptr <GameObject> m_gameObject;
public:
	Picture(std::shared_ptr <Entity> entity);
	// copy construtor
	Picture(const Picture& pic) = delete;
	// move constructor
	Picture(Picture&& pic) noexcept;

	// set gameobj
	void setGameObject(std::shared_ptr <GameObject> gameObject);
	
	// get gameobj
	std::shared_ptr <GameObject> getGameObject() const;
	
	~Picture();
	template <typename T>
	inline T getEntity() {
		return *std::static_pointer_cast <T, Entity> (this->entity_);
	}
	
	virtual void render() override;
	virtual void update() override {};
};

class Tile : public Entity {
public:
	Tile(int x, int y, int w, int h, sdl::shared_ptr <SDL_Texture> texture);
};

class Piece : public Entity {
public:
	enum COLOR {
		BLACK,
		WHITE
	};
private:
	int color;
public:
	Piece (SDL_Rect&& srcRect, SDL_Rect&& destRect, sdl::shared_ptr <SDL_Texture> texture , int color);
	// Piece constructor by rect copy
	Piece (const SDL_Rect& srcRect, const SDL_Rect& destRect, sdl::shared_ptr <SDL_Texture> texture, int color);
};


#endif // GAME_ENTITIES_HPP_INCLUDED