// Credit by Gufran Yeşilyurt 2021

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	float InitialYaw;


	UPROPERTY(EditAnywhere);
	float TargetYaw = 90.f;

	UPROPERTY(EditAnywhere)
	float RequiredMass = 55.f;

	UPROPERTY(EditAnywhere);
	float DoorCloseDelay = 0.42f;

	UPROPERTY(EditAnywhere);
	float DoorRotationSpeed = 2.f;

	UPROPERTY(EditAnywhere);
	ATriggerVolume* PressurePlate;
	
	UPROPERTY(EditAnywhere);
	AActor* ActorThatOpens;	

	float DoorLastOpened = 0.f;

	float TotalMassOfActors() const;

};
