#ifndef PHYSICSOBJ_H
#define PHYSICSOBJ_H

#include <memory>

#include "../Base/Base.h"

class PhysicsObj
{
public:
    PhysicsObj();
    ~PhysicsObj();

    f64 mass; // kg
    f64 radius; // px
    std::unique_ptr<Base::Vec2<f64>> pos; // px
    std::unique_ptr<Base::Vec2<f64>> vel; // m/s
    std::unique_ptr<Base::Vec2<f64>> sigma_force; // N

    void add_force(Base::Vec2<f64> F);
    void reset_force();
};

#endif