#pragma once
#include<DxLib.h>
#include<math.h>
#include"../../Lib/Object/Object.h"
#include"../../Lib/input/Input.h"

// プレイヤーのモデルのパス
static const char PLAYER_PATH[] = "../Data/Pink Man/Run (32x32) ";


class Player : public Object {
private:

public:
	// コンストラクタ・デストラクタ
	Player();
	~Player();

	// 初期化
	void Init();
	// モデルデータのロード
	void Load();
	// 全行動を処理する
	void Step();
	// 描画処理
	void Draw();
	// ヒット後の処理
	void HitCale();
};