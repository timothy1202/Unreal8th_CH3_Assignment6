// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnManager.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();
	SpawnPlatforms();
}

// Called every frame
void ASpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnManager::SpawnPlatforms()
{
	int32 SpawnCount = 5; 
	for (int32 i = 0; i < SpawnCount; i++)
	{
		//월드 원점 기준 (0,0,0)
		FVector SpawnLocation = FVector
		(
			FMath::RandRange(-1000.0f, 1000.0f),
			FMath::RandRange(-1000.0f, 1000.0f),
			FMath::RandRange(100.0f, 500.0f)
		);

		FRotator SpawnRotation = FRotator::ZeroRotator;
		FActorSpawnParameters SpawnParams;

		AMovingItem* SpawnedItem = GetWorld()->SpawnActor<AMovingItem>(
			MovingItemClass,
			SpawnLocation,
			SpawnRotation,
			SpawnParams
		);
		
		
		AItem* SpawnedItem2 = GetWorld()->SpawnActor<AItem>(
			ItemClass,
			SpawnLocation,
			FRotator::ZeroRotator
		);

		// 랜덤 속성 부여
		if (SpawnedItem)
		{
			SpawnedItem->MoveSpeed = FMath::RandRange(50.0f, 300.0f);
			SpawnedItem->MaxRange = FMath::RandRange(200.0f, 800.0f);
		}
	}
	
}