#pragma once
#include "game/base/manager_base.h"



class C_MAP_MANAGER : public C_OBJECT_MANAGER_BASE
{
public:

	enum SELECT_STAGE {
		SELECT_STAGE_1,
		SELECT_STAGE_2,
		SELECT_STAGE_3,
		SELECT_STAGE_MAX,
	};

private:

public:

	//初期化
	void Init();

	//リソース読込
	void LoadAnSync();	

	//読込
	void LoadSync();

	//更新
	void Step();

	//更新確定
	void Update();

	//描画
	void Draw();

	//終了
	void Exit();
};
