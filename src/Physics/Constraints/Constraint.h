#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include <vector>

#include "../../Base/Base.h"
#include "../../Entity/Entity.h"

class Constraint
{
public:
    Constraint() {}
    virtual ~Constraint() {}

    virtual void solve(Entity* cur_entity, std::vector<Entity*>* oth_entities) {}
};

#endif