#pragma once

#include "scene.h"

class C_SCENE_RESULT : public C_SCENE_BASE
{
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

	~C_SCENE_RESULT() override;	//デストラクタ

	void Exit();
};
