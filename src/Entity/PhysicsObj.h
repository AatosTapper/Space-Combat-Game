#ifndef PHYSICSOBJ_H
#define PHYSICSOBJ_H

#include <memory>

#include "../Base/Base.h"

class PhysicsObj
{
public:
    PhysicsObj();
    ~PhysicsObj();

    f32 weight; // kg
    std::unique_ptr<Base::Vec2<f32>> pos; // px
    std::unique_ptr<Base::Vec2<f32>> vel; // m/s
    std::unique_ptr<Base::Vec2<f32>> sigma_force; // N

    void add_force(Base::Vec2<f32> F);

private:
    void m_update_forces();
};

#endif