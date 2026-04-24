#include "game/object/field.h"

//初期化
void C_FIELD::Init()
{
	C_OBJECT_BASE::Init();
}

//読込
void C_FIELD::Load()
{
	SetUpCollInfo();
	m_objectType = OBJECT_TYPE_ITEM;
}

//更新
void C_FIELD::Step()
{

}

//更新確定
void C_FIELD::Update()
{
	UpdateModel();
	UpdataCollInfo();
}

//描画
void C_FIELD::Draw()
{
	DrawModel();
}

//終了
void C_FIELD::Exit()
{
	DeleteModel();
	DeleteCollInfo();
}