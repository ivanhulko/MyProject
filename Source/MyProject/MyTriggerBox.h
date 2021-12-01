// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Components/BoxComponent.h"
#include "MyTriggerBox.generated.h"

/**
 * 
 */
class AMyActor;

UCLASS()
class MYPROJECT_API AMyTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

	UPROPERTY()
	UBoxComponent* BoxComponent;

	FTimerHandle Timer;

	UPROPERTY(EditAnywhere)
	float Delay = 3.f;

	UFUNCTION()
	void Spawn();

	UPROPERTY(EditAnywhere)
	TSubclassOf<AMyActor> PlacableActor;

	UPROPERTY(EditAnywhere)
	int MaxItems = 3;

	int CurrentItems;

public:
	void StartTimer();
	
protected:
	virtual void BeginPlay() override;
};
