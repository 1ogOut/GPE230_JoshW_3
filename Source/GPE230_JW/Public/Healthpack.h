// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Healthpack.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_JW_API AHealthpack : public ATriggerBox
{
	GENERATED_BODY()

	//creates functions for .cpp file
public:
	//used to connect functions to the triggerbox
	AHealthpack();

	//checks actors in overlap
	UFUNCTION()
	void CheckOtherActor(class AActor* OverlappedActor, class AActor* OtherActor);

	//heals the player
	UFUNCTION()
	void HealPlayer();
};
