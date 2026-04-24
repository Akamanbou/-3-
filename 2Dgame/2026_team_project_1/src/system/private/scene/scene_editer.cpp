#include "scene/scene_editer.h"

C_SCENE_EDITER::~C_SCENE_EDITER()
{
	//追加で行う必要のある終了処理を書く
	//各メソッドでポインタの二重解放などへの安全対策をしておくこと
}

void C_SCENE_EDITER::Init()
{
	c_sceneData = C_SCENE_DATA::GetInstance();	//C_SCENE_DATAクラスのインスタンスを取得

	//ここよりも上に処理を書く

	//フェードインのリクエスト
	C_FADE::RequestFadeIn();

	//全ての処理を終えた後にステータスを更新
	m_sceneState = LOAD;
}

void C_SCENE_EDITER::LoadAnSync()
{
	//非同期読み込み処理を書く

}

void C_SCENE_EDITER::LoadSync()
{
}

void C_SCENE_EDITER::LoadWait()
{
	//リソースの読み込み完了を待つ処理を書く
}

void C_SCENE_EDITER::LoadEnd()
{
	//リソースの読み込み完了後の処理を書く

	//ここよりも上に処理を書く
}

void C_SCENE_EDITER::StartWait()
{
	C_FADE::RequestFadeIn();	//フェードインのリクエスト
	m_sceneState = STEP;
}

void C_SCENE_EDITER::Step()
{
	//読み込み状態を変更
	m_loadState = LOAD_OUT;

	//ここよりも下に処理を書く

	//ここよりも上に処理を書く

	//遷移テスト用の処理
	if (C_INPUT::IsInputTrg(KEY_INPUT_Z) || C_XINPUT::GetButtanInputTrg(DX_INPUT_PAD1, XINPUT_BUTTON_B))
	{
		c_sceneData->SetSceneType(C_SCENE_DATA::END);	//次に遷移したいシーンのタイプを代入

		m_sceneState = ENDWAIT;		//ステータスを更新
	}
	else if (C_INPUT::IsInputTrg(KEY_INPUT_X) || C_XINPUT::GetButtanInputTrg(DX_INPUT_PAD1, XINPUT_BUTTON_A))
	{
		c_sceneData->SetSceneType(C_SCENE_DATA::TITLE);	//次に遷移したいシーンのタイプを代入

		m_sceneState = ENDWAIT;		//ステータスを更新
	}
}

void C_SCENE_EDITER::EndWait()
{
	C_FADE::RequestFadeOut();	//フェードアウトのリクエスト

	m_sceneState = END;			//ステータスを更新
}

void C_SCENE_EDITER::Exit()
{

	//ここで各インスタンスの終了処理を行う
}

void C_SCENE_EDITER::DrawLoading()
{

}

void C_SCENE_EDITER::DrawPlay()
{

}