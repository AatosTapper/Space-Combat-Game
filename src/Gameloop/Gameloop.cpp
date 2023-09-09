
#include "Gameloop.h"

void gameloop(Renderer* r, Scene* s, LogicManager* lm, PhysicsSolver* p)
{
    r->setup();
    while (!glfwWindowShouldClose(r->get_window())) 
    {
        lm->frame_update(s, p);
        r->draw_frame(s);
    }
    r->clean();
}