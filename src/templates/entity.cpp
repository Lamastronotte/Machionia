
#include "entity.hpp"

// mostly nothing
namespace Entity
{
  // pls no static functions
  Entity::Entity() {}
  // void Entity::Draw() {DrawTexturePro(*Global_Assets.GetTexture("fodder"), {0, 0, 100, 100}, {0, 0, 100, 100}, {50, 50}, 0, WHITE);}
  // void Entity::Update(float dt) {}

  void Entity::OnRegister(std::vector<Entity*> *_entities_list) {}
}