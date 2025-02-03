// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorCpp.generated.h"

UCLASS()
class EXAMPROJECT_API ADoorCpp : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoorCpp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, Category = "myC++Class")
	void SetIsPlayerNear(bool nIsPlayerNear);

	UPROPERTY(BlueprintReadWrite, Category = "myC++Class")
	bool isPlayerNear = false;
	UPROPERTY(VisibleAnywhere, Category = "myC++Class")
	bool isOpened = false;
	UPROPERTY(VisibleAnywhere, Category = "myC++Class")
	float currentRotation = 0;
	UPROPERTY(VisibleAnywhere, Category = "myC++Class")
	float rotationSpeed = 250;
	UPROPERTY(VisibleAnywhere, Category = "myC++Class")
	float rotationValue = 0;

	void openCloseDoor(float DeltaTime);
};
