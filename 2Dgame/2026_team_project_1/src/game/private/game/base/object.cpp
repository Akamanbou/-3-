#include "game/base/object.h"

void C_OBJECT_BASE::Init()
{
	m_objectData = { 0 };

	m_size = { 0 };		//各方向の大きさ

	m_imageHndl = -1;	//モデルハンドル

	m_instance = C_2D_HNDL_MANAGER::GetInstance();
}

void C_OBJECT_BASE::Request(T_OBJECT_DATA _objectData)
{
	//リクエスト処理
	m_objectData = _objectData;
	m_imageHndl = m_instance->Get2DImageHndl(m_objectData.imagepath.c_str());
}

void C_OBJECT_BASE::DrawImage()
{
	//画像の描画
	DrawRotaGraph(static_cast<int>(m_objectData.pos.x), static_cast<int>(m_objectData.pos.y),
					static_cast<double>(m_objectData.scale), static_cast<double>(m_objectData.rota),
					m_imageHndl, TRUE);
}