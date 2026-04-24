#include "game/UI/title_back.h"
#include "lib/2Dhndlmanager.h"


//初期化
void C_TITLE_BACK::Init(VECTOR _pos)
{
	m_pos = _pos;

	m_hndl1 =  0;
}

//読込
void C_TITLE_BACK::LoadAnSync()
{
	C_2D_HNDL_MANAGER* incetans = C_2D_HNDL_MANAGER::GetInstance();
	incetans->Load2DImage(TITLEBACK_IAMGE_PATH);
	m_hndl1 = incetans->Get2DImageHndl(TITLEBACK_IAMGE_PATH);
}

//更新
void C_TITLE_BACK::Step()
{

}

//更新確定処理
void C_TITLE_BACK::Update()
{

}

//描画
void C_TITLE_BACK::Draw()
{
	DrawRotaGraph(m_pos.x, m_pos.y, 1.0f, 0, m_hndl1, TRUE);
}

//終了
void C_TITLE_BACK::Exit()
{
	C_2D_HNDL_MANAGER* incetans = C_2D_HNDL_MANAGER::GetInstance();
	incetans->Delete2DData(TITLEBACK_IAMGE_PATH);
}

void C_TITLE_BACK::SetSize(int _sizeX, int _sizeY)
{

}