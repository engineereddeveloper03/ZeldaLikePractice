// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayerInputConfig.generated.h"

class UInputAction;

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
	TObjectPtr<UInputAction> Look;

	/**Movement Input */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> Move;

	/**Jump Input */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> Jump;

	/**Crouch Input */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> Crouch;
};
