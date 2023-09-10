
#include "AiEntity.h"

AiEntity::AiEntity()
{
    m_needs_to_see_other_entities = true;
}

AiEntity::~AiEntity()
{

}

void AiEntity::set_target(Entity* target)
{
    if (target == nullptr)
        return;
    m_target = target;
    m_has_target = true;
}

void AiEntity::m_virtual_frame_update()
{
    if (m_target == nullptr)
    {
        m_has_target = false;
    }
}

void AiEntity::m_move()
{

}

void AiEntity::m_move(std::vector<Entity*>* other_entities)
{

}