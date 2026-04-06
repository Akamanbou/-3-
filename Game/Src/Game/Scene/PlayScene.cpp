#include"PlayScene.h"

//-----------------------------------
// コンストラクタ
//-----------------------------------
PlayScene::PlayScene()
{
	m_State = INIT;
}

//-----------------------------------
// デストラクタ
//-----------------------------------
PlayScene::~PlayScene()
{
	Exit();
}

//-----------------------------------
// 毎フレーム呼ぶ処理
//-----------------------------------
int PlayScene::Loop()
{
	// ゲームが終了したかを外部に伝えるため
	int Result = -1;

	switch (m_State)
	{
	case PlayScene::INIT:
		Init();
		m_State = LOAD; // 次へ進む
		break;
	case PlayScene::LOAD:
		Load();
		m_State = MAIN; // 次へ進む
		break;
	case PlayScene::MAIN:
		Step();
		break;
	case PlayScene::END:
		Exit();
		m_State = INIT; // 次へ進む
		Result = 0;
		break;
	case PlayScene::PLAY_SCENE_NUM:
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
void PlayScene::Draw()
{
	m_Player.Draw();
}

//-----------------------------------
// 初期化
//-----------------------------------
void PlayScene::Init()
{
	m_Player.Init();
	m_Camera.Init();
}

//-----------------------------------
// データロード
//-----------------------------------
void PlayScene::Load()
{
	m_Player.Load();
}

//-----------------------------------
// 毎フレーム呼ぶ処理
//-----------------------------------
void PlayScene::Step()
{
	m_Player.Step(m_Camera);
	m_Camera.Step(m_Player.GetCenter(), m_Player.GetRotation().y);

	// 更新処理
	m_Player.Update();
	m_Camera.Updata();
}

//-----------------------------------
// 終了処理
//-----------------------------------
void PlayScene::Exit()
{
	m_Player.Exit();
}