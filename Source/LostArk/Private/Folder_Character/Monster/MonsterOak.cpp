#include "Folder_Character/Monster/MonsterOak.h"

AMonsterOak::AMonsterOak()
{
	Tags.Add("Oak");
	Type = EMonster::Oak;

	TotalInfo.SetLevel(5);
	TotalInfo.SetMaxHP(100.f);
	TotalInfo.SetHP(100.f);
	TotalInfo.SetMaxMP(20.f);
	TotalInfo.SetMP(20.f);
	TotalInfo.SetPower(10);
	TotalInfo.SetDefence(3);
	TotalInfo.SetSP(7);

}
