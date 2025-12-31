// Fill out your copyright notice in the Description page of Project Settings.


#include "Healthpack.h"
#include "MazeCharacter.h"

AHealthpack::AHealthpack()
{
	//when overlap begins starts checkotheractor function
	OnActorBeginOverlap.AddDynamic(this, &AHealthpack::CheckOtherActor);
}

void AHealthpack::CheckOtherActor(AActor* OverlappedActor, AActor* OtherActor)
{
	//checks if the other actor is maze character, if it is, run the function to heal them and destroy this. 
	if (OtherActor->IsA(AMazeCharacter::StaticClass()))
	{
		HealPlayer();
	}
}

void AHealthpack::HealPlayer()
{
	this->Destroy();
}
