#pragma once

#include "effekseer/effekseer.h"

#include "object.h"

class C_ACTOR_BASE : public C_OBJECT_BASE
{
protected:

	//アニメーションの再生時間
	float m_animPlayTime;

	//アニメーションの総再生時間
	float m_animAllPlayTime;

	//アニメーションの再生速度
	float m_animPlaySpeed;

	//前回再生していたアニメーション
	string m_prveAnimImagePath;

	//リスポーンフラグ
	bool m_isRespawn;

	//死亡処理
	void DeathCalc();

	//アニメーションのアタッチ
	void AttachAnim(const char* _imageFilePath);

	//アニメーションのデタッチ
	void DettuchAnim();

	//アニメーションの更新処理
	void UppdateAnim();

	//アニメーションのループ処理
	void LoopAnim();

	//アニメーションの終了処理
	void EndAnim();

	//ノックバック処理
	virtual void KnockBackCalc() {}

public:

	//コンストラクタ
	C_ACTOR_BASE(float _animPlayTime = 0.0f, float _animAllPlayTime = 0.0f,
		float _animPlaySpeed = 0.0f, VECTOR _targetPos = { 0 }, VECTOR _modelRot = { 0 },
		bool _isActive = false) :
		m_animPlayTime(_animPlayTime), m_animAllPlayTime(_animAllPlayTime),
		m_animPlaySpeed(_animPlaySpeed), m_prveAnimImagePath(),
		m_isRespawn(false) {}

	//デストラクタ
	virtual ~C_ACTOR_BASE() {}

	//初期化
	virtual void Init();

	//読込
	virtual void Load() = 0;

	//更新
	virtual void Step() = 0;

	//更新確定
	virtual void Update() = 0;

	//描画
	virtual void Draw() = 0;

	//終了
	virtual void Exit() = 0;


};

