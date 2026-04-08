#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"


UCLASS()
class SPARTAPROJECT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,Category="Item|Components")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable,Category="Item|Actions")
	void ResetActorPosition();
	
	UFUNCTION(BlueprintPure, Category = "Item|Properties")
	float GetRoationSpeed() const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Item|Events")
	void OnItemPickedUp();

};
