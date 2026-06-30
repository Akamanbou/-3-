#include"SceneManager.h"

//-----------------------------------
// コンストラクタ
//-----------------------------------
SceneManager::SceneManager()
{
	m_SceneID = INIT;
	CInput::InitInput();
	CGamePad::InitGamePad();
	CGamePad::GetPadNumState();
	SoundManager::Init();
	SoundManager::Load();
	CFade::InitFade();
}

SceneManager::~SceneManager()
{
	SoundManager::Exit();
}

//-----------------------------------
// 毎フレーム呼ぶ処理
//-----------------------------------
int SceneManager::Loop()
{
	// ゲームが終了したかを外部に伝えるため
	int Result = -1;

	// キーマウとコントローラーのステップ
	CInput::StepInput();
	CGamePad::StepGamePad();

	// ここでシーンを管理する
	switch (m_SceneID)
	{
	case SceneManager::INIT:
		m_SceneID = TITLE;
		break;
		// タイトル
	case SceneManager::TITLE:
		if (m_Title.Loop() == 0)
			m_SceneID = GAME;
		break;
		// メインゲーム
	case SceneManager::GAME:
	{
		// ローカル変数に入れる
		int Play = m_Play.Loop();

		// ０だったらリザルトに行く
		if (Play == 0)
		{
			m_SceneID = RESULT;
		}
		// １だったらタイトルに行く
		if (Play == 1)
		{
			if (CFade::IsEndFadeOut())
				m_SceneID = TITLE;
		}
		// 2だったら終了
		if (Play == 2)
		{
			return 0;
		}

		break;
	}
	// リザルト
	case SceneManager::RESULT:
		m_Result.Loop();
		// 左クリックをするか、Bボタンを押したらInitへ進む
		if (CInput::IsPush(MOUSE_LEFT) || CGamePad::IsPadPush(DX_INPUT_PAD1, BUTTON_B))
			m_SceneID = INIT;
		break;
	}
	CFade::StepFade();
	// 本編が終了したかどうかを外部に伝える
	return Result;
}

//-----------------------------------
// 描画処理
//-----------------------------------
void SceneManager::Draw()
{
	// それぞれのシーンで描画するもの
	switch (m_SceneID)
	{
	case SceneManager::INIT:
		break;
	case SceneManager::TITLE:
		m_Title.Draw();
		break;
	case SceneManager::GAME:
		m_Play.Draw();
		break;
	case SceneManager::RESULT:
		m_Result.Draw();
		break;
	}
	CFade::DrawFade();
}
