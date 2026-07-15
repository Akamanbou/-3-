#pragma once
#include<iostream>
#include<DxLib.h>
#include"../../Game/Common.h"

// 基底クラス
class Object {
protected:
	VECTOR m_Pos;			// 座標
	VECTOR m_Rot;			// 回転角度
	VECTOR m_Speed;			// 速度
	VECTOR m_Scale;			// モデルのスケール
	bool m_isActive;		// 生存フラグ
	bool m_isHitGround;		// 地面との当たり判定
	float m_Radius;			// 半径
	int m_Hndl;				// 生存フラグ

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
	// 更新処理
	virtual void Update();

	// モデルデータのロード
	bool LoadModel(const char* filePath);
	// モデルデータのコピーのロード
	bool DuplicateModel(int originHndl);

	// 当たり判定の座標系
	VECTOR GetCenter();

	// 生存情報取得・設定
	bool IsActive()const { return m_isActive; }
	void SetActive(bool active) { m_isActive = active; }

	// 当たり判定の半径サイズを取得
	float GetRadius()const { return m_Radius; }

	// 座標の取得・設定
	VECTOR GetPosition() { return m_Pos; }
	void SetPosition(VECTOR pos) { m_Pos = pos; }

	// 回転角度を取得・設定
	VECTOR GetRotation()const { return m_Rot; }
	void SetRotation(VECTOR rot) { m_Rot = rot; }

	// 地面と当たり判定を取得・設定
	bool GetHitGround()const { return m_isHitGround; }
	void SetHitGround(bool hit) { m_isHitGround = hit; }
};