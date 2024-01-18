#include "Folder_Interface/Skill.h"


void ISkill::Skill(ESkill _type)
{
	switch (_type)
	{
	case ESkill::Base:
		Skill_Base();
		break;

	case ESkill::Skill_Q:
		Skill_Q();
		break;

	case ESkill::Skill_W:
		Skill_W();
		break;
		
	case ESkill::END:
		break;
	}


}
