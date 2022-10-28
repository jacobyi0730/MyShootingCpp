﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class MYSHOOTINGCPP_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float h;
	float v;
	void OnAxisHorizontal(float value);
	void OnAxisVertical(float value);

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	float speed = 500;

	// 화살표시(FirePosition)
	UPROPERTY(EditAnywhere)
	class UArrowComponent* firePosition;
	// BP_Bullet을 담을 포인터변수
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABulletActor> bulletFactory;

	void OnActionFire(); //선언

};

