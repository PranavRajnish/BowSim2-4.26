// Fill out your copyright notice in the Description page of Project Settings.


#include "Arrow.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AArrow::AArrow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	//PlayerCamera = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->getcam
}

// Called when the game starts or when spawned
void AArrow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

