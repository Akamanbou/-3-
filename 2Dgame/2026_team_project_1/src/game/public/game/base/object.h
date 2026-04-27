#pragma once
#include "common.h"
#include "lib/2Dhndlmanager.h"

using namespace std;

class C_OBJECT_BASE
{
public:

	//オブジェクトのタイプ
	enum OBJECT_TYPE
	{
		OBJECT_TYPE_PLAYER,
		OBJECT_TYPE_ENEMY,
		OBJECT_TYPE_ITEM,
	};

	typedef struct
	{
		VECTOR pos;
		float scale;
		float rota;
		int imageNum;
		string imagepath;
	}T_OBJECT_DATA;

protected:

	T_OBJECT_DATA m_objectData;

	C_2D_HNDL_MANAGER* m_instance;

	//各方向の大きさ
	VECTOR m_size;

	//移動ベクトル
	VECTOR m_moveVec;

	//押し戻し速度
	VECTOR m_knockBackSpeed;

	//
	OBJECT_TYPE m_objectType;

	//当たり判定の半径
	int m_redius;

	//3Dモデルのハンドル
	int m_imageHndl;

	//エフェクトのハンドル
	int m_effHndl;

	//当たり判定待機時間
	int m_hitWait;

	//攻撃待機時間
	float m_attackWait;

	//生存フラグ
	bool m_isActive;

	void DrawImage();

public:

	//コンストラクタ
	C_OBJECT_BASE(T_OBJECT_DATA _objectData = {0}, VECTOR _size = VGet(1.0f, 1.0f, 1.0f),
		VECTOR _moveVec = VGet(0.0f, 0.0f, 0.0f), VECTOR _knockBackSpeed = VGet(0.0f, 0.0f, 0.0f),
		OBJECT_TYPE _objectType = OBJECT_TYPE_PLAYER, int _redius = 0,
		int _imageHndl = -1, int _effHndl = -1, int _hitWait = 0, float _attackWait = 0.0f) :
		m_objectData(_objectData), m_size(_size), m_moveVec(_moveVec),
		m_knockBackSpeed(_knockBackSpeed), m_objectType(_objectType), m_redius(_redius),
		m_imageHndl(_imageHndl), m_effHndl(_effHndl),
		m_hitWait(_hitWait), m_attackWait(_attackWait), m_isActive(true), m_instance(nullptr){ }

	//デストラクタ
	virtual ~C_OBJECT_BASE() {}

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

	//座標加算
	virtual void AddPos(VECTOR _addPos) { m_objectData.pos = VAdd(m_objectData.pos, _addPos); }

	//リクエスト
	virtual void Request(T_OBJECT_DATA _objectData);

	//座標を取得
	inline VECTOR GetPos() const { return m_objectData.pos; }

	//回転を取得
	inline float GetRota() const { return m_objectData.rota; }

	//拡大率を取得
	inline float GetScale() const { return m_objectData.scale; }

	inline int GetRedius() const { return static_cast<int>(m_redius); }

	inline VECTOR GetMoveVec() const { return m_moveVec; }

	//攻撃判定の座標取得
	inline virtual VECTOR GetAttackPos() const
	{
		VECTOR tmp = VGet(0.0f, 0.0f, static_cast<float>(m_redius));
		MATRIX	mat1, mat2;
		mat1 = MGetTranslate(tmp);
		mat2 = MGetRotY(m_objectData.rota);
		mat1 = MMult(mat1, mat2);
		tmp = VGet(-mat1.m[3][0], mat1.m[3][1], -mat1.m[3][2]);

		return VAdd(m_objectData.pos, tmp);
	}

	//当たり判定処理
	virtual void HitCalc() = 0;

	//壁との当たり判定
	virtual void HitCalcWall(){}

	//天井との当たり判定
	virtual void HitCalcCeiling(){}

	//オブジェクトのタイプを取得
	inline OBJECT_TYPE GetObjectType() const { return m_objectType; }

	//ノックバック速度を設定
	virtual void SetKonckBackSpeed(VECTOR _knockBackSpeed)
	{
		m_knockBackSpeed = _knockBackSpeed;
	}

	inline bool GetIsActive() const { return m_isActive; }

	inline void SetIsActive(bool _isActive) { m_isActive = _isActive; }
};