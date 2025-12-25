
#include "entity.hpp"

int resource_node_number = 3;



// mostly nothing
namespace Entity
{
  // pls no static functions
  
  std::vector<std::string> RessourceTypeName;

  void LoadRessourceTypeName()
  {
    RessourceTypeName.push_back("NULL");
    RessourceTypeName.push_back("GOLD");
    RessourceTypeName.push_back("OIL");
		RessourceTypeName.push_back("METAL");
  }

}