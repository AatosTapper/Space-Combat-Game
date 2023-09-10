#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include "../Base/Base.h"
#include "Entity.h"

class PlayerEntity : public Entity
{
public:
    PlayerEntity();
    ~PlayerEntity();

protected:
    void m_virtual_frame_update() override;
    void m_move() override;
    void m_move(std::vector<Entity*>* other_entities) override;
};

#endif