// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Arrow.generated.h"

UCLASS()
class BOWSIM2_API AArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CameraVectorZOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector LaunchVelocity;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// TSubclassOf<UCameraComponent> PlayerCamera;
	// UCameraComponent* PlayerCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BowChargeAmount;
	
	
};
