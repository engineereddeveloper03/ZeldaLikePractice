// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputAction.h"
#include "PlayerInputConfig.generated.h"


/**
 * 
 */
UCLASS()
class ZELDALIKEPRACTICE_API UPlayerInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	/**Camera Input */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* Look;

	/**Movement Input */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* Move;

	/**Jump Input */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* Jump;

	/**Crouch Input */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* Crouch;
};
