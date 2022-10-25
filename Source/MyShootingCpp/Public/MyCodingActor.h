﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCodingActor.generated.h"

UCLASS()
class MYSHOOTINGCPP_API AMyCodingActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyCodingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Edit / Visible
	// DefaultOnly / InstanceOnly / Anywhere

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyVar)
	int number = 10;
	UPROPERTY(EditAnywhere, Category = MyVar)
	float pi = 3.141592f;
	UPROPERTY(EditAnywhere, Category = MyVar)
	bool isReal;
	UPROPERTY(EditAnywhere, Category = MyVar)
	FString name = TEXT("이영훈");
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void NotifyActorBeginOverlap(AActor* OtherActor) override;


public:
	UFUNCTION(BlueprintCallable)
	int PlusCallable(int a, int b);

	UFUNCTION(BlueprintPure)
	int PlusPure(int a, int b);
};
