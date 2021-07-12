// Credit by Gufran Yeşilyurt 2021

#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "OpenDoor.h"

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

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	TargetYaw += InitialYaw;

	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("%s has the open door component on it, but no pressure plate set!"), *GetOwner() -> GetName());
	}

	ActorThatOpens = GetWorld() -> GetFirstPlayerController() -> GetPawn();
	
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (PressurePlate && PressurePlate ->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld() -> GetTimeSeconds();
	}
	else if (PressurePlate && !(PressurePlate -> IsOverlappingActor(ActorThatOpens)))
	{
		float CurrentTime = GetWorld() -> GetTimeSeconds();
		if ((CurrentTime - DoorLastOpened) > DoorCloseDelay)
		{
			CloseDoor(DeltaTime);
		}
	}
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("Yaw is: %f"), GetOwner()->GetActorRotation().Yaw);
	float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	FRotator DoorAngle(0.f, TargetYaw, 0.f);
	DoorAngle.Yaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, DoorRotationSpeed);
	GetOwner()->SetActorRotation(DoorAngle);
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("Yaw is: %f"), GetOwner()->GetActorRotation().Yaw);
	float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	FRotator DoorAngle(0.f, InitialYaw, 0.f);
	DoorAngle.Yaw = FMath::FInterpTo(CurrentYaw, InitialYaw, DeltaTime, DoorRotationSpeed);
	GetOwner()->SetActorRotation(DoorAngle);
}