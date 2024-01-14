// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


class LOSTARK_API ResourceMgr
{
public:
	static ResourceMgr* GetInst()
	{
		static ResourceMgr ResMgr;
		return &ResMgr;
	}

	ResourceMgr();
	~ResourceMgr();
};