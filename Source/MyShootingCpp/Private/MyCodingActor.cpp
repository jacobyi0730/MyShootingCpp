// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCodingActor.h"

// Sets default values
AMyCodingActor::AMyCodingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCodingActor::BeginPlay()
{
	Super::BeginPlay();
	 // ��ü�� �ڱ��ڽ��� �θ��� this��� �θ���.
	 UE_LOG(LogTemp, Warning, TEXT("Hello World!!%d"), number);
}

// Called every frame
void AMyCodingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyCodingActor::NotifyActorBeginOverlap(AActor* OtherActor)
{

}

