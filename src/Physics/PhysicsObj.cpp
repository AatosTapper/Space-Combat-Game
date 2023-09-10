
#include "PhysicsObj.h"

PhysicsObj::PhysicsObj()
{
    weight = 1.0f;
    pos = std::make_unique<Base::Vec2<f64>>(0.0f, 0.0f);
    size = std::make_unique<Base::Vec2<f64>>(1.0f, 1.0f);
    vel = std::make_unique<Base::Vec2<f64>>(0.0f, 0.0f);
    sigma_force = std::make_unique<Base::Vec2<f64>>(0.0f, 0.0f);
}

PhysicsObj::~PhysicsObj()
{
    
}

void PhysicsObj::add_force(Base::Vec2<f64> F)
{
    *sigma_force += F;
}