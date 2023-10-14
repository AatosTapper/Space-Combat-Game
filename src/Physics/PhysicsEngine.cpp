
#include "PhysicsEngine.h"

#define SIM_SPEED 20 // nx faster

PhysicsEngine::PhysicsEngine()
{
    m_solver = std::make_unique<RK4>();
    m_constraints = std::make_unique<std::vector<std::unique_ptr<Constraint>>>();
    //m_constraints->push_back(std::make_unique<ConstKineticEnergyTransfer>());
    m_constraints->push_back(std::make_unique<ConstCollision>());
}

PhysicsEngine::~PhysicsEngine()
{
    
}

void PhysicsEngine::update_physics(std::vector<Entity*>* entities, const f64 &dt)
{
    m_solver->scale_forces(entities, CHECKS_PER_FRAME);
    for (u32 i = 0; i < CHECKS_PER_FRAME; i++)
    {
        m_solver->solve_frame(entities, dt / CHECKS_PER_FRAME, SIM_SPEED);
        m_solve_constraints(entities);
    }
    m_solver->reset_forces(entities);
}

void PhysicsEngine::m_solve_constraints(std::vector<Entity*>* entities)
{
    for (u32 j = 0; j < entities->size(); j++)
    {
        if (!entities->at(j)->movable)
            continue;
        std::vector<Entity*> all_but_index;
        for (u32 k = 0; k < entities->size(); k++)
        {
            if (k == j)
                continue;
            if (!m_dist_bound_entity(entities->at(j), entities->at(k)))
                continue;
            all_but_index.push_back(entities->at(k));
        }
        
        for (u32 i = 0; i < m_constraints->size(); i++)
        {
            m_constraints->at(i)->solve(entities->at(j), &all_but_index);
        }
    }
}

bool PhysicsEngine::m_dist_bound_entity(Entity* a, Entity* b)
{
    f32 dist_lim = 0;
    const f64 a_speed = Base::vector_len(*a->body->vel);
    const f64 b_speed = Base::vector_len(*b->body->vel);

    if (a_speed < SLOW_MAX_DIST * VEL_SAFE_LIMIT || b_speed < SLOW_MAX_DIST * VEL_SAFE_LIMIT)
        dist_lim = SLOW_MAX_DIST;
    else if (a_speed < MED_MAX_DIST * VEL_SAFE_LIMIT || b_speed < MED_MAX_DIST * VEL_SAFE_LIMIT)
        dist_lim = MED_MAX_DIST;
    else if (a_speed < FAST_MAX_DIST * VEL_SAFE_LIMIT || b_speed < FAST_MAX_DIST * VEL_SAFE_LIMIT)
        dist_lim = FAST_MAX_DIST;

    if (Base::vector_distance(*a->body->pos, *b->body->pos) > dist_lim)
        return false;

    return true;
}