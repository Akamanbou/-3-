#include "game/base/actor.h"

void C_ACTOR_BASE::Init()
{
	C_OBJECT_BASE::Init();

	//アニメーションの再生時間
	m_animPlayTime = 0;

	//アニメーションの総再生時間
	m_animAllPlayTime = 0;

	//アニメーションの再生速度
	m_animPlaySpeed = 1;

	//生存フラグ
	m_isActive = true;

}

void C_ACTOR_BASE::DeathCalc()
{
	m_isActive = false;
}

void C_ACTOR_BASE::AttachAnim(const char* _imageFilePath)
{
	//ひとつ前のアニメーションと同じであれば再生しない
	if (strcmp(m_prveAnimImagePath.c_str(), _imageFilePath))return;

	//現在のアニメーションに更新
	m_prveAnimImagePath = _imageFilePath;

	//アニメーションの再生時間を初期化
	m_animPlayTime = 0.0f;

	//アニメーションの総再生時間を取得　
	m_animAllPlayTime = m_instance->Get2DImageAllNum(m_prveAnimImagePath.c_str());

	//アニメーションのハンドルを変更
	m_imageHndl = m_instance->Get2DImageHndl(m_prveAnimImagePath.c_str(), m_animPlayTime);
}

void C_ACTOR_BASE::DettuchAnim()
{
	//ハンドルをリセット
	m_imageHndl = -1;
}

void C_ACTOR_BASE::UppdateAnim()
{
	//アニメーションの再生時間を更新
	m_animPlayTime += m_animPlaySpeed;

	//ハンドルを更新
	m_imageHndl = m_instance->Get2DImageHndl(m_prveAnimImagePath.c_str(), m_animPlayTime);
}

void C_ACTOR_BASE::LoopAnim()
{
	//再生時間が総再生時間を超えているか
	if (m_animPlayTime >= m_animAllPlayTime)
	{
		//アニメーションの再生時間を初期化
		m_animPlayTime = 0.0f;

		//ハンドルを更新
		m_imageHndl = m_instance->Get2DImageHndl(m_prveAnimImagePath.c_str(), static_cast<int>(m_animPlayTime));

	}
}

void C_ACTOR_BASE::EndAnim()
{
	//再生時間が総再生時間を超えているか
	if (m_animPlayTime >= m_animAllPlayTime)
	{
		//アニメーションの再生時間を初期化
		m_animPlayTime = 0.0f;

		//ハンドルをリセット
		DettuchAnim();
	}
}