
#include "RK4.h"

RK4::RK4()
{

}

RK4::~RK4()
{
    
}

void RK4::scale_forces(std::vector<Entity*>* entities, u32 steps)
{
    for (auto e : *entities)
    {
        e->body->sigma_force->x *= steps;
        e->body->sigma_force->y *= steps;
    }
}

void RK4::reset_forces(std::vector<Entity*>* entities)
{
    for (auto e : *entities)
    {
        e->body->reset_force();
    }
}

void RK4::solve_frame(std::vector<Entity*>* entities, const f64 &dt, f64 sim_speed)
{
    for (auto e : *entities)
    {
        m_apply_vel(&*e->body, m_runge_kutta(&*e->body, dt * sim_speed));
    }
}

Base::Vec2<f64> RK4::m_calc_vel(const PhysicsObj* obj, Base::Vec2<f64> vel,  const f64 &dt)
{
    const f64 x_acc = (obj->sigma_force->x / obj->mass) * dt;
    const f64 y_acc = (obj->sigma_force->y / obj->mass) * dt;

    const f64 x_vel = x_acc * dt;
    const f64 y_vel = y_acc * dt;

    return Base::Vec2<f64>(x_vel, y_vel);
}

Base::Vec2<f64> RK4::m_runge_kutta(PhysicsObj* obj, const f64 &dt)
{
    Base::Vec2<f64> temp(0.0f, 0.0f); // used for const reasons

    const Base::Vec2<f64> k1 = m_calc_vel(obj, *obj->vel, dt);
    temp = k1;
    const Base::Vec2<f64> k2 = m_calc_vel(obj, temp / Base::Vec2<f64>(2.0f, 2.0f), dt / 2.0f);
    temp = k2;
    const Base::Vec2<f64> k3 = m_calc_vel(obj, temp / Base::Vec2<f64>(2.0f, 2.0f), dt / 2.0f);
    const Base::Vec2<f64> k4 = m_calc_vel(obj, k3, dt);

    const f64 x_new_vel = obj->vel->x + (dt / 6.0f) * (k1.x + (2.0f * k2.x) + (2.0f * k3.x) + k4.x);
    const f64 y_new_vel = obj->vel->y + (dt / 6.0f) * (k1.y + (2.0f * k2.y) + (2.0f * k3.y) + k4.y);

    return Base::Vec2<f64>(x_new_vel, y_new_vel);
}

void RK4::m_apply_vel(PhysicsObj* obj, Base::Vec2<f64> new_vel)
{
    *obj->vel = new_vel;
    *obj->pos += new_vel;
}