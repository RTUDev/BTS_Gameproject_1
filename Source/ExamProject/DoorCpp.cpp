// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorCpp.h"
#include "Components/SphereComponent.h"
using namespace std;
// Sets default values
ADoorCpp::ADoorCpp()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoorCpp::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADoorCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	openCloseDoor(DeltaTime);
}

void ADoorCpp::openCloseDoor(float DeltaTime) {
	if (isPlayerNear && !isOpened) {
		rotationValue = DeltaTime * rotationSpeed;
		AddActorLocalRotation(FRotator(0.0f, rotationValue, 0.0f));
		currentRotation += rotationValue;
		if (currentRotation >= 90) {
			currentRotation = 90;
			SetActorRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
			isOpened = true;
		}
	}
	else if (!isPlayerNear && isOpened) {
		rotationValue = DeltaTime * rotationSpeed * -1;
		AddActorLocalRotation(FRotator(0.0f, rotationValue, 0.0f));
		currentRotation += rotationValue;
		if (currentRotation <= 0) {
			currentRotation = 0;
			SetActorRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
			isOpened = false;
		}

	}

}

void ADoorCpp::SetIsPlayerNear(bool nIsPlayerNear) {
	isPlayerNear = nIsPlayerNear;
}