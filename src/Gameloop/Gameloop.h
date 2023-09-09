#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "../Base/Base.h"
#include "../Renderer/Renderer.h"
#include "../Scene/Scene.h"
#include "../LogicManager/LogicManager.h"
#include "../PhysicsSolver/PhysicsSolver.h"

void gameloop(Renderer* r, Scene* s, LogicManager* lm, PhysicsSolver* p);

#endif