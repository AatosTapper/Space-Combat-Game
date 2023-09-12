#ifndef LOGICMANAGER_H
#define LOGICMANAGER_H

#include <glfw3.h>

#include "../Base/Base.h"
#include "../Scene/Scene.h"
#include "../Entity/Entity.h"
#include "../Entity/PlayerEntity.h"
#include "../Entity/AiEntity.h"
#include "../Physics/PhysicsEngine.h"

class LogicManager
{
public:
    LogicManager(Scene* s);
    ~LogicManager();

    void frame_update(Scene* s, PhysicsEngine* p);

private:
    void m_update_entities(Scene* s);
    std::vector<Entity*>* m_get_entities_but_i(Scene* s, u32 index);
};

#endif