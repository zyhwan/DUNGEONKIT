// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Basic.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
APlayer_Basic::APlayer_Basic()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayer_Basic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayer_Basic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayer_Basic::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* UIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (UIC)
	{
		UIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APlayer_Basic::Move);
		UIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &APlayer_Basic::Look);
	}


}

void APlayer_Basic::Move(const FInputActionValue& Value)
{
	FVector2D Direction = Value.Get<FVector2D>();

	FRotator CameraRotation = GetControlRotation();
	FRotator NewCameraRotation = FRotator(0.f, CameraRotation.Yaw, 0.f);

	FVector CameraForward = UKismetMathLibrary::GetForwardVector(NewCameraRotation);
	FVector CameraRight = UKismetMathLibrary::GetRightVector(NewCameraRotation);

	AddMovementInput(CameraForward * Direction.X);
	AddMovementInput(CameraRight * Direction.Y);

}

void APlayer_Basic::Look(const FInputActionValue& Value)
{
	FVector2D Direction = Value.Get<FVector2D>();

	AddControllerYawInput(Direction.X);
	AddControllerPitchInput(-Direction.Y);

}

