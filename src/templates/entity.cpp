
#include "entity.hpp"

// mostly nothing

Entity::Entity() {}
void Entity::Draw() {DrawText("HELLO FROM ENTITY", 50, 50, 30, PURPLE);}
void Entity::Update(float dt) {}

void Entity::OnRegister(std::vector<Entity*> *_entities_list) {}