#include "game/collision/collision_manager.h"
#include "lib/2Dcollosion.h"

bool C_COLLISION_MANAGER::isHitFloor = false;

bool C_COLLISION_MANAGER::isHitWall = false;

list<C_OBJECT_BASE*> C_COLLISION_MANAGER::m_objectPool;

void C_COLLISION_MANAGER::PlayerToEnemy(C_OBJECT_BASE* _player, C_OBJECT_BASE* _enemy)
{
	//生存フラグが折れているなら次の要素へ
	if (!_player->GetIsActive())return;
	if (!_enemy->GetIsActive())return;

	//当たり判定
	if (C_2D_COLLOSION::CheckHitCircleToCircle2D(_player->GetPos(), _enemy->GetPos(),
		_player->GetRedius(), _enemy->GetRedius()))
	{

	}
}

void C_COLLISION_MANAGER::PlayerToItem(C_OBJECT_BASE* _player, C_OBJECT_BASE* _item)
{
	//生存フラグが折れているなら次の要素へ
	if (!_player->GetIsActive())return;
	if (!_item->GetIsActive())return;

	if (C_2D_COLLOSION::CheckHitCircleToCircle2D(_player->GetPos(), _item->GetPos(),
		_player->GetRedius(), _item->GetRedius()))
	{

	}
}

//当たり判定処理
void C_COLLISION_MANAGER::CollisionCalc()
{
	//関数ポインタを作成
	void (*Calc[])(C_OBJECT_BASE*, C_OBJECT_BASE*) = { C_COLLISION_MANAGER::PlayerToEnemy, C_COLLISION_MANAGER::PlayerToItem };

	int funkIndex = 0;

	//マネージャー1の配列の要素数だけforループを回す
	for (auto itr1 = m_objectPool.begin(); itr1 != m_objectPool.end(); ++itr1)
	{
		//マネージャー2の配列の要素数だけforループを回す
		for (auto itr2 = m_objectPool.begin(); itr2 != m_objectPool.end(); ++itr2)
		{
			//同じ要素同士なら次の要素へ
			if ((*itr1) == (*itr2))continue;

			//どのタイプのオブジェクトが参照されているか
			if ((*itr1)->GetObjectType() == C_OBJECT_BASE::OBJECT_TYPE_PLAYER &&
				(*itr2)->GetObjectType() == C_OBJECT_BASE::OBJECT_TYPE_ENEMY)
			{
				funkIndex = 0;
			}
			else if ((*itr1)->GetObjectType() == C_OBJECT_BASE::OBJECT_TYPE_PLAYER &&
				(*itr2)->GetObjectType() == C_OBJECT_BASE::OBJECT_TYPE_ITEM)
			{
				funkIndex = 1;
			}
			else
			{
				continue;
			}

			//コールバック関数
			Calc[funkIndex]((*itr1), (*itr2));

			//参照した要素の生存フラグが折れているならリストから削除する
			if (!(*itr2)->GetIsActive())
			{
				m_objectPool.erase(itr2);
			}
		}

		//参照した要素の生存フラグが折れているならリストから削除する
		if (!(*itr1)->GetIsActive())
		{
			m_objectPool.erase(itr1);
		}
	}
}

void C_COLLISION_MANAGER::Exit()
{
	m_objectPool.clear();
}