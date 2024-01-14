#include "Folder_Interface/Skill.h"

void ISkill::Skill(ESkill _type)
{
	switch (_type)
	{
	case ESkill::NONE:

		break;

	case ESkill::Skill_01:
		Skill_01();
		break;

	case ESkill::Skill_02:
		Skill_02();
		break;
		
	case ESkill::END:
		break;
	default:
		break;
	}
}
