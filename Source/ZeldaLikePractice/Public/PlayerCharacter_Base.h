// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character_Base.h"
#include "InputActionValue.h"
#include "PlayerCharacter_Base.generated.h"

class AZeldaLikePlayerController;
class UInputComponent;
class UInputMappingContext;
class UPlayerInputConfig;

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

private:
	UPROPERTY()
	TObjectPtr<AZeldaLikePlayerController> PlayerController;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

#pragma region Input Actions
	/**Mapping Context */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	/**Input Action Data Structure */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPlayerInputConfig> InputActions;

	UFUNCTION()
	void LookAction(const FInputActionValue& Value);

	UFUNCTION()
	void MoveAction(const FInputActionValue& Value);

	UFUNCTION()
	void JumpAction(const FInputActionValue& Value);

	UFUNCTION()
	void CrouchAction(const FInputActionValue& Value);

#pragma endregion
};
