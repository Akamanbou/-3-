#include "game/manager/enemy_manager.h"
#include "game/collision/collision_manager.h"
#include "effekseer/effekseer.h"
#include"game/actor/enemy/enemy.h"

void C_ENEMY_MANAGER::Init()
{
	c_actorArray.clear();

	m_targetPos = { 0 };

	m_coolTime = 0;
}

void C_ENEMY_MANAGER::LoadAnSync()
{
	C_2D_HNDL_MANAGER* instance = C_2D_HNDL_MANAGER::GetInstance();
	instance->Load2DImage(ENEMY_IMAGE_PATH[0]);
}

void C_ENEMY_MANAGER::LoadSync()
{
	C_2D_HNDL_MANAGER* instance = C_2D_HNDL_MANAGER::GetInstance();

	for (int i = 0;i < 10;i++)
	{
		C_ACTOR_BASE* tmp = new C_ENEMY;
		C_OBJECT_BASE::T_OBJECT_DATA tmpData;
		tmpData.pos = VGet(GetRand(1280), 0.0f, 0.0f);
		tmpData.scale = 0.5f;
		tmpData.rota = 0.0f;
		tmpData.imagepath = ENEMY_IMAGE_PATH[0];
		tmpData.imageNum = instance->Get2DImageAllNum(ENEMY_IMAGE_PATH[0]);
		tmp->Init();
		tmp->Request(tmpData);
		c_actorArray.push_back(tmp);
	}

	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		C_COLLISION_MANAGER::AddObject(*itr);
	}
}

void C_ENEMY_MANAGER::Step()
{
	C_2D_HNDL_MANAGER* instance = C_2D_HNDL_MANAGER::GetInstance();
	C_OBJECT_BASE::T_OBJECT_DATA tmpData;
	m_coolTime++;

	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		if (!(*itr)->GetIsActive() && m_coolTime >= 60)
		{
			tmpData.pos = VGet(GetRand(1280), 0.0f, 0.0f);
			tmpData.scale = 0.5f;
			tmpData.rota = 0.0f;
			tmpData.imagepath = ENEMY_IMAGE_PATH[0];
			tmpData.imageNum = instance->Get2DImageAllNum(ENEMY_IMAGE_PATH[0]);
			(*itr)->SetIsActive(true);
			(*itr)->Request(tmpData);
			m_coolTime = 0;
		}

		(*itr)->Step();
	}
}

void C_ENEMY_MANAGER::Update()
{
	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		if ((*itr)->GetIsActive())(*itr)->Update();
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
		if ((*itr)->GetIsActive())return false;
	}

	return true;
}