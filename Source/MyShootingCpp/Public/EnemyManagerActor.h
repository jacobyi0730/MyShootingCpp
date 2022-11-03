// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyManagerActor.generated.h"

UCLASS()
class MYSHOOTINGCPP_API AEnemyManagerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyManagerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
	class UArrowComponent* spawnArrow;

	// �ð��� �帣�ٰ� �����ð��� �Ǹ� �� ���忡�� ���� ���� spawnArrow��ġ�� ��ġ�ϰ�ʹ�.
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AEnemyActor> enemyFactory;

	UPROPERTY(EditAnywhere)
	float makeTime = 2;

	float currentTime;

	void MakeEnemy();

};
