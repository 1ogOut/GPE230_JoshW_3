// Fill out your copyright notice in the Description page of Project Settings.


#include "K2Node_InputAxisKeyEvent.h"
#include "MazeCharacter.h"

// Sets default values
AMazeCharacter::AMazeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMazeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMazeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMazeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//sets up the player inputs then binds the axis to the functions we created for moving the player/camera
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveFB", this, &AMazeCharacter::MoveFB);
	PlayerInputComponent->BindAxis("MoveLR", this, &AMazeCharacter::MoveLR);
	PlayerInputComponent->BindAxis("Rotate", this, &AMazeCharacter::Rotate);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
}

//Creates a movement input that pushes our character forward by taking the value from our playerinput and adding it to our moveSpeed, this is the same for MoveLR and Rotate just with different ve
void AMazeCharacter::MoveFB(float axisValue)
{
	AddMovementInput(GetActorForwardVector(), axisValue);
}

void AMazeCharacter::MoveLR(float axisValue)
{
	AddMovementInput(-GetActorRightVector(), axisValue);
}

void AMazeCharacter::Rotate(float axisValue)
{
	AddControllerYawInput(axisValue);
}

void AMazeCharacter::Jump()
{
	Super::Jump();
}

