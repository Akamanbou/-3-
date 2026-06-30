#include"Menu.h"

Menu::Menu()
{
	Init();
}

Menu::~Menu()
{
	Exit();
}

void Menu::Init()
{
	m_Pos = ZERO;
	m_Scere = ZERO;

	m_Hndl = -1;
	m_RightHndl = -1;
	m_Select = 0;
}

void Menu::Exit()
{
	if (m_Hndl != -1)
	{
		m_Hndl = DeleteGraph(m_Hndl);
	}

	if (m_RightHndl != -1)
	{
		m_RightHndl = DeleteGraph(m_RightHndl);
	}
}

void Menu::Load()
{
	if (m_Hndl == -1)
	{
		m_Hndl = LoadGraph(MENU_IMAGE_PATH);
	}
	if (m_RightHndl == -1)
	{
		m_RightHndl = LoadGraph(MENU_RIGHT_PATH);
	}
}

int Menu::Step()
{
	Select();
	if (CInput::IsPush(KEY_W))
	{
		if (m_Select != 0)
		{
			m_Select--;
		}
		else
			m_Select = 2;
	}
	if (CInput::IsPush(KEY_S))
	{
		if (m_Select != 2)
		{
			m_Select++;
		}
		else
			m_Select = 0;
	}
	if (CInput::IsPush(KEY_SPACE))
		return m_Select;
	else return -1;
}

void Menu::Draw()
{
	DrawRotaGraph(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2, 1.0f, 0.0f, m_Hndl, TRUE);
	DrawRotaGraph(m_Pos.x, m_Pos.y, 0.5f, 0.0f, m_RightHndl, TRUE);
}

void Menu::Select()
{
	if (m_Select == 0)
	{
		m_Pos = { WINDOW_SIZE_X / 2 - 270,370.0f,0.0f };
	}
	if (m_Select == 1)
	{
		m_Pos = { WINDOW_SIZE_X / 2 - 270,480.0f,0.0f };
	}
	if (m_Select == 2)
	{
		m_Pos = { WINDOW_SIZE_X / 2 - 270,590.0f,0.0f };
	}
}