
#include "LogicManager.h"

LogicManager::LogicManager(Scene* s)
{
    
}

LogicManager::~LogicManager()
{
    
}

void LogicManager::frame_update(Scene* s, PhysicsEngine* p)
{
    m_update_entities(s);
}

void LogicManager::m_update_entities(Scene* s)
{
    auto entities = s->get_entities();
    for (u32 i = 0; i < entities->size(); i++)
    {
        entities->at(i)->frame_update(m_get_entities_but_i(s, i));
    }
}

std::vector<Entity*>* LogicManager::m_get_entities_but_i(Scene* s, u32 index)
{
    std::vector<Entity*>* output = new std::vector<Entity*>();
    for (u32 i = 0; i < s->get_entities()->size(); i++)
    {
        if (i == index)
            continue;
        output->push_back(s->get_entities()->at(i));
    }
    return output;
}