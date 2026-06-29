#pragma once
#include<DxLib.h>
#include"../Common.h"
#include"../../Lib/Input/Input.h"

static const char MENU_IMAGE_PATH[] = "../Data/Image/Menu.png";
static const char MENU_RIGHT_PATH[] = "../Data/Image/Right.png";

class Menu
{
private:
	VECTOR m_Pos;
	VECTOR m_Scere;

	int m_Hndl;
	int m_RightHndl;
	int m_Select;

	void Select();

public:
	Menu();
	~Menu();

	void Init();
	void Exit();
	void Load();
	int Step();
	void Draw();
};