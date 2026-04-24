#include "UI/UI_manager.h"

#include "game/UI/load_anim.h"
#include "game/UI/title_back.h"
#include "game/UI/back_ground.h"
#include "game/UI/play_back_ground.h"


//初期化
void C_UI_MANAGER::Init()
{
	c_sceneData = C_SCENE_DATA::GetInstance();

	C_LOAD_ANIM* tmp4 = nullptr;

	C_TITLE_BACK* tmp5 = nullptr;

	C_BACK_GROUND* tmp6 = nullptr;

	C_UI_OBJECT_BASE* tmp = nullptr;

	switch (c_sceneData->GetSceneType())
	{
	case C_SCENE_DATA::SCENE_TYPE::TITLE:

		tmp4 = new C_LOAD_ANIM;
		tmp4->Init(VGet(1180.0f, 700.0f, 0.0f));
		c_UIObject.push_back(tmp4);

		tmp6 = new C_BACK_GROUND;
		tmp6->Init(VGet(WINDOW_CENTER_WIDTH, WINDOW_CENTER_HEIGHT, 0.0f));
		c_UIObject.push_back(tmp6);

		tmp5 = new C_TITLE_BACK;
		tmp5->Init(VGet(WINDOW_CENTER_WIDTH, WINDOW_CENTER_HEIGHT, 0.0f));
		c_UIObject.push_back(tmp5);

		break;

	case C_SCENE_DATA::SCENE_TYPE::SELECT:

		tmp4 = new C_LOAD_ANIM;
		tmp4->Init(VGet(1180.0f, 700.0f, 0.0f));
		c_UIObject.push_back(tmp4);

		tmp6 = new C_BACK_GROUND;
		tmp6->Init(VGet(WINDOW_CENTER_WIDTH, WINDOW_CENTER_HEIGHT, 0.0f));
		c_UIObject.push_back(tmp6);

		break;

	case C_SCENE_DATA::SCENE_TYPE::PLAY:

		tmp4 = new C_LOAD_ANIM;
		tmp4->Init(VGet(1180.0f, 700.0f, 0.0f));
		c_UIObject.push_back(tmp4);

		tmp = new C_PLAY_BACK_GROUND;
		tmp->Init(VGet(WINDOW_CENTER_WIDTH, WINDOW_CENTER_HEIGHT, 0.0f));
		c_UIObject.push_back(tmp);

		break;

	case C_SCENE_DATA::SCENE_TYPE::RESULT:

		tmp4 = new C_LOAD_ANIM;
		tmp4->Init(VGet(1180.0f, 700.0f, 0.0f));
		c_UIObject.push_back(tmp4);

		tmp6 = new C_BACK_GROUND;
		tmp6->Init(VGet(WINDOW_CENTER_WIDTH, WINDOW_CENTER_HEIGHT, 0.0f));
		c_UIObject.push_back(tmp6);

		break;

	case C_SCENE_DATA::SCENE_TYPE::END:

		break;

	}

}

void C_UI_MANAGER::LoadSync()
{
	for (auto itr = c_UIObject.begin(); itr != c_UIObject.end(); ++itr)
	{
		(*itr)->LoadSync();
	}
}

//読込
void C_UI_MANAGER::LoadAnSync()
{
	for (auto itr = c_UIObject.begin(); itr != c_UIObject.end(); ++itr)
	{
		(*itr)->LoadAnSync();
	}
}

void C_UI_MANAGER::StepLoading()
{
	for (auto itr = c_UIObject.begin(); itr != c_UIObject.end(); ++itr)
	{
		(*itr)->StepLoading();
	}
}

void C_UI_MANAGER::Step()
{
	for (auto itr = c_UIObject.begin(); itr != c_UIObject.end(); ++itr)
	{
		(*itr)->Step();
	}
}

//更新確定
void C_UI_MANAGER::Update()
{
	for (auto itr = c_UIObject.begin(); itr != c_UIObject.end(); ++itr)
	{
		(*itr)->Update();
	}
}

void C_UI_MANAGER::DrawLoading()
{
	for (auto itr = c_UIObject.begin(); itr != c_UIObject.end(); ++itr)
	{
		(*itr)->DrawLoading();
	}
}

//描画
void C_UI_MANAGER::Draw()
{
	for (auto itr = c_UIObject.begin(); itr != c_UIObject.end(); ++itr)
	{
		(*itr)->Draw();
	}
}

//終了
void C_UI_MANAGER::Exit()
{
	for (auto itr = c_UIObject.begin(); itr != c_UIObject.end(); ++itr)
	{
		(*itr)->Exit();
		delete (*itr);
	}
}

void C_UI_MANAGER::SelectCalc()
{

}

void C_UI_MANAGER::DrawDebug()
{
	switch (c_sceneData->GetSceneType())
	{
	case C_SCENE_DATA::SCENE_TYPE::TITLE:

		break;

	case C_SCENE_DATA::SCENE_TYPE::SELECT:

		break;

	case C_SCENE_DATA::SCENE_TYPE::PLAY:

		break;

	case C_SCENE_DATA::SCENE_TYPE::RESULT:

		break;

	case C_SCENE_DATA::SCENE_TYPE::END:

		break;

	}

}