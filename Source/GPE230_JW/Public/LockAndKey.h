// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "LockAndKey.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_JW_API ALockAndKey : public ATriggerBox
{
	GENERATED_BODY()
	
	//creats the functions for our .cpp file
public:
	//used to connect custum functoins to the triggerbox function
	ALockAndKey();

	//Checks both actors involved in the overlap
	UFUNCTION()
	void CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor);

	//Opens the door when called by destroying the key/door
	UFUNCTION()
	void OpenTheDoor();
};
