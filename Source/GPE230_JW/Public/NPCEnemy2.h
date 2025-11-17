// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//this page is useless and was made because NPCEnemy 1 wouldn't show up. It then crashed unreal and continued to have neither show up for a week before randomly showing up after I changed litterally nothing. 
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPCEnemy2.generated.h"

UCLASS()
class GPE230_JW_API ANPCEnemy2 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCEnemy2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
