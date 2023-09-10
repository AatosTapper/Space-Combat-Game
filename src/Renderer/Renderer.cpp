
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
    m_draw_quad(e->body->pos->x,
                e->body->pos->y,
                e->body->size->x,
                e->body->size->y,
                *e->color);
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