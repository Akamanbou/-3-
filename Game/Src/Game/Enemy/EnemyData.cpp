#include"EnemyData.h"

const vector<EnemyData>& EnemyData::GetEnemyData()
{
	// CSVƒtƒ@ƒCƒ‹‚ð“ü‚ê‚é
	int hndl = FileRead_open(ENEMY_CSV);

	// ‚O‚ð“ü‚ê‚Ä‚¢‚­
	ReadData tmp = { 0 };

	// ‚O‚É‚È‚é‚Ü‚Å‰ñ‚è‘±‚¯‚é
	while (FileRead_scanf(hndl, "%d,%f,%f,%f,%d,%d,%d", &tmp.m_Type, &tmp.m_Pos.x, &tmp.m_Pos.y, &tmp.m_Pos.z,
		&tmp.m_Hp, &tmp.m_Power, &tmp.m_Exp) != EOF) 
	{
		EnemyBase* temp = nullptr;

		switch (tmp.m_Type)
		{
		case 0:
			temp = new Enemy(); 
			break;
		}
		temp->SetHp(tmp.m_Hp);
		temp->SetPower(tmp.m_Power);
		temp->SetExp(tmp.m_Exp);
	}
}