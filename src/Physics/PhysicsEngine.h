#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>
#include <memory>

#include "../Base/Base.h"
#include "../Entity/Entity.h"
#include "PhysicsObj.h"
#include "RK4.h"
#include "Constraints/Constraint.h"

// check bounds for different speeds
#define SLOW_MAX_DIST 100.0f
#define MED_MAX_DIST 200.0f
#define FAST_MAX_DIST 400.0f
#define VEL_SAFE_LIMIT 0.8f

class PhysicsEngine
{
public:
    PhysicsEngine();
    ~PhysicsEngine();

    void update_physics(std::vector<Entity*>* entities, const f64 &dt);

private:
    std::unique_ptr<RK4> m_solver;
    std::unique_ptr<std::vector<Constraint*>> m_constraints;

    void m_solve_constraints(std::vector<Entity*>* entities);
    bool m_dist_bound_entity(Entity* a, Entity* b);
};

#endif