// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_Basic.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class DUNGEONKIT_API APC_Basic : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputMappingContext> InputMapping;
	
protected:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;
};
