// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCEnemy.h"
//added to let us use a sphere trace and apply damage
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"

// Sets default values
ANPCEnemy::ANPCEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ANPCEnemy::DetectHit()
{
	//allows the npc to deal damage, without it theres a possibility of the hit applying over and over with 1 hit causing the player to take 100000 damage from 1 hit 
	bool canDamage = true;

	//get the location of the punching hand socket
	const FVector PunchLocation = GetMesh()->GetSocketLocation(_PunchingHandSocketName);

	//Dont detect ourself or the controller in the sphere trace to stop our npc from hitting itself
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	ActorsToIgnore.Add(GetOwner());

	//array for actors hit by the sphere trace 
	TArray<FHitResult> HitArray;

	//sphere trace around fist for overlaped actors. If it hits one it's true, if not its false. 

	const bool Hit = UKismetSystemLibrary::SphereTraceMulti(GetWorld(), PunchLocation, PunchLocation, _TraceRadius, UEngineTypes::ConvertToTraceType(ECC_Camera), false, ActorsToIgnore, EDrawDebugTrace::None, HitArray, true, FLinearColor::Red, FLinearColor:: Green, 2.0f);

	//name of the actor for debugging
	FString ownerName = this->GetName();

	// the code for actually hitting people
	//if there is a hit
	if (Hit)
	{
		//for each object that was hit, find them by looking at the array of hit results
		for (const FHitResult HitResult : HitArray)
		{
			//if the npc is allowed to damage
			if (canDamage)
			{
				//gets the name of the actor hit for debugging  and prints it in the output log
				FString hitActorName = HitResult.GetActor()->GetName();
				UE_LOG(LogTemp, Log, TEXT("NPCEnemy actor \"%s\" hit other actor \"%s\""), *ownerName, *hitActorName);

				//applys damage to the hit actor 
				UGameplayStatics::ApplyDamage(HitResult.GetActor(), _HitDamage, GetController(), this, UDamageType::StaticClass());
				//sets can damage to false so we dont apply damage multiple times in one punch
				canDamage = false;
			}	
		}
	}
	//if the hit misses
	else
	{
		UE_LOG(LogTemp, Log, TEXT("NPCEnemy actor \"%s\" missed!"), *ownerName);
	}
}

// Called when the game starts or when spawned
void ANPCEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPCEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ANPCEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

