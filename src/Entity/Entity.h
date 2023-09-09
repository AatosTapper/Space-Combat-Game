#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include <vector>

#include "../Base/Base.h"
#include "PhysicsObj.h"
#include "../Renderer/Color.h"

class Entity
{
public:
    Entity();
    ~Entity();

    std::unique_ptr<PhysicsObj> body;
    std::unique_ptr<Base::Vec2<f32>> angle;
    std::unique_ptr<Base::Vec2<f32>> size; // width, height
    std::unique_ptr<Color> color;

    void frame_update(std::vector<Entity*>* other_entities);

private:
    bool m_needs_to_see_other_entities;
};

#endif