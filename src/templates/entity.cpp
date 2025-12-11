
#include "entity.hpp"

// mostly nothing
namespace Entity
{
  // pls no static functions
  Entity::Entity() {}
  void Entity::Draw() {}
  void Entity::Update(float dt) {}

  void Entity::OnRegister(std::vector<Entity*> *_entities_list) {}
}