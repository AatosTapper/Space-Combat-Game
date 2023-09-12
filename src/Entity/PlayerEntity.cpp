
#include "PlayerEntity.h"

PlayerEntity::PlayerEntity()
{
    m_needs_to_see_other_entities = false;
}

PlayerEntity::~PlayerEntity()
{

}

void PlayerEntity::m_virtual_frame_update()
{

}

void PlayerEntity::m_move()
{
    
}

void PlayerEntity::m_move(std::vector<Entity*>* other_entities)
{

}