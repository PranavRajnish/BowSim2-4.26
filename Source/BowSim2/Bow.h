// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bow.generated.h"

//class AArrow;

UCLASS()
class BOWSIM2_API ABow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// UFUNCTION(BlueprintCallable)
	// void AttachArrow(AArrow arrow);

protected:
	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// TSubclassOf<AArrow> arrow;
	// AArrow* arrow;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ChargeAmount = 0.0;

};
