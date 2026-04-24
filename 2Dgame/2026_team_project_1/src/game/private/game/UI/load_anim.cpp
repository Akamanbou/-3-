#include "game/UI/load_anim.h"
#include "lib/2Dhndlmanager.h"
#include "game/base/UI_object.h"

const char* LOAD_ANIM_PATH = "data/素材一覧/MainCharacterIdle/MaskDude.Idelpng";

//初期化
void C_LOAD_ANIM::Init(VECTOR _pos)
{

	m_pos = _pos;

	m_index = 0;
}

//
void C_LOAD_ANIM::LoadSync()
{
	C_2D_HNDL_MANAGER* incetans = C_2D_HNDL_MANAGER::GetInstance();
	incetans->Load2DImage(LOAD_ANIM_PATH, LOADA_ANIM_MAX, 4, 2, 32, 32);
	for (int i = 0; i < LOADA_ANIM_MAX; i++)
	{
		m_hndl[i] = incetans->Get2DImageHndl(LOAD_ANIM_PATH, i);
	}

}

//読込
void C_LOAD_ANIM::LoadAnSync()
{

}

void C_LOAD_ANIM::StepLoading()
{
	m_index++;
	if (m_index >= LOADA_ANIM_MAX)m_index = 0;
}

//更新
void C_LOAD_ANIM::Step()
{

}

//更新確定処理
void C_LOAD_ANIM::Update()
{

}

void C_LOAD_ANIM::DrawLoading()
{
	DrawRotaGraph(m_pos.x, m_pos.y, 5.0f, 0.0f, m_hndl[m_index], TRUE);
}

//描画
void C_LOAD_ANIM::Draw()
{

}

//終了
void C_LOAD_ANIM::Exit()
{
	C_2D_HNDL_MANAGER* incetans = C_2D_HNDL_MANAGER::GetInstance();
	incetans->Delete2DData(LOAD_ANIM_PATH);
}

void C_LOAD_ANIM::SetSize(int _sizeX, int _sizeY)
{

}