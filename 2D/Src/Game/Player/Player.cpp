#include"Player.h"

// コンストラクタ
Player::Player()
{
	Init();
}

// デストラクタ
Player::~Player()
{
	Exit();
}

// 初期化
void Player::Init()
{
}

// モデルデータのロード
void Player::Load()
{
	// ロードされていなければする
	if (m_Hndl = -1)
	{
		m_Hndl = LoadDivGraph(PLAYER_PATH,12,12,1,32,32,m_Hndl);
	}
}

// プレイヤーの動き
void Player::Step()
{

}

// 描画
void Player::Draw()
{
}

// ヒット後の処理
void Player::HitCale()
{
}