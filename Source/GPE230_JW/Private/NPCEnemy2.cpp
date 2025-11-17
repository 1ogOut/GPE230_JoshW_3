// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCEnemy2.h"
//this page is useless and was made because NPCEnemy 1 wouldn't show up. It then crashed unreal and continued to have neither show up for a week before randomly showing up after I changed litterally nothing. 
// Sets default values
ANPCEnemy2::ANPCEnemy2()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPCEnemy2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPCEnemy2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
//oid ANPCEnemy2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
	 //Super::SetupPlayerInputComponent(PlayerInputComponent);

//}

