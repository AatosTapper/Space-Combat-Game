
#include "PlayerEntity.h"

PlayerEntity::PlayerEntity()
{
    m_needs_to_see_other_entities = false;
    m_window = nullptr;
}

PlayerEntity::~PlayerEntity()
{

}

void PlayerEntity::m_virtual_frame_update()
{

}

void PlayerEntity::m_move()
{
    if (m_window == nullptr)
        return;

    const f64 speed = 50.0f;
    const f32 turn_speed = PI / 80.0f;

    if (glfwGetKey(m_window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        angle -= turn_speed;
        Base::clamp_radians(&angle);
    }

    if (glfwGetKey(m_window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        angle += turn_speed;
        Base::clamp_radians(&angle);
    }

    if (glfwGetKey(m_window, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        body->add_force(Base::Vec2<f64>(cos(angle) * -speed, sin(angle) * -speed));
    }
}

void PlayerEntity::m_move(std::vector<Entity*>* other_entities)
{

}

void PlayerEntity::get_window(GLFWwindow* window)
{
    m_window = window;
}