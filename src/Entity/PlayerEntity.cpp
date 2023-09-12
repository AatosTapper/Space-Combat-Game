
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

    if (glfwGetKey(m_window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        body->add_force(Base::Vec2<f64>(-5.0f, 0.0f));
    }
    if (glfwGetKey(m_window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        body->add_force(Base::Vec2<f64>(5.0f, 0.0f));
    }
    if (glfwGetKey(m_window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        body->add_force(Base::Vec2<f64>(0.0f, -5.0f));
    }
    if (glfwGetKey(m_window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        body->add_force(Base::Vec2<f64>(0.0f, 5.0f));
    }
}

void PlayerEntity::m_move(std::vector<Entity*>* other_entities)
{

}

void PlayerEntity::get_window(GLFWwindow* window)
{
    std::cout << "got window\n";
    m_window = window;
}