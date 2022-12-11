// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "E_PlayerMovementStatus.generated.h"

UENUM()
enum E_PlayerMovementStatus
{
	Standing,
	Crouching,
	Sliding,
	InAir
};
