#include "Folder_Interface/Skill.h"

void ISkill::Skill(ESkill _type)
{
	switch (_type)
	{
	case ESkill::BaseAttack:
		BaseAttack();
		break;

	case ESkill::DoubleAttack:	
		DoubleAttack();
		break;
		
	case ESkill::END:
		break;
	default:
		break;
	}
}
