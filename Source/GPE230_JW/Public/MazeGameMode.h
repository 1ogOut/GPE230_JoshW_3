// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MazeCharacter.h"
#include "GameFramework/DefaultPawn.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MazeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_JW_API AMazeGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void InitGameState() override;

private: 
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<AMazeCharacter> DefaultPlayerCharacter = AMazeCharacter::StaticClass();
};
