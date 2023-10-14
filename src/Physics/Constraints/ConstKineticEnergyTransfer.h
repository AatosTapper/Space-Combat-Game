#ifndef KINETICENERGYTRANSFER_H
#define KINETICENERGYTRANSFER_H

#include "Constraint.h"

class ConstKineticEnergyTransfer : public Constraint
{
public: 
    ~ConstKineticEnergyTransfer() override;

    void solve(Entity* cur_entity, std::vector<Entity*>* oth_entities) override;

private:
    bool m_are_touching(Entity* a, Entity* b);
    f64 m_calc_impulse(Entity* a, Entity* b, const Base::Vec2<f64>& coll_normal);
};

#endif