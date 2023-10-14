
#include "ConstCollision.h"

ConstCollision::~ConstCollision()
{
    
}

void ConstCollision::solve(Entity* cur_entity, std::vector<Entity*>* oth_entities)
{
    for (u32 i = 0; i < oth_entities->size(); i++)
    {
        apply_collision(cur_entity, oth_entities->at(i));
    }
}

void ConstCollision::apply_collision(Entity* a, Entity* b)
{
    const Base::Vec2<f64> intersection = calc_intersection(a, b);
    if (intersection.x == 0.0 && intersection.y == 0.0)
        return;
    if (!b->movable)
    {
        a->body->pos->x += intersection.x;
        a->body->pos->y += intersection.y;
    }
    else
    {
        const f64 total_mass = a->body->mass + b->body->mass;
        const f64 ratio_x = (intersection.x / total_mass) * a->body->mass;
        const f64 ratio_y = (intersection.y / total_mass) * a->body->mass;

        a->body->pos->x += intersection.x - ratio_x;
        a->body->pos->y += intersection.y - ratio_y;
        b->body->pos->x -= ratio_x; 
        b->body->pos->y -= ratio_y;

        a->body->add_force(Base::Vec2<f64>((intersection.x - ratio_x) * 100000, (intersection.y - ratio_y) * 100000));
        b->body->add_force(Base::Vec2<f64>(-ratio_x * 1000, -ratio_y * 100000));
    }
}

Base::Vec2<f64> ConstCollision::calc_intersection(Entity* a, Entity* b)
{
    const f64 safety_multiplier = 1.05;
    const f64 surface_dist = Base::vector_distance(*a->body->pos, *b->body->pos) - (a->body->radius + b->body->radius);
    if (Base::vector_distance(*a->body->pos, *b->body->pos) <= (a->body->radius + b->body->radius))
    {
        const f64 dist_ratio = surface_dist * (-1) / Base::vector_distance(*a->body->pos, *b->body->pos);
        const f64 d_x = (a->body->pos->x - b->body->pos->x) * dist_ratio * safety_multiplier;
        const f64 d_y = (a->body->pos->y - b->body->pos->y) * dist_ratio * safety_multiplier;

        return Base::Vec2<f64>(d_x, d_y);
    }
    return Base::Vec2<f64>(0.0, 0.0);
}