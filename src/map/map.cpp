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
      // DrawTexturePro(*texture, {0, 0, 100, 100}, {0, 0, 100, 100}, {50, 50}, 0, WHITE);
      // void DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint);oid DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint);
      //void DrawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint);   
      // DrawTexturePro(*texture, {0, 0, 100, 100}, {0, 0, 100, 100}, {50, 50}, 0, WHITE);
      // DrawTextureRec(*texture, cell.m_texture_pos, cell.m_pos, WHITE);   
      DrawTexturePro(*texture, cell.m_texture_pos, {cell.m_pos.x, cell.m_pos.y, (float)m_tile_size, (float)m_tile_size}, {0.f, 0.f}, 0, WHITE);
    }
  }
  void Map::Update()
  {

  }
  void Map::LoadMap(int* data, std::string texture, int tile_size, int map_size)
  {
    m_texture = texture;
    m_tile_size = tile_size;
    m_map_size = map_size;
    
    for(int x = 0; x < m_map_size; x++)
    {
      for(int y = 0; y < m_map_size; y++)
      {
        int id = x + y * m_map_size;
        // spdlog::info("{}", id);
        m_cells.push_back({{(float)data[id] * (float)100 + 1, (float)0, (float)100, (float)100}, {(float)x * (float)m_tile_size, (float)y * (float)m_tile_size}});
      }
    }
    // m_cells.push_back({{0, 0, 100, 100}, {0, 0}});
  }

};