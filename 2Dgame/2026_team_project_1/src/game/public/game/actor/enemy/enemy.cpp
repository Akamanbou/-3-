#include "game/actor/enemy/enemy.h"
#include "lib/input_config.h"

//初期化
void C_ENEMY::Init()
{
	C_ACTOR_BASE::Init();
	m_isActive = false;
	m_redius = 20.0f;
	m_objectType = C_OBJECT_BASE::OBJECT_TYPE_ENEMY;
}

//読込
void C_ENEMY::Load()
{

}

//更新
void C_ENEMY::Step()
{
	m_moveVec = { 0 };

	m_moveVec.y += 2.0f;

	m_objectData.pos = VAdd(m_objectData.pos, m_moveVec);

	if (m_objectData.pos.y >= WINDOW_HEIGHT)m_isActive = false;
}

//更新確定
void C_ENEMY::Update()
{

}

//描画
void C_ENEMY::Draw()
{
	C_OBJECT_BASE::DrawImage();
}

//終了
void C_ENEMY::Exit()
{
	m_imageHndl = -1;
}

void C_ENEMY::HitCalc()
{

}