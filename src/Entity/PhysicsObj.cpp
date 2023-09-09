
#include "PhysicsObj.h"

PhysicsObj::PhysicsObj()
{
    weight = 1.0f;
    pos = std::make_unique<Base::Vec2<f32>>(0.0f, 0.0f);
    vel = std::make_unique<Base::Vec2<f32>>(0.0f, 0.0f);
    sigma_force = std::make_unique<Base::Vec2<f32>>(0.0f, 0.0f);
}

PhysicsObj::~PhysicsObj()
{
    
}

void PhysicsObj::add_force(Base::Vec2<f32> F)
{
    *sigma_force += F;
}

void PhysicsObj::m_update_forces()
{
    *sigma_force = Base::Vec2<f32>(0.0f, 0.0f);
}