// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerBox.h"
#include "MyActor.h"
#include "Kismet/KismetMathLibrary.h"

void AMyTriggerBox::BeginPlay()
{
	BoxComponent = Cast<UBoxComponent>(GetCollisionComponent());
}

void AMyTriggerBox::Spawn()
{
	if (CurrentItems < MaxItems)
	{
		FTransform Transform;
		Transform.SetLocation(UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), BoxComponent->GetScaledBoxExtent()));
		GetWorld()->SpawnActor<AActor>(PlacableActor, Transform);
		CurrentItems++;
	}
}

void AMyTriggerBox::StartTimer()
{
	GetWorldTimerManager().SetTimer(Timer, this, &AMyTriggerBox::Spawn, Delay, true);
}