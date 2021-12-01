// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlacableActor.generated.h"

UCLASS()
class MYPROJECT_API APlacableActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlacableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "-Misc Settings")
	float Health = 0.0f;

	UFUNCTION(BlueprintCallable)
	void PrintText();

};