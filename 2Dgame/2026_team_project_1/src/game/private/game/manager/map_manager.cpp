#include "game/manager/map_manager.h"
#include "game/collision/collision_manager.h"


void C_MAP_MANAGER::Init()
{
	c_objectArray.clear();
}

void C_MAP_MANAGER::LoadAnSync()
{

}

void C_MAP_MANAGER::LoadSync()
{
	for (auto itr = c_objectArray.begin(); itr != c_objectArray.end(); ++itr)
	{
		C_COLLISION_MANAGER::AddObject(*itr);
	}
}

void C_MAP_MANAGER::Step()
{
	for (auto itr = c_objectArray.begin(); itr != c_objectArray.end(); ++itr)
	{
		(*itr)->Step();
	}
}

void C_MAP_MANAGER::Update()
{
	for (auto itr = c_objectArray.begin(); itr != c_objectArray.end(); ++itr)
	{
		(*itr)->Update();
	}
}

void C_MAP_MANAGER::Draw()
{
	for (auto itr = c_objectArray.begin(); itr != c_objectArray.end(); ++itr)
	{
		(*itr)->Draw();
	}
}

void C_MAP_MANAGER::Exit()
{
	for (auto itr = c_objectArray.begin(); itr != c_objectArray.end(); ++itr)
	{
		(*itr)->Exit();
		delete (*itr);
	}

	c_objectArray.clear();
}