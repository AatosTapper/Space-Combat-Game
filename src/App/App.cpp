
#include "App.h"

Renderer* r = new Renderer();
Scene* s = new Scene();
LogicManager* lm = new LogicManager(s);
PhysicsSolver* p = new PhysicsSolver();

void prepare()
{
    r->set_screen(1280u, 720u);
}

void run()
{
    gameloop(r, s, lm, p);
}

void clean()
{
    Base::safe_delete(r);
    Base::safe_delete(s);
    Base::safe_delete(lm);
    Base::safe_delete(p);
}

void run_app()
{
    prepare();
    run();
    clean();
}