
#include "Entity.h"

Entity::Entity()
{
    body = std::make_unique<PhysicsObj>();
    color = std::make_unique<Color>(0.4f, 0.4f, 0.4f);
    movable = true;
    angle = PI / 2.0f;
    m_target = nullptr;
    m_needs_to_see_other_entities = false;
    m_has_target = false;
}

Entity::~Entity()
{
    
}

void Entity::frame_update(std::vector<Entity*>* other_entities)
{
    m_virtual_frame_update();
    if (m_needs_to_see_other_entities)
    {
        m_move(other_entities);
    }
    
    m_move();
    Base::safe_delete<std::__1::vector<Entity *>>(other_entities);
}