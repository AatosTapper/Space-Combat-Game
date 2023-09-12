
#include "Gameloop.h"

void gameloop(Renderer* r, Scene* s, LogicManager* lm, PhysicsEngine* p)
{
    r->setup();

    f64 last_time = 0.0f;
    while (!glfwWindowShouldClose(r->get_window())) 
    {
        f64 time = glfwGetTime();
        f64 delta_time = time - last_time;
        last_time = time;

        p->update_physics(s->get_entities(), delta_time);
        lm->frame_update(s, p);
        r->draw_frame(s);
    }
    r->clean();
}