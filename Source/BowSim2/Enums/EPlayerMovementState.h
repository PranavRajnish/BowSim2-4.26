// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EPlayerMovementState.generated.h"

UENUM(BlueprintType)
enum class EPlayerMovementState : uint8
{
	Standing,
	Crouching,
	Sliding,
	InAir
};