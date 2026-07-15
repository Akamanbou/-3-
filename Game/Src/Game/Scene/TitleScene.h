#pragma once
#include<DxLib.h>
#include"../Common.h"
#include"../../Lib/Input/Input.h"
#include"../../Lib/Input/PadInput.h"
#include"../../Lib/Fade/Fade.h"

static const char TITLE_IMAGE[] = { "../Data/Image/Title.png" };
static const char TITLE_SELECT[] = { "../Data/Image/Select.png" };


class TitleScene
{
private:
	enum tagScene {
		INIT,
		LOAD,
		START_WAIT,
		MAIN,
		END_WAIT,
		END,

		TITLE_SCENE_NUM
	};

	tagScene m_State; // 現在の状態遷移
	int m_Hndl;
	int m_SelectHndl;
	int m_Select;
	VECTOR m_SelectPos;

public:
	// コンストラクタ・デストラクタ
	TitleScene();
	~TitleScene();


	// 繰り返し行う処理
	int Loop();
	// 描画処理
	void Draw();

private:
	// 初期化
	void Init(void);
	// 終了処理
	void Exit();
	// データロード
	void Load();
	// 毎フレーム呼ぶ処理
	int Step();

	void Select();
};