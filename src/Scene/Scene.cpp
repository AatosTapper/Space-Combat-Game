
#include "Scene.h"

Scene::Scene()
{
    m_entities = new std::vector<Entity*>();
}

Scene::~Scene()
{
    m_free_entities();
    Base::safe_free(m_entities);
}

std::vector<Entity*>* Scene::get_entities()
{
    return m_entities;
}

void Scene::add_entity(Entity* e)
{
    if (e == nullptr)
        return;
    m_entities->push_back(e);
}

void Scene::m_free_entities()
{
    for (auto e : *m_entities)
        Base::safe_free(e);
}