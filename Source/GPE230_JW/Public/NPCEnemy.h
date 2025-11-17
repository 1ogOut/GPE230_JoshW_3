// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPCEnemy.generated.h"

UCLASS()
class GPE230_JW_API ANPCEnemy : public ACharacter
{
	GENERATED_BODY()
	//fuck my stupid fucking life this fucking shit doesnt' fucking work wht is the fuckiung point of making notes if tgher not going to be accurate even to the other fucking notes "Oh yeah use the NPCEnemy.h File that doesn't fucking exist yeah that should work" 

public:
	// Sets default values for this character's properties
	ANPCEnemy();
	UFUNCTION(BlueprintCallable, Category = "Collision")
	void DetectHit();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private: 
	//stats for our enemies punch for DetectHit
	UPROPERTY(EditAnywhere)
	float _TraceRadius = 500.0f;
	UPROPERTY(EditAnywhere)
	FName _PunchingHandSocketName;
	UPROPERTY(EditAnywhere)	
	float _HitDamage; 
};
