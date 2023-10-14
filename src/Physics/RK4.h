#ifndef RK4_H
#define RK4_H

#include <cmath>
#include <memory>
#include <vector>
#include <iostream>

#include "../Base/Base.h"
#include "../Entity/Entity.h"
#include "PhysicsObj.h"

class RK4
{
public:
    RK4();
    ~RK4();
    
    void scale_forces(std::vector<Entity*>* entities, u32 steps);
    void solve_frame(std::vector<Entity*>* entities, const f64 &dt, f64 sim_speed);
    void reset_forces(std::vector<Entity*>* entities);

private:
    Base::Vec2<f64> m_calc_vel(const PhysicsObj* obj, Base::Vec2<f64> vel, const f64 &dt);
    Base::Vec2<f64> m_runge_kutta(PhysicsObj* obj, const f64 &dt);
    void m_apply_vel(PhysicsObj* obj, Base::Vec2<f64> new_vel);
};

#endif