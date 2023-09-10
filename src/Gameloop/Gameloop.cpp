
#include "Gameloop.h"

void gameloop(Renderer* r, Scene* s, LogicManager* lm, PhysicsSolver* p)
{
    r->setup();
    
    f64 last_time = 0.0f;
    while (!glfwWindowShouldClose(r->get_window())) 
    {
        f64 time = glfwGetTime();
        f64 delta_time = time - last_time;
        last_time = time;

        lm->frame_update(s, p, delta_time);
        r->draw_frame(s);
    }
    r->clean();
}