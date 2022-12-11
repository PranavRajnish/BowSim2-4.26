// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::MoveForward(float AxisValue)
{
	if(PlayerMovementState == EPlayerMovementState::Standing || PlayerMovementState == EPlayerMovementState::Crouching || PlayerMovementState == EPlayerMovementState::InAir)
		AddMovementInput(GetActorForwardVector() * AxisValue);
}

void APlayerCharacter::MoveRight(float AxisValue)
{
	if (PlayerMovementState == EPlayerMovementState::Standing || PlayerMovementState == EPlayerMovementState::Crouching || PlayerMovementState == EPlayerMovementState::InAir)
		AddMovementInput(GetActorRightVector() * AxisValue);
}

void APlayerCharacter::PlayerCrouch()
{
}

void APlayerCharacter::SprintPressed()
{
	bSprintKeyDown = true;
	if(PlayerMovementState == EPlayerMovementState::Standing)
		GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
}

void APlayerCharacter::SprintReleased()
{
	bSprintKeyDown = false;
	if(PlayerMovementState == EPlayerMovementState::Standing)
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void APlayerCharacter::SetMovementState(EPlayerMovementState newMovementState)
{
	PlayerMovementState = newMovementState;
	switch (PlayerMovementState)
	{
		case EPlayerMovementState::Standing:
		{
			EndCrouch();
			if (bSprintKeyDown)
				GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
			else
				GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
			break;
		}
		case EPlayerMovementState::Crouching:
		{
			BeginCrouch();
			GetCharacterMovement()->MaxWalkSpeed = MaxCrouchSpeed;
			break;
		}
		case EPlayerMovementState::Sliding:
		{
			BeginCrouch();
			BeginSlide();
		}

	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("MouseLookY"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("MouseLookX"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Pressed, this, &APlayerCharacter::SprintPressed);
	PlayerInputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Released, this, &APlayerCharacter::SprintReleased);
}

