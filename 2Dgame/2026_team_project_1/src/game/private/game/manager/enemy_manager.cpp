#include "game/manager/enemy_manager.h"
#include "game/collision/collision_manager.h"
#include "effekseer/effekseer.h"

void C_ENEMY_MANAGER::Init()
{
	c_actorArray.clear();

	m_targetPos = { 0 };
}

void C_ENEMY_MANAGER::LoadAnSync()
{

}

void C_ENEMY_MANAGER::LoadSync()
{
	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		C_COLLISION_MANAGER::AddObject(*itr);
	}
}

void C_ENEMY_MANAGER::Step()
{
	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		(*itr)->Step();
	}
}

void C_ENEMY_MANAGER::Update()
{
	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		if((*itr)->GetIsActive())(*itr)->Update();
	}
}

void C_ENEMY_MANAGER::Draw()
{
	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		if ((*itr)->GetIsActive())(*itr)->Draw();
	}
}

void C_ENEMY_MANAGER::Exit()
{
	MV1DeleteModel(m_modelHndl);

	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		(*itr)->Exit();
		delete (*itr);
	}
	//c_globalData->GetEnemySpawnPointList()->clear();
	c_actorArray.clear();
}

void C_ENEMY_MANAGER::SetTargetPos(VECTOR _targetPos)
{
	m_targetPos = _targetPos;
}

bool C_ENEMY_MANAGER::GetIsEnd()
{
	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		if((*itr)->GetIsActive())return false;
	}

	return true;
}