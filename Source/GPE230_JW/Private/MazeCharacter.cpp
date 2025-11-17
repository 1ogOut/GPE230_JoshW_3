// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeCharacter.h"
#include "K2Node_InputAxisKeyEvent.h"

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
	//sets our current health to our max health and dead to false
	_currentHealth = maxHealth;
}

//called for taking damage
float AMazeCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	//disables taking damage if were dead
	if (_dead == false)
	{
		//subtract incoming damage from current health
		_currentHealth -= DamageAmount;
		//print current health to the output log for testing
		UE_LOG(LogTemp, Log, TEXT("Player took %f damage. %f health remaining."), DamageAmount, _currentHealth);
		//if player is below 0 die
		if (_currentHealth <= 0)
		{
			Die();
		}
		//since were overiding Unreals TakeDamage function we have to return it to make sure everything stays in order even though were probably not using it
		return DamageAmount;
	}
	//if no damage can be applied take 0 damage
	else
		return 0;
}
//called for dying
void AMazeCharacter::Die()
{
	//stops us from moving and taking damage (modifying the movespeed/rotationspeed doesn't work for ???, but this works pretty well actually) 
	_dead = true;
	//plays death animation
	GetMesh()->PlayAnimation(_deathAnim, false);
	//ToDo: Add game over and all that stuff
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

//movement functions, if our character is dead these shouldn't work
	void AMazeCharacter::MoveFB(float axisValue)
	{
		if (_dead == false)
		{
			AddMovementInput(GetActorForwardVector(), _moveSpeed * axisValue);
		}
	}

	void AMazeCharacter::MoveLR(float axisValue)
	{
		if (_dead == false)
		{
			AddMovementInput(-GetActorRightVector(), _moveSpeed * axisValue);
		}
	}

	void AMazeCharacter::Rotate(float axisValue)
	{
		if (_dead == false)
		{
			AddControllerYawInput(axisValue * _rotationSpeed);
		}
	}

	void AMazeCharacter::Jump()
	{
		if (_dead == false)
		{
			Super::Jump();
		}
	}