#include "Folder_Character/Monster/MonsterWolf.h"

AMonsterWolf::AMonsterWolf()
{
	Tags.Add("Wolf");

	TotalInfo.SetLevel(2);
	TotalInfo.SetMaxHP(50.f);
	TotalInfo.SetHP(50.f);
	TotalInfo.SetMaxMP(10.f);
	TotalInfo.SetMP(10.f);
	TotalInfo.SetPower(5);
	TotalInfo.SetDefence(1);
	TotalInfo.SetSP(5);
}
