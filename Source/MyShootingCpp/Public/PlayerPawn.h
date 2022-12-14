// Fill out your copyright notice in the Description page of Project Settings.

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



	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	// 화살표시(FirePosition)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* firePosition;
	

	UPROPERTY(EditAnywhere)
	class UPlayerMoveComponent* moveComp;

	UPROPERTY(EditAnywhere)
	class UPlayerFireComponent* fireComp;

	int hp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int maxHP = 5;

	// Event함수, Callbaek함수
	void OnMyHit(int damage);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnMyUpdateHealth(int value);

};

