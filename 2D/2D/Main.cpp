#include <crtdbg.h>
#include <memory>
#include "DxLib.h"
#include <math.h>


// プログラムは WinMain から始まります
int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{

	// メモリリーク発見用
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// スクリーン設定
	ChangeWindowMode(TRUE);			// フルスクリーンorウィンドウモード
	SetGraphMode(1280, 720, 32);	// ウィンドウのサイズ

#ifndef _DEBUG
	// リリース版はログを出さない
	SetOutApplicationLogValidFlag(false);
#endif

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;


	//一番最初に１回だけやる処理
	SetDrawScreen(DX_SCREEN_BACK);


	// 背景の初期化
	VECTOR vGroundPos{ 0.0f,0.0f,0.0f };

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		//エスケープキーが押されたら終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;


		ClearDrawScreen();	// 画面クリア


		ScreenFlip();		// 描画切り替え

	}

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}