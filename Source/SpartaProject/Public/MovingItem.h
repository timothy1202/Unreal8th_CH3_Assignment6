#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingItem.generated.h"

UCLASS()
class SPARTAPROJECT_API AMovingItem : public AActor
{
	GENERATED_BODY()
	
public:	

	AMovingItem();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Item")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Item")
	float MaxRange;

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Item")
	FVector StartLocation;
	
	FTimerHandle DisappearTimerHandle;
	void DisappearActor();
	
	bool bMovingForward;
};
