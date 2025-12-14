#include "camera.hpp"

namespace Entity
{
  void Camera::Update(float dt)
  {
    m_camera.zoom = expf(logf(m_camera.zoom) + ((float)GetMouseWheelMove()*0.1f));

    if (m_camera.zoom > 3.0f) m_camera.zoom = 3.0f;
    else if (m_camera.zoom < 0.1f) m_camera.zoom = 0.1f;
  }

  void Camera::OnRegister(std::vector<Entity*> *_entities_list)
  {
    Global_Camera = &m_camera;

    m_camera.target = {0, 0};
    m_camera.offset = {0, 0};//{(float)screenWidth / 2.f, (float)screenHeight / 2.f};
    m_camera.rotation = 0.f;
    m_camera.zoom = 0.75f;
  }
};