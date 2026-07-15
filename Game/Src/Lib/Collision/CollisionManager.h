#pragma once
#include"Collision.h"
#include"../../Game/Player/Player.h"
#include"../../Game/Field/Field.h"
#include"../../Game/Enemy/EnemyManager.h"

class CollisionManager {
public:
	// プレイヤーとフィールドの当たり判定
	static bool CheckHitPlToField(Player player, int  hndl);

	// プレイヤーの攻撃と敵の当たり判定
	static void CheckHitPlAttackToEnemy(Player& player, EnemyManager& enemy);
	// 敵の攻撃とプレイヤーの当たり判定
	static void CheckHitEnemyAttackToPl(Player& player, EnemyManager& enemy);
	// 敵同士の弾き判定
	static void CheckHitEnemyToEnemyPick(EnemyManager& enemy,Player&player);
};
