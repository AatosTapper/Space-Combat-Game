#ifndef ENTITY_H
#define ENTITY_H

#include <glfw3.h>
#include <memory>
#include <vector>

#include "../Base/Base.h"
#include "../Physics/PhysicsObj.h"
#include "../Renderer/Color.h"

class Entity
{
public:
    Entity();
    virtual ~Entity();

    bool movable;
    f32 angle;
    std::unique_ptr<PhysicsObj> body;
    std::unique_ptr<Color> color;

    void frame_update(std::vector<Entity*>* other_entities);

protected:
    bool m_needs_to_see_other_entities;
    bool m_has_target;
    Entity* m_target;

    // this is called at the START of the frame
    virtual void m_virtual_frame_update() {};
    virtual void m_move() {};
    virtual void m_move(std::vector<Entity*>* other_entities) {};
};

#endif