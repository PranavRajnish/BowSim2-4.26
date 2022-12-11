// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enums/EPlayerMovementState.h"

#include "PlayerCharacter.generated.h"

UCLASS()
class BOWSIM2_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void PlayerCrouch();
	void SprintPressed();
	void SprintReleased();

	UFUNCTION(BlueprintCallable)
	void SetMovementState(EPlayerMovementState newMovementState);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void BeginCrouch();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void EndCrouch();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void BeginSlide();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EPlayerMovementState PlayerMovementState = EPlayerMovementState::Standing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float WalkSpeed = 600;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float RunSpeed = 1000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxCrouchSpeed = 400;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	bool bSprintKeyDown = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	bool bCrouchKeyDown = false;

};
