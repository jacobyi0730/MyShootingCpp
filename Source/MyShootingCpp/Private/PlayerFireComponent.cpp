// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFireComponent.h"
#include "PlayerPawn.h"
#include <Components/ArrowComponent.h>
#include "BulletActor.h"
#include <Kismet/GameplayStatics.h>

// Sets default values for this component's properties
UPlayerFireComponent::UPlayerFireComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerFireComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerFireComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


// ???? / ????
void UPlayerFireComponent::OnActionFire()
{
	auto player = Cast<APlayerPawn>(GetOwner());

	GetWorld()->SpawnActor<ABulletActor>(bulletFactory, player->firePosition->GetComponentTransform());

	UGameplayStatics::PlaySound2D(GetWorld(), fireSound);
}

void UPlayerFireComponent::SetupInput(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &UPlayerFireComponent::OnActionFire);
}

