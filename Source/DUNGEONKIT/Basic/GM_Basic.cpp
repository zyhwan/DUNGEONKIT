// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_Basic.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/DataTable.h"



void AGM_Basic::BeginPlay()
{
	Super::BeginPlay();

	static ConstructorHelpers::FObjectFinder<UDataTable> DungeonDataTable(
		TEXT("/Script/Engine.DataTable'/Game/Data/DataTable/DungeonData/DT_Dungeon_Data.DT_Dungeon_Data'"));

	if (DungeonDataTable.Succeeded())
	{
		DT_DungeonData = DungeonDataTable.Object;
	}

	SetCachedDungeonData();
	SetTotalWeight();

}

void AGM_Basic::SetCachedDungeonData()
{


	if (!DT_DungeonData)
	{
		return;
	}

	DungeonDataCaches.Empty();

	TArray<FName> RowNames = DT_DungeonData->GetRowNames();

	for (const auto& RowName : RowNames)
	{
		FDungeonData* Row = DT_DungeonData->FindRow<FDungeonData>(RowName, TEXT("SetCachedDungeonData"));
		if (Row)
		{
			DungeonDataCaches.Add(*Row);
		}
	}
}

void AGM_Basic::SetTotalWeight()
{
	TotalWeight = 0.f;

	for (const FDungeonData& Data : DungeonDataCaches)
	{
		TotalWeight += Data.Weight;
	}
}
