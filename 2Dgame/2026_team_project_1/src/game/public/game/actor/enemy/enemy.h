#pragma once
#include "game/base/actor.h"

constexpr float MOVE_SPEED = 10.0f;

static const char* ENEMY_IMAGE_PATH[] = { "data/graphic/kuti.png" };

class C_ENEMY : public C_ACTOR_BASE
{
public:

	enum ENEMY_STATE
	{
		IDLE,
		RUN
	};

private:

	ENEMY_STATE m_State;

public:

	//デストラクタ
	~C_ENEMY() {}

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