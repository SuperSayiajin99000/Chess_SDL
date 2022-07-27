// entity component system

#pragma once
#include "game.hpp"

// class Entity;
class Component;

// component type id genenrator
int typeIdGen();
// type id getter

// get type id
template <typename T>
int typeId()
{
	// defined here becuse linker does not recognise template fucntions 
	// that are not called in the same file
	static int id = typeIdGen();
	return id;
}

// type components map
class componentsMap
{
private:
	static std::unordered_map<int, std::vector<std::shared_ptr<Component>>> components_;
	using vectorIt = size_t;
	static std::unordered_map<int, vectorIt> componentsMapIter_;

public:
	static void addCompoenent(
		int typeId,
		int componentId,
		std::shared_ptr<Component> component);
	static void removeComponent(int typeId, int componentId);
	static void renderComponets();
	static void updateComponets();
};

class Entity
{
protected:
	std::unordered_map<int, std::shared_ptr<Component>> myComponents_;
	bool isAlive_ = true;

public:
	Entity() = default;
	~Entity();

	template <typename T>
	T& addComponent(std::shared_ptr<T> component)
	{
		componentsMap::addCompoenent(
			typeId<T>(),
			component->getComponentId(),
			component
		);
		myComponents_[typeId<T>()] = component;
		return *component;
	}

	template <typename T>
	T& getComponent()
	{
		return *std::static_pointer_cast<T, Component>(myComponents_[typeId<T>()]);
	}

	template <typename T>
	void removeComponent()
	{
		// disown the component
		componentsMap::removeComponent(
			typeId<T>(),
			myComponents_[typeId<T>()]->getComponentId()
		);
		myComponents_.erase(typeId<T>());
	}

	void kill();

	void revive();

	bool isAlive() const
	{
		return isAlive_;
	}
};

class Component
{
protected:
	std::shared_ptr<Entity> entity_;
	int typeId_;
	int componentId_;
	static int componentIdGen_;

public:
	Component() = default;
	// Component(std::shared_ptr<Entity> entity);

	// a component cannot be initialize without an entity
	template <typename compT>
	void init(std::shared_ptr<Entity> entity) {
		this->entity_ = (entity);
		this->typeId_ = (typeId<compT>());
		this->componentId_ = (componentIdGen_++);
	}

	virtual ~Component()  = 0;
	virtual void render() = 0;
	virtual void update() = 0;

	inline int getTypeId() const
	{
		return typeId_;
	}

	inline int getComponentId() const
	{
		return componentId_;
	}

	virtual Entity getEntity() const
	{
		return *entity_;
	}
};
