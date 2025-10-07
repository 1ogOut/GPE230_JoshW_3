// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeCharacter.h"
#include "LockAndKey.h"

ALockAndKey::ALockAndKey()
{
	//When overlap begins, it starts our CheckActorType Function
	OnActorBeginOverlap.AddDynamic(this, &ALockAndKey::CheckActorType);
}

void ALockAndKey::CheckActorType(AActor* OverlappedActor, AActor* OtherActor)
{
	//checks if other character is maze character, if it is run function OpenTheDoor
	if (OtherActor->IsA(AMazeCharacter::StaticClass()))
	{
		OpenTheDoor();
	}
}

//when called upon destroys this and all its children.
void ALockAndKey::OpenTheDoor()
{
	this->Destroy();
}
