#ifndef RK4_H
#define RK4_H

#include <cmath>
#include <memory>
#include <vector>

#include "../Base/Base.h"
#include "../Entity/Entity.h"
#include "PhysicsObj.h"

class RK4
{
public:
    RK4();
    ~RK4();
    
    void solve_frame(std::vector<Entity*>* entities, const f64 &dt);

private:
    void m_apply_forces(PhysicsObj* obj, const f64 &dt);
};

#endif