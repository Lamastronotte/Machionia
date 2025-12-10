
#include "entity.hpp"

// mostly nothing
Entity::Entity() {}
void Entity::Draw() {DrawTexture(*Global_Assets.GetTexture("fodder"), 0, 0, WHITE);}
void Entity::Update(float dt) {}

void Entity::OnRegister(std::vector<Entity*> *_entities_list) {}