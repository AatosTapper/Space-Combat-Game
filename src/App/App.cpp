
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
    Base::safe_free(r);
    Base::safe_free(s);
    Base::safe_free(lm);
    Base::safe_free(p);
}

void run_app()
{
    prepare();
    run();
    clean();
}