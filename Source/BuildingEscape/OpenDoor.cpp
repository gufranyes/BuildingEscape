// Credit by Gufran Yeşilyurt 2021


#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	float RotateAngle = 90.f;
	FRotator DoorAngle = GetOwner() -> GetActorRotation();
	DoorAngle.Yaw = RotateAngle;
	GetOwner() -> SetActorRotation(DoorAngle);
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

