#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

#include "../Base/Base.h"
#include "../Entity/Entity.h"

class Scene
{
public:
    Scene();
    ~Scene();

    std::vector<Entity*>* get_entities();
    // ownership is exchanged to this class
    void add_entity(Entity* e);

private:
    std::vector<Entity*>* m_entities;

    void m_free_entities();
};

#endif