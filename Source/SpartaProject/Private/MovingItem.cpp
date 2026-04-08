#include "MovingItem.h"


AMovingItem::AMovingItem()
{
 	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	
	PrimaryActorTick.bCanEverTick = true;
	MoveSpeed = 100.0f;
	MaxRange = 500.0f;
	bMovingForward = true;
}


void AMovingItem::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	
	GetWorld()->GetTimerManager().SetTimer(
		DisappearTimerHandle, this, 
		&AMovingItem::DisappearActor, 
		5.0f, false);
	
}

void AMovingItem::Tick(float DeltaTime)

{
	Super::Tick(DeltaTime);
	
	FVector CurrentLocation = GetActorLocation();
	float DistanceFromStart = (CurrentLocation - StartLocation).Size();

	if (bMovingForward)
	{
		FVector TargetLocation = CurrentLocation + FVector(0, MoveSpeed * DeltaTime, 0);
		SetActorLocation(TargetLocation);

		if (DistanceFromStart >= MaxRange)
		{
			bMovingForward = false;
		}
	}
	else
	{
		FVector TargetLocation = CurrentLocation + FVector(0, -MoveSpeed * DeltaTime, 0);
		SetActorLocation(TargetLocation);

		if (DistanceFromStart <= 5.0f)  
		{
			SetActorLocation(StartLocation);  
			bMovingForward = true;
		}
	}
}

void AMovingItem::DisappearActor()
{
	UE_LOG(LogTemp, Warning, TEXT("Actor disappeared"));
	Destroy();
}


