#include "game/UI/back_ground.h"
#include "lib/2Dhndlmanager.h"


//初期化
void C_BACK_GROUND::Init(VECTOR _pos)
{
	m_pos = _pos;

	m_hndl1 = 0;
}

//読込
void C_BACK_GROUND::LoadAnSync()
{
	C_2D_HNDL_MANAGER* incetans = C_2D_HNDL_MANAGER::GetInstance();
	incetans->Load2DImage(BACKGROUND_IMAGE_PATH);
	m_hndl1 = incetans->Get2DImageHndl(BACKGROUND_IMAGE_PATH);
}

//更新
void C_BACK_GROUND::Step()
{

}

//更新確定処理
void C_BACK_GROUND::Update()
{

}

//描画
void C_BACK_GROUND::Draw()
{
	DrawRotaGraph(m_pos.x, m_pos.y, 1.0f, 0.0f, m_hndl1, TRUE);
}

//終了
void C_BACK_GROUND::Exit()
{
	C_2D_HNDL_MANAGER* incetans = C_2D_HNDL_MANAGER::GetInstance();
	incetans->Delete2DData(BACKGROUND_IMAGE_PATH);
}

void C_BACK_GROUND::SetSize(int _sizeX, int _sizeY)
{

}