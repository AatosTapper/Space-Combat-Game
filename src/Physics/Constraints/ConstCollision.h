#ifndef CONSTCOLLISION_H
#define CONSTCOLLISION_H

#include "Constraint.h"

class ConstCollision : public Constraint
{
public:
    ~ConstCollision() override;

    void solve(Entity* cur_entity, std::vector<Entity*>* oth_entities) override;

private:
    void apply_collision(Entity* a, Entity* b);
    Base::Vec2<f64> calc_intersection(Entity* a, Entity* b);
};

#endif