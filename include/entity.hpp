#pragma once
#include "config.hpp"

/*
Class to handle every object

#

*/
class Entity
{
  public:

    Entity();

    virtual void Draw();
    virtual void Update(float dt);

    virtual void OnRegister(std::vector<Entity*> *_entities_list);
};