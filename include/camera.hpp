#include "config.hpp"

namespace Entity
{

  /*
  handle a camera2d object

  if mouse is on the border or some keys are pressed, the camera moves
  zoom
  */

  class Camera: public Entity
  {
  public:
    void Update(float dt);
    void OnRegister(std::vector<Entity*> *_entities_list);
  private:
    Camera2D m_camera;
  };
};