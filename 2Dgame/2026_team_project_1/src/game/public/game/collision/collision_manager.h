#pragma once

#include <list>
#include <math.h>

#include "lib/collision.h"

#include "game/base/manager_base.h"

class C_COLLISION_MANAGER
{
private:

	//床との衝突フラグ
	static bool isHitFloor;

	//壁との衝突フラグ
	static bool isHitWall;

	//オブジェクトの判定用プール
	static list<C_OBJECT_BASE*> m_objectPool;

	//プレイヤーとエネミーの当たり判定
	static void PlayerToEnemy(C_OBJECT_BASE* _player, C_OBJECT_BASE* _enemy);

	//プレイヤーとブロックの当たり判定
	static void PlayerToItem(C_OBJECT_BASE* _player, C_OBJECT_BASE* _item);

public:

	//当たり判定処理
	static void CollisionCalc();

	//オブジェクト追加
	static void AddObject(C_OBJECT_BASE* _object) { m_objectPool.push_back(_object); }

	//終了処理
	static void Exit();


};
