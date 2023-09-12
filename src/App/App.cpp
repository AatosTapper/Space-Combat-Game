
#include "App.h"

Renderer* r = new Renderer();
Scene* s = new Scene();
LogicManager* lm = new LogicManager(s);
PhysicsEngine* p = new PhysicsEngine();
Entity* player = new PlayerEntity();

void prepare()
{
    r->set_screen(1280u, 720u);

    player->body->mass = 10.0f;
    *player->body->pos = Base::Vec2<f64>(-200.0f, -200.0f);
    *player->body->size = Base::Vec2<f64>(30.0f, 30.0f);
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