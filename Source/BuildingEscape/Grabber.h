// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	UPROPERTY(EditAnywhere)
	float Delay = 1.f;

	UPROPERTY(EditAnywhere)
	float Reach = 300.f;

	UPhysicsHandleComponent* PhysicHandler = nullptr;

	UInputComponent* InputComponent = nullptr;

	void Initialize();

	void GrabControl();

	void Grab();

	void Release();

	FHitResult RayCasting() const;
	FVector LineTraceEnd() const;
	FVector LineTraceStart() const;

};
