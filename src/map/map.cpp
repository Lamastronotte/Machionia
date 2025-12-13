#include "map.hpp"

/*

*/

namespace Entity
{
  /*
  TODO use of vertex array for performances

  */

  /*
    struct Cell
  {
    Rectangle m_texture_pos;
    Vector2 m_pos;
    bool has_collision;
  };

  /*

  class Map: public Entity
  {
  public:
    virtual void Draw();
    virtual void Update();
    void LoadMap(std::string data, std::string texture, int tile_size, int map_size);
  private:
    std::vector<Cell> m_cells;
    std::string m_texture;
  };*/

  void Map::Draw()
  {
    Texture* texture = Global_Assets.GetTexture(m_texture);
    for(auto& cell : m_cells)
    {
      DrawTextureRec(*texture, cell.m_pos, cell.m_pos, WHITE);
    }
  }
  void Map::Update()
  {

  }
  void Map::LoadMap(std::string data, std::string texture, int tile_size, int map_size)
  {
    
  }

};