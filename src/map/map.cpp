#include "map.hpp"

/*

*/

namespace Entity
{
  /*
  use of vertex array for performances

  */

  char *map_vertex_src = "#version 330 core\n"
  "layout (location = 0) in vec3 aPos;\n"
  "void main()\n"
  "{\n"
  "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
  "}\0";

  char *map_frag_src = "#version 330 core\n"
  "out vec4 FragColor;\n"
  "void main()\n"
  "{\n"
  "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
  "}\n\0";

  unsigned int map_shader_id;

  void Map::Draw()
  {

  }
  void Map::Update()
  {

  }
  void Map::LoadMap(std::string data, std::string texture, int tile_size, int map_size)
  {

  }

};