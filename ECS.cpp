#include "ECS.hpp"

Component::Component(std::shared_ptr<Entity> entity) :
	entity_(entity),
	typeId_(typeId<Component>()),
	componentId_(componentIdGen_++) {}

Component::~Component() {}

std::unordered_map <int, std::vector <std::shared_ptr<Component>>> componentsMap::components_;
using vectorIt = typename std::vector <std::shared_ptr<Component>>::iterator;
std::unordered_map <int, vectorIt> componentsMap:: componentsMapIter_;

void componentsMap::addCompoenent(int typeId, int componentId, std::shared_ptr<Component> component) {
	components_[typeId].push_back(component);
	componentsMapIter_[componentId] = components_[typeId].end() - 1;
}

void componentsMap::removeComponent(int typeId, int componentId) {
	components_[typeId].erase(componentsMapIter_[componentId]);
	componentsMapIter_.erase(componentId);
}

void componentsMap::renderComponets() {
	for (const auto& pair : components_) {
		for (const auto& component : pair.second) {
			component->render();
		}
	}
}

void componentsMap::updateComponets() {
	for (const auto& pair : components_) {
		for (const auto& component : pair.second) {
			component->update();
		}
	}
}

Entity::~Entity() {
	// components_ disowns the Components in it
	kill();
	myComponents_.clear();
};

template <typename T>
T& Entity::addComponent(std::shared_ptr <T> component) {
	componentsMap::addCompoenent(typeId<T>(), component->getComponentId(), component);
	myComponents_[typeId<T>()] = component;
	return *component;
}

template <typename T>
T& Entity::getComponent() {
	return *static_cast<std::shared_ptr <T>>(myComponents_[typeId<T>()]);
}

template <typename T>
void Entity::removeComponent() {
	// disown the component
	componentsMap::removeComponent(typeId<T>(), myComponents_[typeId<T>()]->getComponentId());
}

void Entity::kill() {
	isAlive_ = false;
	// remove components form the components map
	for (const auto& pair : myComponents_) {
		componentsMap::removeComponent(pair.first, pair.second->getComponentId());
	}
}
void Entity::revive() {
	if (isAlive_)
		return;
	// add components to the components map
	for (const auto& pair : myComponents_) {
		componentsMap::addCompoenent(pair.first, pair.second->getComponentId(), pair.second);
	}
}