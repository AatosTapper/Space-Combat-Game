#ifndef PHYSICSSOLVER_H
#define PHYSICSSOLVER_H

#include <vector>
#include <memory>

#include "../Base/Base.h"
#include "../Entity/Entity.h"
#include "PhysicsObj.h"
#include "RK4.h"

class PhysicsSolver
{
public:
    PhysicsSolver();
    ~PhysicsSolver();

    void update_physics(std::vector<Entity*>* entities, const f64 &dt);

private:
    std::unique_ptr<RK4> solver;
};

#endif