#include"Object.h"

// コンストラクタ
Object::Object()
{
	Init();
}

// デストラクタ
Object::~Object()
{
	Exit();
}

// 初期化
void Object::Init()
{
	m_Pos = { 0.0f,0.0f,0.0f };
	m_Hndl = -1;
	m_isActive = false;
}

// 描画処理
void Object::Draw()
{
	if (m_isActive)
		DrawRotaGraph(m_Pos.x, m_Pos.y, 1.0f, 0.0f, m_Hndl, TRUE);
}

// 終了時の破棄
void Object::Exit()
{
	if (m_Hndl != -1)
	{
		m_Hndl = -1;
		DeleteGraph(m_Hndl);
	}
}