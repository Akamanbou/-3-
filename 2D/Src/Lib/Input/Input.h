#pragma once

#define KEY_W (1 << 0)
#define KEY_A (1 << 1)
#define KEY_S (1 << 2)
#define KEY_D (1 << 3)
#define KEY_SPACE (1 << 4)

class Input {
public:
	//入力制御初期化
	static void InitInput();

	//入力制御ステップ
	//StepInputは他のStepより早く呼ぶ
	static void StepInput();

	//今押された
	static bool IsPush(int key_bit);

	//押されている
	static bool IsCont(int key_bit);

	// 今離した
	static bool Release(int key_bit);

private:
	static int pre_key_state;		//前回のキー状態
	static int current_key_state;	//今回のキー状態
};