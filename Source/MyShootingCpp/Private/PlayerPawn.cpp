﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include <Components/ArrowComponent.h>
#include "BulletActor.h"
#include "PlayerMoveComponent.h"
#include "PlayerFireComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));

	SetRootComponent(meshComp);

	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("firePosition"));
	firePosition->SetRelativeLocation(FVector(0, 0, 100));
	firePosition->SetRelativeRotation(FRotator(90, 0, 0));
	firePosition->SetupAttachment(meshComp);

	moveComp = CreateDefaultSubobject<UPlayerMoveComponent>(TEXT("moveComp"));

	fireComp = CreateDefaultSubobject<UPlayerFireComponent>(TEXT("fireComp"));

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 사용자의 입력(축)으로 방향을 만들고
	
	//FVector direction = GetActorRightVector() * h + GetActorUpVector() * v;
	//direction.Normalize();
	//// P = P0 + vt
	//// 그 방향으로 이동하고싶다.
	//FVector p0 = GetActorLocation();
	//FVector velocity = direction * speed;
	//float t = DeltaTime;

	//SetActorLocation(p0 + velocity * t);


}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	moveComp->SetupInput(PlayerInputComponent);
	fireComp->SetupInput(PlayerInputComponent);

}

