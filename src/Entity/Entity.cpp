
#include "Entity.h"

Entity::Entity()
{
    body = std::make_unique<PhysicsObj>();
    angle = std::make_unique<Base::Vec2<f32>>(0.0f, -1.0f);
    size = std::make_unique<Base::Vec2<f32>>(1.0f, 1.0f);
    color = std::make_unique<Color>(0.5f, 0.5f, 0.5f);
}

Entity::~Entity()
{

}

void Entity::frame_update(std::vector<Entity*>* other_entities)
{
    if (m_needs_to_see_other_entities)
    {
        // do sum stuff with da data
    }

    Base::safe_free(other_entities);
}