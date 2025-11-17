// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MazeCharacter.generated.h"

UCLASS()
class GPE230_JW_API AMazeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMazeCharacter();

	//Our max hp, public so it can be changed in editor
	UPROPERTY(EditAnywhere)
	float maxHealth;
	//sets our movespeed and rotation speed, public so it can be changed in editor because it would be an easier way to test speeds
	UPROPERTY(EditAnywhere)
	float _moveSpeed;
	UPROPERTY(EditAnywhere)
	float _rotationSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//current health, not public so it doesn't clutter things
	float _currentHealth;

	//damage items
	//take damage function (overides AActor::TakeDamage) [might have to add "Class" infront of AController if there are issues] [might have to add struct infront of FDamageEvent if there are issues]
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	//die function 
	virtual void Die();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//adds the functions for Moving the player/camera
private:
	void MoveFB(float axisValue);
	void MoveLR(float axisValue);
	void Rotate(float axisValue);
	void Jump() override;

	//variables for our death animation
	UPROPERTY(EditAnywhere)
	UAnimSequence* _deathAnim;
	//is the player dead
		//death boolean
	bool _dead = false;
};
