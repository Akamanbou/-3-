#include "game/actor/player/player.h"
#include "lib/input_config.h"

//初期化
void C_PLAYER::Init()
{
	C_ACTOR_BASE::Init();
	m_redius = 20.0f;
	m_isActive = true;
	m_objectType = C_OBJECT_BASE::OBJECT_TYPE_PLAYER;
}

//読込
void C_PLAYER::Load()
{

}

//更新
void C_PLAYER::Step()
{
	m_moveVec = { 0 };

	if (C_INPUT_CONFIG::IsButtanInputRep(C_INPUT_CONFIG::MOVE_LEFT))
	{
		m_moveVec.x -= MOVE_SPEED;
	}
	else if (C_INPUT_CONFIG::IsButtanInputRep(C_INPUT_CONFIG::MOVE_RIGHT))
	{
		m_moveVec.x += MOVE_SPEED;
	}

	m_objectData.pos = VAdd(m_objectData.pos, m_moveVec);
}

//更新確定
void C_PLAYER::Update()
{

}

//描画
void C_PLAYER::Draw()
{
	C_OBJECT_BASE::DrawImage();
}

//終了
void C_PLAYER::Exit()
{
	m_imageHndl = -1;
}

void C_PLAYER::HitCalc()
{

}