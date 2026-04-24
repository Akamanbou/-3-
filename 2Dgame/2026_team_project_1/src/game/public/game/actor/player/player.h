#pragma once
#include "game/base/actor.h"

constexpr float MOVE_SPEED = 10.0f;

static const char* PLAYER_IMAGE_PATH[] = { "data/素材一覧/Idle.png",
											"data/素材一覧/Run.png" };

class C_PLAYER : public C_ACTOR_BASE
{
public:

	enum PLAYER_STATE
	{
		IDLE,
		RUN
	};

private:

	PLAYER_STATE m_State;

public:

	//デストラクタ
	~C_PLAYER() {}

	//初期化
	void Init();

	//読込
	void Load();

	//更新
	void Step();

	//更新確定
	void Update();

	//描画
	void Draw();

	//終了
	void Exit();

	//当たり判定処理
	void HitCalc();
};