#pragma once
#include "config.hpp"

namespace Entity
{
  extern char* map_vertex_src;
  extern char* map_frag_src;
  extern unsigned int map_shader_id;

  /*
  use of vertex array for performances

  */
  class Map: public Entity
  {
  public:
    virtual void Draw();
    virtual void Update();
    void LoadMap(std::string data, int tile_size, int map_size);
  private:
    unsigned int VAO, VBO, EBO;
  };
};