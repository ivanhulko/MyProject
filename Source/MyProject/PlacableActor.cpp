// Fill out your copyright notice in the Description page of Project Settings.


#include "PlacableActor.h"

// Sets default values
APlacableActor::APlacableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = 100.0f;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static_Mesh");
	RootComponent = StaticMesh;
}

// Called when the game starts or when spawned
void APlacableActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlacableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlacableActor::PrintText()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor(1, 0, 0), TEXT("Debug message"));
}
