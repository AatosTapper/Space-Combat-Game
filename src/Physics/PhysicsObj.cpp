
#include "PhysicsObj.h"

PhysicsObj::PhysicsObj()
{
    mass = 1.0f;
    radius = 30.0f;
    restitution = 0.1f;
    pos = std::make_unique<Base::Vec2<f64>>(0.0f, 0.0f);
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

void PhysicsObj::reset_force()
{
    *sigma_force = Base::Vec2<f64>(0.0f, 0.0f);
}