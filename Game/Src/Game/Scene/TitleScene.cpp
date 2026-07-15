#include"TitleScene.h"

//-----------------------------------
// コンストラクタ
//-----------------------------------
TitleScene::TitleScene()
{
	m_State = INIT;
}

//-----------------------------------
// デストラクタ
//-----------------------------------
TitleScene::~TitleScene()
{
	Exit();
}

//-----------------------------------
// 毎フレーム呼ぶ処理
//-----------------------------------
int TitleScene::Loop()
{
	// ゲームが終了したかを外部に伝えるため
	int Result = -1;

	switch (m_State)
	{
	case TitleScene::INIT:
		Init();
		m_State = LOAD; // 次へ進む
		break;
	case TitleScene::LOAD:
		Load();
		m_State = START_WAIT; // 次へ進む
		break;
	case TitleScene::START_WAIT:
		if (CFade::IsEndFadeIn())
		{
			m_State = MAIN;
		}
		else
			break;
	case TitleScene::MAIN:
		Step();
		// 左クリックをするか、Bボタンを押したらゲームへ進む
		if (CInput::IsPush(MOUSE_LEFT) || CGamePad::IsPadPush(DX_INPUT_PAD1, BUTTON_B))
		{
			CFade::RequestFadeOut();
			m_State = END_WAIT;
		}
		else
			break;
	case TitleScene::END_WAIT:
		if (CFade::IsEndFadeOut())
		{
			m_State = END;
		}
		break;
	case TitleScene::END:
		Exit();
		m_State = INIT; //次へ進む
		Result = 0;
		break;
	default:
		break;
	}

	// 本編が終了したかどうかを外部に伝える
	return Result;
}

//-----------------------------------
// 描画処理
//-----------------------------------
void TitleScene::Draw()
{
	DrawRotaGraph(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2, 1.0f, 0.0f, m_Hndl, true);

	DrawRotaGraph(m_SelectPos.x, m_SelectPos.y, 1.0f, 0.0f, m_SelectHndl, true);
}

//-----------------------------------
// 初期化
//-----------------------------------
void TitleScene::Init()
{
	m_Hndl = -1;
	m_SelectHndl = -1;
	m_Select = 0;
	m_SelectPos = { WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2 ,0.0f };
}

//-----------------------------------
// データロード
//-----------------------------------
void TitleScene::Load()
{
	if (m_Hndl == -1)
		m_Hndl = LoadGraph(TITLE_IMAGE);
	if (m_SelectHndl == -1)
		m_SelectHndl = LoadGraph(TITLE_SELECT);
	CFade::RequestFadeIn();
}

//-----------------------------------
// 毎フレーム呼ぶ処理
//-----------------------------------
int TitleScene::Step()
{
	Select();
	if (CInput::IsPush(KEY_W))
	{
		if (m_Select != 0)
		{
			m_Select--;
		}
		else
			m_Select = 2;
	}
	if (CInput::IsPush(KEY_S))
	{
		if (m_Select != 2)
		{
			m_Select++;
		}
		else
			m_Select = 0;
	}
	if (CInput::IsPush(KEY_SPACE))
		return m_Select;
	else return -1;
}

//-----------------------------------
// 終了処理
//-----------------------------------
void TitleScene::Exit()
{
}

void TitleScene::Select()
{
	if (m_Select == 0)
	{
		m_SelectPos = { m_SelectPos.x,360.0f,0.0f };
	}
	if (m_Select == 1)
	{
		m_SelectPos = { m_SelectPos.x,465.0f,0.0f };
	}
	if (m_Select == 2)
	{
		m_SelectPos = { m_SelectPos.x,570.0f,0.0f };
	}
}