// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "../DungeonTypes.h"
#include "GM_Basic.generated.h"


/**
 * 
 */
UCLASS()
class DUNGEONKIT_API AGM_Basic : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;


};
