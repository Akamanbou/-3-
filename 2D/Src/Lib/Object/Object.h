#pragma once
#include<iostream>
#include<DxLib.h>

// 基底クラス
class Object {
protected:
	VECTOR m_Pos;			// 座標
	int m_Hndl;				// 生存フラグ
	bool m_isActive;		// 生存フラグ

public:
	// コンストラクタ・デストラクタ
	Object();
	virtual ~Object();

	// 初期化
	virtual void Init();
	// 終了時のデータ破棄など
	virtual void Exit();
	// 描画処理
	virtual void Draw();


	// 生存情報取得・設定
	bool IsActive() { return m_isActive; }
	void SetActive(bool active) { m_isActive = active; }
	// 当たり判定の半径サイズを取得

		// 座標の取得・設定
	VECTOR GetPosition() { return m_Pos; }
	void SetPosition(VECTOR pos) { m_Pos = pos; }

};