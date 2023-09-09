#ifndef RENDERER_H
#define RENDERER_H

#include <glfw3.h>
#include <iostream>

#include "../Base/Base.h"
#include "Color.h"
#include "../Scene/Scene.h"
#include "../Entity/Entity.h"

class Renderer
{
public:
    Renderer();
    ~Renderer();

    std::unique_ptr<Base::Vec2<f32>> offset;

    void set_screen(u32 width, u32 height);
    void setup();
    void draw_frame(Scene* s);
    void clean();
    GLFWwindow* get_window();

private:
    u32 m_SW;
    u32 m_SH;
    GLFWwindow* m_window;

    void m_draw_entity(Entity* e);
    void m_draw_quad(f32 mid_x, f32 mid_y, f32 width, 
        f32 height, const Color& c);
};

#endif