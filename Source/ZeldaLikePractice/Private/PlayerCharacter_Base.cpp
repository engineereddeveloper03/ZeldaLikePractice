// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter_Base.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "PlayerInputConfig.h"

// Sets default values
APlayerCharacter_Base::APlayerCharacter_Base()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter_Base::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerCharacter_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Save out player controller.  Set here because this calls before BeginPlay
	PlayerController = Cast<AZeldaLikePlayerController>(GetController());

	// Map input context to this player character
	if (PlayerController)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());

		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(defaultMappingContext, 0);
	}

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (Input)
	{
		Input->BindAction(InputActions->Look, ETriggerEvent::Triggered, this, &APlayerCharacter_Base::LookAction);
		//Input->BindAction(InputActions->Move, ETriggerEvent::Triggered, this, &APlayerCharacter_Base::MoveAction);
		//Input->BindAction(InputActions->Jump, ETriggerEvent::Triggered, this, &APlayerCharacter_Base::JumpAction);
		//Input->BindAction(InputActions->Crouch, ETriggerEvent::Triggered, this, &APlayerCharacter_Base::CrouchAction);
	}
	
}

void APlayerCharacter_Base::LookAction(const FInputActionValue& Value)
{

}

void APlayerCharacter_Base::MoveAction(const FInputActionValue& Value)
{

}

void APlayerCharacter_Base::JumpAction(const FInputActionValue& Value)
{

}

void APlayerCharacter_Base::CrouchAction(const FInputActionValue& Value)
{

}
