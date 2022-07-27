// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "gameEntities.hpp"
#include "textureHandler.hpp"

extern int typeIdGen();

template <typename T> 
extern int typeId();

// picture 
Picture::Picture(std::shared_ptr <Entity> entity) {
	entity_ = std::move (entity);
	typeId_ = typeId<Picture>();
	componentId_ = componentIdGen_++;
}

// picture move consturctor
Picture::Picture(Picture&& picture) noexcept {
	entity_ = std::move (picture.entity_);
	typeId_ = picture.typeId_;
	componentId_ = picture.componentId_;
	picture.~Picture();
}

// picture deconstructor
Picture::~Picture() {
	entity_ = nullptr;
}

void Picture::render() {
	textureHandler::draw(*m_gameObject);
}


// get game object
std::shared_ptr <GameObject> Picture::getGameObject() const {
	return m_gameObject;
}

// set game object
void Picture::setGameObject(std::shared_ptr <GameObject> gameObject) {
	m_gameObject = std::move (gameObject);
}

// Tile
// Tile consturctor
Tile::Tile(int x, int y, int w, int h, sdl::shared_ptr <SDL_Texture> texture) {
	this->addComponent<Picture>(
		std::make_shared <Picture>(
			Picture(std::make_shared <Entity>(*this))
		)
	);
	GameObject temp;
	temp.texture = std::move (texture);
	temp.destRect = { x, y, w, h };
	temp.srcRect = { 0, 0, w, h };
	this->getComponent <Picture> ().setGameObject (std::make_shared <GameObject> (temp));
}

// Piece
// Piece consturctor
Piece::Piece(SDL_Rect&& srcRect, SDL_Rect&& destRect, sdl::shared_ptr <SDL_Texture> texture , int color) {
	this->addComponent<Picture>(
		std::make_shared <Picture>(
			Picture(std::make_shared <Entity>(*this))
		)
	);
	this->getComponent <Picture> ().setGameObject (std::make_shared <GameObject> (
		GameObject(
			texture,
			srcRect,
			destRect
		)
	));
	this->color = color;
}

// Piece constructor by rect copy
Piece::Piece(const SDL_Rect& srcRect, const SDL_Rect& destRect, sdl::shared_ptr <SDL_Texture> texture, int color) {
	this->addComponent<Picture>(
		std::make_shared <Picture>(
			Picture(std::make_shared <Entity>(*this))
		)
	);
	this->getComponent <Picture> ().setGameObject (std::make_shared <GameObject> (
		GameObject(
			texture,
			srcRect,
			destRect
		)
	));
	this->color = color;
}
