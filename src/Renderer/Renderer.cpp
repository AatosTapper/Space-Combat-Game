
#include "Renderer.h"

Renderer::Renderer()
{
    offset = std::make_unique<Base::Vec2<f32>>(0.0f, 0.0f);
}

Renderer::~Renderer()
{
    
}

GLFWwindow* Renderer::get_window()
{
    return m_window;
}

void Renderer::set_screen(u32 width, u32 height)
{
    m_SW = width;
    m_SH = height;
    offset->x = (width / 2.0f);
    offset->y = (height / 2.0f);
}

void Renderer::setup()
{
    if (!glfwInit())
    {
        std::cout << "Error: glfw didn't initialize\n";
        return;
    }
    m_window = glfwCreateWindow(m_SW, m_SH, "Window", NULL, NULL);
    if (!m_window)
    {
        glfwTerminate();
        std::cout << "Error: window didn't open\n";
        return;
    }
    glfwMakeContextCurrent(m_window);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, m_SW, m_SH, 0, -10, 10);
}

void Renderer::clean()
{
    glfwTerminate();
}

void Renderer::draw_frame(Scene* s)
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (auto e : *s->get_entities())
        m_draw_entity(e);

    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void Renderer::m_draw_entity(Entity* e)
{
    if (e == nullptr)
        return;
    //m_draw_quad(e->body->pos->x,
    //            e->body->pos->y,
    //            e->body->radius->x,
    //            e->body->radius->y,
    //            *e->color);
    m_draw_circle(Base::Vec2<f32>(*&e->body->pos->x, *&e->body->pos->y), 
                e->body->radius,
                *e->color, e->angle);
}

void Renderer::m_draw_quad(f32 midX, f32 midY, f32 width, 
    f32 height, const Color& c)
{
    glColor3f(c.r, c.g, c.b);
    glBegin(GL_QUADS);
    glVertex2f(midX - width / 2.0f + offset->x, midY - height / 2.0f + offset->y);
    glVertex2f(midX - width / 2.0f + offset->x, midY + height / 2.0f + offset->y);
    glVertex2f(midX + width / 2.0f + offset->x, midY + height / 2.0f + offset->y);
    glVertex2f(midX + width / 2.0f + offset->x, midY - height / 2.0f + offset->y);
    glEnd();
}

void Renderer::m_draw_tri(Base::Vec2<f32> a, Base::Vec2<f32> b, Base::Vec2<f32> c, Color col)
{
    glColor3f(col.r, col.g, col.b);
    glBegin(GL_TRIANGLES);
    glVertex2f(a.x + offset->x, a.y + offset->y);
    glVertex2f(b.x + offset->x, b.y + offset->y);
    glVertex2f(c.x + offset->x, c.y + offset->y);
    glEnd();
}

void Renderer::m_draw_circle(const Base::Vec2<f32>& mid_pos, f32 radius, Color col, f32 angle)
{
    const u32 res = 28u;
    const f32 step = PI2 / (f32)res;
    for (u32 i = 0; i < res; i++)
    {
        Color c = col;
        f32 angle_multiplier = 1.0f;

        if (angle != -1)
        {
            if ((step * i) <= angle && (step * (i + 1) > angle))
            {
                c = Color(0.9f, 0.3f, 0.04f);
                angle_multiplier = 1.5f;
            }
        }

        const f32 x_off_1 = cos(step * i) * radius * angle_multiplier;
        const f32 y_off_1 = sin(step * i) * radius * angle_multiplier;
        const f32 x_off_2 = cos(step * (i + 1)) * radius * angle_multiplier;
        const f32 y_off_2 = sin(step * (i + 1)) * radius * angle_multiplier;
        m_draw_tri(mid_pos, Base::Vec2<f32>(x_off_1 + mid_pos.x, y_off_1 + mid_pos.y), 
                            Base::Vec2<f32>(x_off_2 + mid_pos.x, y_off_2 + mid_pos.y), c);
    }
}