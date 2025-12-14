#pragma once
#include "config.hpp"

namespace Entity
{

  struct Cell
  {
    Rectangle m_texture_pos;
    Vector2 m_pos;
    // bool has_collision;
  };

  /*
  TODO use of vertex array for performances

  convert some data in the form "aaabbbaacc
                                 aabbbaaccc"
  in a tilemap
  for now use of void DrawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint); for drawing
  */
  class Map: public Entity
  {
  public:
    void Draw();
    void Update();
    void LoadMap(int* data, std::string texture, int tile_size, int map_size);
  private:
    std::vector<Cell> m_cells;
    std::string m_texture;
    int m_tile_size;
    int m_map_size;
  };
};

/*
TAKE INSPIRATION OF 
#ifndef GRIDD_HPP
#define GRIDD_HPP

#include "config.hpp"
#include "textures.hpp"

#include <raylib.h>

#include <map>

// a grid containing all game data

class Cell {
public:
  int m_texture;
  int hp;
  int cell_type;

  void update()
  {}
};

class Grid {
private:
  Cell data[grid_size * grid_size];

public:
  Grid() // empty grid
  { 
    Cell blank = { 0, -1 };
    Cell _core = { core, -1 };
    std::fill_n(data, sizeof(data)/sizeof(data[0]), blank);
    set(core_pos, core_pos, _core);
  }


  void set(int x, int y, Cell value)
  { data[x + y * grid_size] = value; }

  Cell* get()
  { return data; }

  Cell get(int x, int y)
  { return data[x + y * grid_size]; }

  void render() {
    //Rectangle recSRC = {0, 0, tile_size, tile_size};
    for(int x = 0; x < grid_size; x++) {
      for(int y = 0; y < grid_size; y++) {
        // (window_width / 2) - (tile_size * grid_size / 2) + (x * tile_size), (window_height / 2) - (tile_size * grid_size / 2) + y * tile_size, tile_size, tile_size, texture_grid[data[x + y * grid_size]]


        DrawTexturePro(
          texture_grid[data[x + y * grid_size].m_texture],
          {0.f, 0.f, 16.f, 16.f},
          {(window_width / 2) - (tile_size * grid_size / 2.f) + (x * tile_size),
           (window_height / 2) - (tile_size * grid_size / 2.f) + y * tile_size,
            tile_size, tile_size},
          {0, 0},
          0,
          WHITE
        );
        
      }
    }
  }
};

#endif
*/