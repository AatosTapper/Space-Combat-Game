
#include "App.h"

Renderer* r = new Renderer();
Scene* s = new Scene();
LogicManager* lm = new LogicManager(s);
PhysicsEngine* p = new PhysicsEngine();
Entity* player = new PlayerEntity();
Entity* enemy = new AiEntity();

void prepare()
{
    r->set_screen(1280u, 720u);

    player->body->radius = 30.0f;
    player->body->mass = 20.0f;
    *player->body->pos = Base::Vec2<f64>(-200.0f, -200.0f);

    enemy->body->radius = 60.0f;
    enemy->body->mass = 50.0f;
    *enemy->body->pos = Base::Vec2<f64>(0.0f, 0.0f);
    s->add_entity(enemy);
}

void run()
{
    gameloop(r, s, lm, p, player);
}

void clean()
{
    Base::safe_delete<Renderer>(r);
    Base::safe_delete<Scene>(s);
    Base::safe_delete<LogicManager>(lm);
    Base::safe_delete<PhysicsEngine>(p);
}

void run_app()
{
    prepare();
    run();
    clean();
}