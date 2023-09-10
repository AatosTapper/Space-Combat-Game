#ifndef LOGICMANAGER_H
#define LOGICMANAGER_H

#include "../Base/Base.h"
#include "../Scene/Scene.h"
#include "../Entity/Entity.h"
#include "../Physics/PhysicsSolver.h"

class LogicManager
{
public:
    LogicManager(Scene* s);
    ~LogicManager();

    void frame_update(Scene* s, PhysicsSolver* p, const f64 &dt);

private:
    void m_update_entities(Scene* s);
    std::vector<Entity*>* m_get_entities_but_i(Scene* s, u32 index);
};

#endif