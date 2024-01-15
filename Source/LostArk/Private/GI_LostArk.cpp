#include "GI_LostArk.h"


UGI_LostArk::UGI_LostArk()
	: currScene(EScene::NONE)
{
	static ConstructorHelpers::FObjectFinder<UDataTable> JobMeshTable(TEXT("/Game/DataTable/JobMeshTable"));
	if (JobMeshTable.Succeeded())
	{
		JobMesh = JobMeshTable.Object;
	}
}

