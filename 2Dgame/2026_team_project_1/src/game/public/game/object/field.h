#pragma once

#include "game/base/object.h"

class C_FIELD : public C_OBJECT_BASE 
{
private:

public:

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

	//
	void HitCalc(){}
};