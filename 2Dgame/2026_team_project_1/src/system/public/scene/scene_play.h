#pragma once

#include "scene.h"
#include "game/manager/player_manager.h"


class C_SCENE_PLAY: public C_SCENE_BASE
{
private:

	enum PLAY_STATE
	{
		START,
		PLAYWAIT,
		PLAY,
		RESPAWN,
		GOAL,
		FADE,
	};

	PLAY_STATE m_playState;

	C_PLAYER_MANAGER c_playerManager;

private:

	//初期化処理
	void Init();

	//非同期読込処理
	void LoadAnSync();

	//同期読込処理
	void LoadSync();

	//読込待機処理
	void LoadWait();

	//読込完了処理
	void LoadEnd();

	//更新前待機処理
	void StartWait();

	//更新処理
	void Step();

	//読み込み中描画処理
	void DrawLoading();

	//プレイ中描画処理
	void DrawPlay();

	//終了前待機処理
	void EndWait();

public:

	~C_SCENE_PLAY() override;	//デストラクタ

	void Exit();
};