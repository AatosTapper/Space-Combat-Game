
#include "ConstKineticEnergyTransfer.h"

ConstKineticEnergyTransfer::~ConstKineticEnergyTransfer()
{

}

void ConstKineticEnergyTransfer::solve(Entity* cur_entity, std::vector<Entity*>* oth_entities)
{
    for (u32 i = 0; i < oth_entities->size(); i++)
    {
        Entity* b = oth_entities->at(i);
        if (m_are_touching(cur_entity, b))
        {
            const Base::Vec2<f64> coll_normal = Base::vector_angle_normal(*cur_entity->body->pos, *b->body->pos);
            const f64 impulse = m_calc_impulse(cur_entity, b, coll_normal);
            
            const f64 x_f = impulse * coll_normal.x * 100.0;
            const f64 y_f = impulse * coll_normal.y * 100.0;

            cur_entity->body->add_force(Base::Vec2<f64>(x_f, y_f));
            b->body->add_force(Base::Vec2<f64>(-x_f, -y_f));
        }
    }
}

bool ConstKineticEnergyTransfer::m_are_touching(Entity* a, Entity* b)
{
    if (Base::vector_distance(*a->body->pos, *b->body->pos) < (a->body->radius + b->body->radius))
        return true;
    return false;
}

f64 ConstKineticEnergyTransfer::m_calc_impulse(Entity* a, Entity* b, const Base::Vec2<f64>& coll_normal)
{
    const f64 mass_ratio = (a->body->mass * b->body->mass) / (a->body->mass + b->body->mass);
    const f64 avrg_rest = 1.0 + (a->body->restitution + b->body->restitution) / 2.0;
    const Base::Vec2<f64> delta_vec = (
        b->body->vel->x - a->body->vel->x,
        b->body->vel->y - a->body->vel->y
    );
    const f64 dot_prod =  Base::vector_dot_product(delta_vec, coll_normal);
    return mass_ratio * avrg_rest * dot_prod;
}