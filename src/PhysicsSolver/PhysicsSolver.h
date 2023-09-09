#ifndef PHYSICSSOLVER_H
#define PHYSICSSOLVER_H

#include <vector>
#include <memory>

#include "../Base/Base.h"
#include "../Entity/Entity.h"

class PhysicsSolver
{
public:
    PhysicsSolver();
    ~PhysicsSolver();

    void update_physics(std::vector<Entity*>* entities);

private:

};

#endif