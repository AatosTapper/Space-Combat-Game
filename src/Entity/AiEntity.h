#ifndef AIENTITY_H
#define AIENTITY_H

#include "../Base/Base.h"
#include "Entity.h"

class AiEntity : public Entity
{
public:
    AiEntity();
    ~AiEntity();

    void set_target(Entity* target);

protected:
    void m_virtual_frame_update() override;
    void m_move() override;
    void m_move(std::vector<Entity*>* other_entities) override;
};

#endif