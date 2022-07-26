// entity component system
#include "game.hpp"

class Entity;
class Component;

// component type id genenrator
inline int typeIdGen() {
	static int id = 0;
	return id++;
}

template <typename T>
inline int typeId() {
	static int id = typeIdGen();
	return id;
}

class Component {
private:
	std::shared_ptr<Entity> entity_;
	int typeId_;
	int componentId_;
	static int componentIdGen_;
public:
	
	Component(std::shared_ptr<Entity> entity);
	
	virtual ~Component() {};
	virtual void render() = 0;
	virtual void update() = 0;
	
	inline int getTypeId() const {
		return typeId_;
	}
	
	inline int getComponentId() const {
		return componentId_;
	}
	
	std::shared_ptr<Entity> getEntity() const {
		return entity_;
	}
};

// type components map
class componentsMap {
private:
	static std::unordered_map <int, std::vector <std::shared_ptr<Component>>> components_;
	using vectorIt = typename std::vector <std::shared_ptr<Component>>::iterator;
	static std::unordered_map <int, vectorIt> componentsMapIter_;
public:
	static void addCompoenent(int typeId, int componentId, std::shared_ptr<Component> component) {
		components_[typeId].push_back(component);
		componentsMapIter_[componentId] = components_[typeId].end () - 1;
	}
	static void removeComponent(int typeId, int componentId) {
		components_[typeId].erase(componentsMapIter_[componentId]);
		componentsMapIter_.erase(componentId);
	}
	static void renderComponets() {
		for (const auto& pair : components_) {
			for (const auto& component : pair.second) {
				component->render();
			}
		}
	}
	static void updateComponets() {
		for (const auto& pair : components_) {
			for (const auto& component : pair.second) {
				component->update();
			}
		}
	}
};

class Entity {
private:
	std::unordered_map <int, std::shared_ptr<Component>> myComponents_;
	bool isAlive_ = true;
public:
	Entity() {}
	virtual ~Entity();
	
	template <typename T>
	T& addComponent(std::shared_ptr <T> component);
	
	template <typename T>
	T& getComponent();
	
	template <typename T>
	void removeComponent();
	
	void kill();
	
	void revive();
	
	bool isAlive() const {
		return isAlive_;
	}
};