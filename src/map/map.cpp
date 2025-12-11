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
    unsigned short indices[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    rlEnableShader(map_shader_id);
        rlEnableVertexArray(VAO);
            // rlDrawVertexArray(0, 3);
            rlDrawVertexArrayElements(0, 6, indices);
        rlDisableVertexArray();
    rlDisableShader();
  }
  void Map::Update()
  {

  }
  void Map::LoadMap(std::string data, int tile_size, int map_size)
  {
    float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };

    unsigned short indices[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };  

    VAO = rlLoadVertexArray();
    rlEnableVertexArray(VAO);

    VBO = rlLoadVertexBuffer(vertices, sizeof(vertices), false);
    EBO = rlLoadVertexBufferElement(indices, sizeof(indices), false);

    rlSetVertexAttribute(0, 3, RL_FLOAT, 0, 3 * sizeof(float), 0);
    rlEnableVertexAttribute(0);

    rlDisableVertexBuffer();
    rlDisableVertexArray();
  }

};