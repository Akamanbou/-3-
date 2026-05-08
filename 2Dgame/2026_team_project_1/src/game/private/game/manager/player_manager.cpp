#include "game/manager/player_manager.h"
#include "game/collision/collision_manager.h"
#include "lib/2Dhndlmanager.h"
#include "game/actor/player/player.h"

void C_PLAYER_MANAGER::Init()
{
	//listの初期化
	c_actorArray.clear();

	//ターゲットのインデックスの初期化
	m_targetPosListIndex = 0;
}

void C_PLAYER_MANAGER::LoadAnSync()
{
	C_2D_HNDL_MANAGER* instance = C_2D_HNDL_MANAGER::GetInstance();
	instance->Load2DImage(PLAYER_IMAGE_PATH[0], 1,1, 1, 16, 16);
}

void C_PLAYER_MANAGER::LoadSync()
{
	C_2D_HNDL_MANAGER* instance = C_2D_HNDL_MANAGER::GetInstance();

	C_ACTOR_BASE* tmp = new C_PLAYER;
	C_OBJECT_BASE::T_OBJECT_DATA tmpData;
	tmpData.pos = VGet(WINDOW_CENTER_WIDTH, 700.0f, 0.0f);
	tmpData.scale = 2.0f;
	tmpData.rota = 0.0f;
	tmpData.imagepath = PLAYER_IMAGE_PATH[0];
	tmpData.imageNum = instance->Get2DImageAllNum(PLAYER_IMAGE_PATH[0]);
	tmp->Init();
	tmp->Request(tmpData);
	c_actorArray.push_back(tmp);

	//プレイヤーの初期化
	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		(*itr)->Load();
		C_COLLISION_MANAGER::AddObject(*itr);
	}
}

void C_PLAYER_MANAGER::Step()
{
	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		(*itr)->Step();
	}
}

void C_PLAYER_MANAGER::Step(VECTOR _camRota)
{
	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		(*itr)->Step();
	}
}

void C_PLAYER_MANAGER::Update()
{
	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		(*itr)->Update();
	}

}

void C_PLAYER_MANAGER::Draw()
{
	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		(*itr)->Draw();
	}
}

void C_PLAYER_MANAGER::DebugDraw()
{
	/*DrawFormatString(10, 40, GetColor(0, 0, 0), "Rot:%f", m_debugRot);*/
}

void C_PLAYER_MANAGER::Exit()
{
	//モデルの破棄　
	MV1DeleteModel(m_modelHndl);

	for (auto itr = c_actorArray.begin(); itr != c_actorArray.end(); ++itr)
	{
		(*itr)->Exit();
		delete (*itr);
	}

	c_actorArray.clear();
}

void C_PLAYER_MANAGER::ReflectCollision(VECTOR addVec)
{
	auto itr = c_actorArray.begin();
	if (addVec.x == 0.0f && addVec.y == 0.0f && addVec.z == 0.0f) return;

	VECTOR	pos = (*itr)->GetPos();
	pos = VAdd(pos, addVec);
}

void C_PLAYER_MANAGER::HitCalc()
{

}

