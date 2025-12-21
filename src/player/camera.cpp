#include "camera.hpp"

namespace Entity
{
  void Camera::Update(float dt)
  {
    // zoom
    m_camera.zoom = expf(logf(m_camera.zoom) + ((float)GetMouseWheelMove()*0.075f));
    if (m_camera.zoom > 3.0f) m_camera.zoom = 3.0f;
    else if (m_camera.zoom < 0.1f) m_camera.zoom = 0.1f;

    // mouse movements
    Vector2 mouse_pos = GetMousePosition();
    // spdlog::info("mouse pos x :{}, mouse pos y : {}", mouse_pos.x, mouse_pos.y);

    Vector2 dir = {0, 0};

    if(mouse_pos.x <= needed_camera_move)
    {
      dir.x -= 1;
    }

    if(mouse_pos.x >= screenWidth - (needed_camera_move))
    {
      dir.x += 1;
    }
    
    if(mouse_pos.y <= needed_camera_move)
    {
     dir.y -= 1;
    }

    if(mouse_pos.y >= screenHeight - (needed_camera_move))
    {
      dir.y += 1;
    }

    if(IsKeyDown(KEY_LEFT))
    {
      dir.x -= 1;
    }

    if(IsKeyDown(KEY_RIGHT))
    {
      dir.x += 1;
    }

    if(IsKeyDown(KEY_UP))
    {
      dir.y -= 1;
    }

    if(IsKeyDown(KEY_DOWN))
    {
      dir.y += 1;
    }

    // normalize the vector
    float length = sqrt(dir.x * dir.x + dir.y * dir.y);
    if(length == 0)
    {
      length = 1;
    }

    dir.x = dir.x * camera_speed * dt * (1/m_camera.zoom) / length + m_camera.target.x;
    dir.y = dir.y * camera_speed * dt * (1/m_camera.zoom) / length + m_camera.target.y;
    m_camera.target = dir;
    
  }

  Camera::Camera()
  {
    Global_Camera = &m_camera;

    m_camera.target = {0, 0};
    m_camera.offset = {0, 0};//{(float)screenWidth / 2.f, (float)screenHeight / 2.f};
    m_camera.rotation = 0.f;
    m_camera.zoom = 0.75f;

    // m_pos = {60, 60};
    // m_size = {90, 90};
  }

  void Camera::OnRegister(std::vector<Entity*> *_entities_list)
  {
    
  }

  Type Camera::GetType() {return eCAM;}
};