// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character_Base.h"
#include "PlayerCharacter_Base.generated.h"

/**
 * 
 */
UCLASS()
class ZELDALIKEPRACTICE_API APlayerCharacter_Base : public ACharacter_Base
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
