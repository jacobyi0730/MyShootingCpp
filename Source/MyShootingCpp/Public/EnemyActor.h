// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyActor.generated.h"

UCLASS()
class MYSHOOTINGCPP_API AEnemyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ���������ʹ�.
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	// �¾ �� ������ ���ϰ�ʹ�. 30% Ȯ���� �÷��̾����, �������� �չ������� �����ϰ�ʹ�.

	// ��ư��鼭 �� �������� �̵��ϰ�ʹ�.
	FVector direction;
	float speed = 500;
};
