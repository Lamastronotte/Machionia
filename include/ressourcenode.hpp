#pragma once
#include "config.hpp"
#include "map.hpp"

namespace Entity
{

  // map to a name that maps to a texture

  enum RessourceNodeType
  {
    eNULL,
    eGOLD,
    eOIL,
    eMETAL
  };

  extern std::map<int, std::string> TypeToTexture;

  class RessourceNode: public Entity, public Collider
  {
   public:
     RessourceNode();

    virtual void Draw(); // draw the right sprite
    virtual void Update(float dt); // maybe animation

    Type GetType();
    int GetDrawLayer();


		int m_node_type;
  };

  /*
  loads with 2 maps : a collision box and a mask, place nodes on collision box and erase thos with mask
  the collision box is the terrain and the mask is the path for the troops
  */
  class RessourceNodeManager 
  {
  public:

    // frequency is x / 10 tiles
    // needs 2 loaded maps
    void LoadNodes(Map* area, Map* mask, float frequency)
    {
      // get data
			Rectangle area_rectangle = area->GetRectangle();
			int tile_size = area->m_tile_size;
			int tiles_per_row = area_rectangle.height / tile_size - 1;
			//spdlog::info("There are {} tiles per row", tiles_per_row);

			// for each tile get frequency / 100 chance to spawn a node with a random type
      for (int x = 0; x < tiles_per_row; x++)
      {
        for (int y = 0; y < tiles_per_row; y++)
        {
          int rand_num = (rand() % 100) + 1; // 1 to 100
          if (rand_num <= frequency)
          {
            RessourceNode* new_node = new RessourceNode;
						new_node->m_pos = { (float)(x * tile_size + (rand() % tile_size)), (float)(y * tile_size+ (rand() % tile_size)) };
            new_node->m_node_type = (rand() % 3) + 1; // 1 to 3
            Global_Entities.Register(new_node);
          }
        }
      } 
    }

    void LoadTextures()
    {
      TypeToTexture[eGOLD] = "gold_ore";
      TypeToTexture[eOIL] = "oil_res";
      TypeToTexture[eMETAL] = "metal_deposit";
		}

  private:
		std::vector<RessourceNode> m_nodes;
  };
};