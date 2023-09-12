#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <glfw3.h>

#include "../Base/Base.h"
#include "../Renderer/Renderer.h"
#include "../Scene/Scene.h"
#include "../LogicManager/LogicManager.h"
#include "../Physics/PhysicsEngine.h"
#include "../Entity/Entity.h"
#include "../Entity/PlayerEntity.h"

void gameloop(Renderer* r, Scene* s, LogicManager* lm, PhysicsEngine* p, Entity* player);

#endif