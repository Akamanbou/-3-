#include "DxLib.h"
#include "Input.h"

int Input::pre_key_state = 0;		//前回のキー状態
int Input::current_key_state = 0;	//今回のキー状態

//入力制御初期化
void Input::InitInput()
{
	pre_key_state = 0;
	current_key_state = 0;
}

//入力制御ステップ
void Input::StepInput()
{
	//前回のキー状態を保存
	pre_key_state = current_key_state;

	//今回のキー状態を判定前にfalseに
	current_key_state = 0;

	//必要なキーは以下に判定を書く
	if (CheckHitKey(KEY_INPUT_W) == 1)
		current_key_state |= KEY_W;
	if (CheckHitKey(KEY_INPUT_A) == 1)
		current_key_state |= KEY_A;
	if (CheckHitKey(KEY_INPUT_S) == 1)
		current_key_state |= KEY_S;
	if (CheckHitKey(KEY_INPUT_D) == 1)
		current_key_state |= KEY_D;
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		current_key_state |= KEY_SPACE;

}

//今押された
bool Input::IsPush(int key_bit)
{
	if ((current_key_state & key_bit) && (pre_key_state & key_bit) == false)
		return true;

	return false;
}

//押されている
bool Input::IsCont(int key_bit)
{
	if (current_key_state & key_bit)
		return true;

	return false;
}

// 今離された
bool Input::Release(int key_bit)
{
	if ((pre_key_state & key_bit) && (current_key_state & key_bit) == false)
	{
		return true;
	}
	return false;
}

