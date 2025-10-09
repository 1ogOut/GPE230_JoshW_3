// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGameMode.h"

void AMazeGameMode::InitGameState()
{
	Super::InitGameState();
	
	//if the default pawn is the default unreal pawn change it to what we have selected in our default player value
	if (DefaultPawnClass == ADefaultPawn::StaticClass())
	{
		DefaultPawnClass = DefaultPlayerCharacter;
	}
}