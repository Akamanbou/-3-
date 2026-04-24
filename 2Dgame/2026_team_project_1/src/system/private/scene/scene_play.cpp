#include "scene/scene_play.h"
#include "lib/bgm_manager.h"

C_SCENE_PLAY::~C_SCENE_PLAY()
{
	//追加で行う必要のある終了処理を書く
	//各メソッドでポインタの二重解放などへの安全対策をしておくこと
}

void C_SCENE_PLAY::Init()
{
	c_sceneData = C_SCENE_DATA::GetInstance();	//C_SCENE_DATAクラスのインスタンスを取得


	m_playState = START;

	c_playerManager.Init();

	//ここよりも上に処理を書く 

	c_UIManager.Init();

	//フェードインのリクエスト
	C_FADE::RequestFadeIn();

	//全ての処理を終えた後にステータスを更新
	m_sceneState = LOAD;
}

void C_SCENE_PLAY::LoadAnSync()
{
	//リソースの読み込み処理を書く
	c_UIManager.LoadAnSync();
	c_playerManager.LoadAnSync();
}

void C_SCENE_PLAY::LoadSync()
{
	c_UIManager.LoadSync();
	c_playerManager.LoadSync();
}

void C_SCENE_PLAY::LoadWait()
{
	//リソースの読み込み完了を待つ処理を書く
	c_UIManager.StepLoading();
}

void C_SCENE_PLAY::LoadEnd()
{
	//リソースの読み込み完了後の処理を書く

#ifndef DEBUG_MODE

	C_BGM_MANAGER* bgmMgr = C_BGM_MANAGER::GetInstance();

	bgmMgr->Play(C_BGM_MANAGER::BGMID_GAME, DX_PLAYTYPE_LOOP);

#endif

	//ここよりも上に処理を書く

}

void C_SCENE_PLAY::StartWait()
{
	C_FADE::RequestFadeIn();	//フェードインのリクエスト
	m_sceneState = STEP;

}

void C_SCENE_PLAY::Step()
{
	m_loadState = LOAD_OUT;

	//ここよりも下に処理を書く

	c_UIManager.Step();

	c_playerManager.Step();

	//ここよりも上に処理を書く

	//遷移テスト用の処理
	if (C_INPUT::IsInputTrg(KEY_INPUT_X))
	{
		c_sceneData->SetSceneType(C_SCENE_DATA::SELECT);	//次に遷移したいシーンのタイプを代入

		m_sceneState = ENDWAIT;		//ステータスを更新
	}
	else if (C_INPUT::IsInputTrg(KEY_INPUT_Z) || C_XINPUT::GetButtanInputTrg(DX_INPUT_PAD1, XINPUT_BUTTON_A))
	{
		c_sceneData->SetSceneType(C_SCENE_DATA::RESULT);	//次に遷移したいシーンのタイプを代入

		m_sceneState = ENDWAIT;		//ステータスを更新
	}
}

void C_SCENE_PLAY::EndWait()
{
	C_BGM_MANAGER* bgmMgr = C_BGM_MANAGER::GetInstance();
	bgmMgr->Stop(C_BGM_MANAGER::BGMID_GAME);	//BGM停止

	m_sceneState = END;			//ステータスを更新
}

void C_SCENE_PLAY::Exit()
{
	//ここで各インスタンスの終了処理を行う
	c_UIManager.Exit();
	c_playerManager.Exit();
}

void C_SCENE_PLAY::DrawLoading()
{
	c_UIManager.DrawLoading();
}

void C_SCENE_PLAY::DrawPlay()
{
	//ここで描画処理を行う
	c_UIManager.Draw();
	c_playerManager.Draw();
	DrawString(16, 32, "play", GetColor(255, 255, 255));


}
