// Fill out your copyright notice in the Description page of Project Settings.


#include "PC_Basic.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"


void APC_Basic::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	if (IsLocalPlayerController())
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

		if (Subsystem)
		{
			Subsystem->ClearAllMappings();
			Subsystem->AddMappingContext(InputMapping.LoadSynchronous(), 0);
		}
	}

}

void APC_Basic::OnUnPossess()
{
	Super::OnUnPossess();

	if (IsLocalPlayerController())
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

		if (Subsystem)
		{
			Subsystem->ClearAllMappings();
		}
	}

}
