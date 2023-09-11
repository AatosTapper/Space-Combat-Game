
#include "PhysicsSolver.h"

#define SIM_SPEED 10 // nx faster

PhysicsSolver::PhysicsSolver()
{
    solver = std::make_unique<RK4>();
}

PhysicsSolver::~PhysicsSolver()
{
    
}

void PhysicsSolver::update_physics(std::vector<Entity*>* entities, const f64 &dt)
{
    solver->solve_frame(entities, dt, SIM_SPEED);
}