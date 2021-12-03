// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Engine/Engine.h"
// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = 100.0f;
	LearpDuration = 3.f;
	LearpTime = 0.f;
	Growth = 1.1f;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static_Mesh");
	RootComponent = StaticMesh;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(0.1f, 0.1f, 0.1f));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Grow(DeltaTime);
}

void AMyActor::Grow(float DeltaSeconds)
{
	float LearpAlpha = LearpTime / LearpDuration;
	LearpAlpha *= LearpAlpha;
	if (LearpTime < LearpDuration)
	{
		SetActorScale3D(FMath::Lerp(FVector(0.1f, 0.1f, 0.1f), FVector::OneVector, LearpAlpha));
		LearpTime += Growth * DeltaSeconds;
	}
	else
	{
		Destroy();
	}
}

void AMyActor::PrintText()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor(1, 0, 0), TEXT("Debug message"));
}

